CFLAGS = -Wall -Wextra -fsanitize=address
CFLAGS += -g
.PHONY: all clean

all: linked_list

clean:
	rm -f main

main:
	$(CC) $(CFLAGS) $^ -o $@
