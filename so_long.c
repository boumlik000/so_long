/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:31:30 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/21 18:38:25 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_long *so_long, char **av)
{
    int i = 0; 
    int lines_num = read_map1(so_long,av);
    
    so_long->fd = open(av[1], O_RDONLY);
    if (so_long->fd == -1)
    {
        printf("Error\nThere is no file with this name!");
        exit(0);
    }
    so_long->map = malloc((lines_num + 1) * sizeof(char *));
    so_long->line = get_next_line(so_long->fd);
    while (so_long->line != NULL)
    {
        so_long->map[i] = so_long->line;
        so_long->line = get_next_line(so_long->fd);
        i++;
    }
    close(so_long->fd);
}
void flood_fill_return(t_long *so_long)
{
    ;
    get_player_cord(so_long);
    fill_array(so_long);
    int i = 0;
    int j = 0;
    so_long->collect_found = 0;
    flood_fill(so_long, so_long->player_y, so_long->player_x);
    while (i < so_long->height)
    {
        j = 0;
        while (j < so_long->width)
            j++;
        i++;
    }
    if (so_long->collect_found != map_check_coins(so_long))
    {
        printf("[%d] -- [%d]",so_long->collect_found,map_check_coins(so_long));
        printf("Error\nfd_return");
        exit(1);
    }
}


int	main(int ac, char **av)
{
    if (ac != 2)
        return 1;
        
    t_long so_long;
    
    read_map(&so_long, av);
	so_long.mlx = mlx_init();
    so_long.fd = open(av[1], O_RDONLY);
    so_long.height = count_lines(so_long.fd);
    close(so_long.fd);
    
    so_long.fd = open(av[1], O_RDONLY);
    so_long.line = get_next_line(so_long.fd);
    so_long.width = (ft_strlen(so_long.line) - 1);
    close(so_long.fd);
    
    //chekers for map
    read_map1(&so_long,av);
    map_check_borders(&so_long);
    map_chek_width(&so_long);
    map_check_player(&so_long);
    
    
    flood_fill_return(&so_long);
    
    so_long.height *= 64;
    so_long.width *= 64;
    
    so_long.window = mlx_new_window(so_long.mlx, so_long.width, so_long.height, "boumlik's game");
    print_imgs(&so_long, so_long.height / 64);

    mlx_hook(so_long.window, 2, 1L<<0, ft_close, NULL);
    mlx_hook(so_long.window, 17, 0, ft_exit, NULL);
    mlx_loop(so_long.mlx);
}
