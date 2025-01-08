/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:07:52 by ezeppa            #+#    #+#             */
/*   Updated: 2025/01/08 10:48:54 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ---------------- Conversion functions --------------------------------------

/**
 * Converts a string to an integer.
 *
 * @param nptr The string to be converted.
 * @return The integer value of the string.
 */
int					ft_atoi(const char *nptr);

/**
 * Converts an integer to a string.
 *
 * @param n The integer to be converted.
 * @return The string representation of the integer.
 */
char				*ft_itoa(int n);

/**
 * Converts a long integer to a string.
 *
 * @param n The long integer to be converted.
 * @return The string representation of the long integer.
 */
char				*ft_litoa(long n);

// ---------------- Character type functions ----------------------------------

/**
 * Checks if the given character is alphabetic.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int					ft_isalpha(int c);

/**
 * Checks if the given character is a digit.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int					ft_isdigit(int c);

/**
 * Checks if the given character is alphanumeric (letters or digits).
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int					ft_isalnum(int c);

/**
 * Checks if the given character is a valid ASCII character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is ASCII, 0 otherwise.
 */
int					ft_isascii(int c);

/**
 * Checks if the given character is printable (including space).
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
 */
int					ft_isprint(int c);

/**
 * Converts a character to uppercase.
 *
 * @param c The character to be converted.
 * @return The uppercase version of the character.
 */
int					ft_toupper(int c);

/**
 * Converts a character to lowercase.
 *
 * @param c The character to be converted.
 * @return The lowercase version of the character.
 */
int					ft_tolower(int c);

// --------------- Input/Output functions -------------------------------------

/**
 * Writes a character to a file descriptor.
 *
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 */
void				ft_putchar_fd(char c, int fd);

/**
 * Writes a string to a file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * Writes a string followed by a newline to a file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * Writes an integer as a string to a file descriptor.
 *
 * @param n The integer to write.
 * @param fd The file descriptor to write to.
 */
void				ft_putnbr_fd(int n, int fd);

// --------------- List functions ---------------------------------------------

/**
 * Adds a new node to the end of the list.
 *
 * @param lst A pointer to the list.
 * @param new The new node to add.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Adds a new node to the front of the list.
 *
 * @param lst A pointer to the list.
 * @param new The new node to add.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Clears the list by deleting all its nodes and freeing the memory.
 *
 * @param lst A pointer to the list.
 * @param del A function to delete the content of each node.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Deletes a node from the list and frees its memory.
 *
 * @param lst The node to delete.
 * @param del A function to delete the content of the node.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * Iterates through the list, applying a function to the content of each node.
 *
 * @param lst The list to iterate through.
 * @param f The function to apply to each node.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Returns the last node of the list.
 *
 * @param lst The list to search.
 * @return The last node of the list.
 */
t_list				*ft_lstlast(t_list *lst);

/**

	* Creates a new list by applying a function to each node's content in the original list.
 *
 * @param lst The list to map.
 * @param f The function to apply to each node's content.
 * @param del A function to delete the content of each node.
 * @return A new list with the transformed content.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/**
 * Creates a new node with the given content.
 *
 * @param content The content of the new node.
 * @return The new node.
 */
t_list				*ft_lstnew(void *content);

/**
 * Returns the size of the list (number of nodes).
 *
 * @param lst The list to measure.
 * @return The size of the list.
 */
int					ft_lstsize(t_list *lst);

// --------------- Memory functions -------------------------------------------

/**

	* Sets the first 'n' bytes of the memory area pointed to by 's' to the value 'c'.
 *
 * @param s The memory area to modify.
 * @param c The value to set.
 * @param n The number of bytes to set.
 * @return The pointer to the memory area.
 */
void				*ft_memset(void *s, int c, size_t n);

/**
 * Sets the first 'n' bytes of the memory area pointed to by 's' to zero.
 *
 * @param s The memory area to clear.
 * @param n The number of bytes to clear.
 */
void				ft_bzero(void *s, size_t n);

/**
 * Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 *
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area.
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copies 'n' bytes from memory area 'src' to memory area 'dest',
	handling overlap.
 *
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area.
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/**

	* Searches for the first occurrence of the character 'c' in the memory area 's'.
 *
 * @param s The memory area to search.
 * @param c The character to find.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of 'c', or NULL if not found.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * Compares the first 'n' bytes of two memory areas.
 *
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to compare.
 * @return 0 if the areas are equal, a positive or negative value otherwise.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Allocates memory for an array of 'nmemb' elements of size 'size' bytes.
 *
 * @param nmemb The number of elements.
 * @param size The size of each element.
 * @return A pointer to the allocated memory.
 */
void				*ft_calloc(size_t nmemb, size_t size);

/**
 * Reallocates memory for a pointer to a new size.
 *
 * @param ptr The original pointer.
 * @param new_size The new size of the memory.
 * @return A pointer to the reallocated memory.
 */
void				*ft_realloc(void *ptr, size_t new_size);

// --------------- Number functions -------------------------------------------

/**
 * Returns the number of digits in a long integer.
 *
 * @param n The long integer.
 * @return The number of digits.
 */
long				ft_long_size(long n);

/**
 * Returns the number of digits in an integer.
 *
 * @param n The integer.
 * @return The number of digits.
 */
int					ft_int_size(int n);

// --------------- String functions -------------------------------------------

/**
 * @brief Calculates the length of a string.
 *
 * @param s The string.
 * @return The length of the string (does not count the null character '\0').
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Copies a string to another, respecting a maximum size.
 *
 * @param dst The destination buffer.
 * @param src The source string to copy.
 * @param size The maximum size to copy (including the null character).
 * @return The total length of the source string.
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Concatenates a source string to a destination string,
	respecting a maximum size.
 *
 * @param dst The destination string.
 * @param src The source string to concatenate.
 * @param size The maximum size of the destination string.
 * @return The total length of the concatenated source string.
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Searches for the first occurrence of a character in a string,
	limited to n characters.
 *
 * @param s The string to analyze.
 * @param c The character to search for.
 * @param n The maximum number of characters to analyze.
 * @return A pointer to the first occurrence of c in the string,
	or NULL if not found.
 */
char				*ft_strnchr(const char *s, int c, size_t n);

/**
 * @brief Searches for the first occurrence of a character in a string.
 *
 * @param s The string to analyze.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of c in the string,
	or NULL if not found.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Searches for the last occurrence of a character in a string.
 *
 * @param s The string to analyze.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of c in the string,
	or NULL if not found.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Compares two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return A negative integer if s1 is less than s2, 0 if they are equal,
	a positive integer otherwise.
 */
int					ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compares the first n characters of two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return A negative integer if the first n characters of s1 are less than those of s2,
	0 if they are equal, a positive integer otherwise.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Searches for a substring within a string, limited to n characters.
 *
 * @param big The main string.
 * @param little The substring to search for.
 * @param len The maximum number of characters to analyze.
 * @return A pointer to the first occurrence of little in big,
	or NULL if not found.
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/**
 * @brief Creates a new string that is a copy of the given string.
 * @param s The string to copy.
 * @return A pointer to the newly allocated string, or NULL if allocation fails.
 */
char				*ft_strdup(const char *s);

/**
 * @brief Extracts a substring from a string, starting at a given index.
 *
 * @param s The original string.
 * @param start The starting index of the substring.
 * @param len The length of the substring to extract.
 * @return The extracted substring, or NULL if allocation fails.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Joins two strings together.
 *
 * @param s1 The first string.
 * @param s2 The second string to concatenate to the first.
 * @return A new string that is the concatenation of s1 and s2,
	or NULL if allocation fails.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Removes characters specified in a set from a string.
 *
 * @param s1 The string to process.
 * @param set The set of characters to remove.
 * @return The processed string, or NULL if allocation fails.
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Splits a string into an array of substrings separated by a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of substrings, or NULL if allocation fails.
 */
char				**ft_split(char const *s, char c);

/**

	* @brief Applies a function to each character of a string to return a new string.
 *
 * @param s The string to process.
 * @param f The function to apply to each character of the string.
 * @return The resulting string after applying the function,
	or NULL if allocation fails.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies a function to each character of a string,
	modifying the string in place.
 *
 * @param s The string to modify.
 * @param f The function to apply to each character of the string.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// --------------- Printf Defines ---------------------------------------------
// Boolean
# define FALSE 0
# define TRUE 1

// Flags
# define FLAG_MINUS '-'
# define FLAG_PLUS '+'
# define FLAG_SPACE ' '
# define FLAG_HASH '#'
# define FLAG_ZERO '0'

// Printf Structs
typedef struct s_format
{
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				flag_hash;
	int				flag_zero;
	int				width;
	int				precision;
	char			specifier;
}					t_format;

// --------------- Printf Functions -------------------------------------------

/**
 * A custom implementation of the printf function.
 *
 * @param format The format string that specifies the output format.
 * @param ... The variable arguments that correspond to the format specifiers.
 * @return The total number of characters printed.
 */
int					ft_printf(const char *format, ...);

/**
 * Initializes the format structure based on the given format string.
 *
 * @param ptr A pointer to the format string.
 * @return A pointer to the initialized format structure.
 */
t_format			*init_format(const char **ptr);

/**
 * Writes a character to the standard output and returns the number of characters printed.
 *
 * @param c The character to be printed.
 * @return The number of characters printed (always 1).
 */
int					ft_putchar_size(char c);

/**
 * Writes a string to the standard output and returns the number of characters printed.
 *
 * @param str The string to be printed.
 * @return The number of characters printed.
 */
int					ft_putstr_size(char *str);

/**
 * Converts a number to its hexadecimal representation as a string.
 *
 * @param nb The number to be converted.
 * @param base The base to use for the conversion (e.g., "0123456789abcdef").
 * @return The hexadecimal representation of the number as a string.
 */
char				*convert_to_hexa(unsigned long long nb, char *base);

/**
 * Prints a character with the specified format and returns the number of characters printed.
 *
 * @param format The format structure containing the formatting information.
 * @param c The character to be printed.
 * @return The number of characters printed.
 */
int					print_c(t_format *format, char c);

/**
 * Prints a string with the specified format and returns the number of characters printed.
 *
 * @param format The format structure containing the formatting information.
 * @param str The string to be printed.
 * @return The number of characters printed.
 */
int					print_s(t_format *format, char *str);

/**
 * Prints a pointer address with the specified format and returns the number of characters printed.
 *
 * @param format The format structure containing the formatting information.
 * @param ptr The pointer to be printed.
 * @return The number of characters printed.
 */
int					print_p(t_format *format, void *ptr);

/**
 * Prints an integer or decimal number with the specified format and returns the number of characters printed.
 *
 * @param format The format structure containing the formatting information.
 * @param nb The number to be printed.
 * @return The number of characters printed.
 */
int					print_d_i(t_format *format, int nb);

/**
 * Prints an unsigned integer with the specified format and returns the number of characters printed.
 *
 * @param format The format structure containing the formatting information.
 * @param nb The unsigned integer to be printed.
 * @return The number of characters printed.
 */
int					print_u(t_format *format, unsigned int nb);

/**
 * Prints a hexadecimal number with the specified format and returns the number of characters printed.
 *
 * @param format The format structure containing the formatting information.
 * @param nb The number to be printed in hexadecimal.
 * @param is_upper Whether to use uppercase letters for hexadecimal digits.
 * @return The number of characters printed.
 */
int					print_x(t_format *format, unsigned long nb, int is_upper);

/**
 * Formats a string according to the width and minus/zero flags for padding.
 *
 * @param str The string to be formatted.
 * @param width The total width to pad the string to.
 * @param has_minus Whether the minus flag is present.
 * @param has_zero Whether the zero flag is present.
 * @return The formatted string with the appropriate padding.
 */
char				*formatted_width_minus_zero(char *str, int width,
						int has_minus, int has_zero);

/**
 * Formats a number string according to the precision and plus/space flags.
 *
 * @param str The string representation of the number to be formatted.
 * @param precision The precision to format the number to.
 * @param has_plus Whether the plus flag is present.
 * @param has_space Whether the space flag is present.
 * @return The formatted number string with the appropriate precision and flags.
 */
char				*formatted_number_precision(char *str, int precision,
						int has_plus, int has_space);

// ----------------------------------------------------------------------------

#endif
