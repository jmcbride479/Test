//This writes the configuration
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void writeconfig(int npart, double rpart[5000][3], double lbox[3][3]) {

int i;
ofstream file;

file.open("config.inp");

file<<"Number_of_particles:\n  "<< npart <<"\nBox_dimensions:\n"<<setprecision(16)
    << lbox[0][0] << "  " << lbox[0][1] << "  " << lbox[0][2] << "\n" 
    << lbox[1][0] << "  " << lbox[1][1] << "  " << lbox[1][2] << "\n" 
    << lbox[2][0] << "  " << lbox[2][1] << "  " << lbox[2][2] << "\n" 
    << "Configuration:";
for (i=0; i!=npart; ++i)  {
    file<<setprecision(16)<<"\n"<<rpart[i][0]<<"  "<<rpart[i][1]<<"  "<<rpart[i][2];
}

file.close();

}
