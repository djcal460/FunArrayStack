CC=gcc
CFLAGS=-I.
DEPS = func.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

funfunarraystack: funfunarraystack.o menufunc.o func.o
	$(CC) -o funfunarraystack funfunarraystack.o menufunc.o func.o
clean:
	$(RM) funfunarraystack.o func.o menufunc.o funfunarraystack
