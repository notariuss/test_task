#include "lib.h"

void	*my_memalloc(size_t size)
{
	void	*ptr;
	void	*tmp;

	ptr = NULL;
	tmp = ptr;
	if ((ptr = malloc(size)))
	{
		tmp = ptr;
		while (size--)
			*(unsigned char*)ptr++ = 0;
	}
	return (tmp);
}
