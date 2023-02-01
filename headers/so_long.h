/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:32:01 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/01 11:50:11 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../GNL/get_next_line.h"
# include "errors.h"
# include <mlx.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdlib.h>

struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*collec;
	void	*exit_c;
	void	*exit_o;
	void	*wall;
	void	*floor;
	int		stars;
	int		movements;
	int		col;
	int		line;
	int		player_line;
	int		player_col;
};	typedef struct s_mlx t_mlx;

/*------------------------SO_LONG FUNCTIONS----------------------------*/
int		main(int argc, char **argv);
void	ft_struct_init(t_mlx *window);
int		ft_check_errors(t_mlx *window, char *path);
void	ft_print_error(char *error);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*-----------------------GAME_RULES FUNCTIONS--------------------------*/
int		ft_init_game(t_mlx *window);
void	ft_put_sprites(t_mlx *window);
void	ft_sprites(t_mlx *window, void **image, char *path);
int		ft_close(t_mlx *window);

/*-----------------------MAP_RULES FUNCTIONS---------------------------*/
int		ft_create_map(t_mlx *window, char *path);
void	ft_put_image_to_window(t_mlx *window, void *image, int x, int y);
char	**ft_dup_map(t_mlx *window);
int		ft_read_map(t_mlx *window, char *path);
void	ft_free_matrix(char **matrix);

/*-----------------------MAP_RULES_UTILS FUNCTIONS--------------------*/
int		ft_show_map(t_mlx *window);
int		ft_show_moves(t_mlx *window);
void	ft_locate_player(t_mlx *window);
int		ft_key_input(int key, t_mlx *window);
void	ft_hook_limits(t_mlx *window, int col, int line);

/*-------------------------IMAGES_RULES FUNCTIONS---------------------*/
int		ft_valid_walls(t_mlx *window);
int		ft_check_characters(t_mlx *window, int e, int p, int invalid);
int		ft_valid_character(t_mlx *window);
int		ft_check_path(char **copy, t_mlx *window);
void	ft_test_path(char **copy, int line, int col, t_mlx *window);

/*--------------------IMAGES_RULES_UTILS FUNCTIONS--------------------*/
int		ft_count_lines(int fd, char *temp, t_mlx *window);
int		ft_count_col(char *temp);
int		ft_count_collectibles(t_mlx *window);
int		ft_check_exit(int exit, int collec);
int		ft_close_and_free(int fd, char *temp);

#endif
