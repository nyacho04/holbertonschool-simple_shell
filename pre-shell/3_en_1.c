#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	// Declaraciones del fork
	pid_t hijo1, hijo2; //hijo3, hijo4, hijo5;
	// Declaraciones de wait
	int status;
	// Declaraciones de execve
	char *pathname = "/bin/ls";
	char *argv[] = {pathname, "-l",  "/tmp", NULL};
	char *envp[] = {NULL};

	hijo1 = fork();

	if (hijo1 == -1)
	{
		perror("ERROR");
		return (-1);
	}

	if (hijo1 == 0)
	{
		printf("hijo1\n");
		if (execve(pathname, argv, envp) == -1)
		{
			perror("Error");
			return (-1);
		}
	}
	else
	{
		hijo2 = fork();

		if (hijo2 == 0)
		{
			printf("hijo2\n");
			if (execve(pathname, argv, envp) == -1)
			{
				perror("error");
				return (-1);
			}
		}
		else
		{
			wait(&status);
			printf("padre\n");
		}
	}
	return (0);
}		
