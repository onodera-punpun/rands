#!/bin/sh
set -e

# uninstall.sh
# 2015/01/17(San)
# walkingmask
# uninstall rands command

if [ -f /Users/$USER/bin/rands ]; then
	rm /Users/$USER/bin/rands
fi

if [ -L /usr/local/bin/rands ]; then
	sudo rm /usr/local/bin/rands
fi