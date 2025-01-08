#include "main.h"
/**
 * execute - Executes a command with its flags
 * @pointer: A pointer to the command to execute
 * Return: 0 on success
 */

char *execute(char *pointer)
{
	int i = 0, st, status;
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
				exit(127);
			}
		}
		else
		{
			if (wait(&st) == -1)
			{
				perror("wait failed");
				free(array);
			}
			else
			{
				if (WIFEXITED(st))
				{
					status = WEXITSTATUS(st);
					if (status == 127)
					{
						fprintf(stderr, "%s: %s: not found\n", array[0], array[0]);
					}
				}
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
