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

# Objects
OBJECTS=src/lib/element/object/Object.o	\
	src/lib/element/object/Character.o \
	src/lib/element/object/Double.o \
	src/lib/element/object/Integer.o \
	src/lib/element/object/String.o \
	src/lib/element/object/Boolean.o \
	src/lib/element/object/Void.o

LANGUAGES=src/lib/language/$(LANGUAGE).o

.PHONY: all
all: $(DEPENDENCIES) $(OBJECTS) $(LANGUAGES)
	$(CC) $(CFLAGS) $(DEPENDENCIES) $(LANGUAGES) $(SRC_DIR)/kate.cpp -o $(BIN_DIR)/kate

.PHONY: object-test
object-test: $(OBJECTS)
	$(CC) $(CFLAGS) src/lib/element/object/testmain.cpp $(OBJECTS) -o src/lib/element/object/testmain

clean:
	find src/ -type f -name "*.o" -exec rm -f {} +
	rm -f bin/*

.cpp.o:
	$(CC) $(CFLAGS) -c -o $*.o $<
