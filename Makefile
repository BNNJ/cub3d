CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	cub3d

SRC_DIR		=	./src
SRCS		=	main.c				\
				error.c

LIB_DIR		=	./minilib
LIB_SRCS	=	get_options.c		\
				ft_strcmp.c

OBJ_DIR		=	./obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJS))
OBJS		=	$(SRCS:.c=.o) $(LIB_SRCS:.c=.o)

INC_DIR		=	./include
INC			=	$(INC_DIR)/cub3d.h

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
