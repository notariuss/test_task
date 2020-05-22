#include "lib.h"

size_t	my_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		d_len;

	s = src;
	d = dst;
	d_len = 0;
	while (*dst++ && dstsize)
	{
		d_len++;
		dstsize--;
	}
	if (!dstsize)
		return (d_len + my_strlen(src));
	while (*s)
		if (dstsize - 1)
		{
			*((d++) + d_len) = *s++;
			dstsize--;
		}
		else
			s++;
	*(d + d_len) = 0;
	return (d_len + (s - src));
}
