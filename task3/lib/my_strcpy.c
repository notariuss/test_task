#include "lib.h"

char	*my_strcpy(char *dst, const char *src)
{
	char *tmp;

	tmp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (tmp);
}
