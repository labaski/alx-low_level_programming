#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @fname: A pointer to the name of the file.
 * @text_cont: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 * If the file does not exist the user lacks write permissions - -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *fname, char *text_cont)
{
	int i, z, l = 0;

	if (fname == NULL)
		return (-1);

	if (text_cont != NULL)
	{
		for (l = 0; text_cont[l];)
			l++;
	}

	i = open(fname, O_WRONLY | O_APPEND);
	z = write(i, text_cont, l);

	if (i == -1 || z == -1)
		return (-1);

	close(i);

	return (1);
}
