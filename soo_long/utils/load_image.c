/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:19:45 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/04 07:51:08 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images0(t_long *so_long)
{
	init_variables(so_long);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "textures/player.xpm",
			&so_long->map_width, &so_long->map_height);
	if (so_long->player == NULL)
	{
		ft_printf("Error\n[player img]\n");
		free_imgs(so_long);
	}
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "textures/wall.xpm",
			&so_long->map_width, &so_long->map_height);
	if (so_long->wall == NULL)
	{
		ft_printf("Error\n[wall img]\n");
		free_imgs(so_long);
	}
}

void	load_images1(t_long *so_long)
{
	so_long->door = mlx_xpm_file_to_image(so_long->mlx, "textures/door.xpm",
			&so_long->map_width, &so_long->map_height);
	if (so_long->door == NULL)
	{
		ft_printf("Error\n[door img]\n");
		free_imgs(so_long);
	}
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx, "textures/bottom.xpm",
			&so_long->map_width, &so_long->map_height);
	if (so_long->floor == NULL)
	{
		(ft_printf("Error\n[floor img]\n"), free_imgs(so_long));
	}
}

void	load_images2(t_long *so_long)
{
	so_long->coin = mlx_xpm_file_to_image(so_long->mlx, "textures/coin422.xpm",
			&so_long->map_width, &so_long->map_height);
	if (so_long->coin == NULL)
	{
		(ft_printf("Error\n[coin img]\n"), free_imgs(so_long));
	}
	so_long->player_down0 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_down0.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->player_down0 == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
	so_long->player_down1 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_down1.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->player_down1 == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
}

void	load_images3(t_long *so_long)
{
	so_long->player_up0 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_up0.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->player_up0 == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
	so_long->player_up1 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_up1.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->player_up1 == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
	so_long->player_left0 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_left.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->player_left0 == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
	so_long->player_left1 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_left1.xpm", &so_long->map_width,
			&so_long->map_height);
}

void	load_images4(t_long *so_long)
{
	if (so_long->player_left1 == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
	so_long->player_right = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_right.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->player_right == NULL)
	{
		(ft_printf("Error\n[player img]\n"), free_imgs(so_long));
	}
	so_long->door_open = mlx_xpm_file_to_image(so_long->mlx,
			"textures/door_open.xpm", &so_long->map_width,
			&so_long->map_height);
	if (so_long->door_open == NULL)
	{
		(ft_printf("Error\n[door img]\n"), free_imgs(so_long));
	}
}
