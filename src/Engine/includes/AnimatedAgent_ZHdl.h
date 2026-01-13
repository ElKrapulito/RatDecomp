#ifndef _ANIMATEDAGENT_ZHDL_H_
#define _ANIMATEDAGENT_ZHDL_H_
#include "AnimatedMsgAgent_ZHdl.h"

class AnimatedAgent_Z;
class AnimatedMsgAgent_Z;
HANDLE_Z(AnimatedAgent_Z, AnimatedMsgAgent_Z);

typedef DynArray_Z<AnimatedAgent_ZHdl, 8> AnimatedAgent_ZHdlDA;

#endif
