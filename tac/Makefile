CC=clang
EXE=tac.out

SOURCE=main.c $(wildcard src/*.c)
OBJECTS=$(wildcard src/*.o)

$(EXE):
	$(CC) $(SOURCE) -o $(EXE)

clean:
	- rm *.out
