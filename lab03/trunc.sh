#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Usage: trunch <file_to_trunc> <file_with_size>"
	exit 1
fi

readonly FILE_TO_TRUNC=$1
readonly FILE_WITH_SIZE=$2

set -euxo pipefail

truncate -s `wc -c $FILE_WITH_SIZE | awk '{print $1}'` $FILE_TO_TRUNC
