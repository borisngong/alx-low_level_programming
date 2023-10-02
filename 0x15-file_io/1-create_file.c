#include "main.h"
/**
  * create_file - a function that create a file and writes a given text to it
  * @filename: pointer to a name of the file to be created, filename
  * @text_content: pointer to a string, contains the text to write to the file
  * Return: 1 on success, -1 on failure
  */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int l_write;
	int l_longii;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l_longii = 0; text_content[l_longii];)
			l_longii++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	l_write = write(fd, text_content, l_longii);

	if (fd == -1 || l_write == -1)
		return (-1);

	close(fd);

	return (1);
}

