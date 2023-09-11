/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:25:43 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/01 10:12:35 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len(n);
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n == -2147483648)
	{
		str[i--] = 56;
		n /= 10;
	}
	if (n < 0)
	{
		str[0] = 45;
		n *= -1;
	}
	while (i >= 0 && str[i] != 45)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
