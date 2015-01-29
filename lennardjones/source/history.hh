//This writes the history file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include "global.hh"

using namespace std;

void history(int check, int cycles) {

int i;
ofstream file;

if (check == 1 ) {
file.open("history.dat", fstream::trunc);
} else {
file.open("history.dat", fstream::app);
}

file<< "Cycles: " << cycles << endl 
    <<"Number_of_particles:\n  "<< npart <<"\nBox_dimensions:\n"<<setprecision(16)
    << lbox[0][0] << "  " << lbox[0][1] << "  " << lbox[0][2] << "\n" 
    << lbox[1][0] << "  " << lbox[1][1] << "  " << lbox[1][2] << "\n" 
    << lbox[2][0] << "  " << lbox[2][1] << "  " << lbox[2][2] << "\n" 
    << "Configuration:";
for (i=0; i!=npart; ++i)  {
    file<<"\n"<<rpart[i][0]<<"  "<<rpart[i][1]<<"  "<<rpart[i][2];
}

file<< endl;

file.close();

}
