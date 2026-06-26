# 🎯 🎯 VSL-DSP Open Source Driver
![1_NFRogTqj0gCKMQEIMw19Pg](https://github.com/user-attachments/assets/29cea052-00c0-4ef6-88cb-bb293f254959)

# VSL-DSP Open Source Driver

Open source Linux kernel driver for the PreSonus AudioBox 22 VSL audio interface.

This driver is a simple USB device detector that logs when the AudioBox 22 VSL is connected or disconnected. It does **not** interfere with the standard `snd-usb-audio` driver, allowing full audio functionality while providing kernel-level device detection.

## Features

- ✅ Automatic device detection via USB vendor/product ID (0x194f:0x0101)
- ✅ Works alongside the standard ALSA `snd-usb-audio` driver (no conflict)
- ✅ Logs device connection/disconnection and basic info to the kernel ring buffer
- ✅ Optional automatic loading at boot via `/etc/modules-load.d/`
- ✅ Simple build and install with `make` and `sudo make install`
- ✅ GPL-2.0-or-later licensed

## Quick Start

### 1. Install build dependencies (run once as root)

```bash
sudo ./install.sh
```

This script installs the necessary build tools (`build-essential`, `perl`) and the kernel headers for your running kernel.

### 2. Build the driver

```bash
make
```

This produces `audiobox_vsl.ko` in the current directory.

### 3. Install the driver

```bash
sudo make install
```

This copies the kernel module to `/lib/modules/$(uname -r)/extra/`, runs `depmod`, and creates `/etc/modules-load.d/audiobox-vsl.conf` so the module loads automatically on boot.

### 4. Verify it works

Plug in or unplug your AudioBox 22 VSL and check the kernel log:

```bash
dmesg | grep -i audiobox
```

You should see messages like:

```
[  ...] 🎉 AudioBox 22 VSL detected! Vendor: 194f, Product: 0101
[  ...] Manufacturer: PreSonus Audio Electronics
[  ...] Product: AudioBox 22 VSL
[  ...] Serial: <serial-number>
[  ...] 🔌 AudioBox 22 VSL disconnected
```

### 5. Manual loading/unloading (optional)

```bash
# Load the module
sudo modprobe audiobox_vsl

# Unload the module
sudo rmmod audiobox_vsl
```

### 6. Uninstall the driver

```bash
sudo make uninstall
```

This removes the module file, the mods-load.d entry, and runs `depmod`.

## How It Works

The driver registers a USB driver for the AudioBox 22 VSL's vendor and product ID. When the device is connected, the `probe` function prints device information to the kernel log. Importantly, the probe function returns `-ENODEV`, which tells the USB core **not** to bind this driver to the device. This allows the standard `snd-usb-audio` driver to claim the interface and provide full audio functionality (playback, capture, mixer controls) via ALSA.

Thus, this driver serves only as a detector and logger; it does not interfere with audio operation.

## Source Files

- `audiobox_vsl.c` – Main driver source (USB detection and logging)
- `Makefile` – Build rules (`make`, `make install`, `make uninstall`, `make clean`)
- `install.sh` – Installs build dependencies (run as root)
- `configure` – Simple script to verify build environment (optional)
- `audiobox_vsl.h` – Header (kept for compatibility with existing tree)

## About the Python PoC

This repository also contains a Python proof-of-concept (`vsl_dsp_poc/`) that reverse-engineers the AudioBox 22 VSL's USB-HID protocol for direct DSP control (volume, mute, EQ, etc.). That project is separate from this kernel driver and is provided for reference and experimentation. See the `vsl_dsp_poc/` directory for its own README.

## License

This software is licensed under the **GPL-2.0-or-later** license. See the `LICENSE` file for details.

## Contributions

Contributions are welcome! If you have improvements to the driver, packaging, or documentation, please open an issue or submit a pull request.

## Acknowledgments

- Thanks to the PreSonus AudioBox 22 VSL community for their interest in open-source drivers.
- Inspired by reverse‑engineering efforts to understand USB audio devices.

---
**Version:** 1.0.0  
**Last updated:** 2026-06-26

<img width="807" height="858" alt="image" src="https://github.com/user-attachments/assets/2ede9d70-ae80-4936-89b3-b0e4292dec81" />

---

<img width="709" height="873" alt="image" src="https://github.com/user-attachments/assets/123af69c-3f1a-4661-98fe-ba340dc4d373" />

## 🔗 Links (Because Sharing Is Power)
- 📓 Wiki: [https://deepwiki.com/grisuno/blacksandbeacon](https://deepwiki.com/grisuno/blacksandbeacon)
- 📰 Blog: [https://medium.com/@lazyown.redteam/black-sand-beacon-when-your-linux-box-starts-whispering-to-c2-in-aes-256-cfb-and-no-one-notices-105ca5ed9547](https://medium.com/@lazyown.redteam/black-sand-beacon-when-your-linux-box-starts-whispering-to-c2-in-aes-256-cfb-and-no-one-notices-105ca5ed9547)
- 🎤 Podcast: [https://www.podbean.com/eas/pb-qe42t-198ee9d](https://www.podbean.com/eas/pb-qe42t-198ee9d)
- 🐙 GitHub: [https://github.com/grisuno/beacon](https://github.com/grisuno/beacon)
- 🐙 GitHub: [https://github.com/grisuno/LazyOwn](https://github.com/grisuno/LazyOwn)
- 🩸 Patreon: [https://www.patreon.com/c/LazyOwn](https://www.patreon.com/c/LazyOwn)
- 🐙 GitHub: [https://github.com/grisuno/CVE-2022-22077](https://github.com/grisuno/CVE-2022-22077)
- 🧠 LazyOwn Framework: [https://github.com/grisuno/LazyOwn](https://github.com/grisuno/LazyOwn)
- 🌐 Web: [https://grisuno.github.io/LazyOwn/](https://grisuno.github.io/LazyOwn/)
- 📰 Blog: [https://medium.com/@lazyown.redteam](https://medium.com/@lazyown.redteam)
- 🎥 Videolog: [https://youtu.be/spgLpv3XkiA](https://youtu.be/spgLpv3XkiA)
- 🧪 QuantumVault: [https://quantumvault.pro/landing](https://quantumvault.pro/landing)
- 🧑‍💻 HTB: [https://app.hackthebox.com/users/1998024](https://app.hackthebox.com/users/1998024)
- ☕ Ko-fi: [https://ko-fi.com/grisuno](https://ko-fi.com/grisuno) (Buy me a yerba mate for the next all-nighter)

![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54) ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) ![Flask](https://img.shields.io/badge/flask-%23000.svg?style=for-the-badge&logo=flask&logoColor=white) [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Y8Y2Z73AV)
