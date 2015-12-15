/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 16:14:48 by tpayen            #+#    #+#             */
/*   Updated: 2015/09/29 17:13:36 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	err_arg(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ./ft_ls [-", 2);
	ft_putstr_fd(VALID_ARG, 2);
	ft_putendl_fd("] [file ...]", 2);
	exit(EXIT_FAILURE);
}
