#include "scatter.h"

Scatter::Scatter(int _ncirc, int _n, double _pic, vector<double> _x_data, vector<double> _y_data, QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: white");
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);
    this->x_data = _x_data;
    this->y_data = _y_data;
    this->ncirc = _ncirc;
    this->n = _n;
    this->pi = _pic;
}

Scatter::~Scatter()
{
}

void Scatter::paintEvent(QPaintEvent*){
    if ((x_data.size() > 0) and (x_data.size() == y_data.size())) {
        QPolygonF data_si(x_data.size());
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        QRect rect(Margin, Margin, width()-2 * Margin, height()-2 * Margin);

        double xmin = -0.2;
        double xmax = 1.2;
        double ymin= -0.2;
        double ymax = 1.2;

        for (unsigned i=0; i<x_data.size(); i++){
            double dx = x_data[i] - xmin;
            double dy = y_data[i] - ymin;
            double xd = rect.left() + (dx * (rect.width()-1)/(xmax-xmin));
            double yd = rect.bottom() - (dy * (rect.height()-1)/(ymax-ymin));
            data_si[i]= QPointF(xd, yd);
        }

        int numXticks = 10;
        int numYticks = 10;

        for (int i=0; i<=numXticks; i++){
            int x = rect.left()  + ( i* rect.width() -1 )/numXticks;
            double label = xmin + (i  * (xmax-xmin)/numXticks);
            painter.setPen(Qt::black);
            painter.drawLine(x, rect.top(), x, rect.bottom());
            painter.setPen(Qt::black);
            painter.drawLine(x, rect.bottom(), x, rect.bottom()+5);
            painter.drawText(x-50, rect.bottom()+5, 100, 15,
                             Qt::AlignHCenter | Qt::AlignTop,
                             QString::number(label));

        }

        for (int j=0; j<=numYticks; j++){
            int y = rect.bottom() - (j*rect.height()-1)/numYticks;
            double label = (ymin + (j* ((ymax-ymin)/numYticks)));
            painter.setPen(Qt::black);
            painter.drawLine(rect.left(), y, rect.right(), y);
            painter.setPen(Qt::black);
            painter.drawLine(rect.left()-5, y, rect.left(), y);
            painter.drawText(rect.left()-Margin, y-10, Margin-5, 20,
                             Qt::AlignRight | Qt::AlignVCenter,
                             QString::number(label));
        }

        painter.setPen(Qt::red);
        double xd1, xd2, yd1, yd2;
        xd1 = rect.left() + ((0.0-xmin) * (rect.width()-1)/(xmax-xmin));
        xd2 = rect.left() + ((1.0-xmin) * (rect.width()-1)/(xmax-xmin));
        yd1 = rect.bottom() - ((0.0-ymin) * (rect.height()-1)/(ymax-ymin));
        yd2 = rect.bottom() - ((1.0-ymin) * (rect.height()-1)/(ymax-ymin));
        QRectF sq;
        sq.adjust(xd1, yd1, xd2, yd2);
        painter.drawRect(sq);
        painter.drawEllipse(sq);

        painter.setPen(Qt::black);
        painter.drawText(25, rect.bottom()+30, QString("Ncirc = %1    N = %2    PI=%3").arg(this->ncirc).arg(this->n).arg(this->pi));

        painter.drawRect(rect.adjusted(0, 0, -1, -1));
        painter.setClipRect(rect.adjusted(+1, +1, -1, -1));

        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::black);
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);
        painter.drawPoints(data_si);

    }
}
