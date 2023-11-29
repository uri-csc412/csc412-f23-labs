#include <iostream>

int main(int argc, char* argv[]) {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << line << std::endl;
    }
    return 0;
}
