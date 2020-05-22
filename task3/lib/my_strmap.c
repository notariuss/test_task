#include "lib.h"

char	*my_strmap(char const *s, char (*f)(char))
{
	size_t	str_len;
	char	*str;

	str = NULL;
	if (s && f)
	{
		str_len = my_strlen(s);
		if ((str = (char*)malloc(sizeof(char) * (str_len + 1))) && str_len)
		{
			while (*s)
				*str++ = f(*s++);
			*str = 0;
			return (str - str_len);
		}
	}
	return (str);
}
