#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t variable;

//	Cuando se usa fork se divide el proceso en padre e hijo,
//	el hijo retorna 0 y el padre retorna el PID del hijo

	variable = fork();

//	Caso de error

	if (variable == -1)
	{
	perror("Error");
	return (-1);
	}

	if (variable == 0) //Es el hijo (se imprime despues que el padre)
	{
		printf("Soy el proceso hijo\n");
	}
	else //Es el padre (Se imprime antes que su hijo)
	{
		printf("Soy el proceso padre\n");
	}

	printf("Los dos procesos llegan a este print y lo ejecutan\n");

	return (0);
}
