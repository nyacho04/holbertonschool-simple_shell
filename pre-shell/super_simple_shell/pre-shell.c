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

char *flags_process(char *line)
{
	char *token;
	int track = 0, frst_token = 1;
	char *buffer = malloc(sizeof(char *) *1024);

	char *cpy = strdup(line);
	
	for (token = strtok(cpy, " "); token != NULL; token = strtok(NULL, " "))
	{
		if (frst_token)
		{
			frst_token = 0;
			continue;
		}

		if (track > 0)
			track += sprintf(buffer + track, " ");

		track += sprintf(buffer + track, "%s", token);
	}

	if (buffer == NULL)
	{
		free(cpy);
		return (NULL);
	}
	free(cpy);
	return (buffer);
}

/**
 *
 *
 */

char *exfowa(char *pointer)
{
	// Var strtok
	int i = 0;
	char *token;
	char **array = malloc(sizeof(char *) * 1024);
	// Var fork
	pid_t pid;
	// Var wait
	int status;

	if (array == NULL)
	{
		perror("Memory allocation failed");
		free(array);
		return (NULL);
	}

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
				return (NULL);
			}
		}
		else
		{
			if (wait(&status) == -1)
				perror("Wait failed");
		}
	}
	else
	{
		free(array);
		return (NULL);
	}
	return(0);
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
	// Variable para srch_path y flags_process
	char *route, *flags;


	while (result != -1)
	{
		printf("$ ");
		result = getline(&line, &len, stdin); // Lee los comandos y printea "$" en la salida en un bucle

		if (result == -1)
			break;

		if (strcmp(line, "exit\n") == 0) // Sale del bucle "$"
			break;

		if (result > 0 && line[result - 1] == '\n') // Saca el valor "\n" para poder ejecutar comandos solos
			line[result - 1] = '\0';

		if (result > 1)
		{
			route = srch_path(line);
			flags = flags_process(line);

			if (route == NULL)
			{
				perror("File not found in PATH");
				free(line);
				free(route);
				free(flags);
				continue;
			}

			if (flags != NULL)
			{
				char *rut_and_flgs = malloc(sizeof(char *) * 1024);
			
				if (rut_and_flgs == NULL)
				{
					perror("Memory allocation failed to route and flags");
					free(line);
					free(route);
					free(flags);
				}

				sprintf(rut_and_flgs, "%s %s", route, flags);

				exfowa(rut_and_flgs);

				if (rut_and_flgs == NULL)
				{
					perror("Process failed");
					free(rut_and_flgs);
					return (-1);
				}
				if (rut_and_flgs == NULL)
				{
					perror("Error when serching in the path");
					free(rut_and_flgs);
					return (-1);
				}
			}
			else
			{
				free(flags);

				exfowa(route);

				if (route == NULL)
				{
					perror("Process failed");
					free(route);
					return (-1);
				}
				if (route == NULL)
				{
					perror("Error when serching in the path");
					free(route);
					return (-1);
				}
			}
		}
	}
	free(route);
	free(line);
	return (0);
}
