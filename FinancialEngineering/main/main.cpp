#include <iostream>
#include <armadillo>
#include <fstream>
#include <chrono>
#include "transaction.h"
#include "mpi/mpi.h"
#include <vector>

using namespace std;
using namespace arma;

int main()
{
    int m0 = 500; //Start sum, også kaldt m0
    int Antall_Agenter = 500; //Antall agenter
    int MC = 1000; //Antall loops, 1 = (Antall_Agenter) linjer
    int loop = 1e7;
    float lambda = 0.5;

    vec tran(Antall_Agenter);
    tran.fill(m0);


    ofstream file;
    file.open("Lommepenger.txt", ios_base::app);

    auto start = chrono::high_resolution_clock::now();


    int numprocs, myrank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MC = MC/numprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


    Transaction(MC, Antall_Agenter, m0, loop, file, myrank, lambda);
    //TransactionArma(MC, Antall_Agenter, tran, loop, file, myrank, lambda);

    MPI_Finalize();

    file.close();

    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = (finish - start);
    if(myrank == 0){
        cout << "Time = " << elapsed.count() << " s " << endl;
    }

    return 0;
}

//mpirun -n 4 ./main
