// This checks for overlaps between all particles
#include <iostream>
#include <numeric>
#include "global.hh"
#include "functions.hh"

bool overlap_all () {

double rij[3];

for (int i=0; i!=npart-1; ++i)  {
    for (int j=i+1; j!=npart; ++j)  {
	for (int k = 0; k!=3; ++k)  {

	    rij[k]=rpart[i][k]-rpart[j][k];
	}

	images(rij);
	double dot_product = rij[0]*rij[0]+rij[1]*rij[1]+rij[2]*rij[2];

	if (dot_product < 1)  {

	    return 1;

	}
    }
}

return 0;

}
		
