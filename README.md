# HolbertonSchool Simple Shell: The nashell
*Project created by [Ignacio Devita](https://github.com/nyacho04) and [Franco Reyes](https://github.com/Franco-byte).*

![nashell](https://github.com/user-attachments/assets/263f54fb-5501-48e4-a24a-93cac75d12e6)

# What is a Shell?
A shell is a user interface that allows you to interact with the operating system of a computer. It acts as a command-line interpreter, enabling users to execute commands, run programs, and manage files. Shells can be graphical, like the interfaces you see on Windows or macOS, or text-based, where you type commands into a terminal window.

- This is a custom implementation of a "simple shell" in C, The project includes a set of functions like it allows you to manage variables, handle basic errors and execute commands.
## File Descriptions

- **[nashell.c](nashell.c)**: This is the main file that runs the shell. It reads input from the user, processes commands, and calls the appropriate functions to execute them.

- **[main.h](main.h)**: This header file contains the necessary includes, definitions, and function prototypes used throughout the project.

- **[execute.c](execute.c)**: This file contains the `execute` function, which executes the command using `fork`, `execve`, and `wait` functions.

- **[is_interactive.c](is_interactive.c)**: This file is used to determine if the shell is running in an interactive mode. This is important for deciding how the shell should behave in different environments.

- **[flags_process.c](flags_process.c)**: This file contains the `flags_process` function, which processes the flags in the command string, ignoring the first token (the command itself).

- **[srch_path.c](srch_path.c)**: This file contains the `srch_path` function, which differentiates a command from an absolute path and returns a pointer to the absolute path.

- **[AUTHORS](AUTHORS)**: This file lists all individuals who have contributed content to the repository.

- **[README.md](README.md)**: This file provides an overview of the project, including descriptions of each file and how the shell works.

## How the Shell Prompt Works?

1. **Prompt Display**: The shell displays the prompt `nashell$ ` to indicate that it is ready to accept user input.

2. **Reading Input**: The shell reads the input from the user using the `getline` function.

3. **Command Processing**:
   - If the user types `exit`, the shell terminates.
   - If the user types `env`, the shell prints the current environment variables.
   - For other commands, the shell processes the input to separate the command and its flags.

4. **Path Search**: The shell uses the `srch_path` function to determine the absolute path of the command.

5. **Flag Processing**: The shell uses the `flags_process` function to process any flags provided with the command.

6. **Command Execution**: The shell uses the `execute` function to execute the command with the provided flags. This involves creating a child process using `fork`, replacing the child process with the command using `execve`, and waiting for the command to complete using `wait`.

7. **Loop**: The shell continues to display the prompt and process commands until the user types `exit` or an error occurs.

## Return Values
- The `execute` function returns 0 on success and NULL on failure.
- The `is_interactive` Returns 1 if the shell is running interactively and if it returns 0 is not.
- The `flags_process` function returns a pointer to the string without the first token or NULL on failure.
- The `srch_path` function returns a pointer to the path in the PATH or to the entered path, or NULL on failure.
- The `main` function (nashell) returns 0 on success.

## Examples Usage

```s
nashell$ ls -l
total 8
-rw-r--r-- 1 user user  0 Oct  1 12:00 AUTHORS
-rw-r--r-- 1 user user  0 Oct  1 12:00 README.md
-rw-r--r-- 1 user user  0 Oct  1 12:00 execute.c
-rw-r--r-- 1 user user  0 Oct  1 12:00 flags_process.c
-rw-r--r-- 1 user user  0 Oct  1 12:00 main.h
-rw-r--r-- 1 user user  0 Oct  1 12:00 nashell.c
-rw-r--r-- 1 user user  0 Oct  1 12:00 srch_path.c
nashell$ exit
```
```s
nashell$ pwd
/home/user/holbertonschool-simple_shell-6
nashell$ exit
```
```s
nashell$ whoami
user
nashell$ exit
```
```s
nashell$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOME=/home/user
LOGNAME=user
```
## Main Function Flowchart (nashell.c)
![image](https://github.com/user-attachments/assets/4056af18-a90d-4cc4-bd2e-ad36630e95af)

# Compilation 
- This shell will be compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

