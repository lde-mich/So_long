/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:08:31 by lde-mich          #+#    #+#             */
/*   Updated: 2023/02/21 18:42:41 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return ((char *) s1);
	str1 = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str1)
		return (0);
	i = -1;
	while (s1[++i])
		str1[i] = s1[i];
	j = 0;
	while (s2[j])
		str1[i++] = s2[j++];
	str1[i] = '\0';
	return (str1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		len_s;

	if (!s || !len)
		return (ft_strdup(""));
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s)
		len = len_s;
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if ((start + len) > len_s)
		len = len_s - start;
	i = 0;
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*ptr;
	int		i;

	len = ft_strlen(s1);
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (ptr == '\0')
		return (0);
	i = 0;
	while (i <= len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	*ptr;

	if (!c)
		return ((char *)&str[ft_strlen(str)]);
	ptr = (unsigned char *) str;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	return (0);
}
