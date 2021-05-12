CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = twolistmerge.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean: 
	rm $(OBJ)
