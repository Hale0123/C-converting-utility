//convert.c
#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "util.h"
#include "cmdline.h"

int main(int argc, char *argv[]) {
    int base = 16;
    long start = 0, finish = 0;
    int range_mode = 0;

    // Parse and initialize command line arguments
    parse_command_line(argc, argv, &base, &start, &finish, &range_mode);

    // Perform the conversion 
    if (range_mode) {
        convert_range(start, finish, base);
    } else {
        convert_stdin(base);
    }

    return 0;
}
