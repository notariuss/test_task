#include "lib.h"

void	*my_memccpy(void *restrict dst,
		const void *restrict src,
		int c,
		size_t n)
{
	while (n--)
		if ((*(unsigned char*)dst++ = *(unsigned char*)src++)
				== (unsigned char)c)
			return (dst);
	return (NULL);
}
