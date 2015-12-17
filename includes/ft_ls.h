/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 11:10:47 by tpayen            #+#    #+#             */
/*   Updated: 2015/12/17 19:56:28 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <sys/errno.h>
# include <fcntl.h>

# define VALID_ARG "lRartdg1fnompAG"

# define OPT_L 0x01
# define OPT_REC 0x02
# define OPT_A 0x04
# define OPT_REV 0x08
# define OPT_T 0x10
# define OPT_D 0x20
# define OPT_G 0x40
# define OPT_F 0x80
# define OPT_N 0x100
# define OPT_O 0x200
# define OPT_M 0x400
# define OPT_P 0x800
# define OPT_A_M 0x1000
# define OPT_G_COLOR 0x2000
# define OPT_ONE 0x4000

int	g_options;

typedef struct	s_space
{
	int	link;
	int	user;
	int	group;
	int	size;
	int	name;
}				t_space;

typedef struct stat	t_stat;

typedef struct	s_file
{
	t_stat		*stat;
	char		*name;
}				t_file;

t_space			*g_space;
char			*g_path;
int				g_p;
int				g_pa;

int				get_options(char **av);
void			get_path(char **av, t_list **dir, t_list **files);
t_file			*new_file(char *name, char *path);
void			sort_files(t_list *list);
void			show_files(t_list *list);
void			get_files(t_list *files, char *path);
char			*create_path(char *name, char *path);
void			get_spaces(t_list *lst);
void			opt_l_show(t_list *lst);
void			opt_m_show(t_list *lst);
char			*get_pwname(t_list *lst);
char			*get_grname(t_list *lst);
void			show_acl(t_list *lst);
void			reset_space(void);
void			err_arg(char c);
void			err_path(char *s);
int				can(int i);
struct stat		*g_stat(t_list *file);
char			*g_name(t_list *file);
int				opt_t_sort(t_list *lst1, t_list *lst2, int rev);
int				alpha_sort(t_list *lst1, t_list *lst2, int rev);

char			*show_color(t_list *file);

void		show_column(t_list *file);
#endif
