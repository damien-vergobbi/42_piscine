#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strslen(char **strs, int size)
{
    int i;
    int a;

    i = 0;
    a = 0;
    while (i < size)
    {
        a += ft_strlen(strs[i]);
        i++;
    }
    return (a);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *str;
    int     i;
    int     j;
    int     k;

    str = malloc((ft_strslen(strs, size)
        + (ft_strlen(sep) * (size - 1))) * sizeof(char));
    if (str == 0)
        return (0);
    i = 0;
    k = 0;
    j = -1;
    while (i < size)
    {
        while (strs[i][k])
        {
            str[++j] = strs[i][k];
            k++;
        }
        k = 0;
        if (i < size - 1 && ft_strlen(strs[i]) > 0)
        {
            while (sep[k])
            {
                str[++j] = sep[k];
                k++;
            }
        }
        k = 0;
        i++;
    }
    str[++j] = '\0';
    
    return (str);
}