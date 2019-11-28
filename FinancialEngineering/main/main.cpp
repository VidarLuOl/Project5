#include <iostream>
#include <armadillo>
#include <fstream>
#include "transaction.h"
#include "mpi/mpi.h"

using namespace std;
using namespace arma;

int main()
{
    int m0 = 500; //Start sum, også kaldt m0
    int Antall_Agenter = 500; //Antall agenter
    int MC = 24; //Antall loops
    int loop = 1e7;

    //Fyller opp lommene til alle agentene
    vec tran(Antall_Agenter);
    tran.fill(m0);

    ofstream file;
    file.open("Lommepenger.txt");

    int numprocs, myrank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MC = MC/numprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


    Transaction(MC, Antall_Agenter, tran, loop, file, myrank);

    cout << "IABOIBÅOFBONDN" << endl;

    MPI_Finalize();

    file.close();
    return 0;
}

//mpirun -n 4 ./main_function
