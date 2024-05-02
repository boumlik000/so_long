/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:21:31 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/02 15:47:17 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ESC 65307
# define Q 113
# define W 119
# define S 115
# define D 100
# define A 97
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

typedef struct s_long
{
	void	*mlx;
	void	*window;

	void	*floor;
	void	*door;
	void	*coin;
	void	*wall;
	void	*player;
	void	*player_right;
	void	*player_left0;
	void	*player_left1;
	void	*player_up0;
	void	*player_up1;
	void	*player_down0;
	void	*player_down1;
	void	*door_open;

	int		map_height;
	int		map_width;

	int		map_check_y;
	int		map_check_x;

	int		count_moves;
	int		total_collect;
	int		count_coins_p;

	int		fd;
	char	*line;
	char	**map;
	int		**visited;

	int		player_x;
	int		player_y;

	int		exit_x;
	int		exit_y;

	int		map_x;
	int		map_y;

	int		exit_found;
	int		collect_found;

	int		flag_player;
	int		flag_coin;
	int		flag_exit;
}			t_long;

// window
void		validate_and_initialize(t_long *so_long, int ac, char **av);
void		calculate_map_dimensions(t_long *so_long);
void		setup_window(t_long *so_long);

// read map
int			count_lines(int fd);
int			file_count_lines(t_long *so_long, char **av);
void		read_map(t_long *so_long, char **av);

// map cheker
void		map_check_square(t_long *so_long);
void		map_chek_borders(t_long *so_long);
void		map_check_items(t_long *so_long);
int			map_check_path(char *filename);
int			check_map_is_valid(t_long *so_long, char *filename);
void		flood_fill(t_long *so_long);

// print img
void		load_images0(t_long *so_long);
void		load_images1(t_long *so_long);
void		load_images2(t_long *so_long);
void		load_images3(t_long *so_long);
void		load_images4(t_long *so_long);
void		print_images(t_long *so_long);
void		free_imgs(t_long *so_long);
void		free_images2(t_long *so_long);
void		init_variables(t_long *so_long);
void		print_images_game(t_long *so_long, int i, int j);
// player move
int			player_moves(int keycode, t_long *so_long);

// cleaning
void		cleanup_data(t_long *so_long);
int			clean_everything(t_long *so_long);
void		free_array(t_long *so_long);
void		clean_mlx(t_long *so_long);
void		clean_img(t_long *so_long);
// close
int			ft_close(int keycode, t_long *so_long);
int			ft_exit(t_long *so_long);

// additional functions
char		*ft_strnstr(const char *big, const char *little, size_t len);
void		exit_cordinations(t_long *so_long);
void		player_cordinations(t_long *so_long);
int			fill_array(t_long *so_long);
void		player_coin(t_long *so_long, int x, int y);
int			map_check_coins(t_long *so_long);
int			check_exit(t_long *so_long, int x, int y);
#endif
