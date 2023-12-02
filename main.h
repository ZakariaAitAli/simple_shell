#ifndef SIMPLE_SHELL_MAIN_H
#define SIMPLE_SHELL_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_TOKEN 512
#define BUFFER_SIZE 1024

void handle_memory_allocation_error(void);
void handle_fork_error(void);
void handle_execve_error(void);

char **tokenize_input(char *input_buffer, const char *delimiters);
char *get_executable_path(const char *command);

#endif /* SIMPLE_SHELL_MAIN_H */
