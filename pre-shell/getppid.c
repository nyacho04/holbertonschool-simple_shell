#include <stdio.h>
#include <unistd.h>

/**
 * main - Parent Process ID
 *
 * Return: zero
 */

int main (void)
{
	pid_t parent_pid;

	parent_pid = getppid();
	printf("%u\n", parent_pid);
	return (0);
}
