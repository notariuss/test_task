#include "lib.h"

void				my_free_tab(char **tab)
{
	void	*tmp;

	while (*tab)
	{
		tmp = *tab++;
		free(tmp);
	}
	*tab = NULL;
}
