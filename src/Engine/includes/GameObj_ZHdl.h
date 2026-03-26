#ifndef _GAMEOBJ_ZHDL_H_
#define _GAMEOBJ_ZHDL_H_

#include "ResourceObject_ZHdl.h"

class GameObj_Z;
HANDLE_Z(GameObj_Z, ResourceObject_Z);
typedef DynArray_Z<GameObj_ZHdl, 32> GameObj_ZHdlDA;

#endif
