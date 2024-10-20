SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))
CC := gcc

Slist.exe: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) Slist.exe
