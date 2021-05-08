CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = Prilist.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean: 
	rm $(OBJ)
