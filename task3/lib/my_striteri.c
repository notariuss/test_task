void	my_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s && f)
	{
		i = -1;
		while (s[++i])
			f((unsigned int)i, (s + i));
	}
}
