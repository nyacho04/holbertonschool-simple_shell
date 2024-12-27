#include "nashell.h"

/**
 * flags_process - Processes the flags in the string ignoring the first token
 * @pointer: The pointer to the string
 *
 * Return: The flags
 */

char *flags_process(char *pointer)
{
	char *token, *buffer, *cpy;
	int track = 0, frst_tok = 1;

	buffer = calloc(1024, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	cpy = strdup(pointer);
	if (cpy == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (token = strtok(cpy, " \t"); token != NULL; token = strtok(NULL, " \t"))
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
