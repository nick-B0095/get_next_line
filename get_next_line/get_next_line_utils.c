/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipkim <gipkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:12:01 by gipkim            #+#    #+#             */
/*   Updated: 2021/01/15 16:52:20 by gipkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

f_l *new_fd(f_l *files, int fd)
{
	f_l *tmp;

	tmp->fd = fd;
	tmp->indicator = 0;
	tmp->next = NULL;
	if (files)
	{
		while (files->next)
			files = files->next;
		files->next = &tmp;
		files = files->next;
	}
	return (tmp);
}

int line_append(f_l *f)
{
	int i;
	int j;

	i = 0;
	while (f->tmp[i])
	{
		f->line_buff[i] = f->tmp[i];
		i++;
	}
	j = 0;
	while (j < f->read_buff_size)
	{
		if (f->index_of_char++ > f->indicator)
		{
			f->line_buff[i++] = f->read_buff[j];
			if (f->read_buff[j] == '\n')
			{
				f->indicator = f->index_of_char;
				f->line_buff[i++] = '\0';
				return (1);
			}
		}
		j++;
	}
	f->indicator = f->index_of_char;
	f->line_buff[i] = '\0';
	return (0);
}
