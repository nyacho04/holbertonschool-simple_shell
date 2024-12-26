#include "shell.h"

/**
 *
 *
 *
 */

char *srch_path(char *line)
{
	// Variable para getenv
	char *path, *path_cpy;
	// Variable para strtok
	char *dir, *command;
	// Variable para sprintf
	char *fl_route = malloc(sizeof(char) * 1024);
	// Variable para stat
	struct stat st;

	if (fl_route == NULL)
	{
		perror("Malloc failed");
		free(fl_route);
		return (NULL);
	}

	char *cpy = strdup(line);
	if (cpy == NULL)
	{
		perror("Strdup failed");
		free(fl_route);
		free(cpy);
		return (NULL);
	}

	command = strtok(cpy, " \n");
	if (command == NULL)
	{
		perror("No command provided");
		free(cpy);
		free(fl_route);
		free(command);
		return (NULL);
	}

	path = getenv("PATH"); // Consigo todos los directorios del PATH
	if (path == NULL)
	{
		perror("Environment variable not found");
		free(cpy);
		free(fl_route);
		return (NULL);
	}
	path_cpy = strdup(path);

	dir = strtok(path_cpy, ":"); // Identifico cada directorio separado por ":"
	while (dir != NULL)
	{
		sprintf(fl_route, "%s/%s", dir, command);
		if (stat(fl_route, &st) == 0)         // Se verifica si existe el archivo en cada ruta que se encuentra en PHAT
		{
			free(cpy);
			free(path_cpy);
			return (fl_route);
		}
		dir = strtok(NULL, ":");
	}
	free(cpy);
	free(path_cpy);
	return (NULL);
}

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
	// Variable para srch_path
	char *route;


	while (result != -1)
	{
		printf("$ ");
		result = getline(&line, &len, stdin); // Lee los comandos y printea "$" en la salida en un bucle

		if (result == -1)
			break;

		if (strcmp(line, "exit\n") == 0) // Sale del bucle "$"
			break;

		if (result > 0 && line[result - 1] == '\n')
			line[result - 1] = '\0';

		if (result > 1)
		{
			route = srch_path(line);
			if (route == NULL)
			{
				perror("File not found in PATH");
				free(line);
				free(route);
				continue;
			}

			array = malloc(sizeof(char *) * 1024);

			if (array == NULL)
			{
				perror("Error al asignar memoria");
				free(line);
				free(route);
				return (1);
			}

			i = 0;
			
			if (route != NULL)
			{
				token = strtok(route, " \n");

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
					free(route);
					continue;
				}

				pid = fork();

				if (pid == -1)
				{
					perror("Error al realizar fork");
					free(array);
					free(line);
					free(route);
					return (1);
				}
				if (pid == 0)
				{
					if (execve(array[0], array, NULL) == -1)
					{
						perror("Error en la ejecucion execve");
						free(array);
						free(line);
						free(route);
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
			}
			else
			{
				perror("The file not found in PATH");
				free(route);
			}
		}
	}
	free(array);
	free(route);
	free(line);
	return (0);
}
