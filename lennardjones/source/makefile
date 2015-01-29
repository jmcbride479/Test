CC=g++
CFLAGS= -c -Wall
EXE=../execute/smarties

OBJECTS=lennardJones.o \
  averages.hh \
  count.hh \
  energy_disp.hh \
  energy_volch.hh \
  functions.hh \
  global.hh \
  history.hh \
  metropolis.hh \
  overlap_all.hh \
  overlap_particle.hh \
  read_inputs.hh \
  volume_change.hh \
  write_config.hh \
  write_output.hh \

all: $(EXE)

$(EXE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(EXE)

%.o: %.cc
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *o $(EXE)
