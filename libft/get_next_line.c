/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:41:15 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/04 14:15:39 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_myjoin(char *s1, char const *s2)
{
	char	*fresh;
	int		lentotal;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fresh = NULL;
	if (!s1 || !s2)
		return (NULL);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	if (!(fresh = (char *)malloc((sizeof(*fresh) * lentotal) + 1)))
		return (NULL);
	while (s1 && s1[j])
		fresh[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] && s2[j] != 10)
		fresh[i++] = s2[j++];
	fresh[i] = '\0';
	free(s1);
	return (fresh);
}

int		ft_normit(char **line, char **str, char **temp, char *buf)
{
	if ((*str = ft_myjoin(*str, buf)) == NULL)
		return (-1);
	if ((*temp = ft_strstr(buf, "\n")) != NULL)
	{
		*temp += 1;
		*temp = ft_strdup(*temp);
		*line = *str;
		return (1);
	}
	return (0);
}

int		ft_oneline(char **line, char **str)
{
	*line = *str;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*str;
	static char	*temp[2559];
	int			ret;
	int			state;

	str = ft_strdup("\0");
	if (fd > 2559 || line == NULL || BUFF_SIZE < 1 || fd < 0)
		return (-1);
	if (temp[fd] != NULL)
		if ((state = ft_normit(line, &str, &temp[fd], temp[fd])))
			return (state);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((state = ft_normit(line, &str, &temp[fd], buf)))
			return (state);
	}
	if (ret == 0 && *str != '\0')
		return (ft_oneline(line, &str));
	if (ret == -1)
		return (-1);
	return (0);
}
