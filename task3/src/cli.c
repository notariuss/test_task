#include "my_ls.h"

void	usage(char unknown_param)
{
	printf("ls: illegal option - %c\n", unknown_param);
	printf("usage: ls [-Ralrt] [file ...]\n");
	exit(1);
}

void	init_params(t_params *params)
{
	params->longformat = 0;
	params->recursive = 0;
	params->hiden = 0;
	params->reverse = 0;
	params->tsort = 0;
	params->mult = 0;
	params->filesdirs = 0;
}

int		cli(char **argv, t_params *params)
{
	int		i;
	char	*tmp;

	i = 1;
	while ((tmp = *(argv + i)) && **(argv + i) == '-')
	{
		while (*(++tmp))
		{
			if (*tmp == 'l')
				params->longformat = 1;
			else if (*tmp == 'R')
				params->recursive = 1;
			else if (*tmp == 'a')
				params->hiden = 1;
			else if (*tmp == 'r')
				params->reverse = 1;
			else if (*tmp == 't')
				params->tsort = 1;
			else
				usage(*tmp);
		}
		i++;
	}
	return (i - 1);
}
