#include "lib.h"

t_list	*my_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list)))
		|| !(list->content = (void*)my_memalloc(content_size)))
		return (NULL);
	if (content != NULL)
	{
		list->content_size = content_size;
		my_memcpy(list->content, content, content_size);
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
