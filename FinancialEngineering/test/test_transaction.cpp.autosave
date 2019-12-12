#include <armadillo>
#include <catch.hpp>

using namespace arma;
using namespace std;


TEST_CASE("Test Transaction"){
    int Antall_a = 20;
    int MC = 10;
    int loop = 1e7;
    int m0 = 500;
    int x,y;

    float ting[Antall_a];
    float eps, new_x, new_y;

    for(int i = 0; i < Antall_a; i++){
        ting[i] = m0;
    }

    int seed = time(0);
    mt19937_64 engine(seed);
    uniform_real_distribution<double> eps_d(0, 1);


    for(int C = 0; C < MC; C++){
        for(int i = 0; i < loop; i++){
            x = rand() % Antall_a;
            y = rand() % Antall_a;

            while(x == y){
                x = rand() % Antall_a;
            }

            eps = eps_d(engine);

            new_x = eps*(ting[x] + ting[y]);
            new_y = (1-eps)*(ting[x] + ting[y]);
            ting[x] = new_x;
            ting[y] = new_y;
        }
    }

    double sum = 0;
    for(int i = 0; i < Antall_a; i++){
        sum += ting[i];
    }


    REQUIRE(sum == Approx(Antall_a*m0).epsilon(0.1));
}
