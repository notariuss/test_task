long int					my_nbrlen(long long int n)
{
	long int	i;

	i = 1;
	while ((n /= 10))
		i++;
	return (i);
}
