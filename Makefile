# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 17:20:26 by orazafy           #+#    #+#              #
#    Updated: 2023/03/10 17:20:28 by orazafy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCDIR)
CFLAGS_BONUS = -Wall -Werror -Wextra -g -I$(INCDIR_BONUS)

SRCDIR_CLIENT = src_client
OBJDIR_CLIENT = obj_client
SRCDIR_SERVER = src_server
OBJDIR_SERVER = obj_server
BINDIR = bin
INCDIR = include

SRCDIR_CLIENT_BONUS = src_client_bonus
OBJDIR_CLIENT_BONUS = obj_client_bonus
SRCDIR_SERVER_BONUS = src_server_bonus
OBJDIR_SERVER_BONUS = obj_server_bonus
BINDIR_BONUS = bin_bonus
INCDIR_BONUS = include_bonus

SRCS_CLIENT = $(addprefix $(SRCDIR_CLIENT)/, client.c client_utils.c)
OBJS_CLIENT = $(SRCS_CLIENT:$(SRCDIR_CLIENT)/%.c=$(OBJDIR_CLIENT)/%.o)

SRCS_CLIENT_BONUS = $(addprefix $(SRCDIR_CLIENT_BONUS)/, client_bonus.c client_utils_bonus.c)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:$(SRCDIR_CLIENT_BONUS)/%.c=$(OBJDIR_CLIENT_BONUS)/%.o)

SRCS_SERVER = $(addprefix $(SRCDIR_SERVER)/, server.c server_utils.c)
OBJS_SERVER = $(SRCS_SERVER:$(SRCDIR_SERVER)/%.c=$(OBJDIR_SERVER)/%.o)

SRCS_SERVER_BONUS = $(addprefix $(SRCDIR_SERVER_BONUS)/, server_bonus.c server_utils_bonus.c)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:$(SRCDIR_SERVER_BONUS)/%.c=$(OBJDIR_SERVER_BONUS)/%.o)

INCS = $(INCDIR)/minitalk.h

INCS_BONUS = $(INCDIR_BONUS)/minitalk_bonus.h

NAME = $(BINDIR)/client
NAME_SERVER = $(BINDIR)/server

NAME_BONUS = $(BINDIR_BONUS)/client
NAME_SERVER_BONUS = $(BINDIR_BONUS)/server

RMR = rm -rf
MKDIR_P = mkdir -p

all: $(NAME) ${NAME_SERVER}

$(NAME): $(OBJS_CLIENT) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME)

$(OBJDIR_CLIENT)/%.o: $(SRCDIR_CLIENT)/%.c $(INCS) | $(OBJDIR_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(OBJDIR_SERVER)/%.o: $(SRCDIR_SERVER)/%.c $(INCS) | $(OBJDIR_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

 $(BINDIR):
	$(MKDIR_P) $(BINDIR)

$(OBJDIR_CLIENT):
	$(MKDIR_P) $(OBJDIR_CLIENT)

$(OBJDIR_SERVER):
	$(MKDIR_P) $(OBJDIR_SERVER)

bonus: $(NAME_BONUS) ${NAME_SERVER_BONUS}

$(NAME_BONUS): $(OBJS_CLIENT_BONUS) | $(BINDIR_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_CLIENT_BONUS) -o $(NAME_BONUS)

$(OBJDIR_CLIENT_BONUS)/%.o: $(SRCDIR_CLIENT_BONUS)/%.c $(INCS_BONUS) | $(OBJDIR_CLIENT_BONUS)
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_SERVER_BONUS) -o $(NAME_SERVER_BONUS)

$(OBJDIR_SERVER_BONUS)/%.o: $(SRCDIR_SERVER_BONUS)/%.c $(INCS_BONUS) | $(OBJDIR_SERVER_BONUS)
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

 $(BINDIR_BONUS):
	$(MKDIR_P) $(BINDIR_BONUS)

$(OBJDIR_CLIENT_BONUS):
	$(MKDIR_P) $(OBJDIR_CLIENT_BONUS)

$(OBJDIR_SERVER_BONUS):
	$(MKDIR_P) $(OBJDIR_SERVER_BONUS)

clean:
		$(RMR) $(OBJDIR_CLIENT) $(OBJDIR_SERVER)
		$(RMR) $(OBJDIR_CLIENT_BONUS) $(OBJDIR_SERVER_BONUS)

fclean: clean
		$(RMR) $(BINDIR)
		$(RMR) $(BINDIR_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus