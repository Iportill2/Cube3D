#include "../include/cub3d.h"

size_t ft_strlen(const char *s)
{
	int i;

	i =0;
	if(s == NULL)
		return(0);
	while(s[i])
		i++;
	return(i);
}
size_t ft_arraylen(char **arr)
{
	size_t i;
	i = 0;
	if(arr == NULL)
		return(0);
	while(arr[i])
		i++;
	return(i);
}
int ft_count_array_len(char **arr)
{
	int len = 0;

	int i = 0;
	int e = 0;
	if(arr == NULL)
		return(0);
	while(arr[i])
	{
		e=0;
		while(arr[i][e])
		{
			e++;
			len++;
		}
		i++;
		len++;
	}
	return(len);
}
int	ft_atoi(const char *str)//
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = (str[i] - 48) + (num * 10);
		i++;
	}
	return (num * sign);
}

void* ft_calloc(size_t num, size_t size) 
{
    void* structure;

	structure = NULL;
	structure = malloc(num * size);
    if (structure == NULL) 
        return NULL;
    memset(structure, 0, num * size);

    return (structure);
}

char* ft_strjoin(const char* s1, const char* s2) 
{
    char* result;
	size_t len;
	int i = 0;
	int e = 0;

	if(s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result =NULL;
	result = ft_calloc(sizeof(char),len);
    if (result == NULL) 
        return NULL;
	while(s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[e])
	{
		result[i] = s2[e];
		i++;
		e++;
	}
	result[i]= '\0'; 
	free((void *)s1);
    return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] != s2[i] && i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
char	*ft_strdup(const char *s)
{
	char *dup;
	int i;
	int len;

	dup =NULL;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s)+1;
	dup =ft_calloc(sizeof(char),len);
	if(dup == NULL)
		return(NULL);
	i=0;
	while(s[i])
	{
		dup[i] = s[i];
		i++;
	} 
	dup[i] = '\0';
	return(dup);
}
int ft_strcmp(char *s1,char *s2)
{
	int i =0;
	if (s1 == NULL || s2 == NULL)
		return(1);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}
