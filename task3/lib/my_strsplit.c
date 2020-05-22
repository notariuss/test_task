#include "lib.h"

static unsigned int	dc(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t		elem_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char				**my_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	char	*tmp;
	char	**tmp_tab;

	if (!s || !(tab = (char**)malloc(sizeof(char*) * (dc(s, c) + 1))))
		return (NULL);
	tmp_tab = tab;
	while (*s)
	{
		if (*s != c)
		{
			str = (char*)malloc(sizeof(char) + (elem_len(s, c) + 1));
			tmp = str;
			while (*s != c && *s)
				*str++ = *s++;
			*str = 0;
			*tab++ = tmp;
			--s;
		}
		s++;
	}
	*tab = NULL;
	return (tmp_tab);
}
