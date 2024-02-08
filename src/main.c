#include "../include/cub3d.h"
int run_program()
{
	return(0);
}


int ft_read_map(char **argv,t_list *s)
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
	int len;

	if (argc ==2)
	{
		len = ft_strlen(argv[1]);
		if ((argv[1][len - 1] != 'b') && (argv[1][len - 2] != 'u')\
		 && (argv[1][len - 3] != 'c') && (argv[1][len - 4] != '.'))
			return(printf("Wrong file extension\n"), 1);
		s=ft_calloc(sizeof(t_list),(1));
		if(ft_get_maps(s,argv) == 1)
			return(printf("Error in get_maps\n"),1);
		if(ft_floor_cell(s) == 1)
			return(printf("Error in ft_floor_cell\n"),1);
		if(ft_checks(s) == 1)
			return(printf("Error in ft_check\n"),1);
		toito(s);
		//ft_star_game(s);
	}
	else
		printf("Invalid num of arguments\n");
return(0);
}
