#include "mprintf.h"

size_t	print_arg(t_argfmt arg_fmt, va_list ap)
{
	if (arg_fmt.flags & STAR)
		arg_fmt.width = va_arg(ap, int);
	if (arg_fmt.type == DECIMAL)
		return ((size_t)print_decimal(arg_fmt, ap));
	if (arg_fmt.type == STRING)
		return ((size_t)print_string(arg_fmt, ap));
	return (0);
}

int		mprintf(const char *restrict format, ...)
{
	va_list		ap;
	t_argfmt	arg_fmt;
	int			count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			arg_fmt = handle_fmt(format + 1);
			format += arg_fmt.fmt_len + 1;
			count += print_arg(arg_fmt, ap);
		}
		else
			write(1, format++, 1);
	}
	va_end(ap);
	return (count);
}
