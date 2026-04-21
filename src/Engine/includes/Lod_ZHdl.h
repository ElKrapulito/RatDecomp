#ifndef _LOD_ZHDL_H_
#define _LOD_ZHDL_H_
#include "Object_ZHdl.h"

class Object_Z;
class Lod_Z;
HANDLE_Z(Lod_Z, Object_Z);

typedef DynArray_Z<Lod_ZHdl, 32> Lod_ZHdlDA;

#endif
