/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipkim <gipkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:06:39 by gipkim            #+#    #+#             */
/*   Updated: 2021/01/15 16:44:45 by gipkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

typedef struct f_list
{
	int				fd;
	char			*line_buff;
	char			*tmp;
	char			read_buff[BUFFER_SIZE];
	int				read_buff_size;
	int				indicator;
	int				index_of_char;
	struct f_list	*next;
}					f_l;

int	get_next_line(int fd, char **line);

f_l *new_fd(f_l *files, int fd);

int line_append(f_l *f);
