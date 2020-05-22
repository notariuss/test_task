#include "lib.h"

char	*my_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char*)--s);
	if (*s == 0 && !(char)c)
		return ((char*)s);
	return (NULL);
}
