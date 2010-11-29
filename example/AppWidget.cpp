#include <QtCore>
#include <QtGui>

#include "AppWidget.hpp"

#include "Highlight.hpp"

AppWidget::AppWidget() {
    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *highlightBut = new QPushButton("simple default highlight");
    highlightEffect = new Highlight_Effect(this);
    connect(highlightBut, SIGNAL(clicked(bool)),
            this, SLOT(highlightButClicked(bool)));
    layout->addWidget(highlightBut);

    QPushButton *pulseBut = new QPushButton("10 green pulse");
    pulseEffect = new Highlight_Effect(this, Qt::green, 800, 10);
    connect(pulseBut, SIGNAL(clicked(bool)),
            this, SLOT(pulseButClicked(bool)));
    layout->addWidget(pulseBut);

    resize(400, 200);
    setLayout(layout);
    show();
}

AppWidget::~AppWidget() {
    // the effects don't delete themselves
    delete highlightEffect;
    delete pulseEffect;
}

void AppWidget::highlightButClicked(bool) {
    if (highlightEffect->isRunning())
        highlightEffect->stop();
    highlightEffect->start();
}

void AppWidget::pulseButClicked(bool) {
    if (pulseEffect->isRunning())
        pulseEffect->stop();
    pulseEffect->start();
}
