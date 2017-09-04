#!/bin/bash
trap 'exit 0' SIGINT SIGTERM
make
timeout --signal=INT 10 ./minsh
RET="$?";
if [[ "$RET" = "124" ]]; then

	echo "Caught 124, exiting gracefully"
	exit 0

fi
