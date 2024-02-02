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
	printf("******NO*******\n");
	while(s->NO &&   s->NO[i])
	{
		printf("s->NO[%i] = %s\n",i,s->NO[i]);
		i++;
	}
	i =0;
	printf("******SO*******\n");
	while(s->SO &&  s->SO[i])
	{
		printf("s->SO[%i] = %s\n",i,s->SO[i]);
		i++;
	}
	i =0;
	printf("******WE*******\n");
	while(s->WE &&  s->WE[i])
	{
		printf("s->WE[%i] = %s\n",i,s->WE[i]);
		i++;
	}
	i =0;
	printf("******EA*******\n");
	while(s->EA && s->EA[i])
	{
		printf("s->EA[%i] = %s\n",i,s->EA[i]);
		i++;
	}
	i =0;
	printf("******floor*******\n");
	while(s-> floor && s->floor[i])
	{
		printf("s->floor[%i] = %s\n",i,s->floor[i]);
		i++;
	}
	i =0;
	printf("******celling******\n");
	while( s->celling && s->celling[i])
	{
		printf("s->celling[%i] = %s\n",i,s->celling[i]);
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
	printf("******s->cell_int_arr******\n");
	while(i < s->cell_size)
	{
		printf("s->celling_int_arr[%i] = %d\n",i,s->celling_int_arr[i]);
		i++;
	}
	i =0;
	printf("******s->playable_map******\n");
	while(s->playable_map[i])
	{
		printf("s->playable_map[%i] = %s\n",i,s->playable_map[i]);
		i++;
	}
	printf("----------------\n");

	printf("s->n=%i\n",s->n);
	printf("s->s=%i\n",s->s);
	printf("s->e=%i\n",s->e);
	printf("s->w=%i\n",s->w);
	printf("s->pj_init_nsew=%c\n",s->pj_init_nsew);

	printf("---TOITO-----\n");

	/* int i = 0;
	while(s->array)
	{
		printf("s->array[%i] =%s\n",i,s->array[i]);
		i++;
	} */
}

int read_map(char **argv,t_list *s)
{
	char *temp =NULL;
	int fd;
	int read_bytes;

	fd = 0;
	fd= open(argv[1],O_RDONLY);
	if(fd == -1)
		return(printf("mal\n"),free((void *)s), 1);
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
		//printf("[]%s[]\n",s->map2d);
		s->map3d = ft_split(s->map2d,'\n');
		clean_map3d_split(s);
/* 		int i =0;
		while(s->map3d[i])
		{
			printf("||%s\n",s->map3d[i]);
			i++;
		} */


		parshing_map_args(s);
		if(check_map_args(s) == 1)
			return(1);
		if(check_textures_fd_and_termination(s) == 1)
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
		if(get_pj_init_position(s) == 1)/////////
			return(1);
		if(check_chars_in_playable_map(s) == 1)
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
		else
			printf("OK\n");
		//toito(s);
/* 		s->lines = count_lines(s);//
		s->array = create_array(s); */
		
	
/* 		if(parshing_map(s) == 1)
			return(printf("Error parshing map\n"),1); */
		
/* 		if(split_floor(s) == 1)
			return(printf("Error split_floor\n"),1);
		if(split_cell(s) == 1)
			return(printf("Error split_cell\n"),1); */
/* 		if(check_chars(s) == 1)
			return(printf("Error check_chars\n"),1); */


		//ft_star_game(s);
	}
	else
		printf("Invalid num of arguments\n");
return(0);

}
