/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipkim <gipkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:11:51 by gipkim            #+#    #+#             */
/*   Updated: 2021/01/15 17:05:47 by gipkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static f_l	*openfiles;
	f_l			*f;
	int			i;

	f = openfiles;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	while (f != NULL & f->fd != fd)
		f = f->next;
	if (f->fd != fd)
		f = new_fd(openfiles, fd);
	else
		free(f->line_buff);
	i = 0;
	f->index_of_char = 0;
	f->line_buff = NULL;
	while ((f->read_buff_size = read(fd, f->read_buff, BUFFER_SIZE)) > 0)
	{
		if (f->index_of_char + f->read_buff_size < f->indicator)
			f->index_of_char += f->read_buff_size;
		else
		{
			i += f->read_buff_size;
			f->tmp = f->line_buff;
			if (!(f->line_buff = (char*)malloc(sizeof(char) * (i + 1))))
				return (-1);
			if (line_append(f))
			{
				*line = f->line_buff;
				return (1);
			}
		}
	}
	if (f->read_buff_size == 0)
	{
		if (f->line_buff)
		{
			*line = f->line_buff;
			return (1);
		}
		f->line_buff = (char*)malloc(sizeof(char) * 1);
		f->line_buff[0] = '\0';
		*line = f->line_buff;
		return (0);
	}
	return (-1);
}
