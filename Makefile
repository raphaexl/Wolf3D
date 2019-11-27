# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 22:15:58 by ebatchas          #+#    #+#              #
#    Updated: 2019/02/27 11:34:45 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes
CFLAGS= -Wall -Wextra -I$(HEADDIR)
LDFLAGS= $(CFLAGS) -I$(HEADDIR) -L$(LIBDIR)/ -lft -lm 
SDL2 = ./frameworks/SDL2.framework/Versions/A/SDL2
SDL2_image = ./frameworks/SDL2_image.framework/Versions/A/SDL2_image
SDL2_mixer = ./frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer
SDL2_ttf = ./frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf

SRC=$(SRCDIR)/main.c\
	$(SRCDIR)/sdl_init.c\
	$(SRCDIR)/sdl_draw.c\
	$(SRCDIR)/sdl_tools.c\
	$(SRCDIR)/utils.c\
	$(SRCDIR)/variable1.c\
	$(SRCDIR)/variable2.c\
	$(SRCDIR)/event1.c\
	$(SRCDIR)/event2.c\
	$(SRCDIR)/utils2.c\
	$(SRCDIR)/tools.c\
	$(SRCDIR)/tools2.c\
	$(SRCDIR)/sprite.c\
	$(SRCDIR)/menu.c\
	$(SRCDIR)/input.c\
	$(SRCDIR)/draw.c\
	$(SRCDIR)/wolf.c\
	$(SRCDIR)/raycast1.c\
	$(SRCDIR)/raycast2.c\
	$(SRCDIR)/raycast3.c\
	$(SRCDIR)/load_walls1.c\
	$(SRCDIR)/load_walls2.c\
	$(SRCDIR)/read_file.c

OBJ=$(LIBDIR)/main.o\
	$(LIBDIR)/sdl_init.o\
	$(LIBDIR)/sdl_draw.o\
	$(LIBDIR)/variable1.o\
	$(LIBDIR)/variable2.o\
	$(LIBDIR)/sdl_tools.o\
	$(LIBDIR)/utils.o\
	$(LIBDIR)/menu.o\
	$(LIBDIR)/input.o\
	$(LIBDIR)/event1.o\
	$(LIBDIR)/event2.o\
	$(LIBDIR)/utils2.o\
	$(LIBDIR)/tools.o\
	$(LIBDIR)/tools2.o\
	$(LIBDIR)/sprite.o\
	$(LIBDIR)/draw.o\
	$(LIBDIR)/load_walls1.o\
	$(SRCDIR)/load_walls2.c\
	$(LIBDIR)/raycast1.o\
	$(LIBDIR)/raycast2.o\
	$(LIBDIR)/raycast3.o\
	$(LIBDIR)/wolf.o\
	$(LIBDIR)/read_file.o

NAME=wolf3d

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)/libft/ fclean && make -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)/
	$(CC) $(LDFLAGS) -o $@ $^ -F ./frameworks -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 $(SDL2) $(NAME)
	@install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image $(SDL2_image) $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer $(SDL2_mixer) $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf $(SDL2_ttf) $(NAME)
$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -F ./frameworks

.PHONY:clean fclean

clean:
	rm -rf $(LIBDIR)/*.o
	make -C $(LIBDIR)/libft clean

fclean:clean
	rm -rf $(NAME)
	make -C $(LIBDIR)/libft fclean

re : fclean all
