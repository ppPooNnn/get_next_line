/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:01:17 by puttasa           #+#    #+#             */
/*   Updated: 2022/09/20 15:08:11 by puttasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_mod(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != c)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sumsize;
	int		count;
	int		i;
	char	*str;

	count = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	sumsize = ft_strlen(s1, '\0') + ft_strlen(s2, '\0');
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	relen;
	char	*substr;

	i = 0;
	if (!s)
		return (0);
	relen = len;
	if (start > ft_strlen(s))
		relen = 0;
	else if (ft_strlen(s) - start < len)
		relen = ft_strlen(s) - start;
	substr = malloc(relen + 1);
	if (!substr)
		return (0);
	ft_bzero (substr, relen + 1);
	while (s[start] != '\0' && start < ft_strlen(s) && i < relen)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}
