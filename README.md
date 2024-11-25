# C_framework_lib
This is a C library that contains some functionalities as simple functions just like a framework.

## Functions

### `CLS();`
Clears the console screen. Works differently depending on the operating system:
- On Windows, it runs `cls`.
- On Unix-like systems (Linux, macOS), it runs `clear`.

### `CLS_ENTER();`
Clears the console after the user presses `ENTER`. It waits for 2 seconds, then clears the screen:
- On Windows, it runs `cls`.
- On Unix-like systems (Linux, macOS), it runs `clear`.

### `userInput(int line);`
Gets user input with the option to display the line number (useful for input in loops). It dynamically allocates memory for the input and resizes the buffer if necessary.
- **Parameters**: `int line` (line number to display before the input prompt).
- **Returns**: `char*` (the user input).

### `getInput();`
Gets a simple one-line user input without displaying the line number. It dynamically allocates memory for the input and resizes the buffer if necessary.
- **Returns**: `char*` (the user input).

### `logMessage(const char* level, const char* message);`
Logs a message with a specified log level (e.g., `INFO`, `WARN`, `ERROR`).
- **Parameters**:
  - `const char* level`: The log level (e.g., "INFO", "WARN", "ERROR").
  - `const char* message`: The message to log.
- **Returns**: `void`.

### `logToFile(const char* filename, const char* level, const char* message);`
Logs a message to a file with a specified log level.
- **Parameters**:
  - `const char* filename`: The log file name.
  - `const char* level`: The log level.
  - `const char* message`: The message to log.
- **Returns**: `void`.

### `trimWhitespace(char* str);`
Trims leading and trailing whitespace from a string.
- **Parameters**: `char* str`: The string to trim.
- **Returns**: `char*` (the trimmed string).

### `toUpperCase(char* str);`
Converts all characters in the string to uppercase.
- **Parameters**: `char* str`: The string to convert.
- **Returns**: `char*` (the converted string).

### `readFile(const char* filename);`
Reads a file's content into a string.
- **Parameters**: `const char* filename`: The file to read.
- **Returns**: `char*` (the content of the file).

### `writeFile(const char* filename, const char* content);`
Writes a string to a file.
- **Parameters**:
  - `const char* filename`: The file to write.
  - `const char* content`: The content to write to the file.
- **Returns**: `void`.

### `getTimestamp();`
Gets the current timestamp as a string in the format `YYYY-MM-DD HH:MM:SS`.
- **Returns**: `char*` (the timestamp string).

### `maximum(int a, int b);`
Finds the maximum of two integers.
- **Parameters**: 
  - `int a`: The first integer.
  - `int b`: The second integer.
- **Returns**: `int` (the maximum value).

### `minimum(int a, int b);`
Finds the minimum of two integers.
- **Parameters**:
  - `int a`: The first integer.
  - `int b`: The second integer.
- **Returns**: `int` (the minimum value).

### `arrayMax(int* array, size_t size);`
Finds the maximum value in an array of integers.
- **Parameters**:
  - `int* array`: The array of integers.
  - `size_t size`: The size of the array.
- **Returns**: `int` (the maximum value in the array).
