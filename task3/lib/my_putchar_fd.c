#include "lib.h"

void	my_putchar_fd(char c, int fd)
{
	if (c >= 0 && fd >= 0)
		write(fd, &c, 1);
	return ;
}
