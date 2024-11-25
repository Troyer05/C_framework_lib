#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <windows.h>
#include <unistd.h>
#include <time.h>   
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

/**
 * Function to log messages with different log levels
 * 
 * @param const char* level Log level (e.g., "INFO", "WARN", "ERROR")
 * @param const char* message Message to log
 */
void logMessage(const char* level, const char* message) {
    printf("[%s] %s\n", level, message);
}

/**
 * Function to log messages to a file
 * 
 * @param const char* filename Log file name
 * @param const char* level Log level
 * @param const char* message Message to log
 */
void logToFile(const char* filename, const char* level, const char* message) {
    FILE* file = fopen(filename, "a");

    if (file == NULL) {
        printf("Fehler: Logdatei konnte nicht geöffnet werden.\n");
        return;
    }

    fprintf(file, "[%s] %s\n", level, message);
    fclose(file);
}

/**
 * Function to trim leading and trailing whitespace from a string
 * 
 * @param char* str String to trim
 * @return char* Trimmed string
 */
char* trimWhitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == '\0') {
        return str;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';

    return str;
}

/**
 * Function to convert a string to uppercase
 * 
 * @param char* str String to convert
 * @return char* Converted string
 */
char* toUpperCase(char* str) {
    for (char* p = str; *p; ++p) {
        *p = toupper(*p);
    }

    return str;
}

/**
 * Function to read a file into a string
 * 
 * @param const char* filename File to read
 * @return char* Content of the file
 */
char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Fehler: Datei konnte nicht geöffnet werden.\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    char* content = (char*)malloc(size + 1);

    if (content == NULL) {
        printf("Fehler: Speicher konnte nicht reserviert werden.\n");
        fclose(file);

        return NULL;
    }

    fread(content, 1, size, file);
    content[size] = '\0';
    fclose(file);

    return content;
}

/**
 * Function to write a string to a file
 * 
 * @param const char* filename File to write
 * @param const char* content Content to write
 */
void writeFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Fehler: Datei konnte nicht geöffnet werden.\n");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}

#include <time.h>

/**
 * Function to get the current timestamp as a string
 * 
 * @return char* Current timestamp
 */
char* getTimestamp() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    char* timestamp = (char*)malloc(20);

    if (timestamp == NULL) {
        printf("Fehler: Speicher konnte nicht reserviert werden.\n");
        exit(EXIT_FAILURE);
    }

    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", t);

    return timestamp;
}

/**
 * Function to find the maximum of two numbers
 * 
 * @param int a First number
 * @param int b Second number
 * @return int Maximum number
 */
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Function to find the minimum of two numbers
 * 
 * @param int a First number
 * @param int b Second number
 * @return int Minimum number
 */
int minimum(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * Function to find the maximum value in an array of integers
 * 
 * @param int* array Array of integers
 * @param size_t size Size of the array
 * @return int Maximum value
 */
int arrayMax(int* array, size_t size) {
    int maxVal = array[0];

    for (size_t i = 1; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    return maxVal;
}
