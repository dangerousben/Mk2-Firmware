/*
 TiLDA Mk2

 RGBTask
 This task handles the two RGB LEDs for the front of the badge.
 Setting them to a requested color and also provides the Torch functionality
 RGB Request are of type RGBRequest_t are sent to the RGBRequestQueue by other tasks

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

#ifndef _RGB_TASK_H_
#define _RGB_TASK_H_

#include <Arduino.h>
#include <FreeRTOS_ARM.h>
#include "EMF2014Config.h"



namespace rgb {
    enum Led {
        LED1,
        LED2,
        BOTH
    };

    class Color {
    public:
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        Color (uint8_t, uint8_t, uint8_t);
        bool moveTowards(Color target, uint8_t step);
    };

    void setColor(rgb::Led led, rgb::Color color);
    void setColor(rgb::Color color);
    void fadeToColor(rgb::Led led, rgb::Color color);
    void fadeToColor(rgb::Color color);

    void initializeTask();
}

#endif // _RGB_TASK_H_