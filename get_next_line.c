#define BUFFER_SIZE 64

#include <libc.h>

char	*get_next_line(int fd)
{
	static char			*buffer;
	size_t				retour_read;
	int					i;
	char				*line;
	char				**start;

	start = &buffer;
	buffer = malloc(1000);
	line = malloc(1000);
	read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while (buffer[i] != '\n' && i <= BUFFER_SIZE)
		{
			i++;
		}
	strlcat(line, *start, i);
	return (line);
}

int		main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
}
