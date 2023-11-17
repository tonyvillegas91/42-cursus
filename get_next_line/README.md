# get_next_line

## Description.

The get_next_line project from school 42 is an implementation of a function that reads and returns the next available line of a file descriptor (e.g. a file or standard input) each time it is called. The function is capable of handling multiple file descriptors and can be used in projects that require reading lines from different sources.

## Goals

1. **Read Lines:**.
   - Implement a function that reads and returns the next available line of a file descriptor.

2. **Multiple descriptor handling:**.
   - Make sure the function can handle multiple file descriptors simultaneously.

3. 3. **Memory Management:**.
   - Avoid memory leaks and ensure efficient resource management.

4. **Special character support:** **Special character support:**.
   - Correctly handle special characters such as '\n' when reading lines.

5. **Dynamic BUFF_SIZE operation:**.
   - Implement a version of get_next_line that works with a user-defined dynamic buffer size (BUFF_SIZE).