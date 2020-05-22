#include "lib.h"

int	my_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
		while (n-- && *(unsigned char*)s1++ == *(unsigned char*)s2++)
			;
	else
		return (0);
	return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
}
