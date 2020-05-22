#include "lib.h"

void	my_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (*alst && alst && del)
		while (*alst)
		{
			next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
}
