//This attempts a Metropolis translation move
#include <cstdlib>
#include <iostream>

#include "global.hh"
#include "overlap_particle.hh"

void metropolis()  {

double rpartNew[3];

//attempt a random displacement of a particle
++transAttempt;
int part =rand() % npart;
double randNo;

for (int i = 0; i != 3; ++i)  {
    randNo = rand();
    rpartNew[i] = rpart[part][i]+ (randNo/RAND_MAX-0.5)*maxDisp;
}

images (rpartNew);

//call overlap; overlap_p then links to energy module
overlap_p (part, rpartNew);




}
