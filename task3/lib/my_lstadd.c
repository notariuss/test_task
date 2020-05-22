#include "lib.h"

void	my_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
