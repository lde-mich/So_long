/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:44:58 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/03 10:59:47 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->mat[j] != '\0')
	{
		i = 0;
		while (i < game->i)
		{
			if (j == 0 && i < game->i && game->mat[j][i] != 49)
				exit(write(1, "Error\nthe map must be surrounded by wall\n", 41));
			else if (i == 0 && game->mat[j][i] != 49)
				exit(write(1, "Error\nthe map must be surrounded by wall\n", 41));
			else if (i == game->i - 1
				&& j > 0 && game->mat[j][i] != 49)
				exit(write(1, "Error\nthe map must be surrounded by wall\n", 41));
			else if (j == game->j - 1
				&& i < game->i - 1 && game->mat[j][i] != 49)
				exit(write(1, "Error\nthe map must be surrounded by wall\n", 41));
			i++;
		}
		j++;
	}
}

void	ft_check_simbols(t_game *game)
{
	int			i;
	int			j;

	j = 0;
	while (game->mat[j] != '\0')
	{
		i = 0;
		while (game->mat[j][i] != '\0')
		{
			if (!(game->mat[j][i] == 49 || game->mat[j][i]
				== 67 || game->mat[j][i]
				== 69 || game->mat[j][i] == 48 || game->mat[j][i]
				== 70 || game->mat[j][i] == 80))
			{
				exit(write(1, "Error\nSymbol not supported for the map\n", 39));
			}
			i++;
		}
		j++;
	}
}
