/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:01:17 by puttasa           #+#    #+#             */
/*   Updated: 2022/09/28 00:41:52 by puttasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_mod(char *str, char c)
{
	size_t	len;

	len = 0;
	if (!*str)
		return (0);
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		sumsize;
	int		count;
	int		i;
	char	*str;

	count = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	sumsize = ft_strlen_mod(s1, '\0') + ft_strlen_mod(s2, '\0');
	str = malloc(sumsize + 1);
	if (!str)
	{
		free(s1);
		return (0);
	}
	while (count < sumsize && s1[i])
		str[count++] = s1[i++];
	i = 0;
	while (count < sumsize && s2[i])
		str[count++] = s2[i++];
	str[count] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	relen;
	char	*substr;

	i = 0;
	if (!s)
	{
		free(s);
		return (0);
	}
	relen = len;
	if (start > ft_strlen_mod(s, '\0'))
		relen = 0;
	else if (ft_strlen_mod(s, '\0') - start < len)
		relen = ft_strlen_mod(s, '\0') - start;
	substr = malloc(relen + 1);
	if (!substr)
		return (0);
	ft_bzero (substr, relen + 1);
	while (s[start] != '\0' && start < ft_strlen_mod(s, '\0') && i < relen)
	{
		substr[i++] = s[start++];
	}
	return (substr);
}

char	*ft_strrchr(char *s, int c)
{
	int	len;

	len = ft_strlen_mod(s, '\0');
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		*(char *)(s + count) = '\0';
		count++;
	}
}
