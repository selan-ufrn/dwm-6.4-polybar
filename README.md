# dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic window manager for X.

This is my custom build of DWM version 6.4 with some patches.

- actualfullscreen
- anybar (to support polybar)
- attachside
- bottomstack (layout)
- center
- centeredmaster
- cyclelayouts
- fixborders (https://dwm.suckless.org/patches/alpha/dwm-fixborders-6.2.diff)
- focusdir
- full gaps
- ipc
- pertag
- push
- resizecorners
- restartsig
- save floats
- scratchpads
- sticky
- toggletag
- zoomswap

We also need to add the IPC Patch, so that the polybar can communicate with dwm. See [this website](https://github.com/mihirlad55/polybar-dwm-module).
