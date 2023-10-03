#include "main.h"
/**
  * append_text_to_file - responsible for appending text at the end of the file
  * @filename: pointer to a name of the file to be created, filename
  * @text_content: pointer to a string, contains the text to write to the file
  * Return: 1 on success, -1 on failure
  */
int append_text_to_file(const char *filename, char *text_content)
{	int fd;
	int l_write;
	int l_longii;

	if (!filename)
		return (-1);

	if (text_content == NULL)
		return (1);

	for (l_longii = 0; text_content[l_longii]; l_longii++)
		;
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	l_write = write(fd, text_content, l_longii);
	if (l_write == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
