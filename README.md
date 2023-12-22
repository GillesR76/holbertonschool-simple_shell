# Readme for the simple shell project

## Simple Shell
A super simple shell program written in C that allows users to input commands and executes them. This shell is designed to be a basic interactive command-line interface.

---
## REQUIREMENTS :
- Allowed editors: vi, vim, emacs
- Compilation on Ubuntu 20.4 LTS
- All files should end with a new line
- All files should follow the Betty style
- No memory leaks
- No more than 5 functions per file
- The header file should be include guarded
- Use system calls only when needed

---
## Compilation Command :
To compile the project, your code will be compiled this way :
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell

---
## Structure and Organization
Function Limit: Keep each file concise with ... functions. Header Inclusion: Feature all function prototypes in main.h and include guards to avoid repetition. Side Note: No more than 3 malloc function provided for this project.

---
## Copy code
./shell
The shell will display a prompt ($) where you can enter commands. It supports basic interactive command-line operations, handle the PATH and should be able to leave the function with exit.

---
## Features
- User-friendly prompt when running interactively.
- Handles commands entered by the user.
- Uses the getline function to read user input.
- Basic error handling and debugging information

---
## Commands
The shell supports executing various commands available on the system. Enter a command and press Enter to execute it.
Exit
To exit the shell, use the Ctrl + D keyboard shortcut or enter the exit command.
Debugging
The program includes debugging information that can be enabled or disabled by modifying the print_debug function calls in the code.

---
## Documentation
Readability: Create a comprehensive README.md as the project's guide. Main Files: Use provided main.c files for testing but avoid including them in your final submission.

---
## Example of shell function

```bash
root@50c158e79d1b:~/holbertonschool-simple_shell# ./shell
$ ls
README.md  execve.c             main.h    print_debug.c  read_command.c  shell.c
_getenv.c  find_file_in_path.c  man_page  printenv.c     shell           tokenize_command.c
$ ls - a
ls: cannot access '-': No such file or directory
ls: cannot access 'a': No such file or directory
$ ls -a
.     README.md  find_file_in_path.c  print_debug.c   shell
..    _getenv.c  main.h               printenv.c      shell.c
.git  execve.c   man_page             read_command.c  tokenize_command.c
$ ls                      -a
.     README.md  find_file_in_path.c  print_debug.c   shell
..    _getenv.c  main.h               printenv.c      shell.c
.git  execve.c   man_page             read_command.c  tokenize_command.c
$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/root
_=./shell
$ pwd
/root/holbertonschool-simple_shell
$ exit
root@50c158e79d1b:~/holbertonschool-simple_shell#

```

---
## Testing

```bash
valgrind --leak-check=full ./shell
echo "/bin/ls" | valgrind --leak-check=full ./shell
echo "                                                       " | valgrind --leak-check=full --show-leak-kinds=all ./shell
echo "/bin/ls -l -a" | valgrind --leak-check=full ./shell
```

## Man page

Refer to the man page for detailed information on how to use the shell function
```bash
man ./man_page
```

---

Authors : Simple Shell by Gilles and Benjamin
