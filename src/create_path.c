/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:10:30 by tpayen            #+#    #+#             */
/*   Updated: 2015/09/29 17:13:26 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*create_path(char *name, char *path)
{
	char	*ret;
	int		path_len;

	if (!path)
		return (ft_strdup(name));
	path_len = ft_strlen(path);
	if (path[path_len - 1] == '/')
		ret = ft_strdup(ft_strjoin(path, name));
	else
		ret = ft_strdup(ft_strjoin(ft_strjoin(path, "/"), name));
	return (ret);
}
