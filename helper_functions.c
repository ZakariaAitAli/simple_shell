#include "shell.h"
#include <string.h>

char *_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	read(0, &bufsize, 0);
	line = (char *)malloc(bufsize);
	if (!line) {
		_perror("hsh");
		_exit(EXIT_FAILURE);
	}
	read(0, line, bufsize);
	return line;
}

void _split_line(char *line, char **tokens)
{
	int position = 0;
	char *token;

	token = strtok(line, " \t\r\n\a");

	while (token != NULL && position < MAX_TOKENS - 1) {
		tokens[position] = token;
		position++;

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
}

void _free_memory(char *ptr)
{
	free(ptr);
}

void _perror(const char *msg)
{
	write(2, msg, strlen(msg));
}
