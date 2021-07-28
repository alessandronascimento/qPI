#include "mainwindow.h"

MainWindow::MainWindow(){
    setWindowTitle(tr("qPi"));
    this->create_tabs();
    this->has_tab_graph = false;

}

void MainWindow::create_tabs(){
    tabwidget = new QTabWidget;
    tabwidget->setTabsClosable(true);
    tabwidget->setMovable(true);
    setCentralWidget(tabwidget);
    statusBar()->show();

    gui* input_menu = new gui();
    QScrollArea* scroll = new QScrollArea;
    scroll->resize(input_menu->size());
    scroll->setWidget(input_menu);
    tabwidget->addTab(scroll, "Input Menu");
    this->nshots = input_menu->nshots->value();

    connect(input_menu->RunButton, SIGNAL(clicked()), this, SLOT(slot_input_run_button()));
    connect(input_menu->nshots, SIGNAL(valueChanged(int)), this, SLOT(slot_nshots(int)));
    connect(tabwidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closethistab(int)));

}

MainWindow::~MainWindow(){
}


void MainWindow::slot_nshots(int n){
    this->nshots = n;
}

void MainWindow::slot_input_run_button(void){
    if (! this->has_tab_graph){
        McPi* MonteCarloPI = new McPi(this->nshots);
        this->values = MonteCarloPI->vpi;

        plotter* plot = new plotter(this->values, 0);
        plot->resize(600,600);
        plot->show();
        QString tab_lab = QString("Pi values for %1 MC shots").arg(this->nshots);
        delete MonteCarloPI;
//        tabwidget->addTab(plot, tab_lab);
//        tabwidget->setCurrentIndex(1);
//        this->has_tab_graph = true;
    }
    else {
    tabwidget->removeTab(1);
    McPi* MonteCarloPI = new McPi(this->nshots);
    this->values = MonteCarloPI->vpi;
    delete MonteCarloPI;
    plotter* plot = new plotter(this->values, 0);
    QString tab_lab = QString("Pi values for %1 MC shots").arg(this->nshots);
    tabwidget->addTab(plot, tab_lab);
    tabwidget->setCurrentIndex(1);
    this->has_tab_graph = true;
    }
}

void MainWindow::closethistab(int tindex){
    tabwidget->removeTab(tindex);
}
