#include "main.h"
/**
  * allocate_buf - creates a buffer of 1024 bytes and returns a pointer to the newly allocated buffer
  * @file: a pointer to char, which will store the memory address of the allocated buffer
  * Return: buffer to the created buffer
  */
char *allocate_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", file);
		exit(97);
	}
	return (buf);
}
/**
  * safe_close_file - to close a file descriptor while also providing error handling in case the
  * closing operation fails
  * @fd: file descriptor communication channel between a process and a file
  * Return: (void)
  */
void safe_close_file(int fd)
{
	int close_status = close(fd);

	if (close_status == -1)
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
  * Return: 0
  */

int main(int argc, char *argv[])
{
	int source_fd, destination_fd;
	int read_status, write_status;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "cp file_from file_to\n");
		exit(98);
	}

	buf = allocate_buf(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_status = read(source_fd, buf, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (destination_fd == -1 || source_fd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
			free(buf);
			exit(98);
		}

		write_status = write(destination_fd, buf, read_status);
		if (source_fd == -1 || write_status  == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
			free(buf);
			exit(99);
		}

		read_status = read(source_fd, buf, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_status > 0);
	free(buf);
	safe_close_file(source_fd);
	safe_close_file(destination_fd);

	return (0);
}
