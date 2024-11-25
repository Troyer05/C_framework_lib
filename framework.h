#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <stddef.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * Function to clear console
 */
void CLS();

/**
 * Function to clear console after user hit ENTER
 */
void CLS_ENTER();

/**
 * Function to get user Inputs (designed to be used in a loop for multi inputs)
 * 
 * @param int line Line Number (in for loop it would be i+1)
 * @return char* the user input
 */
char* userInput(int line);

/**
 * Function to get simple oneline user input
 * 
 * @return char* the user input
 */
char* getInput();

/**
 * Function to log messages with different log levels
 * 
 * @param const char* level Log level (e.g., "INFO", "WARN", "ERROR")
 * @param const char* message Message to log
 */
void logMessage(const char* level, const char* message);

/**
 * Function to log messages to a file
 * 
 * @param const char* filename Log file name
 * @param const char* level Log level
 * @param const char* message Message to log
 */
void logToFile(const char* filename, const char* level, const char* message);

/**
 * Function to trim leading and trailing whitespace from a string
 * 
 * @param char* str String to trim
 * @return char* Trimmed string
 */
char* trimWhitespace(char* str);

/**
 * Function to convert a string to uppercase
 * 
 * @param char* str String to convert
 * @return char* Converted string
 */
char* toUpperCase(char* str);

/**
 * Function to read a file into a string
 * 
 * @param const char* filename File to read
 * @return char* Content of the file
 */
char* readFile(const char* filename);

/**
 * Function to write a string to a file
 * 
 * @param const char* filename File to write
 * @param const char* content Content to write
 */
void writeFile(const char* filename, const char* content);

/**
 * Function to get the current timestamp as a string
 * 
 * @return char* Current timestamp
 */
char* getTimestamp();

/**
 * Function to find the maximum of two numbers
 * 
 * @param int a First number
 * @param int b Second number
 * @return int Maximum number
 */
int maximum(int a, int b);

/**
 * Function to find the minimum of two numbers
 * 
 * @param int a First number
 * @param int b Second number
 * @return int Minimum number
 */
int minimum(int a, int b);

/**
 * Function to find the maximum value in an array of integers
 * 
 * @param int* array Array of integers
 * @param size_t size Size of the array
 * @return int Maximum value
 */
int arrayMax(int* array, size_t size);

#endif
