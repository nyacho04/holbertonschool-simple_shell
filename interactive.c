#include "main.h"

int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}
