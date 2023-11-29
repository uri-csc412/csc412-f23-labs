#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "common.h"

#define PORT 8080

void checkargs(int argc, const char *argv[]) {
    if (argc > 1) {
        std::cerr << "You naughty little elf, this program takes no command-line arguments. :/" << std::endl;
        for (int i = 0; i < argc; ++i) {
            std::cout << "\targument " << i << ": " << argv[i] << std::endl;
        }
        exit(1);
    }
}

int main(int argc, const char *argv[]) {
    checkargs(argc, argv);

    int obj_socket, reader;
    struct sockaddr_in serv_addr;
    const char *message = "CLIENT: I am sending a message!";
    char buffer[1024] = {0};

    if ((obj_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    const char *ip_address = "127.0.0.1";

    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    if (connect(obj_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    send(obj_socket, message, strlen(message), 0);
    std::cout << "CLIENT: Message has been sent!" << std::endl;

    reader = read(obj_socket, buffer, 1024);
    if (reader > 0) {
        std::cout << "CLIENT: printing the buffer..." << std::endl;
        std::cout << buffer << std::endl;
    }

    close(obj_socket);

    return 0;
}
