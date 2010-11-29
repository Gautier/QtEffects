/********************************************************************************
QtFfects is a collection of graphical effects for your Qt Widgets

Copyright (C) 2009 Gautier Hayoun
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, 
       this list of conditions and the following disclaimer.
    
    2. Redistributions in binary form must reproduce the above copyright 
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    3. The name of the author may not be used to endorse or promote products
       derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************/

#include "Highlight.hpp"

Highlight_Effect::Highlight_Effect(QWidget *w, QColor effectColor,
        int duration, int loopCount)
    : Base(w, duration, loopCount), effectColor(effectColor) {
}

Highlight_Effect::~Highlight_Effect() {
}

void Highlight_Effect::setup() {
    QPalette palette = w->palette();
    QColor color = palette.color(w->backgroundRole());

    QPalette defaultPalette = QApplication::palette();
    restoreColor = defaultPalette.color(QPalette::Window);
}

void Highlight_Effect::nextStep(int value) {
    value = 255 - value;

    // manual alpha blending
    QColor newColor = effectColor;
    const double alpha = (double)value/255;
    const double alpha1 = 1 - alpha;
    newColor.setRed(alpha1 * restoreColor.red() + alpha * newColor.red());
    newColor.setGreen(alpha1 * restoreColor.green() + alpha * newColor.green());
    newColor.setBlue(alpha1 * restoreColor.blue() + alpha * newColor.blue());

    QPalette palette = w->palette();
    palette.setColor(w->backgroundRole(), newColor);
    w->setPalette(palette);
    w->repaint();
}

void Highlight_Effect::ensureCoherentState() {
    QPalette palette = w->palette();
    palette.setColor(w->backgroundRole(), restoreColor);
    w->setPalette(palette);
    w->repaint();
}
