#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL; // Buffer donde se almacena la direccion de la string
	size_t len = 0; // Tamaño de la string, se adapta solo
	ssize_t result;

	while (result != -1)
	{
		printf("$ ");
		result = getline(&line, &len, stdin); // stdin se refiere a "de donde saca la string", del standar input

	if (result > 1)
		printf("$ %s",line);
	}
	free(line);

	return (0);
}
