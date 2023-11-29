#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

#define PAGESIZE 4096

int m = 9;

int main(int argc, char **argv) {
    // parent & child processes can share this block
    uint8_t *shared_memory = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    char buffer[16]; // a small buffer for educational purposes said the dark wizard

    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) { // child process
        *shared_memory = 5;
        m = 22;

        // we are inetionally buffer overflow is intentionally caused here.
        // this is an unsafe use of the gets() function, which does not check buffer boundaries.
        // this will overwrite adjacent memory if more than 32 characters are input.
        printf("Enter some text: ");
        gets(buffer); // FYI never use gets() in real production code!

        // here is the safer alternative to avoid buffer overflow
        // fgets(buffer, sizeof(buffer), stdin);

        exit(0);
    } else {
        wait(NULL); // parent waits for child
    }

    printf("Mem not shared. %i\n", m);
    printf("Mem shared. %i\n", *shared_memory);

    // unmap the shared memory when we are done with it
    if (munmap(shared_memory, PAGESIZE) == -1) {
        perror("munmap");
    }

    return 0;
}