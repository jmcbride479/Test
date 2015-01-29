//This creates the repeating lattice unit and builds the configuration
#include <iostream>
#include <fstream>
#include <cmath>
#include "writeconfig.hh"

using namespace std;

int main() {

double pi = atan(1)*4;

int nx,ny,nz, x,y,z;
int npart, i, k;
double eta;
double lx, lbox[3][3];
double unit[4][3]={
	{0.25, 0.25, 0.25},
	{0.75, 0.75, 0.25},
	{0.25, 0.75, 0.75},
	{0.75, 0.25, 0.75},
}; 
string u="useless_info";

//read input data
ifstream infile;
infile.open("data.inp");
    infile>>u>>eta>>u>>nx>>ny>>nz;
infile.close();

npart = 4*nx*ny*nz;

double rpart[npart][3];

//repeat unit cell to get coordinates

i=0;

for (x = 0; x != nx; ++x)  {
    for (y = 0; y != ny; ++y)  {
	for (z = 0; z !=nz; ++z)  {
	    for (k = 0; k != 4; ++k)  {
		rpart[i][0] = (unit[k][0]+x)/nx;
		rpart[i][1] = (unit[k][1]+y)/ny;
		rpart[i][2] = (unit[k][2]+z)/nz;
		++i;
	    }
	}
    }
}

//rescaling coordinates to suit input density
lx=pow( (npart*pi/6/eta), (1/3.0));

for (i=0; i!=npart; ++i)  {
    rpart[i][0]=(rpart[i][1]-0.5)*lx;
    rpart[i][1]=(rpart[i][2]-0.5)*lx;
    rpart[i][2]=(rpart[i][3]-0.5)*lx;
}

//writing box dimensions
for (i = 0; i != 3; ++i)  {
    for (k = 0; k != 3; ++k)  {
    lbox[i][k] = 0.0;
    }
}

lbox[0][0] = lx;
lbox[1][1] = lx;
lbox[2][2] = lx;

//call writeconfig.h
writeconfig (npart,rpart,lbox);

return 0;

}
