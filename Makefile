CC=g++
CFLAGS=-Wall -std=c++11 -g3

OUTNAME=esquadrinhador
SRCFOLDER=src
OBJFOLDER=obj
OBJFILES_NAMES=main.o util.o scanner.o
OBJFILES=$(patsubst %,$(OBJFOLDER)/%,$(OBJFILES_NAMES))

.PHONY: clean distclean

$(OBJFOLDER)/%.o: $(SRCFOLDER)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTNAME): $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f obj/*

distclean: clean
	rm $(OUTNAME)
