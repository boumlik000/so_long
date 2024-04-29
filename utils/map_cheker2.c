#include "../so_long.h"


int map_check_coins(t_long *so_long)
{
    int i; 
    int j;
    i = 0;
    so_long->total_collect = 0;
    while (i < so_long->map_y)
    {
        j= 0 ;
        while (so_long->map[i][j])
        {
            if (so_long->map[i][j] == 'C')
                so_long->total_collect += 1;
            j++;
        }
        i++;
    }
    return so_long->total_collect;
}
void map_check_between(t_long *so_long)
{
    int i; 
    int j;
    i = 0;
    while (i < so_long->map_y)
    {
        j= 0 ;
        while (so_long->map[i][j])
        {
            if (so_long->map[i][0] != '1')
            {
                ft_printf("no empty line between lines in map \n");
                clean_mlx(so_long);
                exit(1);
            }
            j++;
        }
        i++;
    }
}
int map_check_path(char *filename)
{
    int	i;

	i = 0;
	if (!filename)
		return (0);
	while (filename[i])
		i++;
	if (!ft_strnstr(&filename[i - 4], ".ber", 4))
		return (0);
	return (1);
}

int	check_map_is_valid(t_long *so_long, char *filename)
{   
    if (!map_check_path(filename))
    {
	    ft_printf("Error\nmap path false");
        clean_mlx(so_long);
        // cleanup_data(so_long);
        exit(1);
    }
    if (so_long->map_y == 0)
    {
        ft_printf("Error\nmap empty");
        clean_mlx(so_long);
        // cleanup_data(so_long);
        exit(1);    
    }
    map_check_square(so_long);
    map_check_between(so_long);
    map_chek_borders(so_long);
    map_check_items(so_long);
    return 0;
}
