#!/bin/sh
set -e

# install.sh
# 2016/01/17(Sun)
# walkingmask
# install rands command

gcc -Ofast rands.c -o rands
chmod a+x rands

if [ ! -d /Users/$USER/bin ]; then
	mkdir /Users/$USER/bin
fi

if [ -f /Users/$USER/bin/rands ]; then
	rm /Users/$USER/bin/rands
fi

mv ./rands /Users/$USER/bin/rands

if [ -L /usr/local/bin/rands ]; then
	sudo rm /usr/local/bin/rands
fi

sudo ln -s /Users/$USER/bin/rands /usr/local/bin/rands