#include "my_ls.h"

static void				print_dir(t_entriesinfo *files, char *path,
	t_params params)
{
	t_fileinfo	*lst;

	if (params.mult || params.filesdirs)
		printf("%s:\n", path);
	if (params.longformat)
		printf("total %d\n", files->total);
	lst = files->list;
	while (lst)
	{
		print_name(lst, files, params);
		lst = lst->next;
	}
}

static t_entriesinfo	*handledirectory(char *path, t_params params)
{
	DIR				*dir;
	struct dirent	*dp;
	t_entriesinfo	*einfo;
	t_fileinfo		*files;

	files = NULL;
	einfo = init_entriesinfo();
	if ((dir = opendir(path)))
	{
		while ((dp = readdir(dir)))
			if ((dp->d_name[0] == '.' && params.hiden) || dp->d_name[0] != '.')
			{
				fileadd(&files, init_fileinfo(path, dp->d_name));
				einfo->total += (files->finfo)->st_blocks;
				check_max_len(files, einfo);
			}
		einfo->list = files;
		closedir(dir);
	}
	else if (einfo)
		einfo->error = errno;
	return (einfo);
}

static void				recursive_dir(char *current_path,
	t_params params, t_fileinfo *files)
{
	char			*tmp;

	while (files)
	{
		if (!(files->error) && S_ISDIR(((struct stat*)(files->finfo))->st_mode)
			&& (files->name[0] != '.' || (files->name[0] == '.'
				&& params.hiden && my_strcmp(files->name, ".")
				&& my_strcmp(files->name, ".."))))
		{
			printf("\n%s:\n", (tmp = pjoin(current_path, files->name)));
			free(files->name);
			files->name = tmp;
			display_dir(files, params);
		}
		files = files->next;
	}
}

void					display_dir(t_fileinfo *dir_info, t_params params)
{
	t_entriesinfo	*dir_files;

	dir_files = handledirectory(dir_info->name, params);
	if (dir_files->list)
		sort_files(&(dir_files->list), params);
	print_dir(dir_files, dir_info->name, params);
	if (params.recursive)
		recursive_dir(dir_info->name, params, dir_files->list);
	free_flst(dir_files->list);
	free(dir_files);
}
