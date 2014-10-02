#ifndef FME_STRING_H
#define FME_STRING_H

/*============================================================================

   Name     : fmestring.h

   System   : FME Developer Kit

   Language : C++

   Purpose  : Declaration of FMEString and FMEStringArray

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

   Package Overview:

   This is a wrapper around the IFMEString and IFMEStringArray objects.  
   Instances of FMEString and FMEStringArrays should be created on the
   stack and will automatically destroy their wrapped IFMEString and
   IFMEStringArrays respectively when they go out of scope.
   One more important thing is that the static sessions for each class
   must be set before any instance of these object are created.  The lifetime
   of the session must be longer than the lifetime of any object created.

========================================================================*/

// Include interface.
#include <../../fmeobjects/cpp/istring.h>

// Forward declarations.
class IFMESession;

// Wrapper class for IFMEString.
class FMEString
{
public:

   // -----------------------------------------------------------------------
   /*! Default constructor.  Creates a FMEString, which is a wrapper around
   // an IFMEString.  Before this constructor can be called the static
   // IFMESession MUST first be set.  The IFMESession must also have a
   // lifetime that is longer than this objects lifetime. */
   explicit FMEString(const char* str = "");

   // -----------------------------------------------------------------------
   /*! Creates a FMEString, which is a wrapper around an IFMEString.
   // Before this constructor can be called the static IFMESession MUST
   // first be set.  The IFMESession must also have a lifetime that is
   // longer than this objects lifetime. */
   FMEString(const char* str, FME_UInt32 length);

   // -----------------------------------------------------------------------
   /*! Copy constructor.  A copy of the IFMEString wrapped by str is
   // created for this object. */
   FMEString(const FMEString& str);

   // -----------------------------------------------------------------------
   /*! Destructor. Destroys the IFMEString wrapped by this class. */
   ~FMEString();

   // -----------------------------------------------------------------------
   /*! Conversion operator to cast a FMEString to an IFMEString.  The
   // IFMEString returned here is still owned by this object.  The caller
   // should not destroy the IFMEString, it will be destroyed once this
   // object goes out of scope. */
   operator IFMEString&();

   // -----------------------------------------------------------------------
   /*! A copy of the IFMEString wrapped by str is assigned to this
   // object. */
   FMEString& operator =(const FMEString& str);

   // -----------------------------------------------------------------------
   /*! Overloaded operator to access wrapped pointer methods. */
   IFMEString* operator ->();
   const IFMEString* operator ->() const;

   // -----------------------------------------------------------------------
   /*! Overloaded operator to dereference wrapped pointer. */
   IFMEString& operator *();
   const IFMEString& operator *() const;

   // -----------------------------------------------------------------------
   /*! This function releases the ownership of the IFMEString pointer
   // and returns it. */
   IFMEString* release();

   // -----------------------------------------------------------------------
   /*! This function takes in a pointer to an IFMEString and compares it with
   // the member pointer.  If they do not point to the same location, then 
   // the member pointer's IFMEString is destroyed and the member pointer is 
   // set to ifmeStr. */
   void reset(IFMEString* ifmeStr = NULL);

   // -----------------------------------------------------------------------
   /*! Set session.  This must be done before creating an instance of this class. */
   static void setSession(IFMESession* session);
 
private:

   // -----------------------------------------------------------------------
   // Declare private data members (by convention these are identified
   // by a trailing underscore).

   // -----------------------------------------------------------------------
   /*! This is the IFMEString that is wrapped by this class. */
   IFMEString* privString_;

   // -----------------------------------------------------------------------
   /*! Static session is required for creating IFME strings.  Session is static,
   // so it can be shared across all FMEString objects. */
   static IFMESession* stringSession_;
};

// Wrapper class for IFMEStringArray.
class FMEStringArray
{
public:

   // -----------------------------------------------------------------------
   /*! Default constructor.  Creates an IFMEStringArray.  Before this constructor can
   // be called the static IFMESession MUST first be set.  The IFMESession
   // must also have a lifetime that is longer than this objects lifetime. */
   explicit FMEStringArray();

   // -----------------------------------------------------------------------
   /*! Copy constructor.  A copy of the IFMEStringArray wrapped by
   // strArray is created for this object. */
   FMEStringArray(const FMEStringArray& strArray);

   // -----------------------------------------------------------------------
   /*! Destructor. Destroys the IFMEStringArray wrapped by this class. */
   ~FMEStringArray();

   // -----------------------------------------------------------------------
   /*! Conversion operator to cast FMEStringArray to IFMEStringArray. */
   operator IFMEStringArray&();

   // -----------------------------------------------------------------------
   /*! A copy of the IFMEStringArray wrapped by strArray is assigned
   // to this object. */
   FMEStringArray& operator =(const FMEStringArray& strArray);

   // -----------------------------------------------------------------------
   /*! Overloaded operator to access wrapped pointer methods. */
   IFMEStringArray* operator ->() const;

   // -----------------------------------------------------------------------
   /*! Overloaded operator to dereference wrapped pointer. */
   IFMEStringArray& operator *() const;

   // -----------------------------------------------------------------------
   /*! This function releases the ownership of the IFMEStringArray pointer
   // and returns it. */
   IFMEStringArray* release();

   // -----------------------------------------------------------------------
   /*! This function sets the member pointer to ifmeStrArray and destroys the
   // old pointed to IFMEString array if necessary. */
   void reset(IFMEStringArray* ifmeStrArray = NULL);

   // -----------------------------------------------------------------------
   /*! Set session.  This must be done before creating an instance of this class. */
   static void setSession(IFMESession* session);

private:

   // -----------------------------------------------------------------------
   // Declare private data members (by convention these are identified
   // by a trailing underscore).

   // -----------------------------------------------------------------------
   /*! The IFMEStringArray wrapped by this class. */
   IFMEStringArray* privStringArray_;

   // -----------------------------------------------------------------------
   /*! Static session is required for creating IFME string arrays.  Session is 
   // static, so it can be shared across all FMEStringArray objects. */
   static IFMESession* stringArraySession_;
};
#endif
