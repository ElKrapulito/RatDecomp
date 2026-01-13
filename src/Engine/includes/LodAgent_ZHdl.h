#ifndef _LODAGENT_ZHDL_H_
#define _LODAGENT_ZHDL_H_
#include "Throwable_ZHdl.h"

class Throwable_Z;
class LodAgent_Z;
HANDLE_Z(LodAgent_Z, Throwable_Z);

typedef DynArray_Z<LodAgent_ZHdl, 8> LodAgent_ZHdlDA;
#endif
