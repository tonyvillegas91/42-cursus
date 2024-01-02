# Minishell

Minishell is a basic shell project at 42 school, implementing a command-line interface with support for various shell functionalities.

## Features

- **Command Execution**: Execute external commands using `execve`.
- **Environment Variables**: Manage and expand environment variables.
- **Redirection and Pipes**: Support for file redirection and command piping.
- **Signal Handling**: Handle signals such as `Ctrl+C` and `Ctrl+D`.
- **Built-in Commands**: Implementation of basic shell built-in commands.

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/tonyvillegas91/42-cursus.git
    ```

2. **Build and Run:**

    ```bash
    cd minishell
    make
    ./minishell
    ```

## Usage

Enter commands as in a regular shell:

```bash
$ ls -l
$ echo "Hello, Minishell!"
