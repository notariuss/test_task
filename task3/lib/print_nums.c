#include "mprintf.h"

char	*my_itoa_long(long long int n)
{
	char	*number;
	int		digits;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	digits = (int)my_nbrlen(n);
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

size_t	print_decimal(t_argfmt arg_fmt, va_list ap)
{
	int				count;
	char			*str;
	long long int	nbr;

	if (arg_fmt.flags & LONGLONG)
		nbr = va_arg(ap, long long int);
	else if (arg_fmt.flags & LONG_)
		nbr = va_arg(ap, long int);
	else
		nbr = va_arg(ap, int);
	str = my_itoa_long(nbr);
	count = my_nbrlen(nbr);
	if (arg_fmt.precision != -1 && arg_fmt.precision < count)
		count = (size_t)arg_fmt.precision;
	if (arg_fmt.flags & MINUS)
		write(1, str, (size_t)count);
	while (arg_fmt.width > count)
	{
		write(1, " ", 1);
		arg_fmt.width--;
	}
	if (!(arg_fmt.flags & MINUS))
		write(1, str, (size_t)count);
	free(str);
	return (count);
}
