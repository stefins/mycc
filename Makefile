include config.mk

all: $(OBJ)
	$(CC) $? -o $(BIN_NAME)
	make clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all clean
	./mycc

clean:
	$(RM) -r *.o *.s