
Debian
====================
This directory contains files used to package ovod/ovo-qt
for Debian-based Linux systems. If you compile ovod/ovo-qt yourself, there are some useful files here.

## ovo: URI support ##


ovo-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ovo-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ovo-qt binary to `/usr/bin`
and the `../../share/pixmaps/ovo128.png` to `/usr/share/pixmaps`

ovo-qt.protocol (KDE)

