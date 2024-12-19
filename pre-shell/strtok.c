#include <string.h>
#include <stdio.h>

int main(int ac, char **av) //av ingresa la string desde la terminal
{
	const char *delim = " "; // Son los delimitadores constantes que dividiran la string
	char *token;

//	for (token = strtok(av, delim); token != NULL; token = strtok(NULL, delim)
//	 	printf("%s\n", token);

	if (ac > 1) // Se asegura que haya mas argumentos (ac[1] es el nombre del ejecutable)
	{
		token = strtok(av[1], delim);
	
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, delim); 
		}
	}
	return (0);
}
