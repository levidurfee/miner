#!/bin/bash

case "$1" in
	performance)
		gprof ./build/main | tee ./tmp/profile ;;
	memory)
		valgrind ./build/main ;;
esac
