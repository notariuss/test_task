#include "lib.h"

char			*my_itoa(int n)
{
	char	*number;
	int		digits;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	digits = my_nbrlen(n);
	if (!(number = (char*)malloc(sizeof(char) * (sign + digits + 1))))
		return (NULL);
	number[digits + sign] = 0;
	if (sign)
		number[0] = '-';
	while (digits)
	{
		if (sign)
			number[digits + sign - 1] = -(n % 10) + 48;
		else
			number[digits + sign - 1] = (n % 10) + 48;
		n /= 10;
		digits--;
	}
	return (number);
}
