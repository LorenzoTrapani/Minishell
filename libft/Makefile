NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS = ./mini_utils/ft_isalpha.c \
	./mini_utils/ft_isdigit.c \
	./mini_utils/ft_isprint.c \
	./mini_utils/ft_isalnum.c \
	./mini_utils/ft_isascii.c \
	./mini_utils/ft_strlen.c \
	./mini_utils/m_atoi.c \
	./mini_utils/m_putnbr.c \
	./mini_utils/ft_toupper.c \
	./mini_utils/ft_tolower.c \
	./mini_utils/ft_isspace.c \
	./mem_/ft_memset.c \
	./mem_/ft_memchr.c \
	./mem_/ft_memcmp.c \
	./mem_/ft_memcpy.c \
	./mem_/ft_memmove.c \
	ft_bzero.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	./fd/ft_putchar_fd.c \
	./fd/ft_putstr_fd.c \
	./fd/ft_putendl_fd.c \
	./fd/ft_putnbr_fd.c \
	./ft_printf/ft_printf.c \
	./ft_printf/ft_utils.c \
	./ft_printf/ft_utils2.c \
	./list/ft_lstnew.c \
	./list/ft_lstsize.c \
	./list/ft_lstlast.c \
	./list/ft_lstadd_front.c \
	./list/ft_lstadd_back.c \
	./list/ft_lstdelone.c \
	./list/ft_lstclear.c \
	./list/ft_lstiter.c \
	./list/ft_lstmap.c \

OBJS := $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus