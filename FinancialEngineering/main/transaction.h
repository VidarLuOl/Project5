#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <armadillo>
#include <iostream>
#include <fstream>

using namespace arma;
using namespace std;


void Transaction(int MC, int Antall_a, float su, int loop, ofstream& file, int myrank, float lambda);
void TransactionArma(int MC, int Antall_a, vec tran, int loop, ofstream& file, int myrank, float lambda);

#endif
