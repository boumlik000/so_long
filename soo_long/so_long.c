/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:45:08 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/01 21:19:04 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_long	so_long;

	validate_and_initialize(&so_long, ac, av);
	calculate_map_dimensions(&so_long);
	read_map(&so_long, av);
	check_map_is_valid(&so_long, av[1]);
	flood_fill(&so_long);
	setup_window(&so_long);
	so_long.count_moves = 0;
	so_long.count_coins_p = 0;
	mlx_key_hook(so_long.window, player_moves, &so_long);
	mlx_hook(so_long.window, 2, 1L << 0, ft_close, &so_long);
	mlx_hook(so_long.window, 17, 0L, ft_exit, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
