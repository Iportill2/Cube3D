#include "cub3d.h"

int check_chars_utils(t_list *s,int i)
{
	int q = 0;
	while(s->array[i])
	{
		while((s->array[i][q] == ' ' || s->array[i][q] == '1' || s->array[i][q] == '0') )
			q++;
		if(s->array[i][q] == 'N')
		{
			s->array[i][q] = s->pj_init_nsew;
			s->n++;
			q++;
		}
		else if(s->array[i][q] == 'S')
		{
			s->array[i][q] = s->pj_init_nsew ;
			s->s++;
			q++;
		}
		else if(s->array[i][q] == 'E')
		{
			s->array[i][q] = s->pj_init_nsew ;
			s->e++;
			q++;
		}
		else if(s->array[i][q] == 'W')
		{
			s->array[i][q] = s->pj_init_nsew ;
			s->w++;
			q++;
		}
		else
			return(printf("Invalid character in map\n"),free(s),1);
	}
	return(0);
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
	int i ;

	i = 0;
	if(s->array == NULL)
		return(free(s),1);
	while(s->array[i])
	{
		if(check_chars_utils(s,i) == 1)
			return(1);
		i++;
	}
	if(check_chars_utils_bis(s) == 1)
		return(1);
	return(0); 
}
int count_lines(t_list *s)
{
	int i = 0;
	int u = 0;

	int e = 0;
	while(s->map3d[i])
	{
		while(s->map3d[i][u] == ' ')
			u++;
		if(s->map3d[i][0] == 'N' && s->map3d[i][1] == 'O')
			printf("");
		else if(s->map3d[i][u] == 'S' && s->map3d[i][u+1] == 'O')
			printf("");
		else if(s->map3d[i][u] == 'W' && s->map3d[i][u+1] == 'E')
			printf("");
		else if(s->map3d[i][u] == 'E' && s->map3d[i][u+1] == 'A')
			printf("");
		else if(s->map3d[i][u] == 'F' && s->map3d[i][u+1] == ' ')
			printf("");
		else if(s->map3d[i][u] == 'C' && s->map3d[i][u+1] == ' ')
			printf("");
		else
			e++;
		i++;
	}
	return(e);
}
char **create_array(t_list *s)
{
	s->array = ft_calloc(sizeof(char *),(s->lines + 1));
	if(s->array == NULL)
		return(NULL);
	return(s->array);//
}

int parshing_map(t_list *s)//
{
	int i = 0;
	int u = 0;

	int e = 0;
	while(s->map3d[i])
	{
		printf("I=%s\n",s->map3d[i]);
		u = 0;
		while(s->map3d[i][u] == ' ')
			u++;
		if(s->map3d[i][u] == 'N' && s->map3d[i][u+1] == 'O')
			s->NO =ft_strdup(s->map3d[i]+u);
		else if(s->map3d[i][u] == 'S' && s->map3d[i][u+1] == 'O')
			s->SO =ft_strdup(s->map3d[i]+u);
		else if(s->map3d[i][u] == 'W' && s->map3d[i][u+1] == 'E')
			s->WE =ft_strdup(s->map3d[i]+u);
		else if(s->map3d[i][u] == 'E' && s->map3d[i][u+1] == 'A')
			s->EA =ft_strdup(s->map3d[i]+u);
		else if(s->map3d[i][u] == 'F' && s->map3d[i][u+1] == ' ')
			s->floor =ft_strdup(s->map3d[i]+u);
		else if(s->map3d[i][u] == 'C' && s->map3d[i][u+1] == ' ')
			s->celling =ft_strdup(s->map3d[i]);
		else
		{
			s->array[e] = ft_strdup(s->map3d[i]);//
			e++;
		}
		i++;
	}

	s->array[e] = NULL;
	if(s->NO == NULL || s->SO == NULL || s->WE == NULL || s->EA == NULL || s->floor == NULL || s->celling == NULL)
		return(1);
	return(0);
}

/////////////////////////////////////////////


