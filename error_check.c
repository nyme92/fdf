/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muelfaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 08:31:27 by muelfaha          #+#    #+#             */
/*   Updated: 2019/09/12 08:36:11 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_error(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	if ((get_next_line(fd, &line)) < 0 || (get_next_line(fd, &line)) == 0)
	{
		ft_putstr_fd("\033[1;31m-.- Input Error: ", 2);
		ft_putstr_fd("\033[32mCannot Read File: \033[0;33m ", 2);
		//write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		ft_putstr_fd("\033[1;34mPlease Input Correct .fdf file", 2);
		write(2, "\n", 1);
		exit(0);
	}
	if (argc == 1)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" file\n");
		exit(0);
	}
		if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error: Opening File Failed\n");
		return (-1);
	}
	return (fd);
}
