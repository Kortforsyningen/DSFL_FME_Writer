/*============================================================================

   Name     : fmestring.cpp

   System   : FME Developer Kit

   Language : C++

   Purpose  : Definition of Class "FMEString" and "FMEStringArray"

         Copyright (c) 1994 - 2013, Safe Software Inc. All rights reserved.

   Redistribution and use of this sample code in source and binary forms, with 
   or without modification, are permitted provided that the following 
   conditions are met:
   * Redistributions of source code must retain the above copyright notice, 
     this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright notice, 
     this list of conditions and the following disclaimer in the documentation 
     and/or other materials provided with the distribution.

   THIS SAMPLE CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
   TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SAMPLE CODE, EVEN IF 
   ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

===========================================================================*/

#include "fmestring.h"
#include <../../fmeobjects/cpp/isession.h>

// Initialize Session.
IFMESession* FMEString::stringSession_ = NULL;
IFMESession* FMEStringArray::stringArraySession_ = NULL;

//===========================================================================
// Constructor.
FMEString::FMEString(const char* str)
:
privString_(stringSession_->createString())
{
   *privString_ = str;
}

//===========================================================================
//
FMEString::FMEString(const char* str, const FME_UInt32 length)
:
privString_(stringSession_->createString())
{
   privString_->set(str, length);
}

//===========================================================================
// Copy constructor.
FMEString::FMEString(const FMEString& str)
:
privString_(stringSession_->createString())
{
   privString_->set(str->data(), str->length());
}

//===========================================================================
// Destructor.
FMEString::~FMEString()
{
   if (privString_ != NULL)
   {
      stringSession_->destroyString(privString_);
   }
   privString_ = NULL;
}

//===========================================================================
// Conversion operator to cast a FMEString to an IFMEString.
FMEString::operator IFMEString&()
{
   return *privString_;
}

//===========================================================================
// Assignment operator.
FMEString& FMEString::operator =(const FMEString& str)
{
   if (this != &str)
   {
      privString_->set(str->data(), str->length());
   }

   return *this;
}

//===========================================================================
// Access wrapped pointer.
IFMEString* FMEString::operator ->()
{
   return privString_;
}

//===========================================================================
// Access wrapped pointer.
const IFMEString* FMEString::operator ->() const
{
   return privString_;
}

//===========================================================================
// Dereference wrapped pointer.
IFMEString& FMEString::operator *()
{
   return *privString_;
}

//===========================================================================
// Dereference wrapped pointer.
const IFMEString& FMEString::operator *() const
{
   return *privString_;
}

//===========================================================================
// Releases the ownership of the member pointer to it's IFMEString.
IFMEString* FMEString::release()
{
   IFMEString* temp = privString_;
   privString_ = NULL;
   return temp;
}

//===========================================================================
// Set member pointer to argument pointer.  Destroy member pointer's object
// if necessary.
void FMEString::reset(IFMEString* ifmeStr)
{
   if (privString_ != ifmeStr)
   {
      stringSession_->destroyString(privString_);
      privString_ = ifmeStr;
   }
}

//===========================================================================
// Static function that sets the session for this wrapper. This function
// needs to be called before any constructors for this wrapper are called.
void FMEString::setSession(IFMESession* session)
{
   stringSession_ = session;
}

//===========================================================================
// Constructor.
FMEStringArray::FMEStringArray()
:
privStringArray_(stringArraySession_->createStringArray())
{}

//===========================================================================
// Copy constructor.
FMEStringArray::FMEStringArray(const FMEStringArray& strArray)
:
privStringArray_(stringArraySession_->createStringArray())
{
   for (FME_UInt32 i = 0; i < strArray->entries(); i++)
   {
      privStringArray_->append(*(strArray->elementAt(i)));
   }
}

//===========================================================================
// Destructor.
FMEStringArray::~FMEStringArray()
{
   if (privStringArray_ != NULL)
   {
      stringArraySession_->destroyStringArray(privStringArray_);
   }
   privStringArray_ = NULL;
}

//===========================================================================
// Conversion operator to cast FMEStringArray to IFMEStringArray.
FMEStringArray::operator IFMEStringArray&()
{
   return *privStringArray_;
}

//===========================================================================
// Assignment operator.
FMEStringArray& FMEStringArray::operator =(const FMEStringArray& strArray)
{
   if (this != &strArray)
   {
      privStringArray_->clear();
      for (FME_UInt32 i = 0; i < strArray->entries(); i++)
      {
         privStringArray_->append(*(strArray->elementAt(i)));
      }
   }

   return *this;
}

//===========================================================================
// Access wrapped pointer.
IFMEStringArray* FMEStringArray::operator ->() const
{
   return privStringArray_;
}

//===========================================================================
// Dereference wrapped pointer.
IFMEStringArray& FMEStringArray::operator *() const
{
   return *privStringArray_;
}

//===========================================================================
// Releases the ownership of the member pointer to it's IFMEStringArray.
IFMEStringArray* FMEStringArray::release()
{
   IFMEStringArray* temp = privStringArray_;
   privStringArray_ = NULL;
   return temp;
}

//===========================================================================
// Sets the member pointer to ifmeStrArray.  Destroys the previous 
// IFMEStringArray pointed to by the member pointer if necessary.
void FMEStringArray::reset(IFMEStringArray* ifmeStrArray)
{
   if (privStringArray_ != ifmeStrArray)
   {
      stringArraySession_->destroyStringArray(privStringArray_);
      privStringArray_ = ifmeStrArray;
   }
}

//===========================================================================
// Static function that sets the session for this wrapper. This function
// needs to be called before any constructors for this wrapper are called.
void FMEStringArray::setSession(IFMESession* session)
{
   stringArraySession_ = session;
}
