savedcmd_audiobox_vsl.mod := printf '%s\n'   audiobox_vsl.o | awk '!x[$$0]++ { print("./"$$0) }' > audiobox_vsl.mod
