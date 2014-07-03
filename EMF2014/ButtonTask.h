/*
 TiLDA Mk2

 ButtonTask
 Buttons are handled via interrupt callbacks

 The MIT License (MIT)

 Copyright (c) 2014 Electromagnetic Field LTD

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef _BUTTON_TASK_H_
#define _BUTTON_TASK_H_

#include <Arduino.h>
#include <FreeRTOS_ARM.h>
#include "EMF2014Config.h"

void buttonLightPress();

namespace buttons {
    enum Button {
        NONE         = 0,
        LIGHT        = 1,
        SCREEN_LEFT  = 2,
        SCREEN_RIGHT = 4,
        A            = 8,
        B            = 16,
        UP           = 32,
        DOWN         = 64,
        LEFT         = 128,
        RIGHT        = 256,
        CENTER       = 512
    };

    class ButtonSubscription {
    public:
        ButtonSubscription(int buttons);
        Button waitForPress(TickType_t ticksToWait);
        Button waitForPress();
        void clear();
    private:
        int _buttons;
        QueueHandle_t _queue;
    };

    void initializeTask();
}

#endif // _BUTTON_TASK_H_