/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:17:21 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 16:13:51 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	void			*coins;
	void			*bordo1;
	void			*bordo2;
	void			*bordo3;
	void			*bordo4;
	void			*ostacolo;
	void			*player;
	void			*enemy;
	void			*exit;
	void			*strada;
}	t_map;

typedef struct s_player
{
	int				x;
	int				y;
	int				x_enemy;
	int				y_enemy;
	int				mosse;
	int				x_exit;
	int				y_exit;
	int				get_coins;
	int				coins_count;
}	t_player;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	char			**mat;
	void			*mlx;
	void			*mlx_win;
	void			*mlx_win_start;
	void			*img;
	int				img_width;
	int				img_height;
	int				i;
	int				j;
	int				time;
	int				delay;
	int				animation;
}	t_game;

char		**ft_mat(t_game *game, char *path);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(char *s1);
char		*ft_strchr(const char *str, int c);
char		*ft_backup(char *line);
char		*ft_temp_line(int fd, char *buffer, char *backup);
int			key_hook(int keycode, t_game *game);
void		ft_angoli(t_game *game);
void		ft_print_map0(t_game *game, int j, int i);
void		ft_print_map(t_game *game);
void		ft_bordi0(t_game *game, int j, int i);
void		ft_bordi1(t_game *game);
int			ft_move_up(t_game *game);
int			ft_move_sx(t_game *game);
int			ft_move_down(t_game *game);
int			ft_move_dx(t_game *game);
void		ft_check_count(t_game *game);
void		ft_check_map(t_game *game);
void		ft_check_rectangle(t_game *game, char *path);
int			ft_coin_delay(t_game *game, int time);
int			ft_len(int n);
char		*ft_itoa(int n);
void		ft_path_coins(t_game *game);
void		ft_set_img(t_game *game, int j, int i);
void		ft_put_coins(t_game *game);
int			ft_loop_coins(t_game *game);
void		ft_damage(t_game *game);
void		ft_print_moves(t_game *game);
void		ft_check_input(char *s);
void		ft_check_simbols(t_game *game);
void		ft_destroy(t_game *game, char *error);
void		ft_free(t_game *game);
int			ft_destroy_window(t_game *game);
void		ft_image(t_game *game);

#endif