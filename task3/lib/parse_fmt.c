#include "mprintf.h"

int			check_flag(const char *restrict fmt, t_argfmt *arg_fmt)
{
	arg_fmt->flags |= ((*fmt == '*') ? STAR : 0);
	arg_fmt->flags |= ((*fmt == '-') ? MINUS : 0);
	arg_fmt->flags |= ((*fmt == '+') ? PLUS : 0);
	arg_fmt->flags |= ((*fmt == ' ') ? SPACE : 0);
	arg_fmt->flags |= ((*fmt == '#') ? SHARP : 0);
	arg_fmt->flags |= ((*fmt == '0') ? ZERO : 0);
	arg_fmt->flags |= ((*fmt == 'z') ? SIZET : 0);
	arg_fmt->flags |= ((*fmt == 'j') ? INTMAX : 0);
	arg_fmt->flags |= ((*fmt == 'l' && (arg_fmt->type & LONG_)) ? LONGLONG : 0);
	arg_fmt->flags |= ((*fmt == 'l') ? LONG_ : 0);
	arg_fmt->flags |= ((*fmt == 'h' && (arg_fmt->type & SHORT_))
		? SHORTSHORT : 0);
	arg_fmt->flags |= ((*fmt == 'h') ? SHORT_ : 0);
	return (0);
}

int			check_type(char c, t_argfmt *arg_fmt)
{
	if (c == 's')
		arg_fmt->type = STRING;
	else if (c == 'd')
		arg_fmt->type = DECIMAL;
	else
		return (1);
	arg_fmt->fmt_len += 1;
	return (0);
}

void		parse_fmt(t_argfmt *arg_fmt, const char *restrict fmt)
{
	while (check_type(*fmt, arg_fmt))
	{
		if (*fmt >= '0' && *fmt <= '9')
		{
			arg_fmt->width = my_atoi(fmt);
			fmt += my_nbrlen((long long int)arg_fmt->width);
			arg_fmt->fmt_len += my_nbrlen((long long int)arg_fmt->width);
		}
		else if (*fmt == '.')
		{
			arg_fmt->precision = my_atoi(fmt + 1);
			fmt += my_nbrlen((long long int)arg_fmt->precision) + 1;
			arg_fmt->fmt_len +=
			my_nbrlen((long long int)arg_fmt->precision) + 1;
		}
		else
		{
			check_flag(fmt, arg_fmt);
			arg_fmt->fmt_len += 1;
			fmt++;
		}
	}
}

t_argfmt	handle_fmt(const char *restrict fmt)
{
	t_argfmt	arg_fmt;

	my_bzero(&arg_fmt, sizeof(t_argfmt));
	arg_fmt.precision = -1;
	parse_fmt(&arg_fmt, fmt);
	return (arg_fmt);
}
