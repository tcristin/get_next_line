/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:49:20 by tcristin          #+#    #+#             */
/*   Updated: 2022/01/02 14:43:51 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strline(char *s, char end)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != end)
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s2)
		return (NULL);
	len1 = ft_strline(s1, '\0');
	len2 = ft_strline(s2, '\0');
	str = malloc((len1 + len2 + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len2 + len1)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strline(s, '\0');
	if (!s)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strline(s, '\0'))
		len = ft_strline(s, '\0');
	str = malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (j < len && i >= start)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
