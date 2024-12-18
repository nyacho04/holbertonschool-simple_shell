#include <stdio.h>
#include <unistd.h>
int main(void)
{
	char *pathname = "/bin/ls";
	char *argv[] = {pathname,"/holbertonschool-simple_shell/pre-shell", NULL};
	char *envp[] = {NULL};

	if (execve(pathname, argv, envp) == -1)
	{
		perror("Error carrapito");
	}

	return (0);
}
