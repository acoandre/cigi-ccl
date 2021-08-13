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
 *  FILENAME:   CigiBaseEnvCondReq.h
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
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Added new version conversion method.
 *  Moved Packet information to base packet.
 *  
 *  12/14/2007 Greg Basler                       Version 2.0.0
 *  Added the Request ID parameter.
 *  
 *  07/29/2015 Chas Whitley                      Version 4.0.0
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_BASE_ENV_COND_REQ_INCLUDED_)
#define _CIGI_BASE_ENV_COND_REQ_INCLUDED_

#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_ENV_COND_REQ_PACKET_ID_V3 28
#define CIGI_ENV_COND_REQ_PACKET_SIZE_V3 32

#define CIGI_ENV_COND_REQ_PACKET_ID_V4 0x1b
#define CIGI_ENV_COND_REQ_PACKET_SIZE_V4 32


class CigiEnvCondReqV3;
class CigiEnvCondReqV4;


class CIGI_SPEC CigiBaseEnvCondReq : public CigiBasePacket
{

friend class CigiEnvCondReqV3;
friend class CigiEnvCondReqV4;

public:

   //=========================================================
   //! The enumeration for the CigiBaseEnvCondReq Group
   //!
   enum ReqTypeGrp
   {
      Maritime=1,
      Terrestrial=2,
      Weather=4,
      Aerosol=8
   };




   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseEnvCondReq();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseEnvCondReq();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A pure virtual Pack function.  
   //! This function is not implemented in this class.
   //! \param Base - A pointer to the instance of the packet 
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const=0;

   //=========================================================
   //! A pure virtual Unpack function.
   //! This function is not implemented in this class.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec) =0;

   //=========================================================
   //! A virtual Conversion Information function.
   //! This function provides conversion information for this
   //!  packet.
   //! \param CnvtVersion - The CIGI version to which this packet
   //!    is being converted.
   //! \param CnvtInfo - The information needed for conversion
   //!    
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int GetCnvt(CigiVersionID &CnvtVersion,
                       CigiCnvtInfoType::Type &CnvtInfo);



   //==> Accessing Member Variable Values functions

   //+> Request Type

   //=========================================================
   //! Sets the ReqType with bound checking control
   //! \param ReqTypeIn - Request Type group
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetReqType(const Cigi_uint8 ReqTypeIn, bool bndchk=true);

   //=========================================================
   //! Gets the Lat value.
   //! \return the current Lat.
   Cigi_uint8 GetReqType(void) const { return(ReqType); }

   //+> Request ID

   //=========================================================
   //! Sets the ReqType with bound checking control
   //! \param ReqTypeIn - Request Type group
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetReqID(const Cigi_uint8 ReqIdIn, bool bndchk=true)
   {
      ReqID = ReqIdIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Lat value.
   //! \return the current Lat.
   Cigi_uint8 GetReqID(void) const { return(ReqID); }


   //+> Lat

   //=========================================================
   //! Sets the Lat with bound checking control
   //! \param LatIn - Latitude
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetLat(const double LatIn, bool bndchk=true);

   //=========================================================
   //! Gets the Lat value.
   //! \return the current Lat.
   double GetLat(void) const { return(Lat); }


   //+> Lon

   //=========================================================
   //! Sets the Lon with bound checking control
   //! \param LonIn - Longitude
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetLon(const double LonIn, bool bndchk=true);

   //=========================================================
   //! Gets the Lon value.
   //! \return the current Lon.
   double GetLon(void) const { return(Lon); }


   //+> Alt

   //=========================================================
   //! Sets the Alt with bound checking control
   //! \param AltIn - Altitude
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAlt(const double AltIn, bool bndchk=true)
   {
      Alt = AltIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Alt value.
   //! \return the current Alt.
   double GetAlt(void) const { return(Alt); }



protected:

   //==> Member variables

   //=========================================================
   //! ReqType<br>
   //! Type of conditions or concentrations for which data 
   //!    is requested.<br>
   //! These can be OR'ed together to request more than 1 type 
   //!    of data.
   //!  1-Maritime<br>
   //!  2-Terrestrial<br>
   //!  4-Weather<br>
   //!  8-Aerosol
   //!
   Cigi_uint8 ReqType;

   //=========================================================
   //! Request ID<br>
   //! The Request ID
   //!
   Cigi_uint8 ReqID;

   //=========================================================
   //! Lat<br>
   //! Latitude
   //!
   double Lat;

   //=========================================================
   //! Lon<br>
   //! Longitude
   //!
   double Lon;

   //=========================================================
   //! Alt<br>
   //! Altitude
   //!
   double Alt;


};

#endif // #if !defined(_CIGI_BASE_ENV_COND_REQ_INCLUDED_)
