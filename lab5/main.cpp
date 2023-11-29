#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <fstream>
#include <sys/stat.h>
#include <string>

std::string directoryName = "logFolder";

void threadFunc(int num){
    // calculate the factorial of num

    // create a file, then...
    // file needs permissions 0755 HINT: C++ chmod function

    // write the information to the file and then close the file
}

int genRandNumber(int min, int max) {
    // use std::random_device to obtain a seed

    // use the random device to seed a random number engine:

    // define the range [min, max]:

    // generate and return the random number

}

// we are not using  char* argv[], to avoid warnings we use char**
int main(int argc, char**) {
    // generate random number using genRandNumber
    
    // check for arguments
    // if there are arguments print to stdout "You silly rabbit, this program accepts no arguments."
    
    // create the directory (0755 are the permissions) - HINT: C++ function mkdir

    // create the proper amount of threads
    // pass all required information to the threads
    /* here is some free code, enjoy
    std::vector<std::thread> threadList;
    for (int i = 1; i <= randomNum; i++){
        
    }
    */

    // wait for all threads to complete
    

    return 0;
}
