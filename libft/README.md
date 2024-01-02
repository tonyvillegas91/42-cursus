# libft

`libft` is a fundamental project at 42 school, providing a library of essential C functions. The goal is to reinforce programming skills by implementing custom versions of standard C library functions.

## Features

- **Custom Implementation**: Each function is a custom version of standard C library functions.
- **Modularity**: Grouped functions for easy integration into various projects.
- **Educational Purpose**: Designed to deepen understanding of standard C library functions.

## Getting Started

1. **Clone Repository:**

    ```bash
    git clone https://github.com/tonyvillegas91/42-cursus.git
    ```

2. **Build Library:**

    ```bash
    make
    ```

3. **Link to Your Project:**

    ```bash
    gcc -o your_program your_source_file.c -L./libft -lft
    ```

4. **Include Header File:**

    ```c
    #include "libft.h"
    ```

5. **Start Using libft Functions in Your Code.**


## Build and Test

- **Build Library:**

    ```bash
    make
    ```

- **Clean Files:**

    ```bash
    make clean
    ```

- **Run Tests:**

    ```bash
    make test
    ```