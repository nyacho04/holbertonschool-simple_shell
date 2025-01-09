#include "main.h"
/**
 * main - Entry point
 * @void: No arguments
 * Return: 0 on success
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *line = NULL, *route = NULL, *flags = NULL;
	size_t len = 0;
	ssize_t result = 0;
	int st = 0;

	while (result != -1)
	{
		if (is_interactive())
		{
		printf("nashell$ ");
		fflush(stdout);
		}
		result = getline(&line, &len, stdin);
		if (result == -1)
			break;
		if (strcmp(line, "exit\n") == 0)
			break;
		if (result > 0 && line[result - 1] == '\n')
			line[result - 1] = '\0';

		if (strcmp(line, "env") == 0)
		{
			char **env;

			for (env = environ; *env != NULL; env++)
				printf("%s\n", *env);
			continue;
		}
		if (result > 1)
		{
			route = srch_path(line, argv[0], &st);
			flags = flags_process(line);
			
			if (route == NULL)
			{
				free(line);
				line = NULL;
				free(flags);
				flags = NULL;
				continue;
			}
			if (flags != NULL)
			{
				char *rut_and_flgs;

				rut_and_flgs = malloc(BUFFER_SIZE);
				if (rut_and_flgs == NULL)
				{
					free(line);
					free(route);
					free(flags);
					return (-1);
				}
				
				sprintf(rut_and_flgs, "%s %s", route, flags);
				execute(rut_and_flgs);
				free(rut_and_flgs);
			}
			else
				if (execute(route) == NULL)
					st = 2;

			free(route);
			route = NULL;
			free(flags);
			flags = NULL;
		}
	};
	free(line);
	return (st);
}
