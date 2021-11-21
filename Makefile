CC=g++
TARGETS=src/block.cpp src/cli.cpp src/inode.cpp src/list.cpp src/utils.cpp main.cpp
OUTPUT=memoryfs

build:
	$(CC) $(TARGETS)

debug:
	$(cc) -Wall -pedantic $(TARGETS)

install: build
	$(cc) $(TARGETS) -o $(OUTPUT)
	mv $(OUPUT) /usr/bin
	