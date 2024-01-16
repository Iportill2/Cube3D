#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//librerias de mates man man 3 math
# include <math.h>

typedef struct s_list
{
	int stop;
	char *map2d;
	char **map3d;
	char pj_init_nsew;
	int n;
	int s;
	int e;
	int w;

	char *floor;
	int  *floor_int_ar;

	char *celling;
	int  *celling_int_arr;

	char *NO;
	char *SO;
	char *WE;
	char *EA;

}	t_list;

/*MAIN*/
void 	toito(t_list *s);
int 	main(int argc,char **argv);
int 	read_map(char **argv,t_list *s);
int 	run_program();
/*UTILS*/
size_t 	ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(const char* s1, const char* s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);

/*SPLIT*/
int 	ft_wordlen(char *s,char c);
int 	ft_count_words(char *s,char c);
char 	*word_dupe(char *s,char c);
int 	fill_words(char **array,char *s,char c);
char 	**ft_split(char *s,char c);

/*PARSHING*/
int 	check_chars(t_list *s);
void 	check_chars_utils(t_list *s,int i);
int 	check_chars_utils_bis(t_list *s);
int 	parshing_map(t_list *s);
#endif