#!/bin/bash
trap 'exit 0' SIGINT SIGTERM
timeout --signal=INT --preserve-status 10 ./minsh
RET="$?";
echo $RET;
if [[ "$RET" = "130" ]]; then

	echo "Caught 130, exiting gracefully"
	exit 0

fi
exit 1
