NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

SRCS = main.c read_map.c \
		parsing.c error.c \
		parsing_map.c \

OBJ = ./objs
OBJS = $(addprefix $(OBJ)/, ${SRCS:.c=.o})

LIB_F = libft
LIB = libft.a

FLAGS = -Wall -Wextra -Werror -I .cub3D.h
FLAGS_MLXMAC = -framework AppKit -framework OpenGL -lmlx -Lmlx -Imlx -L./libft -lft
FLAGS_MLX = -lmlx -L./MiniLibX -lX11 -lXext -lm -L./libft -lft
NAME = cub3D

all: $(NAME)

$(NAME) : ${OBJS} $(LIB_F)/$(LIB)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc ${FLAGS} ${FLAGS_MLX} -o ${NAME} ${OBJS}
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@echo $(CURSIVE)$(GRAY) "     - Deleted object files" $(NONE)

$(LIB_F)/$(LIB):
	@make -C $(LIB_F)

$(OBJ)/%.o: ./%.c
	@mkdir -p ${OBJ}
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf ${OBJ}
	@make clean -C $(LIB_F)
	@echo $(GREEN)"     - Removed -"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@make fclean -C $(LIB_F)
	@echo $(GREEN)"     - Removed -"$(NONE)

re: fclean all

.PHONY : all clean fclean re libft
