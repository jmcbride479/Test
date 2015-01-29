// This file reads instructions from the control file
#include <fstream>
#include <iostream>
#include <string>
#include "global.hh"
#include "functions.hh"


double Pres, Temp;
int nCycle, nSample, nHist;
double maxDisp, volCha;
bool lHist;
double transProb, volChProb;

int npart;
double eta;
double lbox[3][3];
double lboxI[3][3]={{0,0,0},{0,0,0},{0,0,0}};
double vol;

double rpart[5000][3];

using namespace std;

void read_inputs() {

int i, j;

//read control file
ifstream file1;
string u = "useless data";

file1.open("control.inp");

file1>> u >> u >> Pres >> Temp >> u  >> u >> nCycle >> nSample;
file1>> u >> maxDisp >> u >> volCha >> u >> u >> lHist >> nHist;
file1>> u >> u >> u >> transProb >> volChProb;

file1.close();

//read configuration
ifstream file2;

file2.open("config.inp");

file2>> u >> npart >> u;

i=0; 
while (i!=3) {
    j=0;
    while (j!=3) {
	file2>>lbox[i][j];
	++j;
    }++i;
}

     //calculate inverted box dimensions and volume
invert(lbox, lboxI);
vol = lbox[0][0]*lbox[1][1]*lbox[2][2];
     //

file2>> u;

i=0;

while (i!=npart)  {
	j=0;
	while (j!=3)  {
	file2>> rpart[i][j];
	++j;
	}
	++i;
}

}

