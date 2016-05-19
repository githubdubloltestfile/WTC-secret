#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define BUFF_SIZE 6

char    *strt_tp(int fd, char buf[], int *i);
char	*getnl(int fd, char buf[], int *i)
{
	char	*str;
	int		stri;

	stri = 0;
	str = (char *)malloc(BUFF_SIZE);
	if (buf[++(*i)] != '\0')
	{
		while (buf[*i] != '\n' && buf[*i] != '\0')
        {
			str[stri] = buf[*i];
            (*i)++;
            stri++;
        }
		if (buf[*i] == '\n')
		{
			return str;
		}
		else if (buf[*i] == '\0')
            return (str);
	}
}

int		get_next_line(const int fd, char **line)
{
	static int		i;
    static int pass;
	char			**p1;
	char			***p2;
	static char            *buf;
    static char             *str;

    p1 = &buf;
	p2 = &p1;
    if (pass == 0)
    {
        buf = (char *)malloc(BUFF_SIZE);
        str = (char *)malloc(BUFF_SIZE);
        pass = 1;
    }
	if (i != 0)
    {
		buf = getnl(fd, str, &i);
        *line = **p2;
        return (1);
    }
	else if (i == 0)
    {
        if (read(fd, buf, BUFF_SIZE))
        {
            strcpy(str, buf);
        }
		buf = strt_tp(fd, buf, &i);
        *line = **p2;
        return (1);
    }
    else
        return (-1);
}

char    *strt_tp(int fd, char buf[], int *i)
{
    char *str;

    str = (char *)malloc(BUFF_SIZE); 
	while (1)
	{
		if	(buf[*i] != '\n' && buf[*i] != '\0')
		{
			str[*i] = buf[*i];
            (*i)++;
		}
		else if (buf[*i] == '\n')
		{
			str[*i] = '\0';
			return str;
		}
		else if (buf[*i] == '\0')
		{
			str[*i] = '\0';
			return str;
		}
	}
}

int main()
{
	char *lolstr;
	int fd = open("testfile2", O_RDONLY);
	if (get_next_line(fd, &lolstr) == 1)
        printf("1We good\n\n%s\n", lolstr);
    else
	    printf("1We not good\n\n%s", lolstr);    
    if (get_next_line(fd, &lolstr) == 1)
        printf("2We good\n\n%s\n", lolstr);
    else
        printf("2We not good\n\n%s", lolstr);
	return 0;
}
