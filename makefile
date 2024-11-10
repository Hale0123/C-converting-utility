convert: convert.c util.c cmdline.c convert.h util.h cmdline.h
	gcc -o convert convert.c util.c cmdline.c

ctest: convert.c util.c cmdline.c convert.h util.h cmdline.h
	gcc --coverage -o ctest convert.c util.c cmdline.c
