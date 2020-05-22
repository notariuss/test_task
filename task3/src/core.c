#include "my_ls.h"

static void				print_files(t_entriesinfo *files, t_params params)
{
	t_fileinfo	*flist;

	if (files->list)
		sort(files->list, &sort_alpha);
	flist = files->list;
	while (flist)
	{
		if (flist->error)
			print_name(flist, files, params);
		flist = flist->next;
	}
	if (files->list)
		sort_files(&(files->list), params);
	flist = files->list;
	while (flist)
	{
		if (!(flist->error))
			print_name(flist, files, params);
		flist = flist->next;
	}
}

static void				display_entries(t_fileinfo *dirs,
	t_entriesinfo *files, t_params params)
{
	t_fileinfo	*tmp;

	print_files(files, params);
	if (params.filesdirs)
		printf("\n");
	tmp = dirs;
	while (tmp)
	{
		display_dir(tmp, params);
		if (tmp->next && !(tmp->error))
			printf("\n");
		tmp = tmp->next;
	}
	free_flst(dirs);
	if (files)
	{
		free_flst(files->list);
		free(files);
	}
}

static t_entriesinfo	*get_files_entries(char **entries_paths)
{
	t_fileinfo		*flist;
	t_fileinfo		*tmp;
	t_entriesinfo	*einfo;

	flist = NULL;
	einfo = init_entriesinfo();
	while (*entries_paths)
	{
		if ((tmp = init_fileinfo(NULL, *entries_paths))
			&& !S_ISDIR((tmp->finfo)->st_mode))
		{
			fileadd(&flist, tmp);
			check_max_len(tmp, einfo);
		}
		else if (tmp)
			free_finfo(tmp);
		entries_paths++;
	}
	einfo->list = flist;
	return (einfo);
}

static t_fileinfo		*handle_input_entries(char **paths, t_params *params)
{
	t_fileinfo	*f_info;
	t_fileinfo	*t;
	int			ds;
	int			fs;

	ds = 0;
	fs = 0;
	f_info = NULL;
	while (*paths)
	{
		if ((t = init_fileinfo(NULL, *paths)) && t
			&& t->error == 0)
		{
			ds += S_ISDIR(((struct stat*)(t->finfo))->st_mode);
			fs += !S_ISDIR(((struct stat*)(t->finfo))->st_mode);
		}
		else
			fs += 1;
		(S_ISDIR(((struct stat*)(t->finfo))->st_mode))
		? fileadd(&f_info, t) : free_finfo(t);
		paths++;
	}
	params->filesdirs = (ds && fs) ? 1 : 0;
	params->mult = (ds > 1) ? 1 : 0;
	return (f_info);
}

void					core(char **entries_paths, t_params params)
{
	t_fileinfo		*dirs;
	t_entriesinfo	*files;

	if (*entries_paths == NULL)
	{
		display_dir((dirs = init_fileinfo(NULL, ".")), params);
		free_finfo(dirs);
	}
	else
	{
		dirs = handle_input_entries(entries_paths, &params);
		if (dirs)
			sort_files(&dirs, params);
		files = get_files_entries(entries_paths);
		display_entries(dirs, files, params);
	}
}
