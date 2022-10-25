#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int long		a;

	a = nb;
	if (a < 0)
	{
		a = -a;
		ft_putchar('-');
	}
	if (a >= 10)
	{
		ft_putnbr (a / 10 );
		ft_putnbr (a % 10 );
	}
	else
		ft_putchar(a + 48);
}
