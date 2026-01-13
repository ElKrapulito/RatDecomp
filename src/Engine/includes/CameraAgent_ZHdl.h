#ifndef _CAMERAAGENT_ZHDL_H_
#define _CAMERAAGENT_ZHDL_H_
#include "Agent_ZHdl.h"

class Agent_Z;
class CameraAgent_Z;
HANDLE_Z(CameraAgent_Z, Agent_Z);

typedef DynArray_Z<CameraAgent_ZHdl, 8> CameraAgent_ZHdlDA;
#endif
