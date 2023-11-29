remake: clean build run

build:
	gcc -fsanitize=address -g -fno-stack-protector -z execstack -o main main.c

run: 
	./main

clean:
	rm main