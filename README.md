# Spanish DNI Generator

A simple C program that generates a random Spanish National Identity Document (DNI) number.

## What is a DNI?

The **Documento Nacional de Identidad (DNI)** is the national identity document used in Spain. It consists of 8 digits followed by a check letter (e.g., `12345678Z`). The letter is determined by computing the remainder of the 8-digit number divided by 23 and mapping the result to a predefined letter table:

| Remainder | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 |
|-----------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|-----|
| Letter    | T | R | W | A | G | M | Y | F | P | D | X  | B  | N  | J  | Z  | S  | Q  | V  | H  | L  | C  | K  | E   |

## How It Works

1. Generates 8 random digits to form the numeric part of the DNI.
2. Calculates the check letter using the modulo-23 algorithm described above.
3. Prints the complete DNI (digits + letter) to the console.

## Build

Compile the program with any C compiler. For example, using `gcc`:

```bash
gcc -o dni_generator dni_generator.c
```

## Run

```bash
./dni_generator
```

Example output:

```
Welcome to my Spanish ID (DNI) generator
Generating ID number...
Getting ID letter...
Your random ID is: 48631205R
```
