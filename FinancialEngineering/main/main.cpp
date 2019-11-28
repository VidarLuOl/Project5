#include <iostream>
#include <armadillo>
#include <fstream>
#include "transaction.h"

using namespace std;
using namespace arma;

int main()
{
    int m0 = 500; //Start sum, også kaldt m0
    int Antall_Agenter = 500; //Antall agenter
    int MC = 10; //Antall loops
    int loop = 1e7;

    //Fyller opp lommene til alle agentene
    vec tran(Antall_Agenter);
    tran.fill(m0);

    ofstream file;
    file.open("Lommepenger.txt");

    Transaction(MC, Antall_Agenter, tran, loop, file);

    file.close();
    return 0;
}

