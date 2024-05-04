/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:54 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/04 07:55:51 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	file_count_lines(t_long *so_long, char **av)
{
	int	lines_num;

	so_long->fd = open(av[1], O_RDONLY);
	if (so_long->fd == -1)
	{
		ft_printf("Error\nread[1]");
		exit(0);
	}
	lines_num = count_lines(so_long->fd);
	close(so_long->fd);
	return (lines_num);
}

void	read_map(t_long *so_long, char **av)
{
	int	i;
	int	lines_num;

	i = 0;
	lines_num = file_count_lines(so_long, av);
	so_long->fd = open(av[1], O_RDONLY);
	if (so_long->fd == -1)
	{
		ft_printf("Error\nread[2]");
		exit(0);
	}
	so_long->map = malloc((lines_num + 1) * sizeof(char *));
	if (so_long->map == NULL)
		return ;
	so_long->line = get_next_line(so_long->fd);
	while (so_long->line != NULL)
	{
		so_long->map[i] = so_long->line;
		so_long->line = get_next_line(so_long->fd);
		i++;
	}
	close(so_long->fd);
}
