#include "cub3d.h"

void ft_free(char **ar)
{
	int i;
	i = 0;
	while(ar[i])
	{
		free(ar[i]);
	}
	free(ar);
	return;
}