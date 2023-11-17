CC=gcc
CFLAGS=-I./include
SRC=./src/
BUILD=./build/
COMPILE=$(CC) $(CFLAGS)

MAIN=$(BUILD)main
TESTS=$(BUILD)tests

all: main

main: $(SRC)main.c $(BUILD)functions.o
	$(COMPILE) -lm $^ -o $(MAIN)

$(TESTS): $(SRC)tests.c $(BUILD)functions.o
	$(COMPILE) -lm $^ -o $(TESTS)

$(BUILD)functions.o: $(SRC)functions.c
	$(COMPILE) -c $^ -o $(BUILD)functions.o


build:
	mkdir -p $(BUILD)

clean:
	rm -rvf $(MAIN) $(BUILD)*.o	

run:
	$(MAIN)

tests: $(TESTS)
	$(TESTS)


.PHONY: build run tests



