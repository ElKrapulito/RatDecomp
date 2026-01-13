#ifndef _OBJECTSGAMECLIP_ZHDL_H_
#define _OBJECTSGAMECLIP_ZHDL_H_
#include "ObjectGame_ZHdl.h"

class ObjectsGameClip_Z;
class ObjectGame_Z;

HANDLE_Z(ObjectsGameClip_Z, ObjectGame_Z);

typedef DynArray_Z<ObjectsGameClip_ZHdl, 32> ObjectsGameClip_ZHdlDA;

#endif
