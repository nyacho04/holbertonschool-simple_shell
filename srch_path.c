#include "main.h"
/**
 * srch_path - Differentiates a command from an absolute
 * path, then return a pointer to the absolite path
 * @pointer - A pointer to the commando or absolute path
 *
 * Return: A pointe to the path in the PATH or to the entered path
 */

char *srch_path(char *pointer, char *argv0, int *status)
{
	char *path, *path_cpy, *dir, *command, *cpy_cmd, *fl_route, *cpy, **env;
	struct stat st;

	fl_route = malloc(sizeof(char) * BUFFER_SIZE);
	if (fl_route == NULL)
		return (NULL);

	cpy = strdup(pointer);
	if (cpy == NULL)
	{
		free(fl_route);
		return (NULL);
	}

	command =strtok(cpy, " \n\t");
	if (command == NULL)
	{
		free(cpy);
		free(fl_route);
		return (NULL);
	}

	if (command[0] == '/' || (command[0] == '.' && command[1] == '/') || ( command[0] == '.' && command[1] == '.'))
	{
		if (stat(command, &st) == 0)
		{
			cpy_cmd = strdup(command);
			free(fl_route);
			free(cpy);
			return (cpy_cmd);
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv0, command);
			free(fl_route);
			free(cpy);
			*status = 127;
			return (NULL);
		}
	}
	else
	{
		path = NULL;
		for (env = environ; *env != NULL; env++)
		{
			if (strncmp(*env, "PATH=", 5) == 0)
			{
				path = *env + 5;
				break;
			}
		}
		if (path == NULL)
		{
			free(cpy);
			free(fl_route);
			return (NULL);
		}

		path_cpy = strdup(path);
		if (path_cpy == NULL)
		{
			free(cpy);
			free(fl_route);
			return (NULL);
		}

		dir = strtok(path_cpy, ":");
		while (dir != NULL)
		{
			sprintf(fl_route, "%s/%s", dir, command);
			if (stat(fl_route, &st) == 0)
			{
				free(cpy);
				free(path_cpy);
				return (fl_route);
			}
			dir = strtok(NULL, ":");
		}
		fprintf(stderr, "%s: 1: %s: not found\n", argv0, command);
		free(cpy);
		free(path_cpy);
		free(fl_route);
		*status = 127;
	}
	return (NULL);
}
