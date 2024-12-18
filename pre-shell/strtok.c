#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	const char *delim = " ";
	char *token;

//	for (token = strtok(av, delim); token != NULL; token = strtok(NULL, delim)
//	 	printf("%s\n", token);

	if (ac > 1)
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
