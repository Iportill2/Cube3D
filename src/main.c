#include "../include/cub3d.h"
int run_program()
{
	return(0);
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
		////////////////////////////////////////////////////
		if(get_maps(s,argv)== 1)
			return(1);
		////////////////////////////////////////////////////
		if(get_pj_init_position(s) == 1)
			return(1);
		parshing_map_args(s);
		if(check_map_args(s) == 1)
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
		if(floor_atoi_array(s) == 1)
			return(printf("error reserving memory for s->floor_int_arr\n"),1);
		if(cell_atoi_array(s) == 1)
			return(printf("error reserving memory for s->cell_int_arr\n"),1);


		/* if(invalid_char_in_array(s) == 1)
		{
			printf("Fail in funtion invalid_char_in_array\n");
			return(1);
		} */
		if(check_chars_in_playable_map(s) == 1)///
			return(1);
		if(check_jumplines_in_playable_map(s) == 1)
			return(1);
		if(check_map_double_jump_line(s) == 1)
			return(printf("error en check_map_double_jump_line\n"),1);
		if(check_new_playable_map_its_playable(s,'0') == 1)
			return(printf("Error in check_new_playable_map_its_playable 0\n"),1);
		if(player_in_new_map(s) == 1)
			return(1);
		//toito(s);//
		

		//ft_star_game(s);
	}
	else
		printf("Invalid num of arguments\n");
return(0);

}
