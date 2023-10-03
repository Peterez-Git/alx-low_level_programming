#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * Explanations of terms used in the code process
 * create_buffer - This function let's you allocates 1024 bytes for a buffer.
 * @file: This parameter allow the name of the file buffer for storing chars.
 *
 * Return: This  let's you allow a pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * This explanation covers this block of code
 * close_file - This function let's you close file descriptors.
 * @fd:This is a specifier, which let's you specify the file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * This Terminology Explanation covers this block of code.
 *
 * main - this function let's you copy the contents of a given file to another file.
 * @argc: this function returns the number of arguments supplied to the program.
 * @argv: This funtion generates an array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Futher Descriptions the code: For instance If the argument count is incorrect or invalid- exit code 97.
 * For instance If file_from does not exist or cannot be read - exit code 98.
 * In the code If file_to cannot be created or written i.e (readonly) to - exit code 99.
 * In the code If file_to or file_from cannot be closed (unwrittable) - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
