#include "lib.h"

char	*my_strstr(const char *haystack, const char *needle)
{
	const char	*tmp;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tmp = needle;
			while (*haystack == *tmp && *tmp && *haystack)
			{
				haystack++;
				tmp++;
			}
			if (!(*tmp))
				return ((char*)(haystack - (tmp - needle)));
			haystack = (const char*)(haystack - (tmp - needle));
		}
		haystack++;
	}
	return (NULL);
}
