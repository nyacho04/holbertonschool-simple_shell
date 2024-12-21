#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
void execute_command(char *line)
{
    char *args[100];
    char *nya;
    int i = 0;

    nya = strtok(line, " \n");
    while (nya != NULL)
    {
        args[i++] = nya;
        nya = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (args[0] == NULL)
    {
        return;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    if (fork() == 0)
    {
        execvp(args[0], args);
        perror(args[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
    wait(NULL);
    }
}