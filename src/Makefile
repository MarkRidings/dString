CFLAGS=-g -Wall -Wextra -std=c11 -O3
EXEDIR=../bin
OBJDIR=../lib

STRING_SRC=main.c dstring.c dstring_ops.c
STRING_OPS_SRC=string_ops_test.c dstring.c dstring_ops.c

DSTRING_SRC=dstring.c
DSTRING_OPS_SRC=dstring_ops.c

all: string string_ops dstring

string_ops: $(STRING_OPS_SRC)
	$(CC) $(CFLAGS) $(STRING_OPS_SRC) -o $(EXEDIR)/ops_test

string: $(STRING_SRC)
	$(CC) $(CFLAGS) $(STRING_SRC) -o $(EXEDIR)/string

dstring: dstring.o dstring_ops.o
	$(CC) $(CFLAGS) -shared -o $(OBJDIR)/libdstring.so $(OBJDIR)/dstring.o $(OBJDIR)/dstring_ops.o

dstring.o: $(DSTRING_SRC)
	$(CC) $(CFLAGS) -fpic -c $(DSTRING_SRC) -o $(OBJDIR)/dstring.o

dstring_ops.o: $(DSTRING_OPS_SRC)
	$(CC) $(CFLAGS) -fpic -c $(DSTRING_OPS_SRC) -o $(OBJDIR)/dstring_ops.o

clean:
	-rm ../bin/string ../bin/ops_test ../lib/*.so ../lib/*.o

.PHONY: all clean
