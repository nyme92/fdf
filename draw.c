/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muelfaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:18:19 by muelfaha          #+#    #+#             */
/*   Updated: 2019/09/12 08:26:10 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawpoints(t_vec *a, t_vec *b, t_env *e)
{
	t_vec p;
	t_vec p2;

	p = fdf_project(*a, e);
	p2 = fdf_project(*b, e);
	if ((int)a->z != (int)b->z)
		dda(&p, &p2, \
				RED - ((fmax(a->z, b->z) - fmin(a->z, b->z)) * 150), e);
	else
		dda(&p, &p2, p.c, e);
}

void	dunk(t_env *e)
{
	t_vec p;
	t_vec p2;

	while (e->y < e->map.size.y)
	{
		while (e->x < e->map.size.x)
		{
			p = (t_vec){ e->x, e->y, e->map.mat[e->y][e->x], 0 };
			if (e->y - 1 >= 0)
			{
				p2 = (t_vec) { e->x, e->y - 1, e->map.mat[e->y - 1][e->x], 0 };
				drawpoints(&p, &p2, e);
			}
			if (e->x - 1 >= 0)
			{
				p2 = (t_vec) { e->x - 1, e->y, e->map.mat[e->y][e->x - 1], 0 };
				drawpoints(&p, &p2, e);
				
					}
			e->x++;
			free(e->map.mat[e->y][e->x]);
			ft_bzero(&p2, sizeof(t_vec));
			
		}
		e->y++;
		e->x = 0;
	}
}

void	draw(t_env *e)
{
	e->x = 0;
	e->y = 0;
	mlx_clear_window(e->mlx, e->win);
	dunk(e);

}
