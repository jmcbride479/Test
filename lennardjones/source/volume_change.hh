//This implement's Wood's method for a MC NPT volume change.
#include <cmath>
#include <cstdlib>

#include "global.hh"
#include "functions.hh"
#include "overlap_all.hh"
#include "energy_volch.hh"

using namespace std;

void wood()  {

++volChAttempt;

//save dimensions and calculate new ones
double throw_die = rand();
double scaling = 1 + (throw_die/RAND_MAX-0.5)*volCha;

double lboxOld[3][3], lboxIOld[3][3], volOld, rpartOld[5000][3];

for (int i = 0; i!=3; ++i)  {
	for (int j = 0; j!=3; ++j)  {
		lboxOld[i][j]=lbox[i][j];
		lboxIOld[i][j]=lboxI[i][j];
		lbox[i][j] = lbox[i][j]*scaling;
	}
}

volOld = vol;

invert(lbox, lboxI);
vol = lbox[0][0]*lbox[1][1]*lbox[2][2];

for (int i = 0; i!=npart; ++i) {
	for (int k = 0; k!=3; ++k)  {
		rpartOld[i][k]=rpart[i][k];
		rpart[i][k]=rpart[i][k]*scaling;
	}
}

//check for overlaps
if (overlap_all())  {
//if overlap_all is true then restore coordinates etc.

    for (int i = 0; i!=3; ++i)  {
	for (int j = 0; j!=3; ++j)  {
		lbox[i][j]=lboxOld[i][j];
		lboxI[i][j]=lboxIOld[i][j];
	}
    }

    vol = volOld;

    for (int i = 0; i!=npart; ++i) {
	for (int k = 0; k!=3; ++k)  {
		rpart[i][k]=rpart[i][k]/scaling;
	}
    }

} else  {

    double energy_diff= energy_volch(volOld, rpartOld);

    double acc = energy_diff/Temp + Pres/Temp*(vol-volOld) - npart*log(vol/volOld);
    throw_die = rand();

    if ( acc <= 0.0 || throw_die/RAND_MAX < exp (-acc) )  {
	
	++volChAccept;
	eta = npart*pi/6/vol;

    } else {
    	for (int i = 0; i!=3; ++i)  {
		for (int j = 0; j!=3; ++j)  {
			lbox[i][j]=lboxOld[i][j];
			lboxI[i][j]=lboxIOld[i][j];
		}
   	 }

   	 vol = volOld;

   	 for (int i = 0; i!=npart; ++i) {
		for (int k = 0; k!=3; ++k)  {
			rpart[i][k]=rpart[i][k]/scaling;
		}
   	 }

    }
}

}
