#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "common.h"

#define PORT 8080

void pserror(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

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

    int obj_server, sock;
    struct sockaddr_in address;
    int opted = 1;
    socklen_t address_length = sizeof(address);
    char buffer[1024] = {0};
    const char *message = "Hi I am a message from the server!";

    if ((obj_server = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        pserror("Opening of Socket Failed !");
    }

    if (setsockopt(obj_server, SOL_SOCKET, SO_REUSEADDR, &opted, sizeof(opted))) {
        pserror("Can't set the socket");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(obj_server, (struct sockaddr *)&address, sizeof(address)) < 0) {
        pserror("Binding of socket failed !");
    }

    if (listen(obj_server, 3) < 0) {
        pserror("Can't listen from the server !");
    }

    if ((sock = accept(obj_server, (struct sockaddr *)&address, &address_length)) < 0) {
        pserror("Accept");
    }

    ssize_t reader = read(sock, buffer, 1024);
    if (reader > 0) {
        std::cout << buffer << std::endl;
    }

    send(sock, message, strlen(message), 0);
    std::cout << "SERVER: I just sent a message to the client!" << std::endl;

    close(sock); // Close the socket after communication
    close(obj_server);

    return 0;
}
