/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:04:43 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 15:51:18 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int		j;

	j = 0;
	while (game->mat[j] != '\0')
	{
		free(game->mat[j]);
		j++;
	}
	free(game->mat);
}

void	ft_destroy(t_game *game, char *error)
{
	if (game->map.bordo1)
		mlx_destroy_image(game->mlx, game->map.bordo1);
	if (game->map.bordo2)
		mlx_destroy_image(game->mlx, game->map.bordo2);
	if (game->map.bordo3)
		mlx_destroy_image(game->mlx, game->map.bordo3);
	if (game->map.bordo4)
		mlx_destroy_image(game->mlx, game->map.bordo4);
	if (game->map.player)
		mlx_destroy_image(game->mlx, game->map.player);
	if (game->map.enemy)
		mlx_destroy_image(game->mlx, game->map.enemy);
	if (game->map.ostacolo)
		mlx_destroy_image(game->mlx, game->map.ostacolo);
	if (game->map.strada)
		mlx_destroy_image(game->mlx, game->map.strada);
	if (game->map.exit)
		mlx_destroy_image(game->mlx, game->map.exit);
	if (game->map.coins)
		mlx_destroy_image(game->mlx, game->map.coins);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_free(game);
	exit((write(1, error, ft_strlen(error))));
}

int	ft_destroy_window(t_game *game)
{
	if (game->map.bordo1)
		mlx_destroy_image(game->mlx, game->map.bordo1);
	if (game->map.bordo2)
		mlx_destroy_image(game->mlx, game->map.bordo2);
	if (game->map.bordo3)
		mlx_destroy_image(game->mlx, game->map.bordo3);
	if (game->map.bordo4)
		mlx_destroy_image(game->mlx, game->map.bordo4);
	if (game->map.player)
		mlx_destroy_image(game->mlx, game->map.player);
	if (game->map.enemy)
		mlx_destroy_image(game->mlx, game->map.enemy);
	if (game->map.ostacolo)
		mlx_destroy_image(game->mlx, game->map.ostacolo);
	if (game->map.strada)
		mlx_destroy_image(game->mlx, game->map.strada);
	if (game->map.exit)
		mlx_destroy_image(game->mlx, game->map.exit);
	if (game->map.coins)
		mlx_destroy_image(game->mlx, game->map.coins);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_free(game);
	exit(write(1, "Player left the game\n", 21) * 0 + 1);
}
