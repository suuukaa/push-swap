/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:48 by sel-bouy          #+#    #+#             */
/*   Updated: 2023/12/10 14:30:01 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *h)
{
	size_t	i;

	i = 0;
	if (!h)
		return (0);
	while (h[i] != '\0')
		i++;
	return (i);
}

char	*ft_search(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_help_join(char *s1, char *s2, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			buff[i] = s1[i];
			i++;
		}
		free(s1);
	}
	if (s2)
	{
		while (s2[j] != '\0')
		{
			buff[i] = s2[j];
			i++;
			j++;
		}
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0 && s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buff = malloc (s1_len + s2_len + 1);
	if (!buff)
		return (NULL);
	return (ft_help_join(s1, s2, buff));
}
