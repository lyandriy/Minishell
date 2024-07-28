# Minishell

## Project Description

The `minishell` project is part of the School 42 curriculum, designed to deepen your understanding of shell programming, process control, and signal handling in Unix-like operating systems. The goal of this project is to create a simple shell that can execute commands, handle pipelines, and manage basic shell features.

## What It Does

The `minishell` program emulates the behavior of a Unix shell. It provides an interactive command-line interface where users can input commands, which the shell then parses and executes. Key features include handling built-in commands, executing binaries, managing pipelines, and signal handling.

## Implementation Details

- **Language**: The project is implemented in C.
- **Main Features**:
  - **Command Execution**: Executes both built-in commands and external binaries.
  - **Pipelines**: Supports piping (`|`) to pass the output of one command as input to another.
  - **Redirections**: Supports input (`<`), output (`>`), and append (`>>`) redirections.
  - **Signal Handling**: Handles signals like `SIGINT` (Ctrl+C) and `SIGQUIT` (Ctrl+\).
  - **Environment Variables**: Manages and manipulates environment variables.
  - **Built-in Commands**: Includes `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Headers**:
  - `#include <unistd.h>`: For system calls.
  - `#include <stdlib.h>`: For memory management.
  - `#include <stdio.h>`: For input/output operations.
  - `#include <fcntl.h>`: For file operations.
  - `#include <sys/wait.h>`: For process control.
  - `#include <signal.h>`: For signal handling.
  - `#include <string.h>`: For string manipulation.

### How It Works

1. **Interactive Loop**: The shell runs an infinite loop, displaying a prompt, reading user input, and processing commands.
2. **Parsing Input**: The input is parsed to handle commands, arguments, pipelines, and redirections.
3. **Executing Commands**:
   - **Built-in Commands**: Handled directly by the shell.
   - **External Commands**: Forks a child process to execute the command using `execve`.
4. **Pipelines**: Creates pipes and forks multiple processes to handle piped commands.
5. **Redirections**: Uses `dup2` to redirect input and output as specified by the user.
6. **Signal Handling**: Registers signal handlers to manage interruptions gracefully.
7. **Environment Variables**: Provides mechanisms to set, unset, and display environment variables.

---

This project provides a comprehensive exercise in building a functional shell, enhancing your understanding of process management, inter-process communication, and system programming in a Unix-like environment.
