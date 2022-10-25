#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_check(char *s, char c, int pos)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c && i < pos)
            return (0);
        i++;
    }
    return (1);
}

void    ft_union(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i])
    {
        if (ft_check(s1, s1[i], i))
            ft_putchar(s1[i]);
        i++;
    }
    i = 0;
    while (s2[i])
    {
        if (ft_check(s1, s2[i], ft_strlen(s1)) && ft_check(s2, s2[i], i))
            ft_putchar(s2[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    return (0);
}