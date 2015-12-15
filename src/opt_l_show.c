/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:23:21 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/15 17:48:55 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	show_info(char *s, int max_space, int r)
{
	int	len;
	int	i;

	len = max_space - ft_strlen(s);
	i = -1;
	ft_putchar(' ');
	if (!r)
		while (++i < len)
			ft_putchar(' ');
	ft_putstr(s);
	if (r)
		while (++i < len)
			ft_putchar(' ');
}

static void	show_date(time_t sec)
{
	time_t	now;

	time(&now);
	ft_putchar(' ');
	if (sec >= (now - (365 / 2 * 86400)) && now >= sec)
		ft_putstr(ft_strsub(ctime(&sec), 4, 12));
	else
	{
		ft_putstr(ft_strsub(ctime(&sec), 4, 6));
		ft_putstr("  ");
		ft_putstr(ft_strsub(ctime(&sec), 20, 4));
	}
}

static void	show_link(t_list *lst)
{
	char	*buf;

	if (!(buf = ft_strnew(g_stat(lst)->st_size + 1)))
		return ;
	readlink(create_path(g_name(lst), g_path), buf, g_stat(lst)->st_size + 1);
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void		opt_l_show(t_list *lst)
{
	show_acl(lst);
	show_info(ft_itoa(g_stat(lst)->st_nlink), g_space->link + 1, 0);
	if (!can(OPT_G))
		show_info(get_pwname(lst), g_space->user + 1, 1);
	if (!can(OPT_O))
		show_info(get_grname(lst), g_space->group + 1, 1);
	show_info(ft_itoa(g_stat(lst)->st_size), g_space->size, 0);
	show_date(g_stat(lst)->st_mtime);
	show_info(g_name(lst), 0, 0);
	if (S_ISLNK(g_stat(lst)->st_mode))
		show_link(lst);
	if (can(OPT_P) && S_ISDIR(g_stat(lst)->st_mode))
		ft_putchar('/');
	ft_putchar('\n');
}
