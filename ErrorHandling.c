#include "main.h"

void handle_memory_allocation_error(void) {
	fprintf(stderr, "Error: Memory allocation failed\n");
	exit(EXIT_FAILURE);
}

void handle_fork_error(void) {
	perror("Error during fork");
	exit(EXIT_FAILURE);
}

void handle_execve_error(void) {
	perror("Error during execve");
	exit(EXIT_FAILURE);
}
