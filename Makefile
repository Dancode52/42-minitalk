SVR_NAME    := server
SVR_BONUS_NAME := server_bonus
CLT_NAME	:= client
CLT_BONUS_NAME := client_bonus
LIBFT = my_libft/libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

SVR_DIR := svr
SVR_SRC := server.c
SVR_BONUS_SRC := server_bonus.c

CLT_DIR := clt
CLT_SRC := client.c
CLT_BONUS_SRC := client_bonus.c

OBJ_DIR := obj

SVR_OBJ_DIR := $(OBJ_DIR)/$(SVR_DIR)
SVR_OBJ := $(SVR_SRC:.c=.o)
SVR_BONUS_OBJ := $(SVR_BONUS_SRC:.c=.o)

CLT_OBJ_DIR := $(OBJ_DIR)/$(CLT_DIR)
CLT_OBJ := $(CLT_SRC:.c=.o)
CLT_BONUS_OBJ := $(CLT_BONUS_SRC:.c=.o)

SVR_SRCS := $(addprefix ./$(SVR_DIR)/, $(SVR_SRC))
SVR_BONUS_SRCS := $(addprefix ./$(SVR_DIR)/, $(SVR_BONUS_SRC))
SVR_OBJS := $(addprefix ./$(SVR_OBJ_DIR)/, $(SVR_OBJ))
SVR_BONUS_OBJS := $(addprefix ./$(SVR_OBJ_DIR)/, $(SVR_BONUS_OBJ))

CLT_SRCS := $(addprefix ./$(CLT_DIR)/, $(CLT_SRC))
CLT_BONUS_SRCS := $(addprefix ./$(CLT_DIR)/, $(CLT_BONUS_SRC))
CLT_OBJS := $(addprefix ./$(CLT_OBJ_DIR)/, $(CLT_OBJ))
CLT_BONUS_OBJS := $(addprefix ./$(CLT_OBJ_DIR)/, $(CLT_BONUS_OBJ))

all: build_server build_client

build_server: $(LIBFT) $(SVR_OBJ_DIR) $(SVR_NAME)

$(SVR_OBJ_DIR):
	mkdir -p ./$(SVR_OBJ_DIR)

$(SVR_NAME): $(SVR_OBJS)
	$(CC) $(CFLAGS) $(SVR_OBJS) -o $(SVR_NAME) $(LIBFT)

./$(SVR_OBJ_DIR)/%.o: $(SVR_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build_client: $(LIBFT) $(CLT_OBJ_DIR) $(CLT_NAME)

$(CLT_OBJ_DIR):
	mkdir -p ./$(CLT_OBJ_DIR)

$(CLT_NAME): $(CLT_OBJS)
	$(CC) $(CFLAGS) $(CLT_OBJS) -o $(CLT_NAME) $(LIBFT)

./$(CLT_OBJ_DIR)/%.o: $(CLT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) bonus -C my_libft

bonus: $(LIBFT) $(SVR_OBJ_DIR) $(CLT_OBJ_DIR) $(SVR_BONUS_NAME) $(CLT_BONUS_NAME)

$(SVR_BONUS_NAME): $(SVR_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SVR_BONUS_OBJS) -o $(SVR_BONUS_NAME) $(LIBFT)

$(CLT_BONUS_NAME): $(CLT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLT_BONUS_OBJS) -o $(CLT_BONUS_NAME) $(LIBFT)

clean:
	$(MAKE) clean -C my_libft
	rm -rf ./$(OBJ_DIR)

fclean: clean
	rm -f $(SVR_NAME) $(CLT_NAME) $(SVR_BONUS_NAME) $(CLT_BONUS_NAME)
	$(MAKE) fclean -C my_libft

re: fclean all

.PHONY: all clean fclean re libft.a
