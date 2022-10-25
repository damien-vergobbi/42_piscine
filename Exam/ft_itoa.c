#include <stdio.h>
#include <stdlib.h>

int ft_nb_len(int nb)
{
    int count;

    count = 0;
    if (nb < 0)
        nb *= -1;
    if (nb == 0)
        return (1);
    while(nb > 0)
    {
        nb /= 10;
        count++;
    }
    return (count);
}

char    *ft_print_pos(int nb, int len)
{
    char    *str;

    str = malloc(len + 1 * sizeof(char));
    str[len] = '\0';
    while (--len >= 0)
    {
        str[len] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}

char    *ft_print_neg(int nb, int len)
{
    char    *str;

    str = malloc(len + 1 * sizeof(char));
    str[len + 1] = '\0';
    str[0] = '-';
    while (--len > 0)
    {
        str[len] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}


char    *ft_itoa(int nb)
{
    char    *str;
    int     len;

    len = ft_nb_len(nb);
    if (nb == -2147483648)
        return ("-2147483648");
    if (nb < 0)
        len++;
    str = malloc(len + 1 * sizeof(char));
    if (nb >= 0)
        str = ft_print_pos(nb, len);
    else
        str = ft_print_neg(-nb, len);
    return (str);
}

int main (void)
{
    printf("%s\n", ft_itoa(2147483647));
}