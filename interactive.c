#include "main.h"
/**
 * is_interactive - Checks if the shell is interactive
 * @void: void
 * Return: 1 if interactive, 0 if not
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}
