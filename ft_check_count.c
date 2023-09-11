/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:33:04 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 10:55:11 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_count(t_game *game)
{
	int			i;
	int			j;
	int			p;
	int			e;

	p = 0;
	e = 0;
	j = -1;
	while (game->mat[++j] != '\0')
	{
		i = -1;
		while (game->mat[j][++i] != '\0')
		{
			if (game->mat[j][i] == 80)
				p++;
			if (game->mat[j][i] == 67)
				game->player.coins_count++;
			if (game->mat[j][i] == 69)
				e++;
		}
	}
	if (p == 0 || e == 0 || game->player.coins_count == 0)
		exit(write(1, "Error\nInvalid Map\n", 19) * 0);
}
