#include <iostream>
#include <armadillo>
#include <fstream>
#include "transaction.h"
#include "mpi/mpi.h"
#include <vector>

using namespace std;
using namespace arma;

int main()
{
    int m0 = 500; //Start sum, også kaldt m0
    int Antall_Agenter = 500; //Antall agenter
    int MC = 400; //Antall loops, 1 = (Antall_Agenter) linjer
    int loop = 1e7;



    ofstream file;
    file.open("Lommepenger.txt", ios_base::app);

    int numprocs, myrank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MC = MC/numprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


    Transaction(MC, Antall_Agenter, m0, loop, file, myrank, numprocs);

    MPI_Finalize();

    file.close();
    return 0;
}

//mpirun -n 4 ./main
