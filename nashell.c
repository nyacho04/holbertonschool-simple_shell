#include "nashell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
void display_prompt (void)
{
    printf("nashell$ ");
    fflush(stdout);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main (void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        display_prompt();
        read = getline(&line, &len, stdin);

        if (read == -1)
        {
            break;
        }
        if (line[0] == '\n')
        {
            continue;
        }
        printf("nashell$ %s", line);
        free(line);
        line = NULL;
        len = 0;
    }
        return (0);
}
