#include "my_ls.h"

void			free_finfo(t_fileinfo *f)
{
	if (f->name)
		free(f->name);
	if (f->lnk)
		free(f->lnk);
	if (f->finfo)
		free(f->finfo);
	free(f);
}

int				fileadd(t_fileinfo **begin, t_fileinfo *elem)
{
	t_fileinfo	*tmp;

	if (!elem)
		return (1);
	tmp = *begin;
	*begin = elem;
	(*begin)->next = tmp;
	return (0);
}

t_entriesinfo	*init_entriesinfo(void)
{
	t_entriesinfo	*einfo;

	if ((einfo = (t_entriesinfo*)my_memalloc(sizeof(t_entriesinfo))))
	{
		einfo->width_group = 0;
		einfo->error = 0;
		einfo->total = 0;
		einfo->width_group = 0;
		einfo->width_size = 0;
		einfo->width_links = 0;
		einfo->list = NULL;
	}
	return (einfo);
}

char			*getlnkname(char *path, size_t sz)
{
	ssize_t	r;
	char	*lnkname;

	lnkname = (char*)my_memalloc(sz + 1);
	r = readlink(path, lnkname, sz + 1);
	lnkname[r] = '\0';
	return (lnkname);
}

t_fileinfo		*init_fileinfo(char *path, char *name)
{
	t_fileinfo	*finfo;
	struct stat	*file_stat;
	char		*tmp;

	finfo = NULL;
	file_stat = NULL;
	if ((finfo = (t_fileinfo*)my_memalloc(sizeof(t_fileinfo))) &&
		(file_stat = (struct stat*)my_memalloc(sizeof(struct stat))))
	{
		if (!lstat((tmp = pjoin(path, name)), file_stat))
		{
			finfo->lnk = (S_ISLNK(file_stat->st_mode)) ?
			getlnkname(tmp, file_stat->st_size) : NULL;
			finfo->error = 0;
		}
		else
			finfo->error = errno;
		if (!(finfo->name = my_strdup(name)))
			return (NULL);
		finfo->next = NULL;
		finfo->finfo = file_stat;
		free(tmp);
	}
	return (finfo);
}
