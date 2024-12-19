#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t variable = fork();
	int status;

	if (variable == -1)
	{
		perror("Error");
		return (-1);
	}

	if (variable == 0)
	{
		printf("Soy el hijo y mi papa me espera\n");
	}
	else
	{
		wait(&status);
		printf("Soy el padre y espero a mi hijo\n");
	}

	printf("------\n");

	return (0);
}

