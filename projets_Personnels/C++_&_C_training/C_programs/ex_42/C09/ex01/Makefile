CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c 
OBJECTS = $(SRCS:.c=.o)
INCLUDES = includes

EXEC = libft.a

all: $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) $< -o $@ 

$(EXEC): $(OBJECTS)
	ar rc $@ $(OBJECTS)
	#ranlib $(EXEC)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(EXEC)

re: fclean all
	
#$@ nom de la cible
#$< nom de la premiere dependance
