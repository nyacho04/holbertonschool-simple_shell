#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	// Declaraciones del fork
	pid_t hijos;
	// Declaraciones de wait
	int status;
	// Declaraciones de execve
	char *pathname = "/bin/ls";
	char *argv[] = {pathname, "-l",  "/tmp", NULL};
	char *envp[] = {NULL};

	int i;

	for (i = 0; i < 5; i++)
	{
		hijos = fork();

		if (hijos == -1)
		{
			perror("Error");
			return (-1);
		}

		if (hijos == 0)
		{
			printf("Proceso hijo %d\n", i + 1);
			if (execve(pathname, argv, envp) == -1)
			{
				perror("Error en execve");
				exit(1);
			}
		}

		wait(&status);
	}
	printf("todos los hijos terminaron");
	
	return (0);
}
