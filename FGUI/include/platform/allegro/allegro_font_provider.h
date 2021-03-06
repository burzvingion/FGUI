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
// File: platform/allegro/allegro_font_provider.h

#ifndef FGUI_PLATFORM_ALLEGRO_ALLEGRO_FONT_PROVIDER_H_
#ifndef FGUI_NO_ALLEGRO
#define FGUI_PLATFORM_ALLEGRO_ALLEGRO_FONT_PROVIDER_H_
#include "fgui_std.h"

#include <map>
#include <set>
#include <string>
#include <cctype>
#include <algorithm>

#ifndef FGUI_DEFAULT_FONT_PROVIDER
#define FGUI_DEFAULT_FONT_PROVIDER AllegroFontProvider
#endif

#include "platform/font_provider_interface.h"

FGUI_BEGIN

class AllegroFontProvider : public FontProviderInterface
{
public:
   AllegroFontProvider() {}
   virtual ~AllegroFontProvider() {}

   virtual FontInterface *getFont(const std::string &typeface, const std::string &style, float_t size);
   virtual void freeFont(FontInterface *font);

   virtual void addFont(const std::string &typeface, const std::string &style, const std::string &filename, float_t padding_top, float_t line_scale);

private:
   struct AFontSpec
   {
      AFontSpec() : filename_(""), size_(0.0f) {}
      AFontSpec(const std::string &filename, float_t size) : filename_(filename), size_(size) {}

      bool operator<(const AFontSpec &rhs) const  { return rhs.filename_ == filename_ ? size_ < rhs.size_ : filename_ < rhs.filename_; }
      bool operator<=(const AFontSpec &rhs) const { return rhs.filename_ == filename_ ? size_ <= rhs.size_ : filename_ < rhs.filename_; }
      bool operator=(const AFontSpec &rhs) const  { return rhs.filename_ == filename_ && size_ == rhs.size_; }
      bool operator>=(const AFontSpec &rhs) const { return rhs.filename_ == filename_ ? size_ >= rhs.size_ : filename_ > rhs.filename_; }
      bool operator>(const AFontSpec &rhs) const  { return rhs.filename_ == filename_ ? size_ > rhs.size_ : filename_ > rhs.filename_; }
      
      std::string filename_;
      float_t size_;
   };

   struct AFont
   {
      AFont() : f_(NULL), references_(1) {}
      AFont(FontInterface *font) : f_(font), references_(1) {}

      FontInterface *f_;
      int references_;
   };

   struct FontFileSpec
   {
      FontFileSpec() : filename_(""), font_face_(""), font_style_(""), padding_top_(0), line_scale_(1) {}
      FontFileSpec(const std::string &typeface, const std::string &style)
            : font_face_(typeface), font_style_(style),
              padding_top_(0), line_scale_(1)
      {
         std::transform(font_face_.begin(), font_face_.end(), font_face_.begin(), tolower);
         std::transform(font_style_.begin(), font_style_.end(), font_style_.begin(), tolower);

         filename_.reserve(font_face_.length() + font_style_.length() + 5);

         filename_.append(font_face_);
         filename_.append("_");
         filename_.append(font_style_);
         filename_.append(".ttf");
      }

      FontFileSpec(const std::string &typeface, const std::string &style, float_t padding_top, float_t line_scale, const std::string &filename)
            : font_face_(typeface), font_style_(style), filename_(filename),
              padding_top_(padding_top), line_scale_(line_scale)
      {}

      FontFileSpec &operator=(const FontFileSpec &rhs) { filename_ = rhs.filename_; font_face_ = rhs.font_face_; font_style_ = rhs.font_style_; padding_top_ = rhs.padding_top_; line_scale_ = rhs.line_scale_; return *this; }

      bool operator<(const FontFileSpec &rhs) const  { return rhs.font_face_ == font_face_ ? font_style_ < rhs.font_style_ : font_face_ < rhs.font_face_; }
      bool operator<=(const FontFileSpec &rhs) const { return rhs.font_face_ == font_face_ ? font_style_ <= rhs.font_style_ : font_face_ < rhs.font_face_; }
      bool operator==(const FontFileSpec &rhs) const  { return rhs.font_face_ == font_face_ && font_style_ == rhs.font_style_; }
      bool operator!=(const FontFileSpec &rhs) const  { return !(*this == rhs); }
      bool operator>=(const FontFileSpec &rhs) const { return rhs.font_face_ == font_face_ ? font_style_ >= rhs.font_style_ : font_face_ > rhs.font_face_; }
      bool operator>(const FontFileSpec &rhs) const  { return rhs.font_face_ == font_face_ ? font_style_ > rhs.font_style_ : font_face_ > rhs.font_face_; }

      const std::string &getFilename() const { return filename_; }

      float_t getPadding() const { return padding_top_; }
      float_t getLineScale() const { return line_scale_; }

   private:
      std::string filename_;
      std::string font_face_;
      std::string font_style_;
      float_t padding_top_;
      float_t line_scale_;
   };

   FontFileSpec getFFS(const std::string &typeface, const std::string &style);

   std::set<FontFileSpec> font_files_;

   std::map<AFontSpec,AFont> fonts_by_spec_;
   std::map<FontInterface*,AFontSpec> specs_by_font_;
};

FGUI_END

#endif
#endif
