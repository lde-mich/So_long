/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coins_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:10:33 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/01 17:17:01 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_coin_delay(t_game *game, int time)
{
	while (game->delay < time)
	{
		game->delay++;
		return (0);
	}
	game->delay = 0;
	game->animation++;
	return (1);
}

int	ft_loop_coins(t_game *game)
{
	if (!(ft_coin_delay(game, 500)))
		return (0);
	ft_put_coins(game);
	return (1);
}

void	ft_path_coins(t_game *game)
{
	char	*str;
	char	*conv;
	char	*str_path;

	conv = ft_itoa(game->animation);
	str = ft_strjoin("./Modelli/Coins_frame/Coins", conv);
	str_path = ft_strjoin(str, ".xpm");
	mlx_destroy_image(game->mlx, game->map.coins);
	game->map.coins = mlx_xpm_file_to_image(game->mlx,
			str_path, &game->img_width, &game->img_height);
	if (!game->map.coins)
		exit(write(1, "Map loading error\n", 19));
	free(conv);
	free(str);
	free(str_path);
}

void	ft_set_img(t_game *game, int j, int i)
{
	int	k;

	k = 0;
	ft_path_coins(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.strada, i * 50, j * 50);
	while (k++ < 100)
		;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.coins, i * 50 + 10, j * 50 + 10);
}

void	ft_put_coins(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->mat[j] != '\0')
	{
		i = 0;
		while (game->mat[j][i] != '\0')
		{
			if (game->mat[j][i] == 67)
				ft_set_img(game, j, i);
			i++;
		}
		j++;
	}
	if (game->animation == 8)
		game->animation = 0;
}
