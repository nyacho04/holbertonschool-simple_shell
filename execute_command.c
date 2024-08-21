#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
/**
 * exectue_command - dfdfsdfsd
 * @command: variable
 *
 * Return: void
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];

	pid = fork();

	if (pid == -1)	
	{
		perror("failed fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("command execute failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
