/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:31:13 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 17:00:33 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_input(char *s)
{
	int	l;

	l = ft_strlen(s);
	if (!(s[l - 1] == 'r' && s[l - 2] == 'e' && s[l - 3]
			== 'b' && s[l - 4] == '.'))
		exit(write(1, "Error\nInvalid input\n", 21) * 0 + 1);
}

void	ft_image(t_game *game)
{
	game->map.bordo1 = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/Bordo_Vd.xpm", &game->img_width, &game->img_height);
	game->map.bordo2 = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/Bordo_Oa.xpm", &game->img_width, &game->img_height);
	game->map.bordo3 = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/Bordo_Vs.xpm", &game->img_width, &game->img_height);
	game->map.bordo4 = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/Bordo_Ob.xpm", &game->img_width, &game->img_height);
	game->map.exit = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/Exit2.xpm", &game->img_width, &game->img_height);
	game->map.coins = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Coins_frame/Coins4.xpm",
			&game->img_width, &game->img_height);
	game->map.strada = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/Strada.xpm", &game->img_width, &game->img_height);
	game->map.ostacolo = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Maps/ostacolo.xpm", &game->img_width, &game->img_height);
	game->map.player = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Mario_frame/Mario_Dx.xpm",
			&game->img_width, &game->img_height);
	game->map.enemy = mlx_xpm_file_to_image(game->mlx,
			"./Modelli/Guscio_frame/Guscio.xpm",
			&game->img_width, &game->img_height);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
		return (write(1, "Error\nInvalid input\n", 21));
	ft_check_input(argv[1]);
	game.mat = ft_mat(&game, argv[1]);
	ft_check_count(&game);
	ft_check_map(&game);
	ft_check_simbols(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx,
			game.i * 50, game.j * 50, "Mario_Kart");
	ft_image(&game);
	if (!(game.map.bordo1) || !(game.map.bordo2) || !(game.map.bordo3)
		|| !(game.map.bordo4) || !(game.map.exit) || !(game.map.coins)
		|| !(game.map.strada) || !(game.map.ostacolo) || !(game.map.player)
		|| !(game.map.enemy))
		ft_destroy(&game, "Error\nImage upload error\n");
	ft_print_map(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_loop_hook(game.mlx, ft_loop_coins, &game);
	mlx_hook(game.mlx_win, 17, 0, ft_destroy_window, &game);
	mlx_loop(game.mlx);
}

	// game.map.bordo1 = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/Bordo_Vd.xpm", &game.img_width, &game.img_height);
	// game.map.bordo2 = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/Bordo_Oa.xpm", &game.img_width, &game.img_height);
	// game.map.bordo3 = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/Bordo_Vs.xpm", &game.img_width, &game.img_height);
	// game.map.bordo4 = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/Bordo_Ob.xpm", &game.img_width, &game.img_height);
	// game.map.exit = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/Exit2.xpm", &game.img_width, &game.img_height);
	// game.map.coins = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Coins_frame/Coins4.xpm",
	// 		&game.img_width, &game.img_height);
	// game.map.strada = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/Strada.xpm", &game.img_width, &game.img_height);
	// game.map.ostacolo = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Maps/ostacolo.xpm", &game.img_width, &game.img_height);
	// game.map.player = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Mario_frame/Mario_Dx.xpm",
	// 		&game.img_width, &game.img_height);
	// game.map.enemy = mlx_xpm_file_to_image(game.mlx,
	// 		"./Modelli/Guscio_frame/Guscio.xpm",
	// 		&game.img_width, &game.img_height);
