#include "../include/cub3d.h"


void    ft_free_array(char ***s)//mandar con &
{
    int i;
    i = 0;
    if (*s)
    {
        while ((*s)[i])
            free((*s)[i++]);
        free (*s);
    }
    *s = NULL;
}