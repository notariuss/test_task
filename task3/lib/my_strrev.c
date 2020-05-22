#include "lib.h"

void	my_strrev(char *str)
{
	int			i;
	int			len;
	char		c;

	len = (int)my_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = c;
		len--;
		i++;
	}
}
