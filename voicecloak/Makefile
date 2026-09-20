CC       ?= gcc
CSTD     ?= -std=c11
CFLAGS   ?= $(CSTD) -O2 -g -Wall -Wextra -Werror -Wshadow -Wpedantic \
            -Wstrict-prototypes -Wmissing-prototypes -Wconversion \
            -Wsign-conversion -Wold-style-definition \
            -fstack-protector-strong -D_FORTIFY_SOURCE=2

SRCDIR   := src
OBJDIR   := build
TESTDIR  := tests

SRCS     := $(SRCDIR)/vc_fft.c $(SRCDIR)/vc_stft.c $(SRCDIR)/vc_wav.c \
            $(SRCDIR)/vc_crypto.c $(SRCDIR)/vc_dsp.c $(SRCDIR)/vc_cli.c
OBJS     := $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
BIN      := $(SRCDIR)/voicecloak

RT_OBJS  := $(addprefix $(OBJDIR)/,vc_stream.o vc_rt.o vc_rt_seed.o \
            vc_alsa.o vc_rt_cli.o vc_fft.o vc_crypto.o)
RT_BIN   := $(SRCDIR)/voicecloak-rt

BINS     := $(BIN) $(RT_BIN)

TEST_SRCS := $(TESTDIR)/test_vc_fft.c $(SRCDIR)/vc_fft.c
TEST_BIN  := $(TESTDIR)/test_vc_fft

STREAM_TEST_SRCS := $(TESTDIR)/test_vc_stream.c $(SRCDIR)/vc_stream.c \
                    $(SRCDIR)/vc_rt.c $(SRCDIR)/vc_fft.c
STREAM_TEST_BIN  := $(TESTDIR)/test_vc_stream

LDLIBS    := -lssl -lcrypto -lm
LDLIBS_RT := -lasound -lssl -lcrypto -lm
LDLIBS_T  := -lssl -lcrypto -lcmocka -lm
LDLIBS_ST := -lcmocka -lm

# --- OBS streaming routes (single source of truth, override on CLI) ---
# Capture is always the AudioBox; playback is the virtual device OBS reads.
# Examples:
#   make pulse VC_MODE=witness
#   make pulse VC_EXTRA="--semitones 7 --formant 1.3"
#   make alsa VSL_CAPTURE=hw:CARD=VSL ALOOP_PB=hw:Loopback,0,0
VSL_CAPTURE  ?= plughw:CARD=VSL
PULSE_SINK   ?= vc_out
PULSE_PCM    ?= pulse
ALOOP_PB     ?= hw:Loopback,0,0
ALOOP_CAP    ?= hw:Loopback,1,0
ALOOP_INDEX  ?= 1
VC_MODE      ?= witness
VC_RATE      ?= 48000
VC_CHANNELS  ?= 2
VC_PERIOD    ?= 256
VC_FFT       ?= 1024
VC_HOP       ?= 256
VC_EXTRA     ?=

.PHONY: all rt clean test pulse alsa setup-pulse setup-alsa help

all: $(BINS)

rt: $(RT_BIN)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(RT_BIN): $(RT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS_RT)

$(TEST_BIN): $(TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_T)

$(STREAM_TEST_BIN): $(STREAM_TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST)

test: $(TEST_BIN) $(STREAM_TEST_BIN)
	$(TEST_BIN)
	$(STREAM_TEST_BIN)

setup-pulse:
	@command -v pactl >/dev/null || { echo "missing pactl (pipewire-pulse / pulseaudio-utils)"; exit 1; }
	@pactl list sinks short | grep -q "$(PULSE_SINK)" || \
		pactl load-module module-null-sink sink_name=$(PULSE_SINK) \
			sink_properties=device.description=VoiceCloak >/dev/null
	@echo "sink ready: $(PULSE_SINK) (in OBS: Monitor of $(PULSE_SINK))"

pulse: $(RT_BIN) setup-pulse
	@echo "OBS: do NOT open the AudioBox; use 'Monitor of $(PULSE_SINK)' as microphone."
	PULSE_SINK=$(PULSE_SINK) $(RT_BIN) live -D $(VSL_CAPTURE) -P $(PULSE_PCM) \
		--mode $(VC_MODE) --rate $(VC_RATE) --channels $(VC_CHANNELS) \
		--period $(VC_PERIOD) --fft $(VC_FFT) --hop $(VC_HOP) $(VC_EXTRA)

setup-alsa:
	@command -v arecord >/dev/null || { echo "missing alsa-utils"; exit 1; }
	@arecord -l | grep -q Loopback || sudo modprobe snd-aloop index=$(ALOOP_INDEX)
	@arecord -l | grep -q Loopback || { echo "snd-aloop failed to load"; exit 1; }
	@echo "loopback ready (OBS captures: $(ALOOP_CAP))"

alsa: $(RT_BIN) setup-alsa
	@echo "OBS: do NOT open the AudioBox; use ALSA source '$(ALOOP_CAP)' as microphone."
	$(RT_BIN) live -D $(VSL_CAPTURE) -P $(ALOOP_PB) \
		--mode $(VC_MODE) --rate $(VC_RATE) --channels $(VC_CHANNELS) \
		--period $(VC_PERIOD) --fft $(VC_FFT) --hop $(VC_HOP) $(VC_EXTRA)

help:
	@echo "OBS usage (pick ONE route, OBS never opens the AudioBox):"
	@echo "  make pulse [VC_MODE=witness|subtle] [VC_EXTRA=\"--semitones 7 --formant 1.3\"]"
	@echo "    AudioBox -> voicecloak -> null-sink $(PULSE_SINK) -> OBS (Monitor of $(PULSE_SINK))"
	@echo "  make alsa  [VSL_CAPTURE=$(VSL_CAPTURE)] [ALOOP_PB=$(ALOOP_PB)]"
	@echo "    AudioBox -> voicecloak -> $(ALOOP_PB) -> OBS (ALSA source $(ALOOP_CAP))"
	@echo "  make setup-pulse / make setup-alsa  prepare the virtual device without running live"
	@echo "Vars: VSL_CAPTURE PULSE_SINK PULSE_PCM ALOOP_PB ALOOP_CAP VC_MODE VC_RATE VC_CHANNELS VC_PERIOD VC_FFT VC_HOP VC_EXTRA"

clean:
	rm -rf $(OBJDIR) $(BINS) $(TESTDIR)/test_vc_fft $(TESTDIR)/test_vc_stream
