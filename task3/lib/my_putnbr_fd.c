#include "lib.h"

void	my_putnbr_fd(int n, int fd)
{
	char	str[1];

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			my_putnbr_fd(-(n / 10), fd);
			my_putnbr_fd(8, fd);
			return ;
		}
		my_putnbr_fd(-n, fd);
		return ;
	}
	str[0] = n % 10 + 48;
	if (n / 10)
		my_putnbr_fd(n / 10, fd);
	write(fd, str, 1);
}
