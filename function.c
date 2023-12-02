#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: the given string
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return length;
}

/**
 * tokenize - splits a given string into tokens
 * @line: the given string
 * @delimiters: the given delimiter
 *
 * Return: pointer to an array of tokens, or NULL if it fails
 */
char **tokenize_input(char *input_buffer, const char *delimiters)
{
	char *token;
	int index = 0;
	char **tokenArray;

	if (!input_buffer)
		return NULL;

	tokenArray = malloc(MAX_TOKEN);
	if (!tokenArray)
		return NULL;

	token = strtok(input_buffer, delimiters);
	while (token)
	{
		tokenArray[index++] = token;
		token = strtok(NULL, delimiters);
	}
	tokenArray[index] = NULL;
	return tokenArray;
}

/**
 * path_concat - concatenates two strings
 * @dest: the first given destination
 * @src: the second given source
 *
 * Return: pointer to the newly concatenated string, or NULL if it fails
 */
char *path_concat(char *dest, char *src)
{
	int destLength, srcLength, i = 0, j = 0;
	char *result;

	destLength = _strlen(dest);
	srcLength = _strlen(src);

	result = malloc(destLength + srcLength + 2);
	if (!result)
		return NULL;

	while (dest[j])
	{
		result[i] = dest[j];
		j++;
		i++;
	}
	result[i++] = '/';
	j = 0;

	while (src[j])
	{
		result[i] = src[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return result;
}

/**
 * _which - locates the given filename if in the PATH
 * @filename: the given filename
 *
 * Return: pointer to the pathname of the file/command, or NULL if not found
 */
char *get_executable_path(const char *filename)
{
	char **pathTokens;
	char *pathEnv;
	struct stat fileStat;
	char *fullPath;
	int index = 0;

	pathEnv = getenv("PATH");
	pathTokens = tokenize_input(pathEnv, ":");

	if (stat(filename, &fileStat) == 0)
	{
		return (char *)filename;
	}
	else
	{
		while (pathTokens[index])
		{
			fullPath = path_concat(pathTokens[index], (char *)filename);
			if (stat(fullPath, &fileStat) == 0)
			{
				return fullPath;
			}
			index++;
		}
	}
	return NULL;
}

