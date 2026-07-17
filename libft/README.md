*This project has been created as part of the 42 curriculum by krahnama.*

# Libft

## Description
---

Libft is a custom C library that reimplements standard libc functions along with additional utility functions.

The objective is to deepen understanding of low-level C programming, including memory management, pointers, strings, and linked lists.

This project serves as a reusable foundation for future 42 projects and enforces strict adherence to manual memory handling and coding standards.

---

Libft is a C library that reimplements standard C library functions and provides additional utility functions.

The goal of this project is to understand memory management, pointers, and string handling in C. It also introduces linked lists and dynamic memory allocation.

---

## Instructions

### Compilation

The library is compiled using the provided Makefile.

To compile the library:


make


This will generate the static library file:


libft.a


---

### Cleaning rules

To remove object files:


make clean


This removes all `.o` files generated during compilation.

---

To remove both object files and the compiled library:


make fclean


This completely cleans the project, including `libft.a`.

---

To recompile everything from scratch:


make re


This performs:


make fclean && make all


---

### Usage

To use the library in your project, include the header file:

```c
#include "libft.h"

Compile your program by linking it with the library:

gcc main.c -L. -lft

``` id="c7"

Make sure the library is compiled in the same directory as your project or provide the correct path using `-L`.

---

### Notes

- The library must be compiled before usage.
- All functions are designed to behave like their standard C counterparts unless otherwise specified.
- Only allowed external functions are `malloc`, `free`, and `write`.
- The library is intended to be reused in future 42 projects.

```
## Resources

### Documentation and References

- https://man7.org/linux/man-pages/  
  Official Linux manual pages used to understand standard C library functions and system calls.

- Various C programming tutorials and articles related to:
  - memory allocation (malloc, free, calloc)
  - string manipulation
  - pointer arithmetic
  - linked list implementation

---

### AI Usage

Artificial Intelligence was used as a learning assistant during the development of this project.

It was used for the following tasks:

- understanding edge cases in standard libc functions (e.g. strlcpy, strlcat, strncmp, strnstr)
- debugging segmentation faults, memory leaks, and undefined behavior
- verifying correctness of implementations against expected libc behavior
- clarifying pointer operations and memory management concepts
- identifying and fixing Norminette-related issues in code structure

AI was used only as a support tool for explanation and debugging.  
All implementations were written, tested, and validated manually by the author.

## Detailed Library Description

Libft is a reimplementation of standard C library functions, extended with additional utility functions for strings, memory, and linked lists.

The functions are grouped into logical categories.

---

## Character Classification

### int ft_isalpha(int c);
### int ft_isdigit(int c);
### int ft_isalnum(int c);
### int ft_isascii(int c);
### int ft_isprint(int c);

These functions check the type of a character based on ASCII values.

Edge cases:
- Input may be negative → must be safely handled using `unsigned char` conversion

---

## Character Conversion

### int ft_toupper(int c);
### int ft_tolower(int c);

These functions convert characters between uppercase and lowercase.

Edge cases:
- Only alphabetic characters are modified
- Non-alphabetic characters must remain unchanged
- Input may be negative → must be cast to `unsigned char`

---

## String Functions

### size_t ft_strlen(const char *s);

Returns the length of a null-terminated string.

---

### char *ft_strdup(const char *s);

Allocates memory and duplicates a string.

Edge cases:
- Must return NULL if allocation fails

---

### char *ft_strchr(const char *s, int c);
### char *ft_strrchr(const char *s, int c);

Search for a character in a string (first and last occurrence).

Edge cases:
- Must support searching for `'\0'`

---

### int ft_strncmp(const char *s1, const char *s2, size_t n);

Compares two strings up to `n` characters.

Edge cases:
- Must stop at `'\0'` or `n`
- Must handle partial comparisons correctly

---

### char *ft_strnstr(const char *big, const char *little, size_t len);

Searches for a substring within a limited length.

Edge cases:
- If `little` is empty → return `big`
- Must not read beyond `len`
- Must not rely on full null-termination

---

### size_t ft_strlcpy(char *dest, const char *src, size_t size);

Copies a string safely into a buffer.

Edge cases:
- If `size == 0`, nothing is written
- Must always return full length of `src`
- Must always null-terminate if `size > 0`

---

### size_t ft_strlcat(char *dst, const char *src, size_t size);

Appends a string to another safely.

Edge cases:
- Must not exceed `size`
- Must always null-terminate if space exists
- If `size <= strlen(dst)` → return `size + strlen(src)`

---

## Memory Functions

### void *ft_memset(void *s, int c, size_t n);

Fills memory with a constant byte.

---

### void ft_bzero(void *s, size_t n);

Sets memory to zero.

---

### void *ft_memcpy(void *dest, const void *src, size_t n);

Copies memory block.

Edge cases:
- Undefined behavior if memory overlaps

---

### void *ft_memmove(void *dest, const void *src, size_t n);

Safely copies memory, even if overlapping.

---

### void *ft_memchr(const void *s, int c, size_t n);

Searches for a byte in memory.

---

### int ft_memcmp(const void *s1, const void *s2, size_t n);

Compares memory blocks.

Edge cases:
- If `n == 0` → returns 0

---

### void *ft_calloc(size_t nmemb, size_t size);

Allocates and initializes memory to zero.

Edge cases:
- Must handle overflow of `nmemb * size`
- Must return NULL on allocation failure

---

## String Allocation Functions

### char *ft_substr(char const *s, unsigned int start, size_t len);

Extracts a substring from a string.

Edge cases:
- If `start >= strlen(s)` → return empty string
- Must not read out of bounds

---

### char *ft_strjoin(char const *s1, char const *s2);

Joins two strings into a new string.

---

### char *ft_strtrim(char const *s1, char const *set);

Removes characters from beginning and end of a string.

Edge cases:
- If all characters are trimmed → return empty string

---

### char **ft_split(char const *s, char c);

Splits a string into an array of strings.

Edge cases:
- Multiple delimiters must be skipped
- Must handle empty string
- Must free all memory on failure

---

### char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

Applies a function to each character and returns a new string.

Edge cases:
- Must handle NULL function pointer
- Must not modify original string

---

### void ft_striteri(char *s, void (*f)(unsigned int, char *));

Applies a function to each character in place.

Edge cases:
- Must handle NULL inputs safely

---

### char *ft_itoa(int n);

Converts an integer to a string.

Edge cases:
- Must handle `INT_MIN`

---

## Linked List Functions

### typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

---

### t_list *ft_lstnew(void *content);

Creates a new node.

---

### void ft_lstadd_front(t_list **lst, t_list *new);
### void ft_lstadd_back(t_list **lst, t_list *new);

Adds a node to front or back of a list.

Edge cases:
- Must handle empty list

---

### int ft_lstsize(t_list *lst);

Returns number of nodes.

---

### t_list *ft_lstlast(t_list *lst);

Returns last node.

Edge cases:
- Must return NULL if list is empty

---

### void ft_lstdelone(t_list *lst, void (*del)(void *));

Deletes a single node.

Edge cases:
- Must handle NULL safely

---

### void ft_lstclear(t_list **lst, void (*del)(void *));

Deletes entire list.

Edge cases:
- Must avoid memory leaks

---

### void ft_lstiter(t_list *lst, void (*f)(void *));

Applies a function to each node.

---

### t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

Creates a new list from transformed nodes.

Edge cases:
- Must free all memory if allocation fails
- Must not modify original list