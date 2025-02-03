Voici une version adaptée en fonction de tes prototypes pour ton README. J’ai mis à jour les fonctionnalités pour refléter précisément les fonctions que ta bibliothèque offre.

# MyLib42

**Project Name:** MyLib42
**Description:**
MyLib42 is a custom library developed during my studies at 42. This library contains essential functions that I implemented from scratch, aiming to be reusable in various projects. Designed for robustness and efficiency, MyLib42 aligns with the **Norminette** standards, ensuring seamless integration with the requirements of 42 and practical use in real-world development.

## Objectives
- **Learning:** Master the fundamental concepts of C by building my own library.
- **Reusability:** Provide a reliable set of tools for future projects at 42 and beyond.
- **Long-term Utility:** Use MyLib42 as a foundation for personal and professional growth as a developer.

## Key Features

### 1. Character Type Functions
- `ft_isalpha` - Check if a character is alphabetic.
- `ft_isdigit` - Check if a character is numeric.
- `ft_isalnum` - Check if a character is alphanumeric.
- `ft_isascii` - Check if a character is part of the ASCII table.
- `ft_isprint` - Check if a character is printable.
- `ft_toupper` - Convert a character to uppercase.
- `ft_tolower` - Convert a character to lowercase.

### 2. String Functions
- `ft_strlen` - Calculate the length of a string.
- `ft_strlcpy` - Copy a string with size limitation.
- `ft_strlcat` - Concatenate strings with size limitation.
- `ft_strnchr` - Find a character in a string, limited by `n`.
- `ft_strchr` - Locate the first occurrence of a character in a string.
- `ft_strrchr` - Locate the last occurrence of a character in a string.
- `ft_strcmp` - Compare two strings.
- `ft_strncmp` - Compare two strings up to `n` characters.
- `ft_strnstr` - Find a substring within a string, limited by `len`.
- `ft_strdup` - Duplicate a string.
- `ft_substr` - Extract a substring from a string.
- `ft_strjoin` - Join two strings.
- `ft_strtrim` - Trim characters from the start and end of a string.
- `ft_split` - Split a string into an array of substrings.
- `ft_strmapi` - Apply a function to each character of a string to create a new one.
- `ft_striteri` - Apply a function to each character of a string in place.

### 3. Number Functions
- `ft_long_size` - Determine the size of a long integer.
- `ft_int_size` - Determine the size of a integer.

### 4. Conversion Functions
- `ft_atoi` - Convert a string to an integer.
- `ft_itoa` - Convert an integer to a string.
- `ft_litoa` - Convert a long integer to a string.

### 5. Memory Functions
- `ft_memset` - Fill memory with a constant byte.
- `ft_bzero` - Zero out a memory area.
- `ft_memcpy` - Copy a memory area.
- `ft_memmove` - Move memory safely between overlapping areas.
- `ft_memchr` - Locate a byte in memory.
- `ft_memcmp` - Compare two memory areas.
- `ft_calloc` - Allocate and initialize memory.
- `ft_realloc` - Reallocate memory with a new size.

### 6. Input/Output Functions
- `ft_putchar_fd` - Write a character to a file descriptor.
- `ft_putstr_fd` - Write a string to a file descriptor.
- `ft_putendl_fd` - Write a string followed by a newline to a file descriptor.
- `ft_putnbr_fd` - Write a number to a file descriptor.

### 7. Printf Functionality
- `ft_printf` - Format and print data to standard output.
- Support for:
  - Characters (`%c`)
  - Strings (`%s`)
  - Pointers (`%p`)
  - Integers (`%d`/`%i`)
  - Unsigned integers (`%u`)
  - Hexadecimals (`%x`/`%X`)

#### Additional Printf Features
- Custom width, precision, and flag support (`-`, `+`, `#`, `0`, and space).
- Helper functions for string formatting and hexadecimal conversion.

### 8. Advanced Functionality
- Support for formatted strings and complex input/output operations.

## Benefits for 42 Projects
- Speeds up development with pre-tested, reusable components.
- Reduces errors by relying on robust, proven functions.
- Provides flexibility and compatibility with 42's Norminette standards.

## Technologies Used
- **Language:** C
- **Tools:** Makefile, Norminette for code style compliance, and unit tests for validation.

## Deliverables
- Organized `.c` and `.h` files in a clear directory structure.
- Comprehensive documentation for each function.
- Unit tests to ensure reliability and robustness.

## Ambition
MyLib42 is more than just a project—it's a growing toolkit that will evolve with my skills and become an essential resource in my journey as a developer. 🚀
