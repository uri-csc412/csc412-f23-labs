CFLAGS = -Wall -Wextra -fsanitize=address
CFLAGS += -g
.PHONY: all clean

all: main

clean:
	rm -f main

main:
	$(CC) $(CFLAGS) $^ -o $@
