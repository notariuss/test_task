#include "lib.h"

char	*my_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tmp;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			tmp = needle;
			while (*haystack == *tmp && *tmp && *haystack && len)
			{
				haystack++;
				tmp++;
				len--;
			}
			if (!(*tmp))
				return ((char*)(haystack - (tmp - needle)));
			len += tmp - needle;
			haystack = (const char*)(haystack - (tmp - needle));
		}
		len--;
		haystack++;
	}
	return (NULL);
}
