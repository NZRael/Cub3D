SRCS = srcs/main.c srcs/read_map.c srcs/check_args.c srcs/parsing.c srcs/error.c srcs/parsing_map.c

SRCS_BONUS =

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -framework AppKit -framework OpenGL -lmlx -Lmlx -Imlx
NAME = Cub3D

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

.c.o :
	@gcc ${FLAGS} -I cub3D.h -c $< -o ${<:.c=.o}

all: ${OBJS}
	@make -C ./libft/
	@make -C ./ft_printf/
	@make -C ./mlx/
	@mv ./libft/libft.a ./libft.a
	@mv ./ft_printf/libftprintf.a ./libftprintf.a
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc ${FLAGS} ${FLAGS_MLX} -o ${NAME} libft.a libftprintf.a mlx/libmlx.a ${OBJS}
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@rm -f $(OBJS)
	@rm ./libft.a
	@rm mlx/libmlx.a
	@rm ./libftprintf.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf
	@echo $(CURSIVE)$(GRAY) "     - Deleted object files" $(NONE)

bonus: ${OBJS_BONUS}
	@make -C ./libft/
	@make -C ./ft_printf/
	@make -C ./mlx/
	@mv ./libft/libft.a ./libft.a
	@mv ./mlx/libmlx.a ./libmlx.a
	@mv ./ft_printf/libftprintf.a ./libftprintf.a
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME) bonus..." $(NONE)
	@gcc ${FLAGS} ${FLAGS_MLX} -o ${NAME} libft.a libftprintf.a libmlx.a ${OBJS_BONUS}
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@rm -f $(OBJS_BONUS)
	@rm ./libft.a
	@rm ./libmlx.a
	@rm ./libftprintf.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf
	@echo $(CURSIVE)$(GRAY) "     - Deleted bonus object files" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f ${OBJS}
	@echo $(GREEN)"     - Removed -"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME) libft.a libftprintf.a libmlx.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf/
	@make clean -C ./mlx
	@echo $(GREEN)"     - Removed -"$(NONE)

re: fclean all

.PHONY : .c.o all bonus clean fclean re
