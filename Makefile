NAME = fdf

FLAGS = -Wall -Wextra -Werror  -g## -fsanitize=address
ATTACH = minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -L libft

SRC = main.c get_map_info.c rotate.c parse.c dda.c draw.c error_check.c
#oldcode.c
OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) -I ./libft -c $(SRC)
	gcc $(FLAGS) -o $(NAME) libft/libft.a $(OBJ) $(ATTACH)

run42:
	./fdf tests/42.fdf

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
