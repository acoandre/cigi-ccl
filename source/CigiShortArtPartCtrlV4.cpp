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
 *  FILENAME:   CigiShortArtPartCtrlV4.cpp
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
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Removed the inline defnitions for the PackedPointer union.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor to initialize the MinorVersion member 
 *  variable.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  Initial Release for CIGI 4.0 compatibility.
 *  Based on CigiShortArtPartCtrlV4.cpp"
 *
 *  12/10/2018 Paul Slade                      Version 4.0.2
 *  Added byte swap capability.
 *
 * </pre>
 *  Author: The Boeing Company
 *
 */

#define _EXPORT_CCL_

#include "CigiShortArtPartCtrlV4.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiShortArtPartCtrlV4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiShortArtPartCtrlV4::CigiShortArtPartCtrlV4()
{

   PacketID = CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V4;
   PacketSize = CIGI_SHORT_ART_PART_CTRL_PACKET_SIZE_V4;
   Version = 4;
   MinorVersion = 0;

   EntityID = 0;
   ArtPart1 = 0;
   ArtPart2 = 0;
   DofSelect1 = NotUsed;
   DofSelect2 = NotUsed;
   ArtPart1En = false;
   ArtPart2En = false;
   Dof1 = 0.0;
   Dof2 = 0.0;

}

// ================================================
// ~CigiShortArtPartCtrlV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiShortArtPartCtrlV4::~CigiShortArtPartCtrlV4()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiShortArtPartCtrlV4::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   PackPointer CDta;

   CigiBaseShortArtPartCtrl * Data = ( CigiBaseShortArtPartCtrl *)Base;

   CDta.c = Buff;

   *CDta.s++ = PacketSize;
   *CDta.s++ = PacketID;

   *CDta.s++ = Data->EntityID;
   *CDta.c++ = Data->ArtPart1;
   *CDta.c++ = Data->ArtPart2;

   Cigi_uint8 HDta = Data->DofSelect1 & 0x07;
   HDta |= (Data->DofSelect2 << 3) & 0x38;
   HDta |= (Data->ArtPart1En) ? 0x40 : 0;
   HDta |= (Data->ArtPart2En) ? 0x80 : 0;
   *CDta.c++ = HDta;

   *CDta.c++ = 0; // reserved
   *CDta.s++ = 0; // reserved

   *CDta.f++ = Data->Dof1;
   *CDta.f++ = Data->Dof2;
   *CDta.l++ = 0; // reserved

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiShortArtPartCtrlV4::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   PackPointer CDta;

   CDta.c = Buff;

   CDta.c += 4;  // Step over packet id and size
   Cigi_uint8 HDta;

   if (!Swap)
   {
       EntityID = *CDta.s++;
       ArtPart1 = *CDta.c++;
       ArtPart2 = *CDta.c++;

       HDta = *CDta.c++;

       CDta.c++;
       CDta.s++;

       Dof1 = *CDta.f++;
       Dof2 = *CDta.f++;
   }
   else {
       CigiSwap2(&EntityID, CDta.s++);
       ArtPart1 = *CDta.c++;
       ArtPart2 = *CDta.c++;

       HDta = *CDta.c++;

       CDta.c++;
       CDta.s++;

       CigiSwap4(&Dof1, CDta.f++);
       CigiSwap4(&Dof2, CDta.f++);

   }
   DofSelect1 = (DofSelectGrp)(HDta & 0x07);
   DofSelect2 = (DofSelectGrp)((HDta >> 3) & 0x07);
   ArtPart1En = ((HDta & 0x40) != 0);
   ArtPart2En = ((HDta & 0x80) != 0);

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


