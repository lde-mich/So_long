/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:45:20 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/02 15:55:53 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(t_game *game, char *path)
{
	char	*l;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(write(1, "Error\nMap not found\n", 20));
	l = get_next_line(fd);
	game->i = ft_strlen(l) - 1;
	while (l)
	{
		if (l[ft_strlen(l) - 1] == '\n')
			l[ft_strlen(l) - 1] = 0;
		if (ft_strlen(l) != game->i)
		{
			free(l);
			exit(write(1, "Error\nMap is not rectangle\n", 27));
		}
		free(l);
		l = get_next_line(fd);
		game->j++;
	}
	if (game->i == game->j)
		exit(write(1, "Error\nMap is not rectangle\n", 27));
	close(fd);
}

char	**ft_mat(t_game *game, char *path)
{
	char	**mat;
	char	*l;
	int		fd;
	int		j;

	ft_check_rectangle(game, path);
	mat = (char **)malloc((game->j + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(write(1, "Error\nMap not found\n", 20));
	l = get_next_line(fd);
	game->i = ft_strlen(l) - 1;
	j = 0;
	while (l)
	{
		if (l[ft_strlen(l) - 1] == '\n')
			l[ft_strlen(l) - 1] = 0;
		mat[j] = l;
		l = get_next_line(fd);
		j++;
	}
	mat[game->j] = 0;
	close(fd);
	return (mat);
}
