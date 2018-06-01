/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:00:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/01/18 10:42:52 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		free_gnl(char *buf, int n)
{
	free(buf);
	return (n);
}

static t_list	*get_fd(t_list **save, int fd)
{
	t_list	*tmp;

	tmp = *save;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = fd;
	tmp->content = ft_strnew(0);
	ft_lstadd(save, tmp);
	return (tmp);
}

static int		get_one_line(char **line, char *content, char *buf, int ret)
{
	char	*temp_c;

	ret == 0 ? free(buf) : 0;
	if (content == NULL)
		return (0);
	temp_c = ft_strchr(content, '\n');
	if (temp_c != NULL)
	{
		*temp_c = '\0';
		*line = ft_strdup(content);
		temp_c = temp_c + 1;
		ft_strcpy(content, temp_c);
		return (1);
	}
	else if (ft_strlen(content) > 0)
	{
		*line = ft_strdup(content);
		*content = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*save;
	t_list			*temp;
	char			*buf;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!save)
		save = get_fd(&save, fd);
	temp = get_fd(&save, fd);
	buf = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(buf, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (free_gnl(buf, -1));
		if (ret == 0)
			return (get_one_line(line, temp->content, buf, ret));
		buf[ret] = '\0';
		*line = ft_strjoin(temp->content, buf);
		free(temp->content);
		temp->content = *line;
	}
	free(buf);
	return (get_one_line(line, temp->content, buf, ret));
}
