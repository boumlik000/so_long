/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:15 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/02 16:52:26 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, t_long *so_long)
{
	if (keycode == ESC || keycode == Q)
	{
		clean_everything(so_long);
		cleanup_data(so_long);
		exit(0);
	}
	return (0);
}

int	ft_exit(t_long *so_long)
{
	clean_everything(so_long);
	cleanup_data(so_long);
	exit(1);
	return (0);
}

void	exit_cordinations(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i] != NULL)
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
			{
				so_long->exit_y = i;
				so_long->exit_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	check_exit(t_long *so_long, int x, int y)
{
	if (so_long->map[y][x] == 'E'
		&& so_long->count_coins_p == so_long->total_collect)
	{
		ft_printf("moves :%d\n", so_long->count_moves + 1);
		ft_printf("\nYOU WIN.\n");
		clean_everything(so_long);
		cleanup_data(so_long);
		exit(0);
	}
	if (so_long->map[y][x] != 'E')
	{
		if (so_long->count_coins_p == so_long->total_collect)
		{
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->door_open, so_long->exit_x * 64, so_long->exit_y * 64);
		}
		return (1);
	}
	return (0);
}

void	load_images(t_long *so_long)
{
	load_images0(so_long);
	load_images1(so_long);
	load_images2(so_long);
	load_images3(so_long);
	load_images4(so_long);
}
