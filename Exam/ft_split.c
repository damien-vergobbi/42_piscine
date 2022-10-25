#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_check_charset(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (c == charset[i] || c == '\0')
            return (1);
        i++;
    }
    return (0);
}

char    **ft_split(char *str, char *charset)
{
    char    **tab;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    tab = malloc(ft_strlen(str));
    tab[0] = malloc(ft_strlen(str));
    while (str[i])
    {
        if (ft_check_charset(str[i], charset) && ft_strlen(tab[k]) > 0 && !ft_check_charset(str[i + 1], charset))
        {
            tab[k][j] = '\0';
            j = 0;
            k++;
            tab[k] = malloc(ft_strlen(str));
        }
        else if (!ft_check_charset(str[i], charset))
        {
            tab[k][j] = str[i];
            j++;
        }
        i++;
    }
    tab[k][j] = '\0';
    tab[++k] = 0;
    return (tab);
}