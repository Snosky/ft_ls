/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:59:45 by tpayen            #+#    #+#             */
/*   Updated: 2015/04/29 14:53:25 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_file(char *name, char *path)
{
	t_file	*tmp;
	char	*tmp_path;

	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	tmp->name = ft_strdup(name);
	if (path)
		tmp_path = create_path(name, path);
	else
		tmp_path = ft_strdup(name);
	if ((tmp->stat = (struct stat *)malloc(sizeof(struct stat))))
		if (lstat(tmp_path, tmp->stat) != -1)
			if (tmp->stat->st_mode)
				return (tmp);
	tmp = NULL;
	free(tmp);
	return (NULL);
}
