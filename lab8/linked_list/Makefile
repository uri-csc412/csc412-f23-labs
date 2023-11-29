CFLAGS = -Wall -Wextra
CFLAGS += -g
.PHONY: all clean format

all: linked_list

clean:
	rm -f linked_list linked_list.o linked_list_test.o

check: linked_list
	./linked_list all

linked_list_test.o: linked_list_test.c
	$(CC) $(CFLAGS) -c $< -o $@

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c $< -o $@

linked_list: linked_list.o linked_list_test.o
	$(CC) $(CFLAGS) $^ -o $@
