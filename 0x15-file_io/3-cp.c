#include "main.h"

char *allocate_buf(char *file);
void safe_close_file(int fd);


/**
  * allocate_buf - creates a buffer of 1024 bytes and returns a pointer
  * to the newly allocated buffer
  * @file: a pointer to char, which will store the memory address
  * of the allocated buffer
  * Return: buffer to the created buffer
  */
char *allocate_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
  * safe_close_file - to close a file descriptor while also providing error
  * handling in case the closing operation fails
  * @fd: file descriptor communication channel between a process and a file
  * Return: (void)
  */
void safe_close_file(int fd)
{
	int status_close = close(fd);

	if (status_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}

}
/**
  * main - the entry point of a c programmm
  * @argc: argument count, number of command lines passed to the programm
  * @argv: array of strings where each represents a command_line argument
  * passed to the program
  * Description: THis programm takes two file arguments the source file name
  * and the destination file name, it reads data from source file in chunks of
  * 1024 bytes and writes to destination file, it exits with different status
  * codes depending on the errors encointered, error handling is performed
  * for file opening, reading and writing operations.
  * provides a basic file copy with minimal error checking.
  * Return: 0
  */

int main(int argc, char *argv[])
{
	int from;
	int to;
	int read_status;
	int write_status;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = allocate_buf(argv[2]);
	from = open(argv[1], O_RDONLY);
	read_status = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || read_status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		write_status = write(to, buf, read_status);
		if (to == -1 || write_status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		read_status = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_status > 0);

	free(buf);
	safe_close_file(from);
	safe_close_file(to);

	return (0);
}

