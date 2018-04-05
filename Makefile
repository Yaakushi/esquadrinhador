CC=g++
CFLAGS=-Wall -std=c++11

SRCFOLDER=src
OBJFOLDER=obj
OBJFILES_NAMES=main.o util.o scanner.o
OBJFILES=$(patsubst %,$(OBJFOLDER)/%,$(OBJFILES_NAMES))

$(OBJFOLDER)/%.o: $(SRCFOLDER)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

esquadrinhador: $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o $@
