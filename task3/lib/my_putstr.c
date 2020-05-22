#include "lib.h"

void	my_putstr(char const *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}
