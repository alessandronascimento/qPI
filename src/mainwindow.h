#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QStatusBar>
#include "gui.h"
#include "mcpi.h"
#include <vector>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow();
    QTabWidget* tabwidget;
    ~MainWindow();
    void create_tabs();
    vector<double> values;
    int nshots;
    bool has_tab_graph;

public slots:
    void slot_input_run_button(void);
    void slot_nshots(int n);
    void closethistab(int tindex);
    
private:
};

#endif // MAINWINDOW_H
