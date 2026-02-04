SVR_NAME    := server
CLT_NAME	:= client
LIBFT = libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

SVR_DIR := ./svr
SVR_SRC := server.c
SVR_BONUS_SRC := server_bonus.c

CLT_DIR := ./clt
CLT_SRC := client.c
CLT_BONUS_SRC := client_bonus.c

OBJ_DIR := ./obj
SVR_OBJ := $(SVR_SRC:.c=.o)
CLT_OBJ := $(CLT_SRC:.c=.o)

SVR_SRCS := $(addprefix $(SVR_DIR)/, $(SVR_SRC))
SVR_OBJS := $(addprefix $(OBJ_DIR)/, $(SVR_OBJ))

CLT_SRCS := $(addprefix $(CLT_DIR)/, $(CLT_SRC))
CLT_OBJS := $(addprefix $(OBJ_DIR)/, $(CLT_OBJ))

all: build_server build_client

$(LIBFT):
	$(MAKE) bonus -C libft/42-Libft

build_server: $(LIBFT) $(SVR_NAME)

$(SVR_NAME): $(SVR_OBJS)
	$(CC) $(CFLAGS) $(SVR_OBJS) -o $(SVR_NAME) $(LIBFT)

$(OBJ_DIR)/%.o: $(SVR_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

build_client: $(LIBFT) $(CLT_NAME)

$(CLT_NAME): $(CLT_OBJS)
	$(CC) $(CFLAGS) $(CLT_OBJS) -o $(CLT_NAME) $(LIBFT)

$(OBJ_DIR)/%.o: $(CLT_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft/42-Libft
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(SVR_NAME) $(CLT_NAME)
	$(MAKE) fclean -C libft/42-Libft

re: fclean all

.PHONY: all clean fclean re
