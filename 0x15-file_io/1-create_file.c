#include "main.h"

/**
 * create_file - Creates a file.
 * @fname: A pointer to the name of the file to create.
 * @text_cont: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 * Otherwise - 1.
 */

int create_file(const char *fname, char *text_cont)
{
	int fc, z, len = 0;

	if (fname == NULL)
		return (-1);

	if (text_cont != NULL)
	{
		for (len = 0; text_cont[len];)
			len++;
	}

	fc = open(fname, O_CREAT | O_RDWR | O_TRUNC, 0600);
	z = write(fc, text_cont, len);

	if (fc == -1 || z == -1)
		return (-1);

	close(fc);

	return (1);

}
