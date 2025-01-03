#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *srch_path(char *line);
char *flags_process(char *line);
char *exfowa(char *pointer);

#endif
