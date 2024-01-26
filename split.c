#include "cub3d.h"

int ft_wordlen(char *s,char c)
{
	int i ;
	
	i=0;
	if(s == NULL)
		return(0);
	while(s[i] && s[i] != c)
		i++;
	return(i);
}

int ft_count_words(char *s,char c)
{
	int i;
	int len;

	i=0;
	len=0;
	if(s == NULL)
		return(0);
	while(s[i] && s[i] ==  c)
		i++;
	while(s[i])
	{
		len++;
		while(s[i] && s[i] !=  c)
			i++;
		while(s[i] && s[i] ==  c)
			i++;
	}
	return(len);
}
char *word_dupe(char *s,char c)
{
	size_t i;
	size_t len;
	char *dupe;

	if(s == NULL)
		return(NULL);
	len= ft_wordlen(s,c);
	dupe = ft_calloc(sizeof(char),len+1);
	if(dupe == NULL)
		return(NULL);
	i=0;
	while(s[i] && i < len)
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return(dupe);
}
int fill_words(char **array,char *s,char c)
{
	int i;
	int index;

	i=0;
	index=0;

	if(s == NULL)
		return(1);
	while(s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		array[index] = word_dupe(s+i,c);
		index++;
		while(s[i] && s[i] != c)
			i++;
		while(s[i] && s[i] == c)
			i++;
	}
	return(0);
}
char **ft_split(char *s,char c)
{
	int num_words;
	char **array;
	int i;

	array = NULL;
	num_words=ft_count_words(s,c);
	array=ft_calloc(sizeof(char *),num_words+1);
	i=0;
	if(fill_words(array,s,c) == 1)
	{
		while(array[i])
		{
			free(array[i]);
			i++;
		}
	}
	array[num_words] = NULL;
	return(array);
}
/* int main()
{
	char **esplit = NULL; 
	char *argv=NULL;
	esplit = ft_split(argv,' ');
	int i=0;
	while(esplit[i])
	{
		printf("%s\n",esplit[i]);
		free(esplit[i]);
		i++;
	}
} */
int split_floor_cell(t_list *s)
{
	char **split_cell;
	//char **split_floor;
	int i = 0;
	int e = 0;
	split_cell=ft_split(s->celling + 2, ',');
	while(split_cell)
	{
		printf("split_cell[%i]=%s\n",i,split_cell[i]);
		i++;
	}
	s->cell_size = i - 1;
	s->celling_int_arr=ft_calloc(sizeof(int),(s->cell_size));
	while (e < s->cell_size)
	{
		s->celling_int_arr[e] = 
	}
	
	return(0);
}