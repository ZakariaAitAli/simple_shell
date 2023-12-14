#include "shell.h"

int execute_command(const char *command) {
	char *args[2];
	args[0] = (char *)command;
	args[1] = NULL;

	if (execve(command, args, NULL) == -1) {
		/* If execve fails, print an error message to stderr */
		write(STDERR_FILENO, "./hsh: No such file or directory\n", 33);

		/* Exit the child process with a failure status */
		_exit(EXIT_FAILURE);
	}

	/* If execve is successful, exit the child process with success */
	_exit(EXIT_SUCCESS);
}
