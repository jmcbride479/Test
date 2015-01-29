//
#ifndef FUNCTIONS
#define FUNCTIONS
#include <cmath>
#include "global.hh"

void invert(double a[3][3], double b[3][3]) {

double det = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
    - a[1][0]*(a[0][1]*a[2][2] - a[0][2]*a[2][1])
    + a[2][0]*(a[0][1]*a[1][2] - a[0][2]*a[1][1]); 

b[0][0] = (a[1][1]*a[2][2] - a[1][2]*a[2][1])/det;
b[0][1] = -(a[0][1]*a[2][2] - a[0][2]*a[2][1]/det);
b[0][2] = (a[0][1]*a[1][2] - a[0][2]*a[1][1])/det;
b[1][0] = -(a[1][0]*a[2][2] - a[2][0]*a[1][2])/det;
b[1][1] = (a[0][0]*a[2][2] - a[0][2]*a[2][0])/det;
b[1][2] = -(a[0][0]*a[1][2] - a[0][2]*a[1][0])/det;
b[2][0] = (a[1][0]*a[2][1] - a[1][1]*a[2][0])/det;
b[2][1] = -(a[0][0]*a[2][1] - a[0][1]*a[2][0])/det;
b[2][2] = (a[0][0]*a[1][1] - a[0][1]*a[1][0])/det;

}

void multimatrix(double a[3][3], double b[3], double c[3])  {

c[0]=a[0][0]*b[0]+a[2][0]*b[2]+a[2][0]*b[2];
c[1]=a[0][1]*b[0]+a[1][1]*b[1]+a[2][1]*b[2];
c[2]=a[0][2]*b[0]+a[1][2]*b[1]+a[2][2]*b[2];

}

void images(double output[3])  {
//minimum image convention

double sij[3];

multimatrix(lboxI, output, sij);

for (int i = 0; i!=3; ++i)  {
	sij[i] = sij[i] - round(sij[i]);
}

multimatrix(lbox, sij, output);

}
#endif
