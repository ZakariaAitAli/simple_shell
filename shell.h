#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_TOKENS 64
#define BUFFER_SIZE 1024

/* Function prototypes */
char *_getline(void);
void _split_line(char *line, char **tokens);
int _execute(char **args);
void _free_memory(char *ptr);
void _perror(const char *msg);

#endif /* SHELL_H */
