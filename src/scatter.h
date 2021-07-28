#ifndef SCATTER_H
#define SCATTER_H

#include <QWidget>
#include <QFile>
#include <vector>
#include <iostream>
#include <cmath>
#include <QPainter>
#include <QFileDialog>

using namespace std;

class Scatter : public QWidget
{
    Q_OBJECT
public:
    Scatter(int _ncirc, int _n, double _pic, vector<double> _x_data, vector<double> _y_data, QWidget *parent = 0);
    ~Scatter();
    vector<double> x_data;
    vector<double> y_data;
    int ncirc;
    int n;
    double pi;
    enum { Margin = 50 };

private:
    void paintEvent(QPaintEvent* event);

};

#endif // SCATTER_H
