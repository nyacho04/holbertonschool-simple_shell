#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* execute_command - Entry point of the shell program
*
* @line: The command to be executed
*
* Return: Always 0
*/
void execute_command(char *line)
{
	char *args[100];
	char *nya;
	int i = 0;
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char full_path[1024];

	nya = strtok(line, " \n");
	while (nya != NULL)
	{
		args[i++] = nya;
		nya = strtok(NULL, " \n");
	}
	args[i] = NULL;

	if (args[0] == NULL)
	{
		return;
	}

	if (fork() == 0)
	{
		while (dir != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", dir, args[0]);
			if ((access(full_path, X_OK) == 0))
			{
				execv(full_path, args);
				exit(EXIT_FAILURE);
			}
			dir = strtok(NULL, ":");
		}
		perror(args[0]);
		exit(EXIT_FAILURE);

	}
	else
	{
	wait(NULL);
	}
}
