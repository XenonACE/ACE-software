#!/bin/bash

if [ $1 == "dark" ]; then
	echo -e "[Settings]\ngtk-application-prefer-dark-theme = true\ngtk-theme-name = Adwaita" > ~/.config/gtk-3.0/settings.ini
	sudo echo -e "[Settings]\ngtk-application-prefer-dark-theme = true\ngtk-theme-name = Adwaita" > /etc/gtk-3.0/settings.ini
elif [ $1 == "light" ]; then
	rm ~/.config/gtk-3.0/settings.ini
	sudo rm /etc/gtk-3.0/settings.ini
else
	echo First param must be light or dark
fi
