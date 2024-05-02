/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:45:01 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/02 16:19:46 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_long *so_long)
{
	static int	flag_c = 0;
	int			y;

	y = so_long->player_y;
	player_coin(so_long, so_long->player_x, so_long->player_y - 1);
	if ((so_long->map[so_long->player_y - 1][so_long->player_x] != '1')
		&& check_exit(so_long, so_long->player_x, so_long->player_y - 1))
	{
		so_long->player_y -= 1;
		ft_printf("moves :%d\n", ++so_long->count_moves);
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor,
			so_long->player_x * 64, y * 64);
		if (flag_c == 0)
		{
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->player_up0, so_long->player_x * 64, so_long->player_y
				* 64);
			flag_c = 1;
		}
		else
			(mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->player_up1, so_long->player_x * 64,
					so_long->player_y * 64), flag_c = 0);
	}
}

void	down(t_long *so_long)
{
	static int	flag_c = 0;
	int			y;

	y = so_long->player_y;
	player_coin(so_long, so_long->player_x, so_long->player_y + 1);
	if ((so_long->map[so_long->player_y + 1][so_long->player_x] != '1')
		&& check_exit(so_long, so_long->player_x, so_long->player_y + 1))
	{
		so_long->player_y += 1;
		ft_printf("moves :%d\n", ++so_long->count_moves);
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor,
			so_long->player_x * 64, y * 64);
		if (flag_c == 0)
		{
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->player_down0, so_long->player_x * 64, so_long->player_y
				* 64);
			flag_c = 1;
		}
		else
			(mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->player_down1, so_long->player_x * 64,
					so_long->player_y * 64), flag_c = 0);
	}
}

void	right(t_long *so_long)
{
	static int	flag_c = 0;
	int			x;

	x = so_long->player_x;
	player_coin(so_long, so_long->player_x + 1, so_long->player_y);
	if ((so_long->map[so_long->player_y][so_long->player_x + 1] != '1')
		&& check_exit(so_long, so_long->player_x + 1, so_long->player_y))
	{
		so_long->player_x += 1;
		ft_printf("moves :%d\n", ++so_long->count_moves);
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, x
			* 64, so_long->player_y * 64);
		if (flag_c == 0)
		{
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->player_right, so_long->player_x * 64, so_long->player_y
				* 64);
			flag_c = 1;
		}
		else
			(mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->player, so_long->player_x * 64, so_long->player_y
					* 64), flag_c = 0);
	}
}

void	left(t_long *so_long)
{
	static int	flag_c = 0;
	int			x;

	x = so_long->player_x;
	player_coin(so_long, so_long->player_x - 1, so_long->player_y);
	if ((so_long->map[so_long->player_y][so_long->player_x - 1] != '1')
		&& check_exit(so_long, so_long->player_x - 1, so_long->player_y))
	{
		so_long->player_x -= 1;
		ft_printf("moves :%d\n", ++so_long->count_moves);
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->floor, x
			* 64, so_long->player_y * 64);
		if (flag_c == 0)
		{
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->player_left0, so_long->player_x * 64, so_long->player_y
				* 64);
			flag_c = 1;
		}
		else
			(mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->player_left1, so_long->player_x * 64,
					so_long->player_y * 64), flag_c = 0);
	}
}

int	player_moves(int keycode, t_long *so_long)
{
	exit_cordinations(so_long);
	if (keycode == W || keycode == ARROW_UP)
		up(so_long);
	if (keycode == S || keycode == ARROW_DOWN)
		down(so_long);
	if (keycode == A || keycode == ARROW_LEFT)
		left(so_long);
	if (keycode == D || keycode == ARROW_RIGHT)
		right(so_long);
	return (0);
}
