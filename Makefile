CC=g++
CFLAGS=-Wall -O3 -DLANGUAGE -DES

# Directories
SRC_DIR=src
BIN_DIR=bin

# Dependencies
DEPENDENCIES=src/lib/parse.o src/lib/trim.o \
	     src/lib/element/Variable.o src/lib/element/Constant.o \
	     src/lib/element/Function.o

.PHONY: all
all: $(DEPENDENCIES)
	$(CC) $(CFLAGS) $(DEPENDENCIES) $(SRC_DIR)/kate.cpp -o $(BIN_DIR)/kate

clean:
	find src/ -type f -name "*.o" -exec rm -f {} +
	rm -f bin/*

.cpp.o:
	$(CC) $(CFLAGS) -c -o $*.o $<
