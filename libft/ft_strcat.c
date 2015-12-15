/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:17:58 by tpayen            #+#    #+#             */
/*   Updated: 2015/01/15 17:03:02 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s;
	int		i;

	s = s1;
	i = 0;
	while (*s)
		s++;
	while (s2[i])
		*s++ = s2[i++];
	*s = 0;
	return (s1);
}