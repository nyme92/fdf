/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camfdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muelfaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:07:41 by muelfaha          #+#    #+#             */
/*   Updated: 2019/09/12 11:26:40 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	 mlx_create(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "mlx 42");
	mlx_hook(e->win, 2, 5, fdf_keyhook, e);
	g_offset.x = 0.002;
	g_offset.y = 0.002;
	e->map.scale = (double)-1.2;
	draw(e);
	mlx_string_put(e->mlx, e->win, 10, WIN_Y - 30, WHITE, "ESC: close");
	mlx_loop(e->mlx);
}

void	 mlx_check_putpixel(t_env *e, int x, int y, int c)
{
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	mlx_pixel_put(e->mlx, e->win, x, y, c);
}

int		 fdf_keyhook(int key, t_env *e)
{
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_LEFT)
		g_offset.y += 0.06;
	if (key == KEY_RIGHT)
		g_offset.y -= 0.06;
	if (key == KEY_UP)
		g_offset.x -= 0.06;
	if (key == KEY_DOWN)
		g_offset.x += 0.06;
	if (key == KEY_F)
		e->map.tile *= 1.1;
	if (key == KEY_G)
		e->map.tile *= 0.5;
	draw(e);
	mlx_string_put(e->mlx, e->win, 10, WIN_Y - 30, WHITE, "ESC: close");
	return (0);
}
int		main(int argc, char **argv)

{
	int		fd ;
	t_env	environ;

	fd = 0;
	/*
** Filling block of memory (environ) with the struct that contains everything
*/
	ft_memset(&environ, 0, sizeof(t_env));
	if(argc !=2)
	{
		ft_putstr_fd("\033[1;32m-.- Input Error: ", 2);
		ft_putstr_fd("\033[1;31mWrong Number of Arguments ", 2);
		while(1){
		exit(0);}
	}
	if (argc == 2)
		
	check_error(fd, argv);
fd = open(argv[1], O_RDONLY);
	get_map_size(&environ, argv[1]);
	parse(argv[1],&environ);
	
    mlx_create(&environ);
free(&environ);
// free(&environ.map.y)
	//free(&environ.map.size.y);
	//free(&environ.map.size.x);
	while(1)
{
	return(0);
}	}

