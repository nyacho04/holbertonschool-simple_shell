#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
extern char **environ;

char *srch_path(char *line,char * argv0);
char *flags_process(char *line);
char *execute(char *pointer);
int is_interactive(void);

#endif
