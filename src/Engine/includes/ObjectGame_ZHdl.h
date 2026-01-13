#ifndef _OBJECTGAME_ZHDL_H_
#define _OBJECTGAME_ZHDL_H_

#include "Manipulator_ZHdl.h"

class ObjectGame_Z;
class Manipulator_Z;

HANDLE_Z(ObjectGame_Z, Manipulator_Z);

typedef DynArray_Z<ObjectGame_ZHdl, 16> ObjectGame_ZHdlDA;

#endif
