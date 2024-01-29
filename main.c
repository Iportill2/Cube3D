#include "cub3d.h"
int run_program()
{
	return(0);
}
void toito(t_list *s)
{
	printf("---TOITO-----\n");
	
	if(s->n == 1)
		printf("s->n =%d\n",s->n);
	if(s->s == 1)
		printf("s->s =%d\n",s->s);
	if(s->e == 1)
		printf("s->e =%d\n",s->e);
	if(s->w == 1)
		printf("s->w =%d\n",s->w);
	//printf("%s\n",s->map2d);
	int i = 0;
	printf("s->NO =%s\n",s->NO);
	printf("s->SO =%s\n",s->SO);
	printf("s->WE =%s\n",s->WE);
	printf("s->EA =%s\n",s->EA);
	printf("s->floor =%s\n",s->floor);
	printf("s->celling =%s\n",s->celling);
	//printf("s->lines=%d\n",s->lines);
	while(s->array[i])
	{
		printf("s->array[%i] =%s\n",i,s->array[i]);
		i++;
	}
	printf("s->pj_init_nsew = %c\n",s->pj_init_nsew);
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
	printf("bien\n");
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
		s->map3d = ft_split(s->map2d,'\n');
		int i =0;
		int e = 0;
		while(s->map3d[i])
		{
			s->map_date=ft_dual_split(s->map3d[i],' ',',');
			e =0;
			while(s->map_date[e])
			{
				printf("s->map_date[%i]=%s\n",e,s->map_date[e]);
				e++;
			}
			i++;
		}
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
		//toito(s);
	}
	else
		printf("Invalid num of arguments\n");
return(0);
}