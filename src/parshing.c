#include "../include/cub3d.h"

int ft_check_jumplines_in_playable_map(t_list *s)/////
{
	if(s == NULL)
		return(1);
	return(0);
}
int ft_check_chars_in_playable_map(t_list *s)
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
	if(s->invalid_char != 0)
		return(printf("Invalid character in map\n"), free((void *)s), 1);
	if(ft_check_initial_position(s) == 1)
		return(1);
	return(0);
}
int ft_check_initial_position(t_list *s)
{
	if(s->pj_init_nsew != 'N' && s->pj_init_nsew != 'S' && s->pj_init_nsew != 'W'&& s->pj_init_nsew != 'E')
		return(printf("The map haven't initial position\n"),1);
	return(0);
}
int ft_get_pj_init_position(t_list *s)///
{
	int i ;
	int e; 
	
	i = 0;
	e = 0;
	if(s->playable_map == NULL)
		return(1);
	while(s->playable_map[i])
	{
		e =0;
		while(s->playable_map[i][e])
		{
			if(s->playable_map[i][e] == 'N')
			{
			s->pj_init_nsew = s->playable_map[i][e] ;
			s->n++;
			}
			else if(s->playable_map[i][e] == 'S')
			{
			s->pj_init_nsew = s->playable_map[i][e] ;
			s->s++;
			}
			else if(s->playable_map[i][e] == 'E')
			{
			s->pj_init_nsew = s->playable_map[i][e] ;
			s->e++;
			}
			else if(s->playable_map[i][e] == 'W')
			{
			s->pj_init_nsew = s->playable_map[i][e] ;
			s->w++;
			}
			else if(s->playable_map[i][e] != 'N' && s->playable_map[i][e] != 'S'\
			&& s->playable_map[i][e] != 'E' && s->playable_map[i][e] != 'W' \
			&& s->playable_map[i][e] != '0' && s->playable_map[i][e] != '1' \
			&& s->playable_map[i][e] != ' ' && s->playable_map[i][e] != '\n')
			{
				s->invalid_char++;
				printf("INVALID=%c\n",s->playable_map[i][e]);
			}	
			e++;
		}
		i++;
	}
	return(0);
}

int ft_clean_floor(t_list *s)
{
	int i;
	
	i =0;
	while(s->floor[1][i])
	{
		if(s->floor[1][i] >= '0' && s->floor[1][i] <= '9')
			i++;
		else
			return(1);
	}
	i =0;
	while(s->floor[2][i])
	{
		if(s->floor[2][i] >= '0' && s->floor[2][i] <= '9')
			i++;
		else
			return(1);
	}
	i =0;
	while(s->floor[3][i])
	{
		if(s->floor[3][i] >= '0' && s->floor[3][i] <= '9')
			i++;
		else
			return(1);
	}
	return(0);
}
int ft_clean_celling(t_list *s)
{
	int i;
	
	i =0;
	while(s->celling[1][i])
	{
		if(s->celling[1][i] >= '0' && s->celling[1][i] <= '9')
			i++;
		else
			return(1);
	}
	i =0;
	while(s->celling[2][i])
	{
		if(s->celling[2][i] >= '0' && s->celling[2][i] <= '9')
			i++;
		else
			return(1);
	}
	i =0;
	while(s->celling[3][i])
	{
		if(s->celling[3][i] >= '0' && s->celling[3][i] <= '9')
			i++;
		else
			return(1);
	}
	return(0);
}

int ft_check_map_double_jump_line(t_list *s)
{
	int i = 0;
	int n = 0;
	int s1 = 0;
	int w = 0;
	int e = 0;
	int f = 0;
	int c = 0;
	int stop = 0;
	int count =0;
	if(s->map2d == NULL)
		return(1);
	while(s->map2d[i])
	{
		if(s->map2d[i]=='N')
			n++;
		else if(s->map2d[i]=='S')
			s1++;
		else if(s->map2d[i]=='E')
			e++;
		else if(s->map2d[i]=='W')
			w++;
		else if(s->map2d[i]=='F')
			f++;
		else if(s->map2d[i]=='C')
			c++;
		if((n == 2 || n == 3) && (s1 == 2 || s1 == 3) && (e == 3 || e == 4) && \
		(w == 2 || w == 3) && f == 1 && c == 1 && (stop ==  0) && s->map2d[i] == '\n') 
			stop = 1;
		else if((stop == 1) && s->map2d[i] == '\n')
			stop = 1;
		else if( stop != 0 &&  (s->map2d[i] == '1' ))
			stop = 2;
		else if((stop == 2 ) && s->map2d[i] == '\n')
			stop = 3;
		else if((stop == 3) && s->map2d[i] == '\n')
			return(1);
		count++;
		i++;
	}
	return(0);

}

int ft_get_playable_map(t_list *s)
{
	int i;
	int e;
	int u;

	i = 0;
	e = 0;
	u = 0;
	while(s->map3d[i])
	{
		e=0;
		while(s->map3d[i][e] == ' ' || s->map3d[i][e] == '\t')
		{
			e++;
		}
		if(s->map3d[i][e] == '0' || s->map3d[i][e] == '1')
			break;
		i++;
	}
	u = i;
	while(s->map3d[u])
	{
		u++;
	}
	s->playable_map=ft_calloc(sizeof(char *),u+1);
	if(s->playable_map == NULL)
		return(1);
	u = 0;
	while(s->map3d[i])
	{
		s->playable_map[u] = s->map3d[i];
		u++;
		i++;
	}
	return(0);
}

int ft_array_check(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == 'C' || s[i] == 'F' || (s[i] == 'N' && s[i+1] == 'O' )||\
		(s[i] == 'S' && s[i+1] == 'O' )||(s[i] == 'W' && s[i+1] == 'E' )||\
		(s[i] == 'E' && s[i+1] == 'A' ))
			return(1);
		i++;
	}
	return(0);
}
int ft_clean_map3d_split(t_list *s)
{
	int i;
	int e; 
	int count;

	i = 0;
	e = 0;
	count = 0;
	while(s->map3d[i])
	{
		count = count + ft_array_check(s->map3d[i]);
		i++;
	}
	if(count != 6)
		return(printf("Too many arguments in map_settings\n"),1);
	s->map_settings = ft_calloc(sizeof(char*),count+1);
	if(s->map_settings == NULL)
		return(1);
	i=0;
	while(s->map3d[i])
	{

		if(ft_array_check(s->map3d[i]) == 1)
		{
			s->map_settings[e]=ft_strdup(s->map3d[i]);
			e++;
			i++;
		}
		else
			i++;
	}
	return(0);
}
void ft_parshing_map_args(t_list *s)
{
	int i;

	i = 0;
		while(s->map_settings[i] &&  i < 6)
		{
			s->map_date=ft_dual_split(s->map_settings[i],' ',',');
			if(ft_strcmp(s->map_date[0], "NO") == 0)
				s->NO_arr = s->map_date;
			else if(ft_strcmp(s->map_date[0], "SO") == 0)
				s->SO_arr = s->map_date;
			else if(ft_strcmp(s->map_date[0], "WE") == 0)
				s->WE_arr = s->map_date;
			else if(ft_strcmp(s->map_date[0], "EA") == 0)
				s->EA_arr = s->map_date;
			else if(ft_strcmp(s->map_date[0], "F") == 0)
				s->floor = s->map_date;
			else if(ft_strcmp(s->map_date[0], "C") == 0)
				s->celling = s->map_date;
			i++;
		}
	return;
}

int ft_check_map_args(t_list *s)
{
	if(ft_arraylen(s->NO_arr)!= 2 || ft_arraylen(s->SO_arr)!= 2 ||\
	 ft_arraylen(s->WE_arr)!= 2 || ft_arraylen(s->EA_arr)!= 2 ||\
	 ft_arraylen(s->floor)!= 4 || ft_arraylen(s->celling)!= 4)
		return(printf("Error in ft_check_map_args\n"),1);
	return(0);
}
int ft_floor_atoi_array(t_list *s)
{
	int i;
	int e; 
	
	i = 0;
	e = 0;
	while(s->floor[i])
		i++;
	s->floor_size = i -1;
	s->floor_int_arr = ft_calloc(sizeof(int *),(s->floor_size));
	if(s->floor_int_arr == NULL)
		return(1);
	i = 1;
	while (s->floor[i])
	{
		s->floor_int_arr[e] = ft_atoi(s->floor[i]);
		e++;
		i++;
	}
	return(0);
}
int ft_cell_atoi_array(t_list *s)
{
	int i;
	int e;

	i = 1;
	e = 0;
	while(s->floor[i])
		i++;
	s->cell_size = i -1;
	s->celling_int_arr = ft_calloc(sizeof(int *),(s->cell_size));
	if(s->celling_int_arr == NULL)
		return(1);
	i = 1;
	while (s->floor[i])
	{
		s->celling_int_arr[e] = ft_atoi(s->celling[i]);
		e++;
		i++;
	}
	
	return(0);
}