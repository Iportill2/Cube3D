#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **getcargs(char **s, int i, int j)
{
	int n = j - i;

	char **cargs = malloc(sizeof(char *) * (n + 1));

	for (int k = 0; k < n; k++)
	{
		cargs[k] = s[i + k];
	}
	cargs[n] = NULL;
	return (cargs);
}

void puterr(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}

int main(int c, char **v)
{
	int i = 1;
	int j = 0;
	int orin = dup(0);
	int orout = dup(1);
	int	fd[2];
	fd[0] = orin;
	fd[1] = orout;

	while (i < c)
	{
		if (v[i] && strcmp(v[i], ";") == 0)
		{
			dup2(orin, 0);
			dup2(orout, 1);
			fd[0] = orin;
			fd[1] = orout;
			i++;
		}
		else if (v[i] && strcmp(v[i], "|") == 0)
			i++;
		if (v[i] && strcmp(v[i], "cd") == 0)
		{
			j = i;
			while (v[j] && strcmp(v[j], ";") && strcmp(v[j], "|"))
				j++;
			if (j - i - 1 != 1)
				puterr("error: cd: bad arguments", NULL);
			else if (chdir(v[i + 1]))
				puterr("error: cd: cannot change directory to ", v[i + 1]);
			i = j;
		}
		else
		{
			j = i;
			while (v[j] && strcmp(v[j], ";") && strcmp(v[j], "|"))
				j++;
			if ((v[i] && j == c && strcmp(v[i], ";")) || (v[j] && !strcmp(v[j], ";") && strcmp(v[i], ";")))
			{
				dup2(orout, 1);
				if (fork() == 0)
				{
					char **cargs = getcargs(v, i, j);
					/*for (int r = 0; cargs[r]; r++)
						fprintf(stderr, "; cargs: %s\n", cargs[r]);*/
					execve(cargs[0], cargs, NULL);
					puterr("error: cannot execute ", cargs[0]);
					free(cargs);
					exit(-1);
				}
				else
					waitpid(-1, NULL, 0);

			}
			else if ((v[j] && !strcmp(v[j], "|") && strcmp(v[i], "|")))
			{
				dup2(fd[0], 0);
				close(fd[0]);

				pipe(fd);
				dup2(fd[1], 1);
				close(fd[1]);

				
				if (fork() == 0)
				{
					char **cargs = getcargs(v, i, j);
					/*for (int r = 0; cargs[r]; r++)
						fprintf(stderr, "| cargs: %s\n", cargs[r]);*/
					execve(cargs[0], cargs, NULL);
					puterr("error: cannot execute ", cargs[0]);
					free(cargs);
					exit(-1);
				}
				else
					waitpid(-1, NULL, 0);

				dup2(fd[0], 0);
				close(fd[0]);
			}
			i = j;
		}
		i++;
	}
}