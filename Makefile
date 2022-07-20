CFLAGS = -Wall -std=c99
EXE = smash
OBJS = smash.o history.o commands.o strTok.o changeDirectory.o cwd.o externalCommands.o rmwhite.o

all: rules.d $(EXE)

$(EXE): $(OBJS)
	gcc $(OBJS) -o $@

debug: CFLAGS += -g -O0
debug: $(EXE)

val:
	valgrind --leak-check=yes $(EXE)

clean:
	rm -f *.o $(EXE) *~ *.d

edit:
	vim $(EXE).c

rules.d: $(wildcard *.c) $(wildcard *.h)
	gcc -MM $(wildcard *.c) >rules.d

-include rules.d
