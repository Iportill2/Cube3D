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



/////////////////////////////////////////////



int parshing_map_args(t_list *s)
{
	int i =0;
		while(s->map3d[i] &&  i < 6)
		{
			s->map_date=ft_dual_split(s->map3d[i],' ',',');

			if(ft_strcmp(s->map_date[0], "NO") == 0)
				s->NO = s->map_date;
			else if(ft_strcmp(s->map_date[0], "SO") == 0)
				s->SO = s->map_date;
			else if(ft_strcmp(s->map_date[0], "WE") == 0)
				s->WE = s->map_date;
			else if(ft_strcmp(s->map_date[0], "EA") == 0)
				s->EA = s->map_date;
			else if(ft_strcmp(s->map_date[0], "F") == 0)
				s->floor = s->map_date;
			else if(ft_strcmp(s->map_date[0], "C") == 0)
				s->celling = s->map_date;
			i++;
		}
	return(0);
}

int check_map_args(t_list *s)
{
	if(ft_arraylen(s->NO)!= 2 || ft_arraylen(s->SO)!= 2 ||\
	 ft_arraylen(s->WE)!= 2 || ft_arraylen(s->EA)!= 2 ||\
	 ft_arraylen(s->floor)!= 4 || ft_arraylen(s->celling)!= 4)
		return(printf("Invalid map settings\n"),1);
	return(0);
}
int check_textures_fd_and_termination(t_list *s)
{
	int fd;

	fd = open(s->NO[1],O_RDONLY);
	if(fd == -1)
		return(printf("File didnt exit\n"),close(fd), 1);
	if(ft_strcmp(s->NO[1]+(ft_strlen(s->NO[1])-4),".xpm")!= 0)
		return(printf("Invalid file extension\n"),close(fd), 1);
	close(fd);
	return(0);
}
int floor_atoi_array(t_list *s)
{

	int i = 1;
	int e = 0;
	while(s->floor[i])
		i++;
	s->floor_size = i -1;
	i = 0;
	s->floor_int_arr = ft_calloc(sizeof(int *),(s->floor_size));
	if(s->floor_int_arr == NULL)
		return(1);
	while (s->floor[i])
	{
		s->floor_int_arr[e] = ft_atoi(s->floor[i]);
		e++;
		i++;
	}
	return(0);
}
int cell_atoi_array(t_list *s)
{

	int i = 1;
	int e = 0;
	while(s->floor[i])
		i++;
	s->cell_size = i -1;
	i = 0;
	s->celling_int_arr = ft_calloc(sizeof(int *),(s->cell_size));
	if(s->celling_int_arr == NULL)
		return(1);
	while (s->floor[i])
	{
		s->celling_int_arr[e] = ft_atoi(s->celling[i]);
		e++;
		i++;
	}
	return(0);
}