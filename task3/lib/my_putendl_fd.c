#include "lib.h"

void	my_putendl_fd(char const *s, int fd)
{
	if (s && fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}
