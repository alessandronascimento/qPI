#include "plotter.h"

plotter::plotter(vector<double> _data, QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: white");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);
    this->data = _data;
}

plotter::~plotter()
{
}

void plotter::paintEvent(QPaintEvent *){
    if (data.size() > 0) {
        QPolygonF data_si(data.size());
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        QRect rect(Margin, Margin, width()-2 * Margin, height()-2 * Margin);

        double xmin = 0.0;
        double xmax = 1.0*(data.size());
        double ymin= data[0];
        double ymax = ymin;

        for (unsigned i=0; i<data.size(); i++){
            if(data[i] < ymin){
                ymin = data[i];
            }
            else if (data[i] > ymax){
                ymax=data[i];
            }
        }

        for (unsigned i=0; i<data.size(); i++){
            double dx = 1.0*i;
            double dy = data[i] - ymin;
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

        double xd1, xd2, yd;
        xd1 = rect.left() + (0.0 * (rect.width()-1)/(xmax-xmin));
        xd2 = rect.left() + ((data.size()*1.0) * (rect.width()-1)/(xmax-xmin));
        yd = rect.bottom() - ((M_PI-ymin) * (rect.height()-1)/(ymax-ymin));
        painter.drawLine(xd1, yd, xd2, yd);

        painter.setPen(Qt::black);

        painter.drawRect(rect.adjusted(0, 0, -1, -1));
        painter.setClipRect(rect.adjusted(+1, +1, -1, -1));

        QPen pen;
        pen.setWidth(5);
        pen.setColor(Qt::black);
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);
        painter.drawPoints(data_si);

    }
}
