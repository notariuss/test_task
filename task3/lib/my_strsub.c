#include "lib.h"

char	*my_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if (!s)
		return (0);
	tmp = NULL;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		tmp = str;
		str[len] = 0;
		while (len--)
			*str++ = *((s++) + start);
	}
	return (tmp);
}
