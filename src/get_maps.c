#include "../include/cub3d.h"

int get_maps(t_list *s,char **argv)
{
	s=ft_calloc(sizeof(t_list),(1));
		if(read_map(argv,s) == 1)
			return(1);
		s->map3d = ft_split(s->map2d,'\n');
		if(s->map3d == NULL)
			return(printf("Error in ft_split: s->map3d == NULL\n"),1);
		if(clean_map3d_split(s) == 1)
			return(printf("Error clean_map3d_split"),1);
		get_playable_map(s);
		get_playable_map_strlen_arraylen(s);
		create_new_playable_map(s);
	return(0);
}

void toito(t_list *s)
{
	(void)s;
	int i =0;
	printf("---TOITO-----\n");
	i =0;
	printf("******NO_arr*******\n");
	while(s->NO_arr &&   s->NO_arr[i])
	{
		printf("s->NO_arr[%i] = %s\n",i,s->NO_arr[i]);
		i++;
	}
	i =0;
	printf("******SO_arr*******\n");
	while(s->SO_arr &&  s->SO_arr[i])
	{
		printf("s->SO_arr[%i] = %s\n",i,s->SO_arr[i]);
		i++;
	}
	i =0;
	printf("******WE_arr*******\n");
	while(s->WE_arr &&  s->WE_arr[i])
	{
		printf("s->WE[%i] = %s\n",i,s->WE_arr[i]);
		i++;
	}
	i =0;
	printf("******EA_arr*******\n");
	while(s->EA_arr && s->EA_arr[i])
	{
		printf("s->EA[%i] = %s\n",i,s->EA_arr[i]);
		i++;
	}
	i =0;
	printf("******s->floor******\n");
	while(i <= s->floor_size)
	{
		printf("s->floor[%i] = %s\n",i,s->floor[i]);
		i++;
	}
	i =0;
	printf("******s->floor_int_arr******\n");
	while(i < s->floor_size)
	{
		printf("s->floor_int_arr[%i] = %d\n",i,s->floor_int_arr[i]);
		i++;
	}
	i =0;
	printf("******s->celling******\n");
	while(i <= s->cell_size)
	{
		printf("s->celling[%i] = %s\n",i,s->celling[i]);
		i++;
	}
	i =0;
	printf("******s->cell_int_arr******\n");
	while(i < s->cell_size)
	{
		printf("s->celling_int_arr[%i] = %d\n",i,s->celling_int_arr[i]);
		i++;
	}

	i =0;
	printf("******s->map3d******\n");
	while(s->map3d[i])
	{
		printf("s->map3d[%i] = %s\n",i,s->map3d[i]);
		i++;
	}
	printf("----------------\n");
	i =0;
	printf("******map_settings******\n");
	while(s->map_settings[i])
	{
		printf("map_settings[%i] = %s\n",i,s->map_settings[i]);
		i++;
	}
	printf("----------------\n");
	i =0;
	printf("******s->playable_map******\n");
	while(s->playable_map[i])
	{
		printf("%s\n",s->playable_map[i]);
		//printf("s->playable_map[%i] = %s\n",i,s->playable_map[i]);
		i++;
	}
	printf("******s->playable_str_len******\n");
	printf("str_len =%i\n",s->playable_str_len);
	printf("----------------\n");

	printf("******s->playable_array_len******\n");
	printf("array_len =%i\n",s->playable_array_len); 
	printf("----------------\n");
	i =0;
	printf("******s->new_playable_map******\n");
	while(s->new_playable_map[i])
	{
		printf("%s\n",s->new_playable_map[i]);
		//printf("s->playable_map[%i] = %s\n",i,s->playable_map[i]);
		i++;
	}
	printf("----------------\n");


	printf("s->n=%i\n",s->n);
	printf("s->s=%i\n",s->s);
	printf("s->e=%i\n",s->e);
	printf("s->w=%i\n",s->w);
	printf("s->pj_init_nsew=%c\n",s->pj_init_nsew);

	printf("---TOITO-----\n");

}