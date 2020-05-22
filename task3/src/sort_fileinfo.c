#include "my_ls.h"

static void	fileinfo_swap(t_fileinfo *f1, t_fileinfo *f2)
{
	int	tmp;

	tmp = f1->error;
	f1->error = f2->error;
	f2->error = tmp;
	my_ptr_swap((void**)&(f1->lnk), (void**)&(f2->lnk));
	my_ptr_swap((void**)&(f1->name), (void**)&(f2->name));
	my_ptr_swap((void**)&(f1->finfo), (void**)&(f2->finfo));
}

int			sort_time(t_fileinfo *f1, t_fileinfo *f2)
{
	if (((f2->finfo)->st_mtimespec.tv_sec -
		(f1->finfo)->st_mtimespec.tv_sec) == 0)
	{
		if (((f2->finfo)->st_mtimespec.tv_nsec -
			(f1->finfo)->st_mtimespec.tv_nsec) == 0)
			return (my_strcmp(f1->name, f2->name));
		return ((f2->finfo)->st_mtimespec.tv_nsec -
			(f1->finfo)->st_mtimespec.tv_nsec);
	}
	return ((f2->finfo)->st_mtimespec.tv_sec -
		(f1->finfo)->st_mtimespec.tv_sec);
}

int			sort_alpha(t_fileinfo *f1, t_fileinfo *f2)
{
	return (my_strcmp(f1->name, f2->name));
}

void	files_reverse(t_fileinfo **files)
{
	t_fileinfo *head;
	t_fileinfo *future_next;
	t_fileinfo *tmp;
	t_fileinfo *tmp2;

	head = *files;
	future_next = NULL;
	while (head->next)
	{
		tmp = head;
		tmp2 = head->next;
		head->next = future_next;
		future_next = tmp;
		head = tmp2;
	}
	head->next = future_next;
	*files = head;
}

void		sort(t_fileinfo *files, int (*f)(t_fileinfo *, t_fileinfo *))
{
	int			sorted;
	t_fileinfo	*current;
	t_fileinfo	*next;

	sorted = 0;
	while (!sorted)
	{
		current = files;
		sorted = 1;
		while (current && current->next)
		{
			next = current->next;
			if (f(current, next) > 0)
			{
				fileinfo_swap(current, next);
				sorted = 0;
			}
			current = current->next;
		}
	}
}
