CC = gcc
SRC_DIR := $(shell pwd)/src
INCLUDES = -I
OBJS = src/resolver.o

default: test

deps:
	pip install -r requirements.txt

test: $(OBJS)
	psychic --cargs='$(OBJS) $(INCLUDES) $(SRC_DIR)'

clean:
	rm src/*.o
