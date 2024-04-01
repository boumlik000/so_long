#include <stdio.h>
#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx = mlx_init();
    void    *window = mlx_new_window(mlx, 700, 500, "boumlik's game");

    int i = -1;
    while(++i < 700)
        mlx_pixel_put(mlx, window, 350, i, 0xFFFFFF);
    i = 0;
    while(++i < 700)
        mlx_pixel_put(mlx, window, i, 250, 0xFFFFFF);
    mlx_loop(mlx);
}