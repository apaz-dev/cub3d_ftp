#------------- COMPILER -------------

COMPILER = cc
CFLAGS = -Wextra -Wall -Werror -g
INCLUDE = -Iinclude -Ilibft -Iminilibx
NAME = cub3D
LIBRARY = libft/libft.a minilibx/libmlx.a

#------------- SRC && OBJ -------------

SRCS = src/main.c
OBJ = $(SRCS:.c=.o)

#------------- COLORS -------------

NC=\033[0m
On_UIGreen=\033[4;102m
On_IGreen=\033[0;102m
UGreen=\033[4;32m
IGreen=\033[0;92m
IYellow=\033[0;93m 
UYellow=\033[4;33m

#------------- RULES -------------

all: lbft mlx $(NAME)


lbft:
	@make --no-print-directory -C libft

mlx:
	@make --no-print-directory -C minilibx > /dev/null 2>&1

%.o: %.c
	@len=$$(printf "%s" "$<" | wc -c); printf "$(IGreen)\rCompiling: $(UGreen)%*s$(NC) 🔨\033[K" "$$len" "$<"
	@$(COMPILER) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJ)
	@$(COMPILER) $(CFLAGS) $(SRCS) $(INCLUDE) $(LIBRARY) -o $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make --no-print-directory -C libft clean
	@make --no-print-directory -C minilibx clean

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C libft fclean

re: clean all

.PHONY: all, clean, fclean, re