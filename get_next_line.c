#define BUFFER_SIZE 42

#include <libc.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

        if (!s)
          return (NULL);
	s_len = strlen(s);
	if (start > s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	sub = malloc(1 + len * sizeof(*s));
	if (!sub)
		return (NULL);
	memmove(sub, s + start, len);
	sub[len] = 0;
	return (sub);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static int end;
	static int start;
	char *line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	start = end;
	while (buffer[end] != '\0')
		end++;
	line = ft_substr(buffer, start, end - start);
	free(buffer);
	return (line);
}

int		main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
