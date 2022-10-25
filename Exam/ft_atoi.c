int ft_atoi(char *str)
{
	int	i;
	int	ret;
	int	neg;

	i = 0;
	ret = 0;
	neg = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
        || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return (ret * neg);
}

int main(void)
{
	printf("%d\n", ft_atoi(" \t\n\v ----+-2147483648"));
}