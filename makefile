convert: convert.c util.c cmdline.c convert.h util.h cmdline.h
	gcc -o convert convert.c util.c cmdline.c
