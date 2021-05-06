CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = terr_to_list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean: 
	rm $(OBJ)
