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

.PHONY: all rt clean test

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

clean:
	rm -rf $(OBJDIR) $(BINS) $(TESTDIR)/test_vc_fft $(TESTDIR)/test_vc_stream
