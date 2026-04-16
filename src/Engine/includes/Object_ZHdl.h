#ifndef _OBJECT_ZHDL_H_
#define _OBJECT_ZHDL_H_

#include "ResourceObject_ZHdl.h"

class Object_Z;
class ObjectDatas_Z;

HANDLE_Z(ObjectDatas_Z, ResourceObject_Z);

typedef DynArray_Z<ObjectDatas_ZHdl, 16> ObjectDatas_ZHdlDA;
typedef DynArray_Z<ObjectDatas_Z*, 16> ObjectDatas_ZPtrDA;

HANDLE_Z(Object_Z, ResourceObject_Z);

typedef DynArray_Z<Object_ZHdl, 16> Object_ZHdlDA;
typedef DynArray_Z<Object_Z*, 16> Object_ZPtrDA;

#endif
