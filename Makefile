#!/usr/bin/mak
.PHONY: all clean

all: main.cpp Logger.hpp
	g++ -Wall -Wextra -Werror -Wpedantic -o logger_example main.cpp

clean:
	rm -rf logger_example

