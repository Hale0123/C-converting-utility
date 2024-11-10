//util.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "util.h"


void convert_to_ASCII(long num, int base) {
    if (num == 0) {
        return;
    }

    int remainder = num % base;
    long remaining_num = num / base;

    convert_to_ASCII(remaining_num, base);
    if (remainder < 10) {
        putchar('0' + remainder);
    } else {
        putchar('A' + remainder - 10);
    }
}

void convert_and_print(long num, int base) {
    if (num < 0) {
        putchar('-');
        num = -num;
    }
    if (num == 0) {
        putchar('0');
    } else {
        convert_to_ASCII(num, base);
    }
    putchar('\n');
}

void convert_range(long start, long finish, int base) {
    if (start > finish) return;
    for (long i = start; i <= finish; i++) {
        convert_and_print(i, base);
    }
}

void convert_stdin(int base) {
    char buffer[64];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        char *endptr;
        errno = 0;
        long num = strtol(buffer, &endptr, 10);
        if (errno != 0 || (*endptr != '\n' && *endptr != '\0')) {
            fprintf(stderr, "Error: Non-long-int token encountered.\n");
            exit(1);
        }
        convert_and_print(num, base);
    }
}
