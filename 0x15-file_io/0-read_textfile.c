#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t cd;
	ssize_t a;
	ssize_t b;

	cd = open(filename, O_RDONLY);
	if (cd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	a = read(cd, buf, letters);
	b = write(STDOUT_FILENO, buf, a);

	free(buf);
	close(cd);
	return (b);
}
