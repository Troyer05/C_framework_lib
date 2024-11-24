#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "framework.h";

#define INITIAL_BUFFER_SIZE 64

/**
 * Function to clear console
 */
void CLS() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * Function to clear console after user hittet ENTER
 */
void CLS_ENTER() {
    sleep(2);
    getchar();

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * Function to get user Inputs (desgined to be used in a loop for multi inputs)
 * 
 * @param int line Line Number (in for loop it would be i+1)
 * @return char* the user input
 */
char* userInput(int line) {
    size_t bufferSize = INITIAL_BUFFER_SIZE;
    char* input = (char*)malloc(bufferSize);

    if (input == NULL) {
        printf("Fehler: Speicher konnte nicht reserviert werden.\n");
        exit(EXIT_FAILURE);
    }

    size_t length = 0;
    int ch;

    if (line != -1) {
        printf("%d| ", line);
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        input[length++] = ch;

        if (length >= bufferSize) {
            bufferSize *= 2;
            input = (char*)realloc(input, bufferSize);

            if (input == NULL) {
                printf("Fehler: Speicher konnte nicht erweitert werden.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    input[length] = '\0';

    return input;
}

/**
 * Function to get simple oneline user input
 * 
 * @return char* the user input
 */
char* getInput() {
    size_t bufferSize = INITIAL_BUFFER_SIZE;
    char* input = (char*)malloc(bufferSize);

    if (input == NULL) {
        printf("Fehler: Speicher konnte nicht reserviert werden.\n");
        exit(EXIT_FAILURE);
    }

    size_t length = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        input[length++] = ch;

        if (length >= bufferSize) {
            bufferSize *= 2;
            input = (char*)realloc(input, bufferSize);

            if (input == NULL) {
                printf("Fehler: Speicher konnte nicht erweitert werden.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    input[length] = '\0';

    return input;
}
