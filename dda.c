/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muelfaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:15:09 by muelfaha          #+#    #+#             */
/*   Updated: 2019/09/10 18:15:24 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	ft_abs(int n)
{
	return ((n > 0) ? n : (n * -1));
}

void		dda(t_vec *start, t_vec *end, int color, t_env *e)
{
	int	dx;
	int	dy;
	int	steps;
	int	i;

	dx = (int)end->x - (int)start->x;
	dy = (int)end->y - (int)start->y;
	steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	i = 0;
	while (i <= steps)
	{
		if (i > 0 && i < steps)
		{
			mlx_check_putpixel(e, start->x, start->y, color);
		}
		start->x += dx / (float)steps;
		start->y += dy / (float)steps;
		i++;
	}
}
