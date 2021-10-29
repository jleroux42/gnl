#define BUFFER_SIZE 4

#include <libc.h>

char	*get_next_line(int fd)
{
	static char			*buffer;
	int					retour_read;
	int					i;
	char				*line;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	line = malloc(1000);
	retour_read = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n' && i <= BUFFER_SIZE)
		i++;
	line = strncpy(line, buffer, i);
	return (line);
}

int		main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
