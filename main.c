#include "shell.h"

int main(void)
{
	char *line;
	char *args[MAX_TOKENS];
	int status;

	do {
		write(1, "($) ", 4);
		line = _getline();
		_split_line(line, args);
		status = _execute(args);

		_free_memory(line);
	} while (status);

	return 0;
}
