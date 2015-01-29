CC=g++
CFLAGS= -c -Wall

all: smarties

smarties: lattice.o writeconfig.hh
	$(CC) lattice.o writeconfig.hh -o smarties

%.o: %.cc
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *o smarties
