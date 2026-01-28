CFILES = ft_printf.c ft_printf_utils.c

BONUS_FILES =

OFILES = $(CFILES:%.c=$(OBJDIR)/%.o)
OBJDIR = ../obj
CFLAGS = -Wall -Werror -Wextra
CC = cc
NAME = ../../libftprintf.a

all: $(NAME)

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I libftprintf.h

directory:
	if ! [ -d $(OBJDIR) ]; then mkdir -p $(OBJDIR);\
	fi

clean:
	rm -rf $(OFILES)
	if [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); \
	fi

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(NAME): directory $(OFILES)
	ar rcs $(NAME) $(OFILES)

.PHONY:  re fclean clean bonus all
