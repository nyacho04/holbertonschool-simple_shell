#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *srch_path(char *line)
{
        // Variable para getenv
        char *path;
        // Variable para strtok
        char *dir;
        // Variable para sprintf
        char *fl_route = malloc(sizeof(char) * 1024);
        // Variable para stat
        struct stat st;

        if (fl_route == NULL)
        {
                perror("Malloc failed");
                free(fl_route);
                return (NULL);
        }

        path = getenv("PATH"); // Consigo todos los directorios del PATH
        dir = strtok(path, ":"); // Identifico cada directorio separado por ":"

        while (dir != NULL)
        {
                sprintf(fl_route, "%s/%s", dir, line);
                if (stat(fl_route, &st) == 0)         // Se verifica si existe el archivo en cada ruta que se encuentra en PHAT
                {
                        return (fl_route);
                }
                dir = strtok(NULL, ":");
        }
        return (NULL);
}

int main(void)
{
	char *ruta,*line = "ls";

	ruta = srch_path(line);

	printf("%s\n", ruta);
	return 0;
}
