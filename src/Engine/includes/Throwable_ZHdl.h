#ifndef _THROWABLE_ZHDL_H_
#define _THROWABLE_ZHDL_H_
#include "MovingAgent_ZHdl.h"

class MovingAgent_Z;
class Throwable_Z;

HANDLE_Z(Throwable_Z, MovingAgent_Z);

typedef DynArray_Z<Throwable_ZHdl, 8> Throwable_ZHdlDA;

#endif
