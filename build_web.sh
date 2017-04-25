#!/bin/bash

print_usage(){
	cat <<EOM
Usage: $0 game_path [OUTDIR=<path>]
    game_path      : the path from to the game source or example to build
    OUTDIR=<path>  : the path to write the output of the build to
EOM
}

if [ "$#" == "0" ]; then
	print_usage
	exit 1
fi

GAME_PATH=$1;
shift;

emmake make -f build/web/Makefile GAMEDIR=${GAME_PATH} $@

