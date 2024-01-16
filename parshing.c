#include "cub3d.h"

void check_chars_utils(t_list *s,int i)
{
	if(s->map2d[i] == 'N')
	{
		s->pj_init_nsew = s->map2d[i];
		s->n++;
	}
	else if(s->map2d[i] == 'S')
	{
		s->pj_init_nsew = s->map2d[i];
		s->s++;
	}
	else if(s->map2d[i] == 'E')
	{
		s->pj_init_nsew = s->map2d[i];
		s->e++;
	}
	else if(s->map2d[i] == 'O')
	{
		s->pj_init_nsew = s->map2d[i];
		s->w++;
	}
	return ;
}

int check_chars_utils_bis(t_list *s)
{
	if(s->n == 1 && (s->s > 0 || s->e > 0 || s->w > 0))
		return(printf("Initial position set multiple times\n"), free((void *)s), 1);
	if(s->s == 1 && (s->n > 0 || s->e > 0 || s->w > 0))
		return(printf("Initial position set multiple times\n"), free((void *)s), 1);
	if(s->e == 1 && (s->s > 0 || s->n > 0 || s->w > 0))
		return(printf("Initial position set multiple times\n"), free((void *)s), 1);
	if(s->w == 1 && (s->s > 0 || s->e > 0 || s->n > 0))
		return(printf("Initial position set multiple times\n"), free((void *)s), 1);
	if(s->n != 0 && s->n != 1)
		return(printf("N set more than one time\n"), free((void *)s), 1);
	if(s->s != 0 && s->s != 1)
		return(printf("S set more than one time\n"), free((void *)s), 1);
	if(s->e != 0 && s->e != 1)
		return(printf("E set more than one time\n"), free((void *)s), 1);
	if(s->w != 0 && s->w != 1)
		return(printf("W set more than one time\n"), free((void *)s), 1);
	return(0);
}
int check_chars(t_list *s)
{
	int i;

	i=0;
	if(s->map2d == NULL)
		return (free (s), 1);
	while(s->map2d[i])
	{
		check_chars_utils(s,i);
		i++;
	}
	if(check_chars_utils_bis(s) == 1)
		return(1);
	return(0);
}