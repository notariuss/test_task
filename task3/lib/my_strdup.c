#include "lib.h"

char	*my_strdup(const char *s1)
{
	char	*nstr;
	char	*tmp;

	if (!(nstr = (char*)malloc(sizeof(char) * (my_strlen(s1) + 1))))
		return (NULL);
	tmp = nstr;
	if (tmp)
		while (*s1)
			*nstr++ = *s1++;
	*nstr = 0;
	return (tmp);
}
