#include "lib.h"

char	*my_strrchr(const char *s, int c)
{
	int	len;

	len = my_strlen(s) + 1;
	while (--len >= 0)
		if (s[len] == (char)c)
			return ((char*)(s + len));
	return (NULL);
}
