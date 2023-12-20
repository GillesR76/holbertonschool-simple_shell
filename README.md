Readme for the simple shell project
- Simple Shell
A super simple shell program written in C that allows users to input commands and executes them. This shell is designed to be a basic interactive command-line interface.

* REQUIREMENTS :
-> Code Foundations
Editors: Allowed vi, vim, or emacs for your coding journey. Compilation: Ensure compatibility with Ubuntu 20.04 LTS using gcc and flags: -Wall -Werror -Wextra -pedantic -std=gnu89. Style Guide: Adhere to the Betty style for clean and consistent code. Global Variables: Omit global variables for a more robust foundation.

* Compilation Command :
->To compile the project, your code will be compiled this way :
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

* Structure and Organization
Function Limit: Keep each file concise with ... functions. Header Inclusion: Feature all function prototypes in main.h and include guards to avoid repetition. Side Note: No more than 3 malloc function provided for this project.

- Copy code
./shell
The shell will display a prompt ($) where you can enter commands. It supports basic interactive command-line operations, handle the PATH and should be able to leave the function with exit.

- Features
* User-friendly prompt when running interactively.
* Handles commands entered by the user.
* Uses the getline function to read user input.
* Basic error handling and debugging information

- Commands
The shell supports executing various commands available on the system. Enter a command and press Enter to execute it.
Exit
To exit the shell, use the Ctrl + D keyboard shortcut or enter the exit command.
Debugging
The program includes debugging information that can be enabled or disabled by modifying the print_debug function calls in the code.

* Documentation
Readability: Create a comprehensive README.md as the project's guide. Main Files: Use provided main.c files for testing but avoid including them in your final submission.

- Example of shell function

```
$ ./simple_shell
[Info] -> Starting program
[Info] -> Waiting for user input
$ ls
[Success] -> byteRead valid
Executing command: ls
file1.txt  file2.txt  main.c  main.h  simple_shell
[Info] -> Waiting for user input
$ echo "Hello, World!"
[Success] -> byteRead valid
Executing command: echo "Hello, World!"
Hello, World!
[Info] -> Waiting for user input
$ exit
[Info] -> Exiting program
```


Autor : Simple Shell by Gilles and Benjamin
