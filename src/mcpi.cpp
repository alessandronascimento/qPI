#include "mcpi.h"

using namespace std;

McPi::McPi(int nshots){
    double x, y;

    pi_calc = 0.0;
    ncirc=0;
    int cont = 0;

//    gsl_rng *r;
    srand(rand());
//    r = gsl_rng_alloc (gsl_rng_ranlxs2);
//    double seed = 30.0 * (rand()/(RAND_MAX + 1.0));
//    gsl_rng_set(r, seed);

    while (cont < nshots){
        for (int i=0; i< 100; i++){
//            x = gsl_rng_uniform(r);
            x = rand() % 1000/1000.0;
            xd.push_back(x);
//            y = gsl_rng_uniform(r);
            y = rand() % 1000/1000.0;
            yd.push_back(y);

            if (this->is_inside_circle(x, y)){
                ncirc++;
            }
        }
        cont += 100;
        pi_calc = 4.0 * double((ncirc*1.0)/cont);
        vpi.push_back(pi_calc);
    }
//    gsl_rng_free (r);
    Scatter* scat_plot = new Scatter(ncirc, cont, pi_calc, xd, yd);
//    scat_plot->setAttribute(Qt::WA_QuitOnClose, false);
    scat_plot->resize(600,600);
    scat_plot->show();

}

bool McPi::is_inside_circle(float x, float y){
    bool ret;
    float r = sqrt(((x-0.5)*(x-0.5)) + ((y-0.5)*(y-0.5)));
    if (r < 0.5){
        ret = true;
    }
    else {
        ret = false;
    }
    return (ret);
}
