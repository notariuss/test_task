#include "mprintf.h"

int	print_string(t_argfmt arg_fmt, va_list ap)
{
	char	*ptr;
	int		len;

	ptr = va_arg(ap, char*);
	len = (int)my_strlen(ptr);
	if (arg_fmt.precision != -1 && arg_fmt.precision < len)
		len = arg_fmt.precision;
	if (arg_fmt.flags & MINUS)
		write(1, ptr, (size_t)len);
	while (arg_fmt.width > len)
	{
		write(1, " ", 1);
		arg_fmt.width--;
	}
	if (!(arg_fmt.flags & MINUS))
		write(1, ptr, (size_t)len);
	return (len);
}
