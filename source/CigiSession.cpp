/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiSession.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/15/2003 James Durtschy                    CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor to set the outgoing message in the VJmp 
 *  member variable.
 *
 *  07/29/2015 Chas Whitley                       Version 4.0.0
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiSession.h"

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiSession
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSession::CigiSession(const int NumInBuf, const int InBufLen,
                         const int NumOutBuf, const int OutBufLen,
                         SessionTypeEnum SessionTypeIn) : 
   SessionType( SessionTypeIn ),
   Synchronous( true ),
   MostMatureKnownCigi(4,0) // chas
{

   CigiVersionID InitVersion = MostMatureKnownCigi;
   OutMsg.SetSession(this);
   OutMsg.ChangeOutgoingCigiVersion(InitVersion);
   InMsg.SetSession(this);
   InMsg.SetReaderVersion(InitVersion);  // Default version initialization

   OutMsg.CreateBuffer(NumOutBuf, OutBufLen);
   InMsg.CreateBuffer(NumInBuf, InBufLen);

   OutMsg.SetAnimationTable(&ATbl);
   InMsg.SetAnimationTable(&ATbl);

}



// ================================================
// ~CigiSession
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSession::~CigiSession()
{

}

