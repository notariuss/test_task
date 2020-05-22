#include "lib.h"

static int		my_nbr_digits_base(int n, int base)
{
	int	i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

char			*my_itoa_base(int nbr, char const *base_str)
{
	char	*number;
	int		sign;
	int		nbr_digits;
	int		base;

	sign = 0;
	if (nbr < 0)
		sign = 1;
	base = (unsigned int)my_strlen(base_str);
	nbr_digits = my_nbr_digits_base(nbr, base);
	number = my_strnew(base + sign);
	if (sign)
		*number = '-';
	while (nbr_digits)
	{
		if (nbr < 0)
			*(number + (nbr_digits--)) = base_str[-(nbr % base)];
		else
			*(number + (nbr_digits--) - 1) = base_str[nbr % base];
		nbr /= base;
	}
	return (number);
}
