#ifndef _MATERIALOBJ_ZHDL_H_
#define _MATERIALOBJ_ZHDL_H_

#include "ResourceObject_ZHdl.h"

class MaterialObj_Z;

HANDLE_Z(MaterialObj_Z, ResourceObject_Z);

typedef DynArray_Z<MaterialObj_ZHdl, 32> MaterialObj_ZHdlDA;

#endif
