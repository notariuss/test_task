#include "my_ls.h"

void	free_flst(t_fileinfo *f)
{
	t_fileinfo	*tmp;

	while (f)
	{
		tmp = f;
		f = f->next;
		free_finfo(tmp);
	}
}

void	check_max_len(t_fileinfo *f, t_entriesinfo *e)
{
	long long int	n;

	if (e->width_size <= (n = my_nbrlen((f->finfo)->st_size)))
		e->width_size = n;
	if (e->width_links <= (n = my_nbrlen((f->finfo)->st_nlink)))
		e->width_links = n;
	if (e->width_group
		<= (n = my_strlen(getgrgid((f->finfo)->st_gid)->gr_name)))
		e->width_group = n;
	if (e->width_user <= (n = my_strlen(getpwuid((f->finfo)->st_uid)->pw_name)))
		e->width_user = n;
}

char	*pjoin(char *p1, char *p2)
{
	char	*np;
	int		len;

	if (!p1)
		return (my_strdup(p2));
	len = 0;
	len += my_strlen(p1);
	len += my_strlen(p2);
	np = (char*)malloc(sizeof(char) * (len + 2));
	my_bzero(np, len + 2);
	my_strcat(np, p1);
	my_strcat(np, "/");
	my_strcat(np, p2);
	return (np);
}

void	raise_error(char *file_name, int my_errno)
{
	dprintf(2, "my_ls: %s: %s\n", file_name, strerror(my_errno));
}

int		main(int argc, char **argv)
{
	t_params	params;

	argc = 1;
	init_params(&params);
	argv += cli(argv, &params) + argc;
	core(argv, params);
	return ((errno >= 1) ? 1 : 0);
}
