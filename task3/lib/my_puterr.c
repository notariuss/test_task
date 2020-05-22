#include "lib.h"
#include <stdarg.h>

void	my_puterr(int n, char *str, ...)
{
	va_list ap;
	char	*ptr;

	va_start(ap, str);
	write(2, str, my_strlen(str));
	while ((n--) - 1)
	{
		ptr = va_arg(ap, char*);
		write(2, ptr, my_strlen(ptr));
	}
	va_end(ap);
}
