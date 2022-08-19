OBJS = ./objs/fileutil.o ./objs/open_file.o ./objs/parse_args.o ./objs/is_delimiter_check.o ./objs/is_all_int.o ./objs/print.o
CC = gcc
CFLAGS = -Wall -c -g
LFLAGS = -Wall

fileutil: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o fileutil

./objs/fileutil.o: ./c/fileutil.c ./h/fileutil.h
	$(CC) $(CFLAGS) ./c/fileutil.c -o ./objs/fileutil.o

./objs/open_file.o: ./c/open_file.c ./h/open_file.h
	$(CC) $(CFLAGS) ./c/open_file.c -o ./objs/open_file.o

./objs/parse_args.o: ./c/parse_args.c ./h/parse_args.h
	$(CC) $(CFLAGS) ./c/parse_args.c -o ./objs/parse_args.o

./objs/is_delimiter_check.o: ./c/is_delimiter_check.c ./h/is_delimiter_check.h
	$(CC) $(CFLAGS) ./c/is_delimiter_check.c -o ./objs/is_delimiter_check.o

./objs/is_all_int.o: ./c/is_all_int.c ./h/is_all_int.h
	$(CC) $(CFLAGS) ./c/is_all_int.c -o ./objs/is_all_int.o

./objs/print.o: ./c/print.c ./h/print.h
	$(CC) $(CFLAGS) ./c/print.c -o ./objs/print.o