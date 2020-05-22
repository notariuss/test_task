#include "lib.h"

void	*my_memchr(const void *s, int c, size_t n)
{
	while (n && *(unsigned char*)s != (unsigned char)c)
	{
		n--;
		s++;
	}
	if (!n)
		return (NULL);
	return ((void*)s);
}
