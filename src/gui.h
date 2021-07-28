#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QPolygonF>
#include <QScrollArea>
#include "mcpi.h"
#include "plotter.h"
#include <iostream>
#include <vector>


using namespace std;

class gui : public QWidget
{
    Q_OBJECT

public:
    QVBoxLayout* VertLayout1;
    QSpinBox* nshots;
    QPushButton* RunButton;
    QLabel* explanation;
    vector<double> values;
    QLabel* plot_header;

    gui();
    virtual ~gui();

public slots:
    void slot_run_button(void);
};

#endif // GUI_H
