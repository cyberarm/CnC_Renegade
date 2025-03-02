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
 *                     $Archive:: /Commando/Code/ww3d2/nullptrrobj.h                             $*
 *                                                                                             *
 *                       Author:: Greg Hjelstrom                                               *
 *                                                                                             *
 *                     $Modtime:: 1/08/01 10:04a                                              $*
 *                                                                                             *
 *                    $Revision:: 1                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef nullptr_H
#define nullptr_H

#ifndef RENDOBJ_H
#include "rendobj.h"
#endif

#include "proto.h"

class nullptr3DObjClass : public RenderObjClass
{
public:
    nullptr3DObjClass(const char* name = "nullptr");
    nullptr3DObjClass(const nullptr3DObjClass& src);
    nullptr3DObjClass& operator=(const nullptr3DObjClass& that);

    virtual int Class_ID(void) const;
    virtual RenderObjClass* Clone(void) const;
    virtual const char* Get_Name(void) const { return Name; }
    virtual void Render(RenderInfoClass& rinfo);
    virtual void Get_Obj_Space_Bounding_Sphere(SphereClass& sphere) const;
    virtual void Get_Obj_Space_Bounding_Box(AABoxClass& box) const;

protected:
    char Name[2 * W3D_NAME_LEN];
};

class nullptrPrototypeClass : public PrototypeClass
{
public:
    nullptrPrototypeClass(void);
    nullptrPrototypeClass(const W3dnullptrObjectStruct& nullptr);

    virtual const char* Get_Name(void) const { return Definition.Name; }
    virtual int Get_Class_ID(void) const { return RenderObjClass::CLASSID_nullptr; }
    virtual RenderObjClass* Create(void) { return NEW_REF(nullptr3DObjClass, (Definition.Name)); }

protected:
    W3dnullptrObjectStruct Definition;
};

class nullptrLoaderClass : public PrototypeLoaderClass
{
public:
    virtual int Chunk_Type(void) { return W3D_CHUNK_nullptr_OBJECT; }
    virtual PrototypeClass* Load_W3D(ChunkLoadClass& cload);
};

/*
** Instance of the default loader which the asset manager can
** automatically install at creation time
*/
extern nullptrLoaderClass _nullptrLoader;

#endif
