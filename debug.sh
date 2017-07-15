#!/bin/bash

case "$1" in
	performance)
		gprof ./bin/main | tee ./tmp/profile ;;
	memory)
		valgrind ./bin/main ;;
esac
