#include "lib.h"

void	*my_bzero(void *s, size_t n)
{
	void	*tmp;

	tmp = s;
	while (n-- > 0)
		*((unsigned char*)s++) = '\0';
	return (tmp);
}
