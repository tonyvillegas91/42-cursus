# pipex

## Description

School 42's Pipex project is an implementation of a program that simulates the operation of the pipe operator (`|`) on the Unix/Linux command line. Pipex should be able to take two commands as arguments and execute them as if they were connected by a pipe, allowing the output of the first command to be used as input for the second.

## Goals.

1. **Use Pipelines:**
   - Use pipes to communicate the output of one process with the input of another.

2. **File Redirection:**
   - Implement file redirection so that standard input and output can come from or go to a file.

3. **Parallel Processing:**
   - Run the two commands in parallel processes.

4. **Error Handling:**
   - Correctly handle any errors that may occur during execution.

5. **Efficiency:**
   - Perform operations efficiently and handle special cases.