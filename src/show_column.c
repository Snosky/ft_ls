/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:23:50 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 21:13:58 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

static int	get_terminal_column(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return(w.ws_col);
}

static void	show_elem(t_list *file, int line_end)
{
	int	len;

	if (line_end)
		ft_putendl(show_color(file));
	else
	{
		len = ft_strlen(g_name(file));
		if ((int)len <= (g_space->name / 2))
		{
			ft_putstr(show_color(file));
			len = g_space->name - len;
			while (len >= 4)
			{
				ft_putstr("\t");
				len -= 4;
			}
		}
		else
			ft_putstr(ft_strjoin(show_color(file), "\t"));
	}

}

static int nb_item(t_list *file)
{
	int	i;

	i = 0;
	while (file)
	{
		i++;
		file = file->next;
	}
	return (i);
}

void		show_column(t_list *file)
{
	int		max_col;
	float	nb_item_per_line;
	t_list	*tmp;
	int		col;
	int		i;


	max_col = get_terminal_column() / (g_space->name + 4);
	nb_item_per_line = nb_item(file) / max_col;
	tmp = file;
	col = 1;
	while (tmp)
	{
		//On affiche
		show_elem(tmp, (col == max_col));
		if (!tmp->next)
			break ;

		if (col == max_col)
		{
			file = file->next;
			tmp = file;
			col = 0;
		}
		else
		{
			// On va au 1er element de la colone suivante
			i = nb_item_per_line;
			while (i--)
				tmp = tmp->next;
		}
		col++;
	}


}
