# Introduction

The Minishell project is a key step in learning how to build a simple shell, a command-line interface similar to Bash. The goal is to create a functional shell that can interpret and execute user commands, handling various built-in functions and system calls.

# Objectives

The project is designed to familiarize students with Unix systems, processes, file descriptors, and the mechanics of building a basic shell. By the end of the project, you will have implemented a small, working shell that supports basic operations.

# Project Requirements

   The shell must support the following built-in commands:
   
      - echo
      - cd
      - pwd
      - export
      - unset
      - env
      - exit
      
   - The shell should interpret and execute commands in the same manner as Bash (except for some minor differences).
   - The shell must handle single and double quotes, environment variables ($), and redirections (<, >, >>).
   - Handle pipes (|) to chain commands.
   - Implement basic signal handling (Ctrl+C, Ctrl+D, Ctrl+\\).

# Features

  - Parsing and Execution: The shell should be able to parse user input, separate commands, and execute them accordingly.
  - Environment Variables: Use environment variables and allow for their modification using export and unset.
  - Command Redirections: Support input/output redirection to/from files and between commands.
  - Signal Handling: Handle keyboard interrupts (such as Ctrl+C) gracefully without exiting the shell.
  - Pipelines: Chain multiple commands together using the pipe (|) operator.
  - Built-in Commands: Implement and correctly manage the built-in commands.
