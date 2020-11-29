CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	cub3d

SRC_DIR		=	./src
SRCS		=	main.c				\
				error.c

LIB_DIR		=	./minilib
LIB_SRCS	=	get_options.c

OBJ_DIR		=	./obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJS))
OBJS		=	$(SRCS:.c=.o) $(LIB_SRCS:.c=.o)

INC_DIR		=	./include
INC			=	$(INC_DIR)/cub3d.h

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_INC	=	$(LIBFT_DIR)/includes

FTPF_DIR	=	./ft_printf
FTPF		=	$(FTPF_DIR)/libftprintf.a
FTPF_INC	=	$(FTPF_DIR)/include

INC_FLAGS	=	-I$(INC_DIR) -I$(LIBFT_INC) -I$(FTPF_INC)
LINK_FLAGS	=	-L$(LIBFT_DIR) -L$(FTPF_DIR) -lft -lftprintf 

all:			$(NAME)

$(NAME):		$(SDL_LIB) $(OBJ_DIR) $(OBJ) $(LIBFT) $(FTPF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LINK_FLAGS)

message:
	@echo compiling $(NAME)...

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(OBJ_DIR)/%.o:	$(LIB_DIR)/%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FTPF):
	@$(MAKE) -C $(FTPF_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FTPF_DIR) clean
	@echo cleaning objects...
	@rm -rf $(OBJ_DIR)

cleansdl:
	@$(MAKE) -C $(SDL_BUILD) clean && $(MAKE) -C $(SDL_BUILD) uninstall

fclean:
	@$(MAKE) clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FTPF_DIR) fclean
	@echo cleaning binaries...
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:			all clean fclean re
