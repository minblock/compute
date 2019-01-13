
Debian
====================
This directory contains files used to package computed/compute-qt
for Debian-based Linux systems. If you compile computed/compute-qt yourself, there are some useful files here.

## compute: URI support ##


compute-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install compute-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your compute-qt binary to `/usr/bin`
and the `../../share/pixmaps/compute128.png` to `/usr/share/pixmaps`

compute-qt.protocol (KDE)

