#include <stdio.h>
#include "fio.h"

// open an existing file for reading
FILE* openFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    return file;
}
