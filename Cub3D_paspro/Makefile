NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

SRCS = main.c read_map.c error.c \
	parsing.c parsing2.c parsing3.c \
	parsing_before_map.c parsing_before_map2.c \
	parsing_map.c parsing_map2.c parsing_map3.c \
	keys.c keys_left_and_right.c \
	texture.c draw.c check_args.c \
	raycast_init.c raycast2.c raycast_calcul.c \
	get_next_line.c get_next_line_utils.c

OBJ = ./objs
OBJS = $(addprefix $(OBJ)/, ${SRCS:.c=.o})

LIB_F = libft
LIB = libft.a

FLAGS = -Wall -Wextra -Werror -I .cub3D.h -g #-fsanitize=address 
FLAGS_MLX = -lmlx -L ./minilibx-linux -lX11 -lXext -lm

NAME = cub3D

all: $(NAME)

$(NAME) : ${OBJS} $(LIB_F)/$(LIB)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc ${FLAGS} -o ${NAME} ${OBJS} ${FLAGS_MLX} -L./libft -lft
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
	@rm -rf ${NAME}
	@echo $(GREEN)"     - Removed -"$(NONE)

re: fclean all

.PHONY : all clean fclean re libft
