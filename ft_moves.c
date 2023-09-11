/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:15:30 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 16:13:39 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		game->player.mosse += ft_move_up(game);
	else if (keycode == 0 || keycode == 123)
		game->player.mosse += ft_move_sx(game);
	else if (keycode == 1 || keycode == 125)
		game->player.mosse += ft_move_down(game);
	else if (keycode == 2 || keycode == 124)
		game->player.mosse += ft_move_dx(game);
	else if (keycode == 53)
		exit(write(1, "Player left the game\n", 21) * 0 + 1);
	if (game->player.get_coins == game->player.coins_count)
	{
		mlx_destroy_image(game->mlx, game->map.exit);
		game->map.exit = mlx_xpm_file_to_image(game->mlx,
				"./Modelli/Maps/Exit1.xpm",
				&game->img_width, &game->img_height);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.exit, game->player.x_exit * 50, game->player.y_exit * 50);
	if (game->mat[game->player.y][game->player.x] == 69 &&
		game->player.get_coins == game->player.coins_count)
		ft_destroy(game, "You win!\n");
	ft_damage(game);
	return (0);
}

int	ft_move_up(t_game *game)
{
	if (game->mat[game->player.y - 1][game->player.x] == 49
		|| (game->mat[game->player.y - 1][game->player.x] == 69
		&& game->player.get_coins != game->player.coins_count))
		return (write(1, "\a", 1) * 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.strada, game->player.x * 50, game->player.y * 50);
	mlx_destroy_image(game->mlx, game->map.player);
	game->map.player = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Mario_frame/Mario_Back.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.player, game->player.x * 50, (game->player.y - 1) * 50);
	game->player.y -= 1;
	if (game->mat[game->player.y][game->player.x] == 67)
	{
		game->mat[game->player.y][game->player.x] = 48;
		game->player.get_coins++;
	}
	ft_print_moves(game);
	return (1);
}

int	ft_move_sx(t_game *game)
{
	if (game->mat[game->player.y][game->player.x - 1] == 49
		|| (game->mat[game->player.y][game->player.x - 1] == 69
		&& game->player.get_coins != game->player.coins_count))
		return (write(1, "\a", 1) * 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.strada, game->player.x * 50, game->player.y * 50);
	mlx_destroy_image(game->mlx, game->map.player);
	game->map.player = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Mario_frame/Mario_Sx.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.player, (game->player.x - 1) * 50, game->player.y * 50);
	game->player.x -= 1;
	if (game->mat[game->player.y][game->player.x] == 67)
	{
		game->mat[game->player.y][game->player.x] = 48;
		game->player.get_coins++;
	}
	ft_print_moves(game);
	return (1);
}

int	ft_move_down(t_game *game)
{
	if (game->mat[game->player.y + 1][game->player.x] == 49
		|| (game->mat[game->player.y + 1][game->player.x] == 69
		&& game->player.get_coins != game->player.coins_count))
		return (write(1, "\a", 1) * 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.strada, game->player.x * 50, game->player.y * 50);
	mlx_destroy_image(game->mlx, game->map.player);
	game->map.player = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Mario_frame/Mario_Front.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.player, game->player.x * 50, (game->player.y + 1) * 50);
	game->player.y += 1;
	if (game->mat[game->player.y][game->player.x] == 67)
	{
		game->mat[game->player.y][game->player.x] = 48;
		game->player.get_coins++;
	}
	ft_print_moves(game);
	return (1);
}

int	ft_move_dx(t_game *game)
{
	if (game->mat[game->player.y][game->player.x + 1] == 49
		|| (game->mat[game->player.y][game->player.x + 1] == 69
		&& game->player.get_coins != game->player.coins_count))
		return (write(1, "\a", 1) * 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.strada, game->player.x * 50, game->player.y * 50);
	mlx_destroy_image(game->mlx, game->map.player);
	game->map.player = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Mario_frame/Mario_Dx.xpm",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.player, (game->player.x + 1) * 50, game->player.y * 50);
	game->player.x += 1;
	if (game->mat[game->player.y][game->player.x] == 67)
	{
		game->mat[game->player.y][game->player.x] = 48;
		game->player.get_coins++;
	}
	ft_print_moves(game);
	return (1);
}

/*
void	ft_get_img(t_game *game, int x, int y)
{
	mlx_destroy_image(game->mlx, game->map.player);
	if (y == -1)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./Modelli/Mario_frame/Mario_Back.xpm",
				&game->img_width, &game->img_height);
	else if (y == 1)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./Modelli/Mario_frame/Mario_Front.xpm",
				&game->img_width, &game->img_height);
	else if (x == -1)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./Modelli/Mario_frame/Mario_Sx.xpm",
				&game->img_width, &game->img_height);
	else if (x == 1)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./Modelli/Mario_frame/Mario_Dx.xpm",
				&game->img_width, &game->img_height);
	else
		exit(1);
}

int	ft_move_all(t_game *game, int x, int y)
{
	if (game->mat[game->player.y + y][game->player.x + x] == 49
		|| (game->mat[game->player.y + y][game->player.x + x] == 69
		&& game->player.get_coins != game->player.coins_count))
		return (write(1, "\a", 1) * 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.strada, game->player.x * 50, game->player.y * 50);
	ft_get_img(game, x, y);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.player, (game->player.x + x) * 50, (game->player.y + y) * 50);
	game->player.x += x;
	game->player.y += y;
	if (game->mat[game->player.y][game->player.x] == 67)
	{
		game->mat[game->player.y][game->player.x] = 48;
		game->player.get_coins++;
	}
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	printf("Mosse: %d\n", game->player.mosse);
	if (keycode == 13 || keycode == 126)
		game->player.mosse += ft_move_all(game, 0, -1);
	else if (keycode == 0 || keycode == 123)
		game->player.mosse += ft_move_all(game, -1, 0);
	else if (keycode == 1 || keycode == 125)
		game->player.mosse += ft_move_all(game, 0, 1);
	else if (keycode == 2 || keycode == 124)
		game->player.mosse += ft_move_all(game, 1, 0);
	else if (keycode == 53)
		exit(1);
	if (game->player.get_coins == game->player.coins_count)
	{
		mlx_destroy_image(game->mlx, game->map.exit);
		game->map.exit = mlx_xpm_file_to_image(game->mlx,
				"./Modelli/Maps/Exit1.xpm",
				&game->img_width, &game->img_height);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.exit, game->player.x_exit * 50, game->player.y_exit * 50);
	if (game->mat[game->player.y][game->player.x] == 69 &&
		game->player.get_coins == game->player.coins_count)
		exit((printf("You win!")));
	ft_damage(game);
	return (0);
}
*/