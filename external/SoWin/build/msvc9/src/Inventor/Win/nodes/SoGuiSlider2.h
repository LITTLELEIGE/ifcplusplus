#ifndef COIN_SOGUISLIDER2_H
#define COIN_SOGUISLIDER2_H

// src\Inventor\Win\nodes\SoGuiSlider2.h.  Generated from Slider2.h.in by configure.

/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#ifndef SOWIN_INTERNAL
#error this is a private header file
#endif /* !SOWIN_INTERNAL */

#include <Inventor/fields/SoSFBool.h>
#include <Inventor/fields/SoSFVec2f.h>
#include <Inventor/fields/SoSFVec3f.h>

#include <Inventor/nodekits/SoBaseKit.h>

class SoGuiSlider2 : public SoBaseKit {
  typedef SoBaseKit inherited;

  SO_KIT_HEADER(SoGuiSlider2);

  SO_KIT_CATALOG_ENTRY_HEADER(topSeparator);
  SO_KIT_CATALOG_ENTRY_HEADER(surfaceGeometry);
  SO_KIT_CATALOG_ENTRY_HEADER(surfaceTexture);
  SO_KIT_CATALOG_ENTRY_HEADER(surfaceMaterial);
  SO_KIT_CATALOG_ENTRY_HEADER(surfaceTexCoords);
  SO_KIT_CATALOG_ENTRY_HEADER(surfaceCoords);
  SO_KIT_CATALOG_ENTRY_HEADER(surfaceFaceSet);
  SO_KIT_CATALOG_ENTRY_HEADER(knobGeometry);

public:
  static void initClass(void);

  SoGuiSlider2(void);

  SoSFVec3f size;

  SoSFVec2f min;
  SoSFVec2f max;
  SoSFVec2f value;

  SoSFBool alwaysHook;

  virtual void handleEvent(SoHandleEventAction * action);

  void sizeUpdate(void);
  void valueUpdate(void);

protected:
  virtual ~SoGuiSlider2(void);

private:
  void * internals;

};

#endif // !COIN_SOGUISLIDER2_H
