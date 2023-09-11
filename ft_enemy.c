/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:23:23 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 12:34:32 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_damage(t_game *game)
{
	if (game->player.x_enemy == game->player.x
		&& game->player.y_enemy == game->player.y)
		ft_destroy(game, "You lose!\n");
}
