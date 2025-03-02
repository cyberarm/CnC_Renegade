/*
**	Command & Conquer Renegade(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Max2W3d                                                      *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/Tools/max2w3d/nullptrsave.h                     $*
 *                                                                                             *
 *                       Author:: Greg Hjelstrom                                               *
 *                                                                                             *
 *                     $Modtime:: 8/05/99 3:05p                                               $*
 *                                                                                             *
 *                    $Revision:: 2                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef nullptrSAVE_H
#define nullptrSAVE_H

#include "chunkio.h"
#include "progress.h"
#include "w3d_file.h"
#include <Max.h>

/*******************************************************************************************
**
** nullptrSaveClass - Create a nullptr object.
**
*******************************************************************************************/
class nullptrSaveClass
{
public:
    enum
    {
        EX_UNKNOWN = 0, // exception error codes
        EX_CANCEL = 1
    };

    nullptrSaveClass(char* mesh_name, char* container_name, Progress_Meter_Class& meter);

    int Write_To_File(ChunkSaveClass& csave);

private:
    W3dnullptrObjectStruct nullptrData;
};

#endif // nullptrSAVE_H
