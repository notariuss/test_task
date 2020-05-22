#include "lib.h"

static t_list	*my_create_elem(void *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		new->content = content;
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}

t_list			*my_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_node;
	t_list	*new_lst;
	t_list	*begin_lst;

	begin_lst = NULL;
	if (f && lst)
	{
		tmp_node = f(lst);
		new_lst = my_create_elem(tmp_node->content, tmp_node->content_size);
		begin_lst = new_lst;
		lst = lst->next;
		while (lst)
		{
			tmp_node = f(lst);
			new_lst->next = my_create_elem(tmp_node->content,
					tmp_node->content_size);
			new_lst = new_lst->next;
			lst = lst->next;
		}
	}
	return (begin_lst);
}
