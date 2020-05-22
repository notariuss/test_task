#ifndef MPRINTF_H
# define MPRINTF_H
# include "lib.h"
# include <stdarg.h>

typedef enum	e_types
{
	string,
	STRING,
	pointer,
	decimal,
	DECIMAL,
	INTEGER,
	octal,
	OCTAL,
	unsigned_,
	U,
	x,
	X,
	char_,
	C
}				t_types;

typedef struct	s_argfmt
{
	int			flags;
	int			width;
	int			precision;
	int			fmt_len;
	t_types		type;
}				t_argfmt;

# define STAR 1
# define MINUS 4
# define PLUS 8
# define SPACE 16
# define SHARP 32
# define ZERO 64
# define SHORT_ 128
# define SHORTSHORT 256
# define LONG_ 512
# define LONGLONG 1024
# define INTMAX 2048
# define SIZET 4096

int				mprintf(const char *restrict format, ...);
t_argfmt		handle_fmt(const char *restrict fmt);
size_t			print_decimal(t_argfmt arg_fmt, va_list ap);
int				print_string(t_argfmt arg_fmt, va_list ap);

#endif
