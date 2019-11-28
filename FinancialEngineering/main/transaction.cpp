#include "transaction.h"
#include <iostream>
#include <armadillo>
#include <fstream>

using namespace std;
using namespace arma;

void Transaction(int MC, int Antall_a, vec tran, int loop, ofstream& file, int myrank){
    int seed = time(0)+myrank;
    cout << "SEEEEEEEEEEEEED = " << seed << " " << myrank << endl;
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

            x_new = eps*(tran(x) + tran(y));
            y_new = (1-eps)*(tran(x) + tran(y));

            tran(x) = x_new;
            tran(y) = y_new;

        }

        for(int j = 0; j < 10; j++){
            file << tran(j) << endl;
            cout << tran(j) << "   " << myrank << endl;
        }
    }
}
