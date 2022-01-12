/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:49:09 by tcristin          #+#    #+#             */
/*   Updated: 2022/01/12 18:46:22 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

typedef struct s_val
{
	int			ret;
	char		*res;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
}	t_val;

char	*get_next_line(int fd);
int		ft_ft(t_val *box, char **mem, int i);
char	*ft_memcat(char **mem);
size_t	ft_strline(char *s, char pin);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
