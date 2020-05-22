#include "lib.h"

char	*my_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t	dest_len;
	size_t	tmp_n;

	tmp_n = 0;
	dest_len = my_strlen(dest);
	while (*src && n--)
	{
		tmp_n++;
		*((dest++) + dest_len) = *src++;
	}
	*(dest + dest_len) = 0;
	return (dest - tmp_n);
}
