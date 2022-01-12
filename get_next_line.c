/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:49:02 by tcristin          #+#    #+#             */
/*   Updated: 2022/01/12 19:15:56 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_val		val;
	static char	*mem = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	val.ret = read(fd, val.buff, BUFFER_SIZE);
	if (!ft_ft(&val, &mem, 0) && !mem)
		return (NULL);
	while (!ft_strchr(mem, '\n'))
	{
		val.ret = read(fd, val.buff, BUFFER_SIZE);
		if (val.ret >= 0)
		{
			if (val.ret == 0)
			{
				ft_ft(&val, &mem, 1);
				val.res = ft_memcat(&mem);
				return (val.res);
			}
			ft_ft(&val, &mem, 1);
		}
	}
	val.res = ft_memcat(&mem);
	return (val.res);
}

int	ft_ft(t_val *val, char **mem, int i)
{
	if (i == 0 && val->ret <= 0)
		return (0);
	val->buff[val->ret] = '\0';
	val->tmp = *mem;
	*mem = ft_strjoin(*mem, val->buff);
	if (val->tmp)
		free(val->tmp);
	return (1);
}

char	*ft_memcat(char **mem)
{
	char	*res;
	char	*tmp;
	size_t	slash_n;

	slash_n = ft_strline(*mem, '\n') + 1;
	res = ft_substr(*mem, 0, slash_n);
	tmp = ft_substr(*mem, slash_n, ft_strline(*mem, '\0'));
	if (*mem)
		free(*mem);
	*mem = tmp;
	if (!tmp[0])
	{
		free(tmp);
		*mem = NULL;
	}
	return (res);
}

int	main(void)
{
	int		i;
	int		fd;
	char	*str;

	fd = open("file", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
