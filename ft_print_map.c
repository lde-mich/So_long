/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:17:08 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 15:49:07 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_angoli(t_game *game)
{
	void	*angolo;

	angolo = mlx_xpm_file_to_image(game->mlx, "./Modelli/Maps/angolo_As.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		angolo, 0, 0);
	mlx_destroy_image(game->mlx, angolo);
	angolo = mlx_xpm_file_to_image(game->mlx, "./Modelli/Maps/angolo_Bd.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		angolo, (game->i - 1) * 50, (game->j - 1) * 50);
	mlx_destroy_image(game->mlx, angolo);
	angolo = mlx_xpm_file_to_image(game->mlx, "./Modelli/Maps/angolo_Bs.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		angolo, 0, (game->j - 1) * 50);
	mlx_destroy_image(game->mlx, angolo);
	angolo = mlx_xpm_file_to_image(game->mlx, "./Modelli/Maps/angolo_Ad.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		angolo, (game->i - 1) * 50, 0);
	mlx_destroy_image(game->mlx, angolo);
}

void	ft_bordi0(t_game *game, int j, int i)
{
	if (i > 0 && j == 0 && i < game->i - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.bordo2, i * 50, j * 50);
	else if (i == 0 && j < game->j - 1 && j > 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.bordo1, i * 50, j * 50);
}

void	ft_bordi1(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->mat[j] != '\0')
	{
		i = 0;
		while (game->mat[j][i] != '\0')
		{
			if (i == game->i - 1 && j < game->j - 1 && j > 0)
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->map.bordo3, i * 50, j * 50);
			else if (j == game->j - 1 && i > 0 && i < game->i - 1)
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->map.bordo4, i * 50, j * 50);
			else if (i != 0 && i != game->i - 1
				&& j != 0 && j != game->j - 1 && game->mat[j][i] == 49)
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->map.ostacolo, i * 50, j * 50);
			else
				ft_bordi0(game, j, i);
			i++;
		}
		j++;
	}
}

void	ft_print_map0(t_game *game, int j, int i)
{
	if (game->mat[j][i] != 49)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.strada, i * 50, j * 50);
	if (game->mat[j][i] == 80)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.player, i * 50, j * 50);
		game->player.x = i;
		game->player.y = j;
	}
	if (game->mat[j][i] == 67)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.coins, i * 50 + 10, j * 50 + 10);
	if (game->mat[j][i] == 69)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.exit, i * 50, j * 50);
		game->player.x_exit = i;
		game->player.y_exit = j;
	}
}

void	ft_print_map(t_game *game)
{
	int			i;
	int			j;

	j = 0;
	while (game->mat[j] != '\0')
	{
		i = 0;
		while (game->mat[j][i] != '\0')
		{
			ft_print_map0(game, j, i);
			if (game->mat[j][i] == 70)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->map.enemy, i * 50 + 5, j * 50 + 5);
				game->player.x_enemy = i;
				game->player.y_enemy = j;
			}
			i++;
		}
		j++;
	}
	ft_angoli(game);
	ft_bordi1(game);
}

			// if (i > 0 && j == 0 && i < game->i - 1)
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 		game->map.bordo2, i * 50, j * 50);
			// else if (i == 0 && j < game->j - 1 && j > 0)
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 		game->map.bordo1, i * 50, j * 50);
			// if (game->mat[j][i] != 49)
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 		game->map.strada, i * 50, j * 50);
			// if (game->mat[j][i] == 80)
			// {
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 		game->map.player, i * 50, j * 50);
			// 	game->player.x = i;
			// 	game->player.y = j;
			// }
			// if (game->mat[j][i] == 67)
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 		game->map.coins, i * 50 + 10, j * 50 + 10);
			// if (game->mat[j][i] == 69)
			// {
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 		game->map.exit, i * 50, j * 50);
			// 	game->player.x_exit = i;
			// 	game->player.y_exit = j;
			// }