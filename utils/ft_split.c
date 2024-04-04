/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:38:32 by fsariogl          #+#    #+#             */
/*   Updated: 2022/06/04 15:01:40 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;
	int		nb;

	i = 0;
	if (!s)
		return (0);
	while (i <= start)
	{
		if (s[i] == '\0')
			return (ft_calloc(1, 1));
		i++;
	}
	nb = len + start;
	if (nb > ft_strlen(s))
		len = ft_strlen(s) - start;
	i = 0;
	ns = malloc(sizeof(char) * len + 1);
	if (!ns)
		return (NULL);
	while (i < len && s[start] != '\0')
		ns[i++] = s[start++];
	ns[i] = '\0';
	return (ns);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	c = malloc(count * size);
	if (!c)
		return (NULL);
	ft_bzero(c, count * size);
	return (c);
}

char	**ft_split(char *str, char c)
{
	int		d;
	int		f;
	int		l;
	char	**tabstr;

	f = 0;
	l = 0;
	if (!str)
		return (NULL);
	tabstr = malloc(sizeof(char **) * (ft_count_words(str, c) + 1));
	if (!tabstr)
		return (NULL);
	while (str[f])
	{
		while (str[f] == c && str[f])
			f++;
		d = f;
		while (str[f] != c && str[f])
			f++;
		if (str[f] || str[f - 1] != c)
			tabstr[l++] = ft_substr(str, d, (f - d));
	}
	tabstr[l] = NULL;
	return (tabstr);
}
