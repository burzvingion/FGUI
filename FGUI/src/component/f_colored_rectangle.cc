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
// File: component/f_colored_rectangle.cc

#include "component/f_colored_rectangle.h"

FGUI_BEGIN


FColoredRectangle::FColoredRectangle():
   normal_color_(Color(1, 0, 0)),
   focused_color_(Color(1, 0, 0)),
   hover_color_(Color(1, 0, 0)),
   active_color_(Color(1, 0, 0))
{
   setFocusable(true);
}

FColoredRectangle::FColoredRectangle(const Color &color):
   normal_color_(color),
   focused_color_(color),
   hover_color_(color),
   active_color_(color)
{
   setFocusable(true);
}

FColoredRectangle::FColoredRectangle(const Color &normalColor,
   const Color &focusedColor,
   const Color &hoverColor,
   const Color &activeColor):
      normal_color_(normalColor),
      focused_color_(focusedColor),
      hover_color_(hoverColor),
      active_color_(activeColor)
{
   setFocusable(true);
}

FColoredRectangle::~FColoredRectangle()
{
}

FGUI_END
