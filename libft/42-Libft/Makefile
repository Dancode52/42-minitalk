CFILES = ft_isalpha.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_split.c get_next_line_bonus.c

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJDIR = ../../obj
LIBFT_OBJ := 42lib
OFILES = $(CFILES:%.c=$(OBJDIR)/$(LIBFT_OBJ)/%.o)
BONUS_OFILES = $(BONUS_FILES:%.c=$(OBJDIR)/$(LIBFT_OBJ)/%.o)
CFLAGS = -Wall -Werror -Wextra
CC = cc
NAME = ../../libft.a
NAME_BONUS = ../../libft.a

all: $(NAME)

bonus: directory $(OFILES) $(BONUS_OFILES)
	@ar rcs $(NAME) $(OFILES) $(BONUS_OFILES)

clean:
	@rm -rf $(OFILES) $(BONUS_OFILES)
	@rm -rf $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

directory:
	mkdir -p $(OBJDIR)/$(LIBFT_OBJ)

$(NAME): directory $(OFILES)
	@ar rcs $(NAME) $(OFILES)

$(OBJDIR)/$(LIBFT_OBJ)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/$(LIBFT_OBJ)/%_bonus.o : %_bonus.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:  re fclean clean bonus all


