#include "main.h"
/**
 * flags_process - Processes the flags in the string ignoring the first token
 * @pointer: A pointer to the string to process
 * Return: A pointer to the string without the first token
 */

char *flags_process(char *pointer)
{
	char *token, *buffer, *cpy;
	int track = 0, frst_tok = 1;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';

	cpy = strdup(pointer);
	if (cpy == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (token = strtok(cpy, " "); token != NULL; token = strtok(NULL, " "))
	{
		if (frst_tok)
		{
			frst_tok = 0;
			continue;
		}
		if (track > 0)
			track += sprintf(buffer + track, " ");

		track += sprintf(buffer + track, "%s", token);
	}
	free(cpy);
	return (buffer);
}
