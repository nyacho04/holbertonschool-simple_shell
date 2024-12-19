#include <stdio.h>

/**
 * main - Print array's arguments
 *
 * Return: void
 */

int main (int ac, char **av) // **av es un puntero a un puntero char que se ingresa al escribir junto al ejecutable al momento de ejecutar
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
