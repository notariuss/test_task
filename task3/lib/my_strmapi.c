#include "lib.h"

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	size_t	i;
	char	*str;

	str = NULL;
	if (s)
	{
		str_len = 0;
		i = 0;
		while (s[str_len])
			str_len++;
		if ((str = (char*)malloc(sizeof(char) * (str_len + 1))) && str_len)
		{
			str[str_len] = 0;
			while (i < str_len)
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
