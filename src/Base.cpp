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

#include "Base.hpp"

Base::Base(QWidget *w, int duration, int loopCount) 
    : duration(duration), w(w){
    timeLine = new QTimeLine(duration);
    timeLine->setFrameRange(0, 255);
    timeLine->setLoopCount(loopCount);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(nextStep(int)));
    connect(timeLine, SIGNAL(finished()), this, SLOT(timelineFinished()));
}

Base::~Base() {
}

bool Base::isRunning() {
    return timeLine->state() == QTimeLine::Running;
}

void Base::timelineFinished() {
    ensureCoherentState();
    emit finished();
}

void Base::start() {
    setup();
    timeLine->start();
}

void Base::stop() {
    timeLine->stop();
    ensureCoherentState();
}
