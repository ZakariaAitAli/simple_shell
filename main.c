#include "main.h"

/**
 * main - the main function of the project
 *
 * Return: 0 Always
 */

int main(void)
{
	char *input_buffer;
	char shell_prompt[] = "#Cisfun$ ";
	char delimiters[] = " \n\t\a";
	int read_result, child_status;
	size_t buffer_size = BUFFER_SIZE;
	char **tokenized_input;
	pid_t child_process_id;

	input_buffer = malloc(BUFFER_SIZE);
	if (!input_buffer)
		handle_memory_allocation_error();

	while (read_result != (-1))
	{
		printf("%s", shell_prompt);
		read_result = getline(&input_buffer, &buffer_size, stdin);
		tokenized_input = tokenize_input(input_buffer, delimiters);
		child_process_id = fork();

		if (child_process_id == -1)
			handle_fork_error();

		if (child_process_id == 0)
		{
			if (execve(get_executable_path(tokenized_input[0]),
					   tokenized_input, NULL) == -1)
				handle_execve_error();
		}
		else
		{
			wait(&child_status);
		}
	}

	return (0);
}
