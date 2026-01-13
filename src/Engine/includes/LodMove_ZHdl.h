#ifndef _LODMOVE_ZHDL_H_
#define _LODMOVE_ZHDL_H_
#include "ObjectThrow_ZHdl.h"

class ObjectThrow_Z;
class LodMove_Z;
HANDLE_Z(LodMove_Z, ObjectThrow_Z);

typedef DynArray_Z<LodMove_ZHdl, 32> LodMove_ZHdlDA;

#endif
