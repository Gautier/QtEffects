#ifndef APPWIDGET
#define APPWIDGET

#include <QObject>
#include <QtCore>
#include <QtGui>

#include "Highlight.hpp"

class AppWidget : public QWidget {
    Q_OBJECT
    public:
        AppWidget();
        ~AppWidget();

    private:
        Highlight_Effect *highlightEffect;
        Highlight_Effect *pulseEffect;

    private slots:
        void highlightButClicked(bool);
        void pulseButClicked(bool);
};

#endif

