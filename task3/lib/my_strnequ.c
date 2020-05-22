#include "lib.h"

int		my_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && n)
		{
			if (*s1 != *s2)
				break ;
			s1++;
			s2++;
			n--;
		}
	}
	else
		return (0);
	if (n)
		return ((*s1 - *s2) == 0);
	else
		return (1);
}
