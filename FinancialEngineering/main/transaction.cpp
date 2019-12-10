#include "transaction.h"
#include <iostream>
#include <armadillo>
#include <fstream>
#include "mpi/mpi.h"

using namespace std;
using namespace arma;

void Transaction(int MC, int Antall_a, float su, int loop, ofstream& file, int myrank, int size){
    int seed = time(0)+myrank;
    mt19937_64 engine(seed);

    float ting[Antall_a];

    for(int i = 0; i < Antall_a; i++){
        ting[i] = su;
    }

    uniform_real_distribution<double> eps_d(0, 1);

    int x,y;
    double eps;
    double x_new, y_new;

    float summ[Antall_a];


    for(int C = 0; C < MC; C++){
        for(int i = 0; i < loop; i++){
            x = rand() % Antall_a;
            y = rand() % Antall_a;

            while(x == y){
                x = rand() % Antall_a;
            }

            eps = eps_d(engine);

            x_new = eps*(ting[x] + ting[y]);
            y_new = (1-eps)*(ting[x] + ting[y]);

            ting[x] = x_new;
            ting[y] = y_new;

        }

        MPI_Reduce(&ting, &summ, Antall_a, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

        if(myrank == 0){
            for(int i = 0; i < Antall_a; i++){
                file << summ[i]*0.25 << endl;
            }
            cout << "hei" << endl;
        }

        MPI_Barrier(MPI_COMM_WORLD);
    }
}
