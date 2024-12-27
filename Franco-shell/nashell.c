#include "nashell.h"

/**
 *
 *
 */

int main(void)
{
	char *line = NULL, *route;
	size_t len = 0;
	ssize_t result = 0;

	while (result != -1)
	{
		printf("nashell$ ");
		result = getline(&line, &len, stdin);
		if (result == -1)
			break;
		if (strcmp(line, "exit\n") == 0)
			break;
		if (result > 0 && line[result - 1] == '\n')
			line[result - 1] = '\0';
		if (result > 1)
		{
			route = srch_path(line);
			printf("%s\n", route);
			free(route);
		}
	}
	free(line);
	return (0);
}
