# `install.sh`

> Source: [install.sh:1](../../install.sh#L1) | language `sh` | coverage 100.0% | [API index](../index.md)

SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl kernel module.

All real build, install, and clean commands live in the top-level Makefile. This script is intentionally minimal: it only ensures the toolchain and kernel headers are present, then exits.
