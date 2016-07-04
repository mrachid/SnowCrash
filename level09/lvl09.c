#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


#define BLOCK_SIZE 26
void    ft_rotation(char *s)
{
	int i;

	i = 0;
	while (s[i + 1] != '\0')
	{
		s[i] = s[i] - i;
		i++;
	}
	if (s[i + 1] == '\0')
		s[i] = s[i] - i;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int content;
		char    buffer[BLOCK_SIZE];
		int     fd;

		fd = open(argv[1], O_RDONLY);
		content = read(fd, (char *)buffer, BLOCK_SIZE);
		while (content > 0)
		{
			printf("%s\n",buffer);
			content = read(fd,(char*)buffer,sizeof(buffer));
		}
		close(fd);
		ft_rotation(buffer);
		printf("%s\n", buffer);
	}
	return (0);
}

