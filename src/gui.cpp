#include "gui.h"

gui::gui()
{
    VertLayout1 = new QVBoxLayout;
    this->setLayout(VertLayout1);

    QLabel* label1 = new QLabel("<h2>Número de pontos: </h2>");
    nshots = new QSpinBox;
    nshots->setValue(1000);
    nshots->setSingleStep(2000);
    nshots->setMinimum(2000);
    nshots->setMaximum(1E9);

    VertLayout1->addWidget(label1);
    VertLayout1->addStretch();

    explanation = new QLabel("Para calcular o valor de pi, podemos usar a relação\n"
                             "entre as áreas do quadrado e do círculo para o caso\n"
                             "de uma circunferência circunscrita em um quadrado.");
    QLabel* fig = new QLabel;
    QPixmap* pm = new QPixmap(":/fig/circ_quad.png");
    fig->setPixmap(*pm);
    fig->setAlignment(Qt::AlignCenter);
    VertLayout1->addWidget(explanation);
    VertLayout1->addWidget(fig);
    QLabel* exp2 = new QLabel("Para uma circunferência de raio \"r\", temos que a área\n"
                              "da circunferência será igual a pi*r^2. Já a área do quadrado\n"
                              "é igual a (2r)^2 = 4r^2.Fazendo uma relação entre estas\n"
                              "grandezas, chegamos à conclusão de que a pi = 4*Ac/Aq, onde\n"
                              "Ac é a area da circunferência e Aq e a área do quadrado.\n\n"
                              "Usaremos as propriedades dos números aleatórios para calcular\n"
                              "estas áreas. A razao Ac/Aq será calculada como a razão entre \n"
                              "o número de pontos sorteados aleatoriamente que cai no circulo\n"
                              "em relacao ao numero que cai no quadrado.\n\n"
                              "Selecione abaixo o número de números a ser sorteado.");
    VertLayout1->addWidget(exp2);
    VertLayout1->addWidget(nshots);
    VertLayout1->addStretch();
    RunButton = new QPushButton("Começar!");
    VertLayout1->addWidget(RunButton);
    VertLayout1->addStretch();

//    connect(RunButton, SIGNAL(clicked()), this, SLOT(slot_run_button()));
}

void gui::slot_run_button(void){
    McPi* MonteCarloPI = new McPi(nshots->value());
    this->values = MonteCarloPI->vpi;
    delete MonteCarloPI;
}

gui::~gui(){
}


