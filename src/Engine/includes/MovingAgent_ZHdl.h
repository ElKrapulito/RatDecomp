#ifndef _MOVINGAGENT_ZHDL_H_
#define _MOVINGAGENT_ZHDL_H_

#include "AnimatedAgent_ZHdl.h"

class MovingAgent_Z;
class AnimatedAgent_Z;

HANDLE_Z(MovingAgent_Z, AnimatedAgent_Z);

typedef DynArray_Z<MovingAgent_ZHdl, 8> MovingAgent_ZHdlDA;

#endif
