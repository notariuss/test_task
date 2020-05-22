#include "lib.h"

char	*my_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	size_t	s1_len;

	s1_len = my_strlen(s1);
	i = -1;
	while (s2[++i])
		s1[s1_len + i] = s2[i];
	s1[s1_len + i] = 0;
	return (s1);
}
