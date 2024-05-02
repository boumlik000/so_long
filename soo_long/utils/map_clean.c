/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:45 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/02 16:45:28 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_array(t_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->map_y)
	{
		free(so_long->visited[i]);
		i++;
	}
	free(so_long->visited);
}

void	cleanup_data(t_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->map_y)
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
}

int	clean_everything(t_long *so_long)
{
	mlx_destroy_image(so_long->mlx, so_long->coin);
	mlx_destroy_image(so_long->mlx, so_long->player);
	mlx_destroy_image(so_long->mlx, so_long->wall);
	mlx_destroy_image(so_long->mlx, so_long->door);
	mlx_destroy_image(so_long->mlx, so_long->floor);
	mlx_destroy_image(so_long->mlx, so_long->player_left0);
	mlx_destroy_image(so_long->mlx, so_long->player_left1);
	mlx_destroy_image(so_long->mlx, so_long->player_right);
	mlx_destroy_image(so_long->mlx, so_long->player_up0);
	mlx_destroy_image(so_long->mlx, so_long->player_up1);
	mlx_destroy_image(so_long->mlx, so_long->player_down0);
	mlx_destroy_image(so_long->mlx, so_long->player_down1);
	mlx_destroy_image(so_long->mlx, so_long->door_open);
	mlx_clear_window(so_long->mlx, so_long->window);
	mlx_destroy_window(so_long->mlx, so_long->window);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	return (0);
}

void	clean_img(t_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->window);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	cleanup_data(so_long);
}
