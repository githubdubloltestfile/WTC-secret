#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define BUFF_SIZE 40

void	*getnl(int fd, char *buf, int i)
{
	char	*str;
	int		stri;

	stri = 0;
	str = (char *)malloc(BUFF_SIZE);
	if (buf[++i] != '\0')
	{
		while (buf[i] != '\n' && buf[i] != '\0')
			str[stri++] = buf[i++]
		if (buf[i] == '\n')
		{
			*line = **p2;
			return (1);
		}
		else if (buf[i] == '\0')
			getnl(fd, buf);
	}
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static int		i;
	char			*str;
	static char		statchar;
	char			**p1;
	char			***p2;
	static char		buf[BUFF_SIZE];

	i = 0;
	str = (char *)malloc(BUFF_SIZE);
	p1 = &str;
	p2 = &p1;
	ret = read(fd, buf, BUFF_SIZE);
	if (i != 0)
		getnl(fd, buf, i);
	else
		strt_tP(fd, &*line, &**p2)
	while (1)
	{
		if	(buf[i] != '\n' && buf[i] != '\0')
		{
			str[i] = buf[i];
			ft_bzero(buf, i);
			i++;
		}
		else if (buf[i] == '\n')
		{
			str[i] = '\0';
			*line = **p2;
			return (1);
		}
		else if (buf[i] == '\0')
		{
			str[i] = '\0';
			*line = **p2;
			return (0);
		}
	}




int main()
{
	char *lolstr;
	int fd = open("testfile2", O_RDONLY);
	get_next_line(fd, &lolstr);
	printf("%s\n", lolstr);
	get_next_line(fd, &lolstr);
	printf("%s\n", lolstr);
	return 0;
}
