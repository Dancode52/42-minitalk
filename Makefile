CFILESSERV = server.c
CFILESCLIENT = client.c

OBJDIR = ./obj
OFILESSERV = $(CFILES:./svr/%.c=$(OBJDIR)/%.o)
OFILESCLIENT = $(CFILES:./clt/%.c=$(OBJDIR)/%.o)
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
CC = cc
LIBFT = libft.a
NAMESERV = server
NAMECLIENT = client

all: $(NAMESERV) $(NAMECLIENT)

makeserver: $(NAMESERV)

makeclient: $(NAMECLIENT)

directory:
	@if ! [ -d $(OBJDIR) ]; then mkdir -p $(OBJDIR);\
	fi

clean:
	@rm -rf $(NAME)
	@rm -rf $(OFILES)
	@$(MAKE) clean -C libft/42-Libft
	@if [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); \
	fi

fclean: clean
	@echo "Look at us go! Taking a sledgehammer to your very delicate work!"
	@rm -f $(NAMESERV) $(NAMECLIENT)
	@$(MAKE) fclean -C libft/42-Libft

re: fclean all


$(NAMESERV): directory $(OFILESSERV)
	@$(MAKE) bonus -C libft/42-Libft
	@$(CC) $(CFLAGS) ./svr/$(CFILESSERV) -o $(NAMESERV) $(LIBFT)
	@echo "Look at us go! Making your project with our silly little techno-gremlin hands!"

$(NAMECLIENT): directory $(OFILESCLIENT)
	@$(MAKE) bonus -C libft/42-Libft
	@$(CC) $(CFLAGS) ./clt/$(CFILESCLIENT) -o $(NAMECLIENT) $(LIBFT)
	@echo "Look at us go! Making your project with our silly little techno-gremlin hands!"

$(OBJDIR)/%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:  re fclean clean bonus all
