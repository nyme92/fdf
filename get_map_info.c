/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muelfaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 08:36:49 by muelfaha          #+#    #+#             */
/*   Updated: 2019/09/12 08:39:19 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_map_size(t_env *e, char *argv)
{
	int			fd;
	char		*line;

	fd = open(argv, O_RDONLY);
	e->count_line = 0;
	line = NULL;
	if ((get_next_line(fd, &line)) < 0)
		return (-1);
	e->map.size.y++;
	e->map.size.x = ft_wrdcount(line, ' ');
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		e->map.size.y++;
		if (ft_wrdcount(line, ' ') != e->map.size.x)
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
	}
	e->map.tile = 0.8f * fmin(WIN_X, WIN_Y) / (sqrt(2) *\
			fmax(e->map.size.y, e->map.size.x));
	close(fd);
	return (1);
}
