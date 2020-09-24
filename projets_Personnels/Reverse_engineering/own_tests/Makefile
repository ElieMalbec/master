CC = gcc
SRC = /src
OBJ = ${SRC: .c=.o}
CFLAGS = -Wall -Wextra
EXEC = my_exec


all: test

${SRC}/%.o: mystery.c
	${CC} $< -o $@ ${CFLAGS}


#all: ${EXEC}

#my_exec :	${OBJ}
#	${CC} ${CFLAGS} -o


clean :
	rm -f *.o
	rm test mystery
