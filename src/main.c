#include "../include/cub3d.h"
int run_program()
{
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
	printf("******s->cell******\n");
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

int read_map(char **argv,t_list *s)
{
	char *temp =NULL;
	int fd;
	int read_bytes;

	fd = 0;
	fd= open(argv[1],O_RDONLY);
	if(fd == -1)
		return(printf("fd=%i\n",fd),printf("mal\n"),free((void *)s), 1);
	while (1)
	{
		temp=ft_calloc(sizeof(char),2);
		temp[1]='\0';
		read_bytes =read(fd,temp,1);
		s->map2d=ft_strjoin(s->map2d,temp);
		free((void *)temp);
		if(read_bytes == 0)
			break;
	}
	close(fd);
	return(0);
}
int main(int argc,char **argv)
{
	t_list *s;
	(void)argc;
	(void)argv;
	int len;

	len = 0;
	 if (argc ==2)
	{
		len = ft_strlen(argv[1]);
		if ((argv[1][len - 1] != 'b') && (argv[1][len - 2] != 'u') && (argv[1][len - 3] != 'c') && (argv[1][len - 4] != '.'))
			return(printf("Wrong file extension\n"), 1);
		s=ft_calloc(sizeof(t_list),(1));
			if(read_map(argv,s) == 1)
				return(1);
		s->map3d = ft_split(s->map2d,'\n');
		clean_map3d_split(s);

		parshing_map_args(s);
		if(check_map_args(s) == 1)
			return(1);
		if(floor_atoi_array(s) == 1)
			return(1);
		if(cell_atoi_array(s) == 1)
			return(1);


		if(invalid_char_in_array(s) == 1)
		{
			printf("Fail in funtion invalid_char_in_array\n");
			return(1);
		}
		get_playable_map(s);
		if(check_chars_in_playable_map(s) == 1)///
			return(1);
		if(check_jumplines_in_playable_map(s) == 1)
			return(1);
		if(clean_floor(s) == 1)
		{
			printf("error en clean_floor\n");
			return(1);
		}
		if(clean_celling(s) == 1)
		{
			printf("error en clean_celling\n");
			return(1);
		}
		if(check_map_double_jump_line(s) == 1)
		{
			printf("error en check_map_double_jump_line\n");
			return(1);
		}
		get_playable_map_strlen_arraylen(s);
		create_new_playable_map(s);
		if(get_pj_init_position(s) == 1)/////////
			return(1);
		if(check_new_playable_map_its_playable(s,'0') == 1)
			return(printf("Error in check_new_playable_map_its_playable 0\n"),1);
		if(player_in_new_map(s) == 1)
			return(1);
		toito(s);//
		

		//ft_star_game(s);
	}
	else
		printf("Invalid num of arguments\n");
return(0);

}
