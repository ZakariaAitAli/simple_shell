#include "shell.h"

int main(void) {
	char buffer[BUFFER_SIZE];
	ssize_t read_chars;
	pid_t child_pid;
	int status;

	while (1) {
		/* Display prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/* Read user input */
		read_chars = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		/* Check for end-of-file (Ctrl+D) */
		if (read_chars == 0) {
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove newline character */
		buffer[read_chars - 1] = '\0';

		/* Fork a child process */
		child_pid = fork();

		if (child_pid == -1) {
			perror("Error forking process");
			_exit(EXIT_FAILURE);
		}

		if (child_pid == 0) {
			/* Child process */
			close(STDIN_FILENO);
			execute_command(buffer);
			/* If execve is successful, this line won't be reached */
			_exit(EXIT_FAILURE);
		} else {
			/* Parent process */
			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
				/* Print the error message only if the child process failed */
				if (WEXITSTATUS(status) != EXIT_FAILURE) {
					write(STDERR_FILENO, "./hsh: No such file or directory\n", 33);
				}
			}
		}
	}

	return 0;
}
