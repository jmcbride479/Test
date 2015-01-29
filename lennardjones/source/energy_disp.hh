//Module for energy calculations

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "global.hh"
#include "functions.hh"


bool energy(int part, double rij_scalar[5000])  {

double r_cutoff = 4;
double rij[3];
double dot_product;
double energy_old = 0;
double energy_new = 0;

for (int i=0; i!=npart; ++i)  {
    if ( i != part)  {
	for (int j=0; j!=3; ++j)  {

	    rij[j]=rpart[i][j]-rpart[part][j];
	}
	images(rij);
	dot_product = rij[0]*rij[0]+rij[1]*rij[1]+rij[2]*rij[2];

	if (dot_product <= r_cutoff) {

	    energy_old += 4*( pow (1/rij_scalar[i], 12) - pow (1/rij_scalar[i], 6) );

	}
    }
}


for (int i=0; i!=npart; ++i)  {
    if ( i != part)  {
	if (rij_scalar[i] <= r_cutoff)  {

	    energy_new += 4*( pow (1/rij_scalar[i], 12) - pow (1/rij_scalar[i], 6) );

	}
    }
}

double acc = exp( -1/Temp*(energy_new-energy_old) );
double throw_die = rand();

if (throw_die/RAND_MAX < acc) {
	return 1;
} else { return 0; }

}
