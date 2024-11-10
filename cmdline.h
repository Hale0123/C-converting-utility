#ifndef CMDLINE_H
#define CMDLINE_H

void parse_command_line(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode);
void print_usage();
void print_help();
int is_valid_base(int base);

#endif

