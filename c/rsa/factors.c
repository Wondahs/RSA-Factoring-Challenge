#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *main - Entry point
 *@argc: Number of command line args
 *@argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file;
	size_t bytesRead, written = 0;
	char buffer[BUFFER_SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		bytesRead = read(file, buffer, BUFFER_SIZE);
		written += bytesRead;
		buffer[written] = '\0';
		if (bytesRead == 0)
			break;

		execute(buffer);
	}
	exit(0);
}
