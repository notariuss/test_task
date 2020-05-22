int		my_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1 && *s2)
		{
			if (*s1 != *s2)
				break ;
			s1++;
			s2++;
		}
		return ((*s1 - *s2) == 0);
	}
	return (0);
}
