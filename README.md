# HOLBERTONSCHOOL SIMPLE SHELL
![Logo](https://www.kindpng.com/picc/m/454-4544393_shell-script-logo-hd-png-download.png)

## Table of Contents

   <a href="#objective">Objective</a>

   <a href="#introduction">Introduction</a>

   <a href = "#tech">Tech Stack</a>

   <a href = "#requirements">Requirements</a>

   <a href = "#list">List of allowed functions and system calls+</a>

   <a href = "#compilation">Compilation</a>

   <a href = "#testing">Testing</a>

   <a href = "#files">Files description</a>

   <a href = "#install">Install and run</a>

   <a href = "#using">Using the Simple Shell</a>

   <a href = "#authors">Authors</a>

## 📝 <span id="objective">Objective</span>
To write a simple UNIX command interpreter.
## <span id="introduction">Introduction</span>
This project is a simple Unix shell implementation written in C. It provides basic shell functionalities
such as command execution, built-in commands support, and environment variable handling.
This shell is designed to be lightweight and easy to understand, making it suitable for
learning purposes or as a base for building more complex shell environments.

## 🛠️ <span id="tech">Tech Stack</span>
<p> 
- <img src="https://img.shields.io/badge/C-a8b9cc?logo=c&logoColor=black&style=for-the-badge" alt="C badge">
- <img src="https://img.shields.io/badge/Git-f05032?logo=git&logoColor=white&style=for-the-badge" alt="Git badge">
- <img src="https://img.shields.io/badge/SHELL-000000?logo=powershell&logoColor=white&style=for-the-badge" alt="Shell badge">
- <img src="https://img.shields.io/badge/UBUNTU-e95420?logo=ubuntu&logoColor=white&style=for-the-badge" alt="Ubuntu badge">
</p>
## <span id="requirements">Requirements</span>
    
    Allowed editors: vi, vim, emacs
    All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
    All your files should end with a new line
    A README.md file, at the root of the folder of the project is mandatory
    Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    Your shell should not have any memory leaks
    No more than 5 functions per file
    All your header files should be include guarded
    Use system calls only when you need to (why?)
    
## <span id="list">List of allowed functions and system calls+</span>

    all functions from string.h
    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    printf (man 3 printf)
    fprintf (man 3 fprintf)
    vfprintf (man 3 vfprintf)
    sprintf (man 3 sprintf)
    putchar (man 3 putchar)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

## <span id="compilation">Compilation</span>

Your shell will be compiled this way:

    `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## <span id="testing">Testing</span>

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
```
## <span id="files">Files description</span>
| Files     | Description                       |
| :------- | :-------------------------------- |
| `Authors` | Contains the names and email addresses of the various authors. |
| `environnement.c` | Contain The `environnement` function displays the currently defined environment variables. |
| `exec_commande.c` | Provides essential functionality for executing commands and searching for executables within the PATH, which are fundamental components of a shell program. |
| `main.c` | All the functions to handle various format specifers for our "printf" |
| `main.h` | Contain libraries and function prototype |
| `man_1_simple_shell` | The manual of our simple shell |
| `str_functions.c` | A set of utility functions commonly used in programs written in the C language. These functions are designed to facilitate string manipulation and access to environment variables in a program. |
| `token.c` | Provides functionality for counting individual commands in a string and tokenizing a string into an array of strings, which are common tasks in parsing user input in a shell program. |
##  <span id="install">How to install run and use our Simple Shell</span>
## Install and run

To install and run Simple Shell, follow these steps:

Clone the repository using the following command:
```
git clone https://github.com/Pandolowitz/holbertonschool-simple_shell.git
```

Navigate to the directory where the repository was cloned.

Compile the program by running the following command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the program by typing the following command:
```
./hsh
```

## <span id="using">Using the Simple Shell</span>

To use Simple Shell, type a command and press Enter.
<br>
The program will execute the command and display the output on the screen.

Here are some examples of commands that you can run:

- `ls`: list the contents of the current directory.
- `pwd`: print the path of the current working directory.
- `echo`: display a message on the screen.
- `mkdir`: create a new directory.
- `exit`: exit the shell.
- `ls -l`: list the contents of the current directory in long format.

##<span id="authors"> Authors</span>

[@Lucas NEGRE](https://www.github.com/LucasNGRE)

[@Marion SAINT-MARTIN](https://github.com/NamaKa298)
