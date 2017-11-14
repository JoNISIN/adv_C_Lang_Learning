CC = gcc
OBJ = main.o list.o

EXE = main.exe
all: $(EXE)
.c.o: ; $(CC) -c $*.c

$(EXE): $(OBJ)
	$(CC) -o $@ $(OBJ)

clean:
	rm -rf $(EXE) *.o *.d core
