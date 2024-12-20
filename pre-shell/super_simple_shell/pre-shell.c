#include "shell.h"

/**
 *
 *
 *
 */

int main(void)
{
	// Variables del getline
	char *line = NULL;
	size_t len = 0;
	ssize_t result = 0;

	// Variables del strtok
	int i = 0;
	char *token; //*aux;
	char **array;

	// Variables del fork
	pid_t pid;

	// Variables del wait
	int status;


	while (result != -1)
	{
		printf("$ ");
		result = getline(&line, &len, stdin);

		if (result == -1)
			break;

		if (strcmp(line, "exit\n") == 0)
			break;

		if (result > 1)
		{
			array = malloc(sizeof(char *) * 1024);

			if (array == NULL)
			{
				perror("Error al asignar memoria");
				free(line);
				return (1);
			}

			i = 0;

			token = strtok(line, " \n");

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
				continue;
			}

			pid = fork();

			if (pid == -1)
			{
				perror("Error al realizar fork");
				free(array);
				free(line);
				return (1);
			}
			if (pid == 0)
			{
				if (execve(array[0], array, NULL) == -1)
				{
					perror("Error en la ejecucion execve");
					free(array);
					free(line);
					return (1);
				}
			}
			else
			{
				if (wait(&status) == -1)
				{
					perror("Error en el wait");
				}
			}
			free(array);
		}

	}
	free(line);
	return (0);
}
