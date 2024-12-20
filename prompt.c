#include "nashell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
    printf("nashell$ ");
    fflush(stdout);
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
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
        printf("funca %s", line);
        free(line);
        line = NULL;
    }

    return (0);
}