//cmdline.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmdline.h"
#include "convert.h"

void print_usage() {
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "%d <= BASE <= %d\n", MIN_BASE, MAX_BASE);
    fprintf(stderr, "START and FINISH are long integers\n");
    exit(1);
}

void print_help() {
    printf("convert: A utility to convert integers to a specified base.\n");
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("Options:\n");
    printf("  -b BASE          Specify the base for conversion (default is 16).\n");
    printf("                   Valid range for BASE is %d to %d.\n", MIN_BASE, MAX_BASE);
    printf("  -r START FINISH  Convert numbers in the range from START to FINISH.\n");
    printf("                   START and FINISH must be long integers.\n");
    printf("  --help           Show this help message.\n");
    exit(0);
}

int is_valid_base(int base) {
    return base >= MIN_BASE && base <= MAX_BASE;
}

void parse_command_line(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) {
            if (i + 1 >= argc) print_usage();
            *base = atoi(argv[++i]);
            if (!is_valid_base(*base)) print_usage();
        } else if (strcmp(argv[i], "-r") == 0) {
            if (i + 2 >= argc) print_usage();
            *range_mode = 1;
            *start = atol(argv[++i]);
            *finish = atol(argv[++i]);
        } else if (strcmp(argv[i], "--help") == 0) {
            print_help();
        } else {
            print_usage();
        }
    }
}

