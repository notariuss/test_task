#include "lib.h"

void	*my_memset(void *b, int c, size_t len)
{
	void	*tmp;

	tmp = b;
	while (len-- > 0)
		*((unsigned char*)b++) = c;
	return (tmp);
}
