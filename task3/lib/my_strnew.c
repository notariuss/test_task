#include "lib.h"

char	*my_strnew(size_t size)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = str;
	if ((str = malloc(sizeof(char) * (size + 1))) != NULL)
	{
		tmp = str;
		while (size-- > 0)
			*str++ = 0;
		*str = 0;
	}
	return (tmp);
}
