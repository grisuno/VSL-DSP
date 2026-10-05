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
            vc_alsa.o vc_rt_cli.o vc_fft.o vc_crypto.o vc_effects.o \
            vc_presets.o vc_level.o vc_eq.o vc_denoise.o)
RT_BIN   := $(SRCDIR)/voicecloak-rt

BINS     := $(BIN) $(RT_BIN)

TEST_SRCS := $(TESTDIR)/test_vc_fft.c $(SRCDIR)/vc_fft.c
TEST_BIN  := $(TESTDIR)/test_vc_fft

STREAM_TEST_SRCS := $(TESTDIR)/test_vc_stream.c $(SRCDIR)/vc_stream.c \
                    $(SRCDIR)/vc_rt.c $(SRCDIR)/vc_fft.c
STREAM_TEST_BIN  := $(TESTDIR)/test_vc_stream

LEVEL_TEST_SRCS := $(TESTDIR)/test_vc_level.c $(SRCDIR)/vc_level.c
LEVEL_TEST_BIN  := $(TESTDIR)/test_vc_level

EFFECT_TEST_SRCS := $(TESTDIR)/test_vc_effects.c $(SRCDIR)/vc_effects.c
EFFECT_TEST_BIN  := $(TESTDIR)/test_vc_effects

EQ_TEST_SRCS := $(TESTDIR)/test_vc_eq.c $(SRCDIR)/vc_eq.c
EQ_TEST_BIN  := $(TESTDIR)/test_vc_eq

DENOISE_TEST_SRCS := $(TESTDIR)/test_vc_denoise.c $(SRCDIR)/vc_denoise.c \
                     $(SRCDIR)/vc_stream.c $(SRCDIR)/vc_rt.c $(SRCDIR)/vc_fft.c
DENOISE_TEST_BIN  := $(TESTDIR)/test_vc_denoise

PRESET_TEST_SRCS := $(TESTDIR)/test_vc_presets.c $(SRCDIR)/vc_presets.c \
                    $(SRCDIR)/vc_effects.c $(SRCDIR)/vc_level.c $(SRCDIR)/vc_eq.c \
                    $(SRCDIR)/vc_stream.c $(SRCDIR)/vc_rt.c $(SRCDIR)/vc_fft.c
PRESET_TEST_BIN  := $(TESTDIR)/test_vc_presets

LDLIBS    := -lssl -lcrypto -lm
LDLIBS_RT := -lasound -lssl -lcrypto -lm
LDLIBS_T  := -lssl -lcrypto -lcmocka -lm
LDLIBS_ST := -lcmocka -lm
ASAN_FLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer
ASAN_TEST_DIR := $(OBJDIR)/asan
ASAN_TEST_BINS := $(ASAN_TEST_DIR)/test_vc_fft $(ASAN_TEST_DIR)/test_vc_stream \
	$(ASAN_TEST_DIR)/test_vc_level $(ASAN_TEST_DIR)/test_vc_effects \
	$(ASAN_TEST_DIR)/test_vc_eq $(ASAN_TEST_DIR)/test_vc_denoise \
	$(ASAN_TEST_DIR)/test_vc_presets

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
VC_PRESET    ?= cloak
VC_TARGET_DBFS ?= -18
VC_MAX_GAIN_DB ?= 12
VC_CEILING_DBFS ?= -1
VC_ATTACK_MS ?= 10
VC_RELEASE_MS ?= 250
VC_LIMITER_RELEASE_MS ?= 50
VC_AGC       ?= 1
# Empty means "use the preset value"; set to forward --drive / --ring-*.
VC_DRIVE       ?=
VC_RING_AMOUNT ?=
VC_RING_HZ     ?=
VC_RING_WAVE   ?=
# Noise reduction (on by default in routes): stay silent for
# VC_NOISE_LEARN_MS at start, or load a print saved with VC_NOISE_SAVE.
VC_DENOISE         ?= 1
VC_NOISE_LEARN_MS  ?=
VC_NOISE_PROFILE   ?=
VC_NOISE_SAVE      ?=
VC_NOISE_REDUCTION ?=
VC_NOISE_GATE_RANGE_DB ?=
# Headphone monitor: copy the transformed voice back to the AudioBox so it
# is audible with the front MIXER knob towards PLAYBACK (OBS is unaffected).
VC_MONITOR   ?= 1
VC_MONITOR_LATENCY_MS ?= 20
PULSE_MONITOR_SINK ?= $(shell pactl list sinks short 2>/dev/null | awk '/AudioBox/{print $$2; exit}')
VC_PRESETS   := robot monster woman man space underwater church phaser
VC_PRESET_ARGS = $(if $(filter cloak,$(VC_PRESET)),--mode $(VC_MODE),--preset $(VC_PRESET))
VC_AGC_ARGS = $(if $(filter 0,$(VC_AGC)),--no-agc,)
VC_TONE_ARGS = $(if $(VC_DRIVE),--drive $(VC_DRIVE),) \
	$(if $(VC_RING_AMOUNT),--ring-amount $(VC_RING_AMOUNT),) \
	$(if $(VC_RING_HZ),--ring-hz $(VC_RING_HZ),) \
	$(if $(VC_RING_WAVE),--ring-wave $(VC_RING_WAVE),)
VC_DENOISE_ARGS = $(if $(filter 1,$(VC_DENOISE)),--denoise \
	$(if $(VC_NOISE_LEARN_MS),--noise-learn-ms $(VC_NOISE_LEARN_MS),) \
	$(if $(VC_NOISE_PROFILE),--noise-profile $(VC_NOISE_PROFILE),) \
	$(if $(VC_NOISE_SAVE),--noise-save $(VC_NOISE_SAVE),) \
	$(if $(VC_NOISE_REDUCTION),--noise-reduction $(VC_NOISE_REDUCTION),) \
	$(if $(VC_NOISE_GATE_RANGE_DB),--noise-gate-range-db $(VC_NOISE_GATE_RANGE_DB),),)

.PHONY: all rt clean test asan pulse alsa setup-pulse setup-alsa setup-monitor \
	stop-monitor help \
	$(addprefix pulse-,$(VC_PRESETS)) $(addprefix alsa-,$(VC_PRESETS))

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

$(LEVEL_TEST_BIN): $(LEVEL_TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST)

$(EFFECT_TEST_BIN): $(EFFECT_TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST)

$(EQ_TEST_BIN): $(EQ_TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST)

$(DENOISE_TEST_BIN): $(DENOISE_TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST)

$(PRESET_TEST_BIN): $(PRESET_TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST)

$(ASAN_TEST_DIR): | $(OBJDIR)
	mkdir -p $@

$(ASAN_TEST_DIR)/test_vc_fft: $(TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

$(ASAN_TEST_DIR)/test_vc_stream: $(STREAM_TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

$(ASAN_TEST_DIR)/test_vc_level: $(LEVEL_TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

$(ASAN_TEST_DIR)/test_vc_effects: $(EFFECT_TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

$(ASAN_TEST_DIR)/test_vc_eq: $(EQ_TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

$(ASAN_TEST_DIR)/test_vc_denoise: $(DENOISE_TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

$(ASAN_TEST_DIR)/test_vc_presets: $(PRESET_TEST_SRCS) | $(ASAN_TEST_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_ST) $(ASAN_FLAGS)

test: $(TEST_BIN) $(STREAM_TEST_BIN) $(LEVEL_TEST_BIN) $(EFFECT_TEST_BIN) \
	$(EQ_TEST_BIN) $(DENOISE_TEST_BIN) $(PRESET_TEST_BIN)
	$(TEST_BIN)
	$(STREAM_TEST_BIN)
	$(LEVEL_TEST_BIN)
	$(EFFECT_TEST_BIN)
	$(EQ_TEST_BIN)
	$(DENOISE_TEST_BIN)
	$(PRESET_TEST_BIN)

asan: $(ASAN_TEST_BINS)
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_fft
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_stream
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_level
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_effects
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_eq
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_denoise
	ASAN_OPTIONS=detect_leaks=1 $(ASAN_TEST_DIR)/test_vc_presets

setup-pulse:
	@command -v pactl >/dev/null || { echo "missing pactl (pipewire-pulse / pulseaudio-utils)"; exit 1; }
	@pactl list sinks short | grep -q "$(PULSE_SINK)" || \
		pactl load-module module-null-sink sink_name=$(PULSE_SINK) \
			sink_properties=device.description=VoiceCloak >/dev/null
	@echo "sink ready: $(PULSE_SINK) (in OBS: Monitor of $(PULSE_SINK))"

setup-monitor: setup-pulse
	@if [ -z "$(PULSE_MONITOR_SINK)" ]; then \
		echo "monitor: no AudioBox sink found (set PULSE_MONITOR_SINK=...); skipping"; \
	elif pactl list modules short | grep -q "module-loopback.*source=$(PULSE_SINK).monitor"; then \
		echo "monitor: already active -> $(PULSE_MONITOR_SINK)"; \
	else \
		pactl load-module module-loopback source=$(PULSE_SINK).monitor \
			sink=$(PULSE_MONITOR_SINK) latency_msec=$(VC_MONITOR_LATENCY_MS) >/dev/null && \
		echo "monitor: $(PULSE_SINK) -> $(PULSE_MONITOR_SINK) (MIXER knob towards PLAYBACK)"; \
	fi

stop-monitor:
	@pactl list modules short | awk '/module-loopback.*source=$(PULSE_SINK).monitor/{print $$1}' | \
		xargs -r -n1 pactl unload-module
	@echo "monitor: stopped"

pulse: $(RT_BIN) setup-pulse $(if $(filter 1,$(VC_MONITOR)),setup-monitor,)
	@echo "OBS: do NOT open the AudioBox; use 'Monitor of $(PULSE_SINK)' as microphone."
	PULSE_SINK=$(PULSE_SINK) $(RT_BIN) live -D $(VSL_CAPTURE) -P $(PULSE_PCM) \
		$(VC_PRESET_ARGS) --rate $(VC_RATE) --channels $(VC_CHANNELS) \
		--period $(VC_PERIOD) --fft $(VC_FFT) --hop $(VC_HOP) \
		--target-dbfs $(VC_TARGET_DBFS) --max-gain-db $(VC_MAX_GAIN_DB) \
		--ceiling-dbfs $(VC_CEILING_DBFS) --attack-ms $(VC_ATTACK_MS) \
		--release-ms $(VC_RELEASE_MS) \
		--limiter-release-ms $(VC_LIMITER_RELEASE_MS) $(VC_AGC_ARGS) \
		$(VC_TONE_ARGS) $(VC_DENOISE_ARGS) $(VC_EXTRA)

setup-alsa:
	@command -v arecord >/dev/null || { echo "missing alsa-utils"; exit 1; }
	@arecord -l | grep -q Loopback || sudo modprobe snd-aloop index=$(ALOOP_INDEX)
	@arecord -l | grep -q Loopback || { echo "snd-aloop failed to load"; exit 1; }
	@echo "loopback ready (OBS captures: $(ALOOP_CAP))"

alsa: $(RT_BIN) setup-alsa
	@echo "OBS: do NOT open the AudioBox; use ALSA source '$(ALOOP_CAP)' as microphone."
	$(RT_BIN) live -D $(VSL_CAPTURE) -P $(ALOOP_PB) \
		$(VC_PRESET_ARGS) --rate $(VC_RATE) --channels $(VC_CHANNELS) \
		--period $(VC_PERIOD) --fft $(VC_FFT) --hop $(VC_HOP) \
		--target-dbfs $(VC_TARGET_DBFS) --max-gain-db $(VC_MAX_GAIN_DB) \
		--ceiling-dbfs $(VC_CEILING_DBFS) --attack-ms $(VC_ATTACK_MS) \
		--release-ms $(VC_RELEASE_MS) \
		--limiter-release-ms $(VC_LIMITER_RELEASE_MS) $(VC_AGC_ARGS) \
		$(VC_TONE_ARGS) $(VC_DENOISE_ARGS) $(VC_EXTRA)

$(addprefix pulse-,$(VC_PRESETS)):
	$(MAKE) pulse VC_PRESET=$(patsubst pulse-%,%,$@)

$(addprefix alsa-,$(VC_PRESETS)):
	$(MAKE) alsa VC_PRESET=$(patsubst alsa-%,%,$@)

help:
	@echo "OBS usage (pick ONE route, OBS never opens the AudioBox):"
	@echo "  make test / make asan  run unit tests normally / with ASan+UBSan"
	@echo "  make pulse [VC_MODE=witness|subtle] [VC_EXTRA=\"--semitones 7 --formant 1.3\"]"
	@echo "  make pulse VC_PRESET=robot|monster|woman|man|space|underwater|church|phaser"
	@echo "  make pulse-robot (aliases: pulse-monster, pulse-woman, pulse-man, pulse-space, pulse-underwater, pulse-church, pulse-phaser)"
	@echo "    AudioBox -> voicecloak -> null-sink $(PULSE_SINK) -> OBS (Monitor of $(PULSE_SINK))"
	@echo "  make alsa  [VSL_CAPTURE=$(VSL_CAPTURE)] [ALOOP_PB=$(ALOOP_PB)]"
	@echo "  make alsa-robot (same preset aliases as pulse-*)"
	@echo "    AudioBox -> voicecloak -> $(ALOOP_PB) -> OBS (ALSA source $(ALOOP_CAP))"
	@echo "  make setup-pulse / make setup-alsa  prepare the virtual device without running live"
	@echo "  pulse routes also monitor to the AudioBox (MIXER knob -> PLAYBACK); VC_MONITOR=0 disables it"
	@echo "  make stop-monitor  remove the headphone monitor loopback"
	@echo "  noise reduction is on by default: stay silent ~1.5 s at start (VC_DENOISE=0 disables)"
	@echo "  make pulse-robot VC_NOISE_SAVE=noise.vcn  then  make pulse-robot VC_NOISE_PROFILE=noise.vcn"
	@echo "  make pulse-robot VC_DRIVE=3 VC_RING_AMOUNT=0 (drive/ring override the preset; empty = preset value)"
	@echo "Vars: VSL_CAPTURE PULSE_SINK PULSE_PCM ALOOP_PB ALOOP_CAP VC_MODE VC_PRESET VC_AGC VC_TARGET_DBFS VC_MAX_GAIN_DB VC_CEILING_DBFS VC_ATTACK_MS VC_RELEASE_MS VC_LIMITER_RELEASE_MS VC_DRIVE VC_RING_AMOUNT VC_RING_HZ VC_RING_WAVE VC_DENOISE VC_NOISE_LEARN_MS VC_NOISE_PROFILE VC_NOISE_SAVE VC_NOISE_REDUCTION VC_NOISE_GATE_RANGE_DB VC_MONITOR VC_MONITOR_LATENCY_MS PULSE_MONITOR_SINK VC_RATE VC_CHANNELS VC_PERIOD VC_FFT VC_HOP VC_EXTRA"

clean:
	rm -rf $(OBJDIR) $(BINS) $(TESTDIR)/test_vc_fft $(TESTDIR)/test_vc_stream \
		$(TESTDIR)/test_vc_level $(TESTDIR)/test_vc_effects $(TESTDIR)/test_vc_eq $(TESTDIR)/test_vc_denoise \
		$(TESTDIR)/test_vc_presets
