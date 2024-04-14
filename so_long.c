/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:31:30 by mboumlik          #+#    #+#             */
/*   Updated: 2024/04/14 18:41:25 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close(int keycode, void *tt)
{
    (void)tt;
    printf("%d\n", keycode);
    if(keycode == 65307)
        exit(0);
    return 0;
}

int ft_exit(int keycode , void *tt)
{
    (void)tt;
    (void)keycode;
    exit(0);
    return 0;
}

int count_lines(int fd)
{
    int i = 0;
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    return i;
}

void    print_imgs(t_long *so_long, int width, int height)
{
    so_long->player = mlx_xpm_file_to_image(so_long->mlx, "textures/terture.xpm", &so_long->width, &so_long->height);
    int i = 0;
    int j = 0;
    printf("width == %d height == %d\n", width, height);
    // printf("width == %d height == %d\n", i, j);
    printf("width == %s height == %d\n", so_long->map[i], height);
    
    while (i < height && so_long->map != NULL && so_long->map[i] != NULL)
    {
        j = 0;
        printf("%c", so_long->map[i][j]);
        printf("width == %d height == %d\n", width, height);
        while (so_long->map[i][j] != '\n' && so_long->map[i][j] != '\0')
        {
            // if (so_long->map[i][j] == '0' || so_long->map[i][j] == 'P' || so_long->map[i][j] == 'E' || so_long->map[i][j] == 'C' || so_long->map[i][j] == '1') 
                mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void read_map(t_long *so_long, char **av)
{
    int i = 0;
    so_long->fd = open(av[1], O_RDONLY);
    if (so_long->fd == -1)
    {
        printf("Error\nThere is no file with this name!");
        exit(0);
    }
    int lines_num = count_lines(so_long->fd);
    close(so_long->fd);
    if (so_long->fd == -1)
    {
        printf("Error\nThere is no file with this name!");
        exit(0);
    }
    so_long->fd = open(av[1], O_RDONLY);
    if (so_long->fd == -1)
    {
        printf("Error\nThere is no file with this name!");
        exit(0);
    }
    so_long->map = malloc((lines_num + 1) * sizeof(char *));
    so_long->line = get_next_line(so_long->fd);
    printf("%s", so_long->line);

    while (so_long->line != NULL)
    {
        so_long->map[i] = so_long->line;
        printf("%s", so_long->line);
        so_long->line = get_next_line(so_long->fd);
        i++;
    }
    close(so_long->fd);
}

int	main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    t_long so_long;
    read_map(&so_long, av);
	so_long.mlx = mlx_init();
    so_long.fd = open(av[1], O_RDONLY);
    so_long.height = count_lines(so_long.fd) * 64;
    close(so_long.fd);
    
    so_long.fd = open(av[1], O_RDONLY);
    so_long.line = get_next_line(so_long.fd);
    so_long.width = (ft_strlen(so_long.line) - 1) * 64;
    close(so_long.fd);
    
    so_long.window = mlx_new_window(so_long.mlx, so_long.width, so_long.height, "boumlik's game");
    print_imgs(&so_long, so_long.width / 64, so_long.height / 64);

    mlx_hook(so_long.window, 2, 1L<<0, ft_close, NULL);
    mlx_hook(so_long.window, 17, 0, ft_exit, NULL);
    mlx_loop(so_long.mlx);
}