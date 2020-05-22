#include "lib.h"

void	*my_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = dst;
	if (src < dst)
		while (len--)
			*((unsigned char*)(dst + len)) = *((unsigned char*)(src + len));
	else
		my_memcpy(dst, src, len);
	return (tmp);
}
