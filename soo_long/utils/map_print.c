/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:52 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/02 16:51:59 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_imgs(t_long *so_long)
{
	if (so_long->player != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player);
	if (so_long->wall != NULL)
		mlx_destroy_image(so_long->mlx, so_long->wall);
	if (so_long->door != NULL)
		mlx_destroy_image(so_long->mlx, so_long->door);
	if (so_long->floor != NULL)
		mlx_destroy_image(so_long->mlx, so_long->floor);
	if (so_long->coin != NULL)
		mlx_destroy_image(so_long->mlx, so_long->coin);
	if (so_long->player_down0 != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_down0);
	if (so_long->player_down1 != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_down1);
	if (so_long->player_up0 != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_up0);
	free_images2(so_long);
	clean_img(so_long);
	exit(1);
}

void	free_images2(t_long *so_long)
{
	if (so_long->player_up1 != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_up1);
	if (so_long->player_left0 != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_left0);
	if (so_long->player_left1 != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_left1);
	if (so_long->player_right != NULL)
		mlx_destroy_image(so_long->mlx, so_long->player_right);
	if (so_long->door_open != NULL)
		mlx_destroy_image(so_long->mlx, so_long->door_open);
	clean_img(so_long);
	exit(1);
}

void	init_variables(t_long *so_long)
{
	so_long->player = NULL;
	so_long->wall = NULL;
	so_long->door = NULL;
	so_long->floor = NULL;
	so_long->coin = NULL;
	so_long->player_down0 = NULL;
	so_long->player_down1 = NULL;
	so_long->player_up0 = NULL;
	so_long->player_up1 = NULL;
	so_long->player_left0 = NULL;
	so_long->player_left1 = NULL;
	so_long->player_right = NULL;
	so_long->door_open = NULL;
}

void	print_images(t_long *so_long)
{
	int	i;
	int	j;

	load_images(so_long);
	i = 0;
	while (i < so_long->map_y)
	{
		j = 0;
		while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
		{
			print_images_game(so_long, i, j);
			j++;
		}
		i++;
	}
}

void	print_images_game(t_long *so_long, int i, int j)
{
	if (so_long->map[i][j] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall, j
			* 64, i * 64);
	if (so_long->map[i][j] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, j
			* 64, i * 64);
	if (so_long->map[i][j] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
			j * 64, i * 64);
	if (so_long->map[i][j] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->door, j
			* 64, i * 64);
	if (so_long->map[i][j] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->coin, j
			* 64, i * 64);
}
