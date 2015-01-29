// This checks for overlaps between particles

// Maybe should have some parts of this in the metropolis header!!: attempt/accept and repositioning
#include <iostream>
#include <numeric>
#include <cmath>
#include "global.hh"
#include "functions.hh"
#include "energy_disp.hh"

void overlap_p (int part, double rpartNew[3]) {

double rij[3];
double rij_scalar[npart];
double dot_product;

//calculate particle separation to determine if overlap
for (int i=0; i!=npart; ++i)  {
    if ( i != part)  {
	for (int j=0; j!=3; ++j)  {

	    rij[j]=rpart[i][j]-rpartNew[j];
	}
	images(rij);
	dot_product = rij[0]*rij[0]+rij[1]*rij[1]+rij[2]*rij[2];

	if (dot_product < 1)  {
	    return;
	}
//Put particle separation into vector
	rij_scalar[i] = sqrt(dot_product);

    }
}

//calculates energy - bool function returns true if accepted
if (energy(part, rij_scalar))  {

    ++transAccept;
    for (int k=0; k!=3; ++k) {
	rpart[part][k]=rpartNew[k];
    }
}

}
