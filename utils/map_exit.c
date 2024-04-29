#include "../so_long.h"

int ft_close(int keycode, t_long *so_long)
{
    if(keycode == ESC || keycode == Q)
    {
        clean_everything(so_long);
        cleanup_data(so_long);
        exit(0);
    }
    return 0;
}

int ft_exit(t_long *so_long)
{
    clean_everything(so_long);
    cleanup_data(so_long);
    exit(1);   
    return 0;
}

void Exit_cordinations(t_long *so_long)
{
    int i; 
    int j;
    i = 0;
    while (so_long->map[i] != NULL)
    {
        j= 0 ;
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
int check_exit(t_long *so_long, int x, int y)
{
    printf("%d,%d\n",so_long->count_coins_p,so_long->total_collect);
    if (so_long->map[y][x] == 'E' && so_long->count_coins_p == so_long->total_collect)
    {
        ft_printf("moves :%d\n", so_long->count_moves);
        ft_printf("\nYOU WIN.\n");
        clean_everything(so_long);
        cleanup_data(so_long);
        exit(0);
    }
    if (so_long->map[y][x] != 'E')
    {
        if (so_long->count_coins_p == so_long->total_collect)
        {
            mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->door_open, so_long->exit_x * 64, so_long->exit_y * 64);
        }
        return 1;      
    }
    return 0;
}
