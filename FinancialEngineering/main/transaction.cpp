#include "transaction.h"
#include <iostream>
#include <armadillo>
#include <fstream>
#include "mpi/mpi.h"
#include <armadillo>

using namespace std;
using namespace arma;

void Transaction(int MC, int Antall_a, float su, int loop, ofstream& file, int myrank, float lambda){
    int seed = time(0)+myrank;
    mt19937_64 engine(seed);

    float ting[Antall_a];
    vec c(Antall_a*Antall_a);
    vec d(Antall_a*Antall_a);


    for(int i = 0; i < Antall_a; i++){
        ting[i] = su;
    }

    uniform_real_distribution<double> eps_d(0, 1);

    int x,y;
    double eps, sm;
    double x_new, y_new, co;

    for(int C = 0; C < MC; C++){
        c.zeros();
        for(int i = 0; i < loop; i++){
            x = rand() % Antall_a;
            y = rand() % Antall_a;

            while(x == y){
                x = rand() % Antall_a;
            }


            co = pow(fabs(ting[x]-ting[y]),-2)*pow(c(x*Antall_a+y)+1, 4);

            /*
                eps = eps_d(engine);

                x_new = eps*(ting[x] + ting[y]);
                y_new = (1-eps)*(ting[x] + ting[y]);

                ting[x] = x_new;
                ting[y] = y_new;
            */

            /*
            if(co > eps_d(engine)){
                eps = eps_d(engine);

                x_new = eps*(ting[x] + ting[y]);
                y_new = (1-eps)*(ting[x] + ting[y]);

                ting[x] = x_new;
                ting[y] = y_new;
            }
            */


            /*
            if(co > eps_d(engine)){
                c(x,y) += 1;
                eps = eps_d(engine);

                sm = (1-lambda)*(eps*ting[y] - (1-eps)*ting[x]);

                x_new = ting[x] + sm;
                y_new = ting[y] - sm;

                ting[x] = x_new;
                ting[y] = y_new;
            }
            */

            if(co > eps_d(engine)){
                c(x*Antall_a + y) += 1;
                eps = eps_d(engine);

                sm = (1-lambda)*(eps*ting[y] - (1-eps)*ting[x]);

                x_new = ting[x] + sm;
                y_new = ting[y] - sm;

                ting[x] = x_new;
                ting[y] = y_new;
            }

            //MPI_Reduce(&c, &d, Antall_a*Antall_a, MPI_INTEGER, MPI_SUM, 0, MPI_COMM_WORLD);

        }
        MPI_Reduce(&c, &d, Antall_a*Antall_a-1, MPI_INTEGER, MPI_SUM, 0, MPI_COMM_WORLD);
        if(myrank==0){
            cout << "____________________" << endl;
            cout << d << endl;
        }
        for(int i = 0; i < Antall_a; i++){
            file << ting[i] << endl;
        }

    }
}

void TransactionArma(int MC, int Antall_a, vec tran, int loop, ofstream& file, int myrank, float lambda){
    int seed = time(0)+myrank;
    mt19937_64 engine(seed);

    uniform_real_distribution<double> eps_d(0, 1);

    int x,y;
    double eps;
    double x_new, y_new;

    for(int C = 0; C < MC; C++){
        for(int i = 0; i < loop; i++){
            x = rand() % Antall_a;
            y = rand() % Antall_a;

            while(x == y){
                x = rand() % Antall_a;
            }

            eps = eps_d(engine);

            //sm = (1-lambda)*(eps*ting[y]);

            x_new = eps*(tran[x] + tran[y]);
            y_new = (1-eps)*(tran[x] + tran[y]);

            tran[x] = x_new;
            tran[y] = y_new;

        }

        file << tran << endl;
    }
}
