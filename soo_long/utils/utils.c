/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:45:03 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/02 16:45:18 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

void	player_cordinations(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->map_y)
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->player_y = i;
				so_long->player_x = j;
			}
			j++;
		}
		i++;
	}
}

void	print_array(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < so_long->map_y)
	{
		j = 0;
		while (j < so_long->map_x)
		{
			ft_printf("%d", so_long->visited[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	player_coin(t_long *so_long, int x, int y)
{
	if (so_long->map[y][x] == 'C')
	{
		so_long->map[y][x] = '0';
		so_long->count_coins_p += 1;
	}
}

void	clean_mlx(t_long *so_long)
{
	mlx_destroy_display(so_long->mlx);
	cleanup_data(so_long);
	free(so_long->mlx);
}
