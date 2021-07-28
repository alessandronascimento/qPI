#ifndef MCPI_H
#define MCPI_H

#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <iostream>
//#include <gsl/gsl_rng.h>
#include "scatter.h"
#include <vector>

using namespace std;

class McPi
{
public:
    double pi_calc;
    vector<double> vpi;
    vector<double> xd;
    vector<double> yd;
    int ncirc;
    McPi(int nshots);
    bool is_inside_circle(float x, float y);
};

#endif // MCPI_H
