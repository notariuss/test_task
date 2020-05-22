#include "lib.h"

void	my_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = 0;
}
