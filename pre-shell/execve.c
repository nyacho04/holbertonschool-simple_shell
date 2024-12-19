#include <stdio.h>
#include <unistd.h>
int main(int ac __attribute__((unused)), char **av)
{
	char *pathname = "/bin/ls";
	//char *argv[] = {pathname, av, NULL};
	char *envp[] = {NULL};

	if (execve(pathname, av, envp) == -1)
	{
		perror("Error carrapito");
	}

	return (0);
}
