#include "main.h"

/**
 * execute - Execute the command using the for, execve and wait functions
 * @pointer: Pointer to string (command and flags)
 *
 * Return: If this goes well... nothing
 */

char *execute(char *pointer)
{
	int i = 0, st;
	pid_t pid;
	char *token, **array;

	array = malloc(sizeof(char *) * BUFFER_SIZE);
	if (array == NULL)
		return (NULL);
	if (pointer != NULL)
	{
		token = strtok(pointer, " \n");
		while (token != NULL)
		{
			array[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		array[i] = NULL;
		if (array[0] == NULL)
		{
			free(array);
			return (NULL);
		}
		pid = fork();
		if (pid == -1)
		{
			free(array);
			return (NULL);
		}
		if (pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				free(array);
				perror("execve failed");
				exit(1);
			}
		}
		else
		{
			if (wait(&st) == -1)
			{
				perror("wait failed");
				free(array);
			}
		}
	}
	else
	{
		free(array);
		return (NULL);
	}
	free(array);
	return (0);
}
