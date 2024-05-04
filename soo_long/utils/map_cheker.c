/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:44:41 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/04 07:57:39 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_check_square(t_long *so_long)
{
	if (so_long->map_y == so_long->map_x)
	{
		ft_printf("Error\nit must be rectangle");
		clean_mlx(so_long);
		exit(1);
	}
}

void	map_chek_borders(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->map_y)
	{
		j = 0;
		while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
		{
			if (so_long->map[0][j] != '1' || so_long->map[so_long->map_y
				- 1][j] != '1')
			{
				(ft_printf("Error\n[in map border width]"), clean_mlx(so_long),
					exit(1));
			}
			if (so_long->map[i][0] != '1' || so_long->map[i][so_long->map_x
				- 1] != '1')
			{
				(ft_printf("Error\n[in map border height]"),
					clean_mlx(so_long), exit(1));
			}
			j++;
		}
		i++;
	}
}

/*check items if they are missing or items additionals*/
void	count_items_on_map(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	so_long->flag_coin = 0;
	so_long->flag_player = 0;
	so_long->flag_exit = 0;
	while (i < so_long->map_y)
	{
		j = 0;
		while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
		{
			if (so_long->map[i][j] == 'P')
				so_long->flag_player += 1;
			else if (so_long->map[i][j] == 'C')
				so_long->flag_coin += 1;
			else if (so_long->map[i][j] == 'E')
				so_long->flag_exit += 1;
			j++;
		}
		i++;
	}
}

void	validate_item_counts(t_long *so_long)
{
	if (so_long->flag_coin < 1 || so_long->flag_exit != 1
		|| so_long->flag_player != 1)
	{
		ft_printf("Error\n[item is missing]\n");
		clean_mlx(so_long);
		exit(1);
	}
}

void	map_check_items(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->map_y)
	{
		j = 0;
		while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
		{
			if (so_long->map[i][j] != 'P' && so_long->map[i][j] != 'C'
				&& so_long->map[i][j] != 'E' && so_long->map[i][j] != '1'
				&& so_long->map[i][j] != '0')
			{
				ft_printf("Error\nin item [%c]", so_long->map[i][j]);
				clean_mlx(so_long);
				exit(1);
			}
			j++;
		}
		i++;
	}
	count_items_on_map(so_long);
	validate_item_counts(so_long);
}
