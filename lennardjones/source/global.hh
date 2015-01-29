//Declarations of global variables

#ifndef GLOBAL
#define GLOBAL

//constants
extern const double pi =3.1415926535897932; 
extern const double boltz = 1.38065156e-23;

//control
extern double Pres, Temp;
extern int nCycle, nSample, nHist;
extern double maxDisp, volCha;
extern bool lHist;
extern double transProb, volChProb;

//structure
extern double lbox[3][3];
extern double lboxI[3][3];
extern double eta;
extern int npart;
extern double rpart[5000][3]; 
extern double vol;

//statistics
extern double transAttempt;
extern double transAccept;
extern double volChAttempt;
extern double volChAccept;
extern double energy_new;

#endif
