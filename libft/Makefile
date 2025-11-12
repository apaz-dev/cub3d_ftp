#------------- GLOBALS -------------

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4
INCLUDES = .

#------------- SRC & OBJ -------------

SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
       libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c  libft/ft_isspace.c \
       libft/ft_isprint.c libft/ft_itoa.c libft/ft_memcmp.c libft/ft_isospace.c \
       libft/ft_memcpy.c libft/ft_memchr.c libft/ft_memmove.c libft/ft_memset.c \
       libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
       libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c \
       libft/ft_strnstr.c libft/ft_strtrim.c libft/ft_strrchr.c libft/ft_splitlen.c \
       libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
       libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c \
       libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_format.c \
	   printf/src/ft_printf.c printf/src/ft_prints_one.c printf/src/ft_prints_two.c \
       printf/src/utils.c \
	   gnl/get_next_line.c gnl/get_next_line_utils.c 
OBJ = $(SRCS:.c=.o)

#------------- COLORS -------------

NC=\033[0m
On_UIGreen=\033[4;102m
On_IGreen=\033[0;102m
UGreen=\033[4;32m
IGreen=\033[0;92m
IYellow=\033[0;93m
UYellow=\033[4;33m
BWhite=\033[1;37m

#------------- RULES -------------

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	@len=$$(printf "%s" "$<" | wc -c); printf "\r$(BWhite)[LIBFT] $(IGreen)Compiling: $(UGreen)%*s$(NC) 🔨\033[K" "$$len" "$<"
	@cc $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
