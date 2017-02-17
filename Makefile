CC=g++
CFLAGS=-Wall -O3

# Directories
SRC_DIR=src
BIN_DIR=bin

all:
	$(CC) $(CFLAGS) $(SRC_DIR)/kate.cpp -o $(BIN_DIR)/kate.exe
	
clean: