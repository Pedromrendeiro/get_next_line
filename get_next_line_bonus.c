/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaustin <pfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:39:41 by pfaustin          #+#    #+#             */
/*   Updated: 2024/10/22 17:11:08 by pfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
			while (buff[fd][i])
				buff[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*(buff[fd]) || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		if (newline(buff[fd]) == 1)
			break ;
	}
	return (line);
}

