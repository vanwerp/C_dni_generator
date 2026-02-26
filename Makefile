CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all test clean

all: dni_generator

dni_generator: dni_generator.c
	$(CC) $(CFLAGS) -o $@ $<

test: test_dni_generator
	./test_dni_generator

test_dni_generator: test_dni_generator.c dni_generator.c
	$(CC) $(CFLAGS) -o $@ test_dni_generator.c

clean:
	rm -f dni_generator test_dni_generator
