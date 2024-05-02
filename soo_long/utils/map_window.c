/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:57 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/01 21:33:41 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_and_initialize(t_long *so_long, int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\narguments err");
		exit(1);
	}
	so_long->mlx = mlx_init();
	so_long->fd = open(av[1], O_RDONLY);
	if (so_long->fd == -1)
	{
		ft_printf("Error\nThere is no file with this name: %s\n", av[1]);
		mlx_destroy_display(so_long->mlx);
		free(so_long->mlx);
		exit(1);
	}
	so_long->map_height = count_lines(so_long->fd);
	close(so_long->fd);
	so_long->fd = open(av[1], O_RDONLY);
	so_long->line = get_next_line(so_long->fd);
	so_long->map_width = ft_strlen(so_long->line) - 1;
	free(so_long->line);
	close(so_long->fd);
}

void	calculate_map_dimensions(t_long *so_long)
{
	so_long->map_x = so_long->map_width;
	so_long->map_y = so_long->map_height;
	so_long->map_height *= 64;
	so_long->map_width *= 64;
}

void	setup_window(t_long *so_long)
{
	so_long->window = mlx_new_window(so_long->mlx, so_long->map_width,
			so_long->map_height, "boumlik's game");
	print_images(so_long);
}
