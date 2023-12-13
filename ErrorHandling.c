#include "main.h"

/**
 * handle_memory_allocation_error - handle error
 *
 * Return: error
 */

void handle_memory_allocation_error(void)
{
	fprintf(stderr, "Error: Memory allocation failed\n");
	exit(EXIT_FAILURE);
}

/**
 * handle_fork_error - handle error
 *
 * Return:  error
 */

void handle_fork_error(void)
{
	perror("Error during fork");
	exit(EXIT_FAILURE);
}

/**
 * handle_execve_error - handle error
 *
 * Return:  error
 */

void handle_execve_error(void)
{
	perror("Error during execve");
	exit(EXIT_FAILURE);
}
