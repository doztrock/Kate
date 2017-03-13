LANGUAGE=en

CC=g++
CFLAGS=-Wall -O3 -DLANGUAGE -D$(LANGUAGE)

# Directories
SRC_DIR=src
BIN_DIR=bin

# Dependencies
DEPENDENCIES=src/lib/parse.o src/lib/library.o src/lib/help.o \
	     src/lib/element/Variable.o src/lib/element/Constant.o \
	     src/lib/function/function.o src/lib/function/ParameterList.o

LANGUAGES=src/lib/language/$(LANGUAGE).o

.PHONY: all
all: $(DEPENDENCIES) $(LANGUAGES)
	$(CC) $(CFLAGS) $(DEPENDENCIES) $(LANGUAGES) $(SRC_DIR)/kate.cpp -o $(BIN_DIR)/kate

clean:
	find src/ -type f -name "*.o" -exec rm -f {} +
	rm -f bin/*

.cpp.o:
	$(CC) $(CFLAGS) -c -o $*.o $<
