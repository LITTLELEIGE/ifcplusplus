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

/*!
  \class SoSFBox3i32 SoSFBox3i32.h Inventor/fields/SoSFBox3i32.h
  \brief The SoSFBox3i32 class is a container for an SbBox3i32 vector.
  \ingroup fields

  This field is used where nodes, engines or other field containers
  needs to store a box.

  \COIN_CLASS_EXTENSION
  \since Coin 2.5
*/

// *************************************************************************

#include <Inventor/fields/SoSFBox3i32.h>

#include <Inventor/SoInput.h>
#include <Inventor/SoOutput.h>
#include <Inventor/errors/SoDebugError.h>
#include <Inventor/errors/SoReadError.h>

#include "fields/SoSubFieldP.h"

// *************************************************************************

SO_SFIELD_SOURCE(SoSFBox3i32, SbBox3i32, const SbBox3i32 &);

// *************************************************************************

// Override from parent class.
void
SoSFBox3i32::initClass(void)
{
  SO_SFIELD_INTERNAL_INIT_CLASS(SoSFBox3i32);
}

// No need to document readValue() and writeValue() here, as the
// necessary information is provided by the documentation of the
// parent classes.
#ifndef DOXYGEN_SKIP_THIS


SbBool
SoSFBox3i32::readValue(SoInput * in)
{
  int32_t min[3];
  int32_t max[3];
  if (!in->read(min[0]) ||
      !in->read(min[1]) ||
      !in->read(min[2]) ||
      !in->read(max[0]) ||
      !in->read(max[1]) ||
      !in->read(max[2])) {
    SoReadError::post(in, "Couldn't read SoSFBox3i32");
    return FALSE;
  }
  this->setValue(min[0], min[1], min[2], max[0], max[1], max[2]);
  return TRUE;
}

void
SoSFBox3i32::writeValue(SoOutput * out) const
{
  int32_t min[3];
  int32_t max[3];
  SbBox3i32 b = this->getValue();
  b.getBounds(min[0], min[1], min[2], max[0], max[1], max[2]);
  out->write(min[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(min[1]);
  if (!out->isBinary()) out->write(' ');
  out->write(min[2]);
  if (!out->isBinary()) out->write(' ');
  out->write(max[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(max[1]);
  if (!out->isBinary()) out->write(' ');
  out->write(max[2]);
}

#endif // DOXYGEN_SKIP_THIS

// *************************************************************************

/*!
  Set value of vector.
*/
void
SoSFBox3i32::setValue(int32_t xmin, int32_t ymin, int32_t zmin,
                      int32_t xmax, int32_t ymax, int32_t zmax)
{
  this->setValue(SbBox3i32(xmin, ymin, zmin, xmax, ymax, zmax));
}


/*!
  Set value of vector.
*/
void
SoSFBox3i32::setValue(const SbVec3i32 & minvec, const SbVec3i32 & maxvec)
{
  this->setValue(SbBox3i32(minvec, maxvec));
}


/*!
  Set value of vector.
*/
void
SoSFBox3i32::getValue(SbBox3i32 & box) const
{
  box = value;
}

// *************************************************************************

#ifdef COIN_TEST_SUITE

BOOST_AUTO_TEST_CASE(initialized)
{
  SoSFBox3i32 field;
  BOOST_CHECK_MESSAGE(SoSFBox3i32::getClassTypeId() != SoType::badType(),
                      "SoSFBox3i32 class not initialized");
  BOOST_CHECK_MESSAGE(field.getTypeId() != SoType::badType(),
                      "missing class initialization");
}

#endif // COIN_TEST_SUITE
