/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:21:56 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/02 14:15:05 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves(t_game *game)
{
	char	*m;
	char	*st;

	m = ft_itoa(game->player.mosse + 1);
	st = ft_strjoin("Mosse: ", m);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.bordo2, 100, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.bordo2, 50, 0);
	mlx_string_put(game->mlx, game->mlx_win, 50, 20, 0xFFFFFF, st);
	write(1, "Mosse: ", 7);
	write(1, m, ft_strlen(m));
	write(1, "\n", 1);
	free(m);
	free(st);
}
