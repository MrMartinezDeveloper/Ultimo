/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikemart <mikemart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:18:40 by mikemart          #+#    #+#             */
/*   Updated: 2024/12/27 17:18:40 by mikemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_str(char *str, unsigned int num, size_t len,
		int is_negative)
{
	if (is_negative)
		str[0] = '-';
	while (len-- && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;
	int				is_negative;

	len = ft_numlen(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		num = -n;
	}
	else
	{
		num = n;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_fill_str(str, num, len, is_negative);
	return (str);
}
