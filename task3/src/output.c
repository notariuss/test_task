#include "my_ls.h"

void		print_perms(mode_t ff)
{
	char	str[10];

	str[0] = (S_ISDIR(ff)) ? 'd' : '-';
	str[0] = (S_ISBLK(ff)) ? 'b' : str[0];
	str[0] = (S_ISCHR(ff)) ? 'c' : str[0];
	str[0] = (S_ISLNK(ff)) ? 'l' : str[0];
	str[0] = (S_ISFIFO(ff)) ? 'p' : str[0];
	str[0] = (S_ISSOCK(ff)) ? 's' : str[0];
	str[1] = (ff & S_IRUSR) ? 'r' : '-';
	str[2] = (ff & S_IWUSR) ? 'w' : '-';
	str[3] = (ff & S_IXUSR) ? 'x' : '-';
	str[4] = (ff & S_IRGRP) ? 'r' : '-';
	str[5] = (ff & S_IWGRP) ? 'w' : '-';
	str[6] = (ff & S_IXGRP) ? 'x' : '-';
	str[7] = (ff & S_IROTH) ? 'r' : '-';
	str[8] = (ff & S_IWOTH) ? 'w' : '-';
	str[9] = (ff & S_IXOTH) ? 'x' : '-';
	printf("%.10s", str);
}

void		print_time(time_t clock)
{
	char	*str;
	time_t	now;

	now = time(NULL);
	str = my_strdup(ctime(&clock));
	printf("%.3s", str + 4);
	if ((now) - clock < 16070400)
		printf("%.9s", str + 7);
	else
	{
		printf("%.3s", str + 7);
		printf(" %.5s", str + 19);
	}
	free(str);
}

void		print_name(t_fileinfo *f, t_entriesinfo *info, t_params params)
{
	if (f->error)
		raise_error(f->name, f->error);
	else if (params.longformat)
	{
		print_perms((f->finfo)->st_mode);
		mprintf("% *ld ", info->width_links + 2, ((f->finfo)->st_nlink));
		printf("%s  ", getpwuid((f->finfo)->st_uid)->pw_name);
		printf("%s", getgrgid((f->finfo)->st_gid)->gr_name);
		printf("% *ld ", (int)(info->width_group -
			my_strlen(getgrgid((f->finfo)->st_gid)->gr_name)
			+ info->width_size + 2), ((f->finfo)->st_size));
		print_time((f->finfo)->st_mtimespec.tv_sec);
		printf(" %s", f->name);
		if (f->lnk)
			printf(" -> %s", f->lnk);
		printf("\n");
	}
	else
		printf("%s\n", f->name);
}

void		sort_files(t_fileinfo **files, t_params params)
{
	if (params.tsort)
		sort(*files, &sort_time);
	else
		sort(*files, &sort_alpha);
	if (params.reverse)
		files_reverse(files);
}
