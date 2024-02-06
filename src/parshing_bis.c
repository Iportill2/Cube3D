#include "../include/cub3d.h"

int get_playable_map_strlen_arraylen(t_list *s)
{
	int i = 0;

	while(s->playable_map && s->playable_map[s->playable_array_len])
	{
		i = ft_strlen(s->playable_map[s->playable_array_len]);
		if(i > s->playable_str_len)
			s->playable_str_len = i;
		s->playable_array_len++;
	}
/* 	printf("str_len =%i\n",s->playable_str_len);
	printf("array_len =%i\n",s->playable_array_len); */

	return(0);
}
int calloc_for_new_playable_map(t_list *s)
{

	int i =0;
	s->new_playable_map=ft_calloc(sizeof(char *),(s->playable_array_len + 1));
	if(s->new_playable_map==NULL)
		return(1);
	while(s->playable_map[i])
	{
		s->new_playable_map[i]=ft_calloc(sizeof(char),(s->playable_str_len + 1));
		if(s->new_playable_map[i] == NULL)
			return(1);
		i++;
	}

	printf("str_len =%i\n",s->playable_str_len);
	printf("array_len =%i\n",s->playable_array_len);
	return(0); 
}
int create_new_playable_map(t_list *s)
{
	int i =0;
	int e =0;
	if(calloc_for_new_playable_map(s)==1)
		return(1);
	while(s->playable_map[i])
	{
		e=0;
		while(s->playable_map[i][e])
		{
			if(s->playable_map[i][e] == ' ')
				s->new_playable_map[i][e] = '-';
			else
				s->new_playable_map[i][e] = s->playable_map[i][e];
			e++;
		}
		while (e < s->playable_str_len)
		{
			s->new_playable_map[i][e] = '-';
			e++;
		}
		i++;
	}
	return(0);
}
int check_new_playable_map_its_playable(t_list *s)
{
	(void)s;
	int i = 0;
	int e = 0;
	while(s->new_playable_map && s->new_playable_map[i])
	{
		e=0;
		while (s->new_playable_map[i][e])
		{
			if((i == 0 || i == s->playable_array_len) && (s->new_playable_map[i][e] == '0'))
				return(1);
			else if(s->new_playable_map[i][e] == '0')
			{
				if((i != 0) && (s->new_playable_map[i-1][e] == '-'))
					return(1);
				else if((i != s->playable_str_len) && (s->new_playable_map[i+1][e] == '-'))
					return(1);
				else if((i != 0) && (s->new_playable_map[i][e-1] == '-'))
					return(1);
				else if((i != s->playable_array_len) && (s ->new_playable_map[i][e+1] == '-'))
					return(1);
				printf("entra\n");
			}
			e++;
		}
		i++;
	}

	return(0);
}