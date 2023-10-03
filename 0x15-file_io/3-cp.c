#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *f);
void close_f(int fc);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @f: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *f)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", f);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fc: The file descriptor to be closed.
 */
void close_file(int fc)
{
	int i;

	i = close(fc);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fc %d\n", fc);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argt: The number of arguments supplied to the program.
 * @argb: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Desc: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argt, char *argb[])
{
	int from, to, y, z;
	char *buffer;

	if (argt != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argb[2]);
	from = open(argb[1], O_RDONLY);
	y = read(from, buffer, 1024);
	to = open(argb[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || y == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argb[1]);
			free(buffer);
			exit(98);
		}

		z = write(to, buffer, y);
		if (to == -1 || z == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argb[2]);
			free(buffer);
			exit(99);
		}

		y = read(from, buffer, 1024);
		to = open(argb[2], O_WRONLY | O_APPEND);

	} while (z > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
