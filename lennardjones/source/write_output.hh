//This writes the start and end of the output file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include "global.hh"

using namespace std;

void write_output(bool output_switch, time_t output_time)  {

ofstream file;
time_t start_time;
time_t end_time;
string divide(100, '_');

if (output_switch) {

start_time = output_time;
char* s_t = ctime(&start_time);

file.open("output.dat");

file << "\tMonte Carlo simulation of spherical Lennard-Jones particles\n" 
     << "Author: John McBride\n"
     << "Written: Jan 2014\n"
     << "Updated: Jan 2014\n"
     << "Date: " << s_t <<endl
     <<divide <<endl;

file.close();

}

else {

end_time = output_time;
char* e_t = ctime(&end_time);
double minutes = difftime(end_time, start_time)/60;

file.open("output.dat", fstream::app);

file << "\n" << divide << endl
     << "\nEnd time: " << e_t
     << "\nTime taken: " << setprecision(5) << minutes << " minutes\n";

file.close();

}

}
