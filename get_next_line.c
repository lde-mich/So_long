/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:39:53 by lde-mich          #+#    #+#             */
/*   Updated: 2023/02/21 18:46:34 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_temp_line(int fd, char *buffer, char *backup)
{
	int		r;
	char	*temp;

	r = 1;
	while (r != '\0')
	{
		r = read(fd, buffer, 1);
		if (r == -1)
			return (0);
		else if (r == 0)
			break ;
		buffer[r] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = 0;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_backup(char *line)
{
	size_t	i;
	char	*backup;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = 0;
	}
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || 1 <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (0);
	line = ft_temp_line(fd, buffer, backup);
	free(buffer);
	buffer = 0;
	if (!line)
		return (0);
	backup = ft_backup(line);
	return (line);
}
