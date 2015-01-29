//Module for energy calculations

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "global.hh"
#include "functions.hh"

double energy_new;

double energy_volch(double volOld, double rpartOld[5000][3])  {

double r_cutoff = 4;
double rij[3];
double dot_product;
double r_root;
double energy_diff;
double energy_old = 0;
energy_new = 0;

//calculates energy of all particles for new configuation
for (int i=0; i!=npart-1; ++i)  {
    for ( int j= i+1; j != npart; ++j)  {
	for (int k=0; k!=3; ++k)  {

	    rij[k]=rpart[i][k]-rpart[j][k];
	}
	images(rij);
	dot_product = rij[0]*rij[0]+rij[1]*rij[1]+rij[2]*rij[2];

	if (dot_product <= r_cutoff) {
	    r_root = sqrt(dot_product);
	    energy_new += 4*( pow (1/r_root, 12) - pow (1/r_root, 6) );

	}
	energy_new += 8*pi*npart/vol*( pow( (1/r_cutoff), 9)/9 - pow( (1/r_cutoff), 3)/3 );
    }
}

//calculates energy of all particles for old configuation
for (int i=0; i!=npart-1; ++i)  {
    for ( int j= i+1; j != npart; ++j)  {
	for (int k=0; k!=3; ++k)  {

	    rij[k]=rpartOld[i][k]-rpartOld[j][k];
	}
	images(rij);
	dot_product = rij[0]*rij[0]+rij[1]*rij[1]+rij[2]*rij[2];

	if (dot_product <= r_cutoff) {
	    r_root = sqrt(dot_product);
	    energy_old += 4*( pow (1/r_root, 12) - pow (1/r_root, 6) );

	}
	energy_new += 8*pi*npart/volOld*( pow( (1/r_cutoff), 9)/9 - pow( (1/r_cutoff), 3)/3 );
    }
}

energy_diff = energy_new - energy_old;

return energy_diff;

}
