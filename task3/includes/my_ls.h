#ifndef MY_LS_H
# define MY_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <pwd.h>
# include <time.h>
# include "lib.h"
# include <sys/xattr.h>
# include "mprintf.h"

# define st_mtimespec st_mtim
# define MEMCHECK(x) if (!x) exit(2)

typedef struct			s_fileinfo
{
	int					error;
	char				*name;
	char				*lnk;
	struct stat			*finfo;
	struct s_fileinfo	*next;
}               		t_fileinfo;

typedef struct			s_entriesinfo
{
	int					error;
	int					total;
	int					width_group;
	int					width_size;
	int					width_links;
	int					width_user;
	t_fileinfo			*list;
}						t_entriesinfo;

typedef struct			s_params
{
	int					acces;
	int					recursive;
	int					longformat;
	int					hiden;
	int					reverse;
	int					tsort;
	int					mult;
	int					filesdirs;
}						t_params;

void					check_max_len(t_fileinfo *f, t_entriesinfo *e);
int						cli(char **argv, t_params *params);
void					sort_files(t_fileinfo **files, t_params params);
void					core(char **entries_paths, t_params params);
t_entriesinfo			*init_entriesinfo(void);
t_fileinfo				*init_fileinfo(char *path, char *name);
void					display_dir(t_fileinfo *dir_info, t_params params);
void					print_name(t_fileinfo *f, t_entriesinfo *info, t_params params);
void					free_finfo(t_fileinfo *f);
int						fileadd(t_fileinfo **begin, t_fileinfo *elem);
void					raise_error(char *file_name, int my_errno);
char					*pjoin(char *p1, char *p2);
void					sort(t_fileinfo *files,
	int (*f)(t_fileinfo *, t_fileinfo *));
int						sort_alpha(t_fileinfo *f1, t_fileinfo *f2);
void					free_flst(t_fileinfo *f);
void					init_params(t_params *params);
int						sort_time(t_fileinfo *f1, t_fileinfo *f2);
void					files_reverse(t_fileinfo **files);
#endif
