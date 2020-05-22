#include "lib.h"

int		my_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
		while (*s1 == *s2 && *s1 && *s2 && --n)
		{
			s1++;
			s2++;
		}
	else
		return (0);
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
