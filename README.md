*This project has been created as part of the 42 curriculum by agarcia2.*

# get_next_line

## Description

**get_next_line** is a C function that reads and returns a single line from a file descriptor.
The goal of this project is to implement a reliable and efficient line-by-line reader while
respecting strict constraints on memory management, function usage, and program behavior.

This project introduces the concept of **static variables** in C, allowing the function to
store unread data between consecutive calls.

Each call to `get_next_line()` returns the next available line from the given file descriptor,
including the newline character (`\n`) if present.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Returned Value

- A string containing the next line, including `\n` if it exists.
- `NULL` if there is nothing more to read or if an error occurs.

## Files

- `get_next_line.c` — main function logic
- `get_next_line_utils.c` — helper functions
- `get_next_line.h` — function prototype and includes

## Instructions

### Compilation

The project must be compiled with a defined `BUFFER_SIZE`, which determines how many bytes
are read at each `read()` call.

Example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The code must compile and work correctly **with or without** the `-D BUFFER_SIZE` flag.

### Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm Explanation and Justification

The implementation relies on a **static buffer** that keeps track of unread data between calls.

### Core Logic

1. A static variable stores leftover data from previous reads.
2. Data is read from the file descriptor into a temporary buffer of size `BUFFER_SIZE`.
3. The read data is appended to the static buffer.
4. When a newline (`\n`) is found:
   - A line is extracted and returned.
   - Remaining data stays in the static buffer for the next call.
5. When EOF is reached:
   - The remaining buffer is returned if not empty.
   - Otherwise, the function returns `NULL`.

### Why This Approach

- Avoids reading the entire file at once.
- Optimizes memory usage.
- Works correctly with any `BUFFER_SIZE` value.
- Supports both files and standard input.
- Demonstrates controlled usage of static variables without global state.

This design ensures correct behavior while complying with all project constraints.

## Constraints and Rules

- Allowed external functions:
  - `read`
  - `malloc`
  - `free`
- Forbidden:
  - `lseek`
  - Global variables
  - Using `libft`
- Memory leaks are not tolerated.
- Undefined behavior may occur when reading binary files or when files are modified during execution.

## Bonus Part (Optional)

The bonus version extends the project to:

- Use only **one static variable**
- Handle **multiple file descriptors** simultaneously

Bonus files (if implemented):

- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`
- `get_next_line_bonus.h`

## Resources

- `man read`
- `man open`
- GNU C Library documentation
- 42 Intranet documentation about static variables

### AI Usage

AI tools were used only for **concept clarification and documentation support**.
All code logic, structure, and implementation decisions were written and fully understood
by the author.

## Final Notes

This project strengthens low-level programming skills, memory management, and algorithmic
thinking. Once validated, `get_next_line` can be reused as a utility function in future C
projects.
