#include "lib.h"

char	*my_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	while (len--)
		*dst++ = 0;
	return (tmp);
}
