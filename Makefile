##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

CC = gcc

NAME	=	libhashtable.a

TEST_NAME	=	unit_tests

SRC	=	src/hash-function/get_index.c 	\
		src/hash-function/hash.c 	\
		src/hash-table/new_hashtable.c	\
		src/hash-table/delete_hashtable.c	\
		src/hash-table/ht_insert.c	\
		src/hash-table/ht_search.c	\
		src/hash-table/ht_delete.c	\
		src/hash-table/ht_dump.c	\
		src/lib/my_int_len.c	\
		src/lib/my_strlen.c	\
		src/lib/my_putstr.c	\
		src/lib/my_puterr.c	\
		src/lib/my_putchar.c	\
		src/lib/my_strdup.c 	\
		src/lib/my_compute_power_rec.c	\
		src/lib/my_put_nbr.c	\
		src/lib/mini_printf.c	\

TESTS	=	tests/test_hash_table.c	\
			tests/test_hash_function.c	\
			tests/test_hash_table_functions.c	\

OBJ	=	$(SRC:.c=.o)

TEST_OBJ	=	$(TESTS:.c=.o)

CFLAGS	= -Iinclude -Wextra -Wall -Wshadow
TESTS_FLAGS	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) cr $(NAME) $(OBJ)

unit_tests: CFLAGS += --coverage
unit_tests:     fclean	$(NAME)	\
	$(TEST_OBJ)
	$(CC) -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(TESTS_FLAGS)

tests_run:      unit_tests
	-./$(TEST_NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
