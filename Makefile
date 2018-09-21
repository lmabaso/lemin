NAME =	lem-in

SRC =	src/main.c \
		src/ft_lstappend.c \
		src/ft_lstseach.c \
		src/ft_test.c \
		src/ft_search_path.c \
		src/ft_maths.c \
		src/ft_lst_copy_op.c \
		src/ft_lst_op.c \
		src/ft_lst_add.c \
		src/ft_errors.c \
		src/ft_errors2.c \
		src/ft_errors3.c \
		src/ft_free_stuff.c \
		src/ft_proccess.c \
		src/ft_create_links.c \
		src/ft_process_ants.c \
		src/ft_process_ants_2.c \

OBJ = 	src/main.o \
		src/ft_lstappend.o \
		src/ft_lstseach.o \
		src/ft_test.o \
		src/ft_search_path.o \
		src/ft_maths.o \
		src/ft_lst_copy_op.o \
		src/ft_lst_op.o \
		src/ft_lst_add.o \
		src/ft_errors.o \
		src/ft_errors2.o \
		src/ft_errors3.o \
		src/ft_free_stuff.o \
		src/ft_proccess.o \
		src/ft_create_links.o \
		src/ft_process_ants.o \
		src/ft_process_ants_2.o \

FLAGS= gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME) $(SRC) -L libft/ -lft -I libft/includes -I includes

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
