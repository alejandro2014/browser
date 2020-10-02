EXE=browser
CC=g++

SRCPATH=./src
OBJPATH=./obj
BINPATH=./bin

OPTC=-g
OPTL=-L/usr/local/lib -lSDL2 -lSDL2_ttf

OBJ1=Browser
OBJ2=Font
OBJ3=main
OBJ=${OBJPATH}/${OBJ1}.o ${OBJPATH}/${OBJ2}.o ${OBJPATH}/${OBJ3}.o

${BINPATH}/${EXE}: ${OBJ}
	${CC} ${OBJ} -o ${BINPATH}/${EXE} ${OPTL}

${OBJPATH}/%.o: ${SRCPATH}/%.cpp
	${CC} ${OPTC} -c -o $@ $<

clean:
	rm -f ${OBJPATH}/* ${BINPATH}/${EXE}
