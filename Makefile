# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/02 18:52:10 by tpayen            #+#    #+#              #
#*   Updated: 2015/04/13 16:19:28 by tpayen           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXEC = ft_ls

CC = gcc
CFLAGS = -Werror -Wextra -Wall

INCLUDES = -I libft/ -I includes
LIBS = libft/libft.a

LIBFTDIR = libft/
SRCDIR = src/
OBJDIR = obj/

SRC_FILES =	main.c		\
		get_options.c	\
		new_file.c	\
		get_path.c	\
		can.c		\
		g_stat.c	\
		alpha_sort.c	\
		g_name.c	\
		opt_t_sort.c	\
		sort_list.c	\
		show_files.c	\
		get_files.c	\
		create_path.c	\
		get_spaces.c	\
		opt_l_show.c	\
		opt_m_show.c	\
		get_pwname.c	\
		get_grname.c	\
		show_acl.c	\
		reset_space.c	\
		err_arg.c	\
		err_path.c	\
		show_color.c	\

DIRS = obj

SRC_OBJ = $(SRC_FILES:%.c=$(OBJDIR)%.o)

all: directories $(EXEC)

$(EXEC): $(SRC_OBJ)
	@($(MAKE) -C $(LIBFTDIR))
	$(CC) -o $@ $^ $(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: directories re clean fclean

re: fclean all

clean:
	rm -rf $(OBJDIR)
	@($(MAKE) -C $(LIBFTDIR) $@)

fclean: clean
	rm -rf $(EXEC)
	@($(MAKE) -C $(LIBFTDIR) $@)

directories: $(DIRS)

$(DIRS):
	mkdir $@
