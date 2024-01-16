#include <unistd.h>
#include <stdio.h>
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
int main()
{
	char *s=NULL;
	int i = ft_count_words(s,' ');
	printf("i=%i\n",i);
}