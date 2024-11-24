#include <stdio.h>
#include <stdlib.h>

// include the framework library
#include "framework.h"

int main() {
    // clear the console
    CLS();


    // clear console after user hits ENTER
    CLS_ENTER();


    // get simple user input
    getInput();


    // get complete user text input
    char* test[10];

    for (int i = 0; i < 10; i++) {
        test[i] = userInput(i);
    }



    return 0;
}