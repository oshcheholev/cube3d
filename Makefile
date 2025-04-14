GREEN=\033[32m
YELLOW=\033[33m
RED=\033[31m
BLUE=\033[34m
BACK=\033[42m
BOLD=\033[1m
RESET=\033[0m

SRCS = cub3d.c \
		init/init_map.c \
		utils/get_next_line/get_next_line.c \
		utils/get_next_line/get_next_line_utils.c \
		utils/utils.c \


HEAD = include/cub3d.h 

NAME = cub3d

CC = cc

RM = rm -f

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g

all: ${NAME}

%.o:	%.c
		@echo "${BLUE}${BOLD}Compiling $<${RESET}"
		@${CC} ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
		@${CC} ${CFLAGS} ${OBJS} -o $@
		@echo "${BACK}${RED}${BOLD} Successfuly built ${NAME} ${RESET}"

clean:
		@echo "${YELLOW}${BOLD}Deleting object files${RESET}" 
		@${RM} ${OBJS}

fclean: clean
		@echo "${RED}${BOLD}Deleting executable${RESET}"
		@${RM} philo

re:		fclean all

.PHONY:	all clean fclean re