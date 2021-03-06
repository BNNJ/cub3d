CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	cub3d

SRC_DIR		=	./src
SRCS		=	main.c				\
				tests.c

PARS_DIR	=	$(SRC_DIR)/parsing
PARS_SRC	=	parser.c			\
				config.c			\
				map.c

LIB_DIR		=	./minilib
LIB_SRCS	=	get_options.c		\
				get_line.c			\
				error.c				\
				find_char.c			\
				strings.c			\
				reader.c			\
				indexof.c			\
				ft_strtoi.c			\
				add_line.c			\
				ft_memcopy.c

OBJ_DIR		=	./obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJS))
OBJS		=	$(SRCS:.c=.o) $(LIB_SRCS:.c=.o) $(PARS_SRC:.c=.o)

INC_DIR		=	./include
INC			=	$(INC_DIR)/cub3d.h		\
				$(INC_DIR)/error.h		\
				$(INC_DIR)/minilib.h

FTPF_DIR	=	./ft_printf
FTPF		=	$(FTPF_DIR)/libftprintf.a
FTPF_INC	=	$(FTPF_DIR)/include

INC_FLAGS	=	-I$(INC_DIR) -I$(FTPF_INC)
LINK_FLAGS	=	-L$(FTPF_DIR) -lftprintf 

all:			$(NAME)

$(NAME):		$(SDL_LIB) $(OBJ_DIR) $(OBJ) $(FTPF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LINK_FLAGS)

message:
	@echo compiling $(NAME)...

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(OBJ_DIR)/%.o:	$(LIB_DIR)/%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(OBJ_DIR)/%.o:	$(PARS_DIR)/%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(FTPF):
	@$(MAKE) -C $(FTPF_DIR)

clean:
	@$(MAKE) -C $(FTPF_DIR) clean
	@echo cleaning objects...
	@rm -rf $(OBJ_DIR)

fclean:
	@$(MAKE) clean
	@$(MAKE) -C $(FTPF_DIR) fclean
	@echo cleaning binaries...
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:			all clean fclean re
