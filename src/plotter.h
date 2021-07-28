#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QFile>
#include <vector>
#include <iostream>
#include <cmath>
#include <QPainter>
#include <QFileDialog>

using namespace std;

class plotter : public QWidget
{
    Q_OBJECT

public:
    plotter(vector<double> _data, QWidget *parent = 0);
    ~plotter();
    vector<double> data;
    enum { Margin = 50 };

private:
    void paintEvent(QPaintEvent* event);
};

#endif // PLOTTER_H
