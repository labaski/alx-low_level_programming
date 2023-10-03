#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @fname: text file being read
 * @letter: number of letters to be read
 * Return: w- actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *fname, size_t letter)
{
	char *buc;
	ssize_t fc;
	ssize_t z;
	ssize_t y;

	fc = open(fname, O_RDONLY);
	if (fc == -1)
		return (0);
	buc = malloc(sizeof(char) * letter);
	y = read(fc, buc, letter);
	z = write(STDOUT_FILENO, buc, y);

	free(buc);
	close(fc);
	return (z);
}
