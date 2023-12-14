#include "shell.h"

void print_error(const char *message) {
	write(STDERR_FILENO, message, strlen(message));
	write(STDERR_FILENO, "\n", 1);
}
