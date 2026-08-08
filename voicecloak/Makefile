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

TEST_SRCS := $(TESTDIR)/test_vc_fft.c $(SRCDIR)/vc_fft.c
TEST_BIN  := $(TESTDIR)/test_vc_fft

LDLIBS   := -lssl -lcrypto -lm
LDLIBS_T := -lssl -lcrypto -lcmocka -lm

.PHONY: all clean test

all: $(BIN)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(TEST_BIN): $(TEST_SRCS)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LDLIBS_T)

test: $(TEST_BIN)
	$(TEST_BIN)

clean:
	rm -rf $(OBJDIR) $(BIN) $(TESTDIR)/test_vc_fft
