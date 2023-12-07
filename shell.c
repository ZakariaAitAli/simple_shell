#include "shell.h"

int _execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL) {
		return 1;
	}

	pid = fork();

	if (pid == 0) {
		if (execve(args[0], args, NULL) == -1) {
			_perror("hsh");
		}
		_exit(EXIT_FAILURE);
	} else if (pid < 0) {
		_perror("hsh");
	} else {
		waitpid(pid, &status, WUNTRACED);
	}

	return 1;
}
