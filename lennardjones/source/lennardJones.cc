// This is the main program for this Monte Carlo simulation of Lennard-Jones particles.

//#inlcude <cstdlib> // for exit command during debugging!!
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "global.hh"
#include "read_inputs.hh"
#include "write_config.hh"
#include "write_output.hh"
#include "count.hh"
#include "metropolis.hh"
#include "volume_change.hh"
#include "averages.hh"
#include "history.hh"

using namespace std;

int main() {

time_t start_time = time(0);
//declare main varibles in global file

//read input files
read_inputs();

//get seed from clock
srand (unsigned (time (NULL) ) );

//write initial output
write_output(1, start_time);

//initialise counters
count();

if (overlap_all()) {cout <<"OVERLAP!";return 1;}

//Make a move
	//Either Metropolis
		//Or Wood
for (int cycles = 1; cycles !=(nCycle+1); ++cycles)  {
	
	for (double j = 0; j !=npart; ++j)  {
		double throw_die = rand();
		if (throw_die/RAND_MAX <= transProb)  {
			metropolis();
		} else  {
			wood();
		}
	}
//write averages into output file

	if (cycles == 1) {
		averages(1, cycles);
	} else if (cycles % nSample == 0) {
		averages(0, cycles);
	}
//write history file

	if (cycles % nHist == 0 && lHist == 1)  {
		history(cycles/nHist, cycles);
	}
}

//record averages

//update output
time_t end_time = time(0);
write_output(0, end_time);

//write new config
write_config(npart,rpart,lbox);

if (overlap_all()) {cout <<"OVERLAP!";return 1;}

return 0;
}
