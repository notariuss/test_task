#include "lib.h"

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;

	if (!(s1) || !(s2))
		return (NULL);
	str = (char*)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	if (!(str))
		return (NULL);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = 0;
	return (tmp);
}
