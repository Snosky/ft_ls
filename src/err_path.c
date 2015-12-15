/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 16:17:57 by tpayen            #+#    #+#             */
/*   Updated: 2015/09/29 17:07:03 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	err_path(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(s, 2);
	if (errno == EACCES)
		ft_putendl_fd(": Permission denied", 2);
	else
		ft_putendl_fd(": No such file or directory", 2);
}
