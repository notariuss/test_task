#include "lib.h"

void	my_putnbr(int n)
{
	char	str[1];

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			my_putnbr(-(n / 10));
			my_putnbr(8);
			return ;
		}
		my_putnbr(-n);
		return ;
	}
	str[0] = n % 10 + 48;
	if (n / 10)
		my_putnbr(n / 10);
	write(1, str, 1);
}
