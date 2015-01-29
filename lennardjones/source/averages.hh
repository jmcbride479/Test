// This records the statistics
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ios>
#include "global.hh"

using namespace std;

void averages(bool output_switch, int cycles) {

ofstream file;

if (output_switch) { 

file.open("output.dat", fstream::app);

file << "\n\n\tCycles\t\ttransAcc\tvolChAcc\teta\tenergy\n";

file.close();

} else {

file.open("output.dat", fstream::app);

streamsize prec = cout.precision();

file << "\t" << cycles << "\t\t" << setprecision(4) << transAccept/transAttempt
     << "\t\t" << volChAccept/volChAttempt << "\t\t" << eta << "\t\t"
     << energy_new << setprecision(prec)  << endl;

file.close();

}

}
