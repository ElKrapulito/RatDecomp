#ifndef _LIGHT_ZHDL_H_
#define _LIGHT_ZHDL_H_
#include "Object_ZHdl.h"

class Light_Z;
class Object_Z;
HANDLE_Z(Light_Z, Object_Z);

class LightData_Z;
class ObjectDatas_Z;
HANDLE_Z(LightData_Z, ObjectDatas_Z);

typedef DynArray_Z<Light_ZHdl, 32> Light_ZHdlDA;
#endif
