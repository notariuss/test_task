#include "lib.h"

void	*my_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*tmp;

	tmp = dst;
	while (n--)
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	return (tmp);
}
