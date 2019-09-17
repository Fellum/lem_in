NAME = lem-in

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

HEADERS = -I $(INC_DIR) -I libft/include

LIBFLAGS = -L libft -lft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) libft
	@gcc -g $(OBJ) -o $@ $(LIBFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -g -c $< -o $@ $(HEADERS)

.PHONY: all libft clean fclean re

libft:
	@make -C libft

clean:
	@make clean -C libft
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@rm -Rf $(NAME)

re: fclean all

