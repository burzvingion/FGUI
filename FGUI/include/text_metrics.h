// Copyright (c) 2012 Benjamin M. Crist
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
// Author: Benjamin Crist
// File: text_metrics.h

#ifndef FGUI_TEXT_METRICS_H_
#define FGUI_TEXT_METRICS_H_
#include "fgui_std.h"

#include "rect.h"

FGUI_BEGIN

struct TextMetrics
{
   TextMetrics()
         : bounds(bounds_),
           line(line_) {}

   TextMetrics(const Rect &bounds, const Rect &line):
      bounds_(bounds),
      line_(line),
      bounds(bounds_),
      line(line_) {}

   TextMetrics(const TextMetrics &other):
      bounds_(other.bounds_),
      line_(other.line_),
      bounds(bounds_),
      line(line_) {}

   TextMetrics &operator=(const TextMetrics &rhs)
   {
      bounds_ = rhs.bounds_;
      line_ = rhs.line_;
      return *this;
   }

   const Rect &bounds;
   const Rect &line;

private:
   Rect bounds_;
   Rect line_;
};

FGUI_END


#endif