#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t result;

	printf("$ ");

	result = getline(&line, &len, stdin);

	if (result == -1)
	{
		printf("error");
		free(line);
		return (1);
	}
	
	printf("%s",line);
	free(line);

	return (0);
}
