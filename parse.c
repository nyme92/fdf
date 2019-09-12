
#include "fdf.h"

void	splitline(char *str,int y,  t_env *e)
{
	char **array;
	int x;
	x = 0;
	array = ft_strsplit(str, ' ');
	while( x < e->map.size.x)
	{
		e->map.mat[y][x] = ft_atoi(array[x]);
		free(array[x]);
		x++;
		
	}
	free(str);
	free(array);
}
void		parse(char *filepath, t_env *e)
{
	int y;
	y = 0;
	int fd;
	char *line;

	line = NULL;
	fd = open(filepath, O_RDONLY);
	e->map.mat = (int **)malloc(sizeof(int *) * e->map.size.y);
	while (get_next_line(fd, &line) > 0)
	{
		e->map.mat[y] = (int *)malloc(sizeof(int ) * e->map.size.x);;
		splitline(line, y, e);
		y++;
		line = NULL;
	}

}
