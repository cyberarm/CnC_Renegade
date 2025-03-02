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
 *                 Project Name : WW3D                                                         *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/ww3d2/nullptrrobj.cpp                           $*
 *                                                                                             *
 *                       Author:: Greg Hjelstrom                                               *
 *                                                                                             *
 *                     $Modtime:: 12/01/01 12:18p                                             $*
 *                                                                                             *
 *                    $Revision:: 2                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "nullptrrobj.h"
#include "chunkio.h"
#include <string.h>

nullptrLoaderClass _nullptrLoader;

nullptr3DObjClass::nullptr3DObjClass(const char* name)
{
    strcpy(Name, name);
}

nullptr3DObjClass::nullptr3DObjClass(const nullptr3DObjClass& src)
{
    strcpy(Name, src.Name);
}

nullptr3DObjClass& nullptr3DObjClass::operator=(const nullptr3DObjClass& that)
{
    strcpy(Name, that.Name);

    RenderObjClass::operator=(that);
    return *this;
}

int nullptr3DObjClass::Class_ID(void) const
{
    return CLASSID_nullptr;
}

RenderObjClass* nullptr3DObjClass::Clone(void) const
{
    return NEW_REF(nullptr3DObjClass, (*this));
}

void nullptr3DObjClass::Render(RenderInfoClass& rinfo)
{
}

void nullptr3DObjClass::Get_Obj_Space_Bounding_Sphere(SphereClass& sphere) const
{
    sphere.Center.Set(0, 0, 0);
    sphere.Radius = 0.1f;
}

void nullptr3DObjClass::Get_Obj_Space_Bounding_Box(AABoxClass& box) const
{
    box.Center.Set(0, 0, 0);
    box.Extent.Set(0.1f, 0.1f, 0.1f);
}

/*
** nullptrPrototypeClass
*/

nullptrPrototypeClass::nullptrPrototypeClass(void)
{
    // Note that the other members of the definition are uninitialized..
    // So don't rely on them if the name is "nullptr".
    strcpy(Definition.Name, "nullptr");
}

nullptrPrototypeClass::nullptrPrototypeClass(const W3dnullptrObjectStruct& nullptr)
{
    Definition = nullptr;
}

/*
** nullptrLoaderClass
*/

PrototypeClass* nullptrLoaderClass::Load_W3D(ChunkLoadClass& cload)
{
    W3dnullptrObjectStruct nullptr;
    cload.Read(&nullptr, sizeof(nullptr));
    return new nullptrPrototypeClass(nullptr);
}