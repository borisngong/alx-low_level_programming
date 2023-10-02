#include "main.h"
/**
  * read_textfile - reads file and return the number of bytes read and
  * printing it to POSIX stdout
  *
  * @filename: pointer to a string representing the file to read
  *
  * @letters: maximun number of characters to read from the file
  *
  * Return: actual number letter of it could read and print
  * if filename is NULL return 0, if fails or doesnt write expected bytes
  * return 0
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t l_read, l_write;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);

	l_read = read(fd, buffer, letters);
	l_write = write(STDOUT_FILENO, buffer, l_read);

	free(buffer);
	close(fd);
	return (l_write);
}
