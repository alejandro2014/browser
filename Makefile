EXE=browser
CC=g++

SRCPATH=./src
OBJPATH=./obj
BINPATH=./bin

OPTC=-g
OPTL=

OBJ1=Browser
OBJ= ${OBJPATH}/${OBJ1}.o

${BINPATH}/${EXE}: ${OBJ}
	${CC} ${OBJ} -o ${BINPATH}/${EXE} ${OPTL}

${OBJPATH}/%.o: ${SRCPATH}/%.cpp
	${CC} ${OPTC} -c -o $@ $<

clean:
	rm -f ${OBJPATH}/* ${BINPATH}/${EXE}
