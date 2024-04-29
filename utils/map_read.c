#include "../so_long.h"

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
int file_count_lines(t_long *so_long, char **av)
{   
    so_long->fd = open(av[1], O_RDONLY);
    if (so_long->fd == -1)
    {
        ft_printf("Error\nThere is no file with this name!");
        exit(0);
    }
    int lines_num = count_lines(so_long->fd);
    close(so_long->fd);
    return lines_num;
}
void read_map(t_long *so_long, char **av)
{
    int i = 0; 
    int lines_num = file_count_lines(so_long,av);
    so_long->fd = open(av[1], O_RDONLY);
    if (so_long->fd == -1)
    {
        ft_printf("Error\nThere is no file with this name!");
        exit(0);
    }
    so_long->map = malloc((lines_num + 1) * sizeof(char *));
    if (so_long->map == NULL)
        return;

    so_long->line = get_next_line(so_long->fd);
    while (so_long->line != NULL)
    {
        so_long->map[i] = so_long->line;
        so_long->line = get_next_line(so_long->fd);
        i++;
    }
    close(so_long->fd);
}
