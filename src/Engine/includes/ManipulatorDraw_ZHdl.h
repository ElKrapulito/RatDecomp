#ifndef _MANIPULATORDRAW_ZHDL_H_
#define _MANIPULATORDRAW_ZHDL_H_
#include "Manipulator_ZHdl.h"

class ManipulatorDraw_Z;
class ManipulatorSceneDraw_Z;

HANDLE_Z(ManipulatorDraw_Z, Manipulator_Z);
HANDLE_Z(ManipulatorSceneDraw_Z, Manipulator_Z);

typedef DynArray_Z<ManipulatorDraw_ZHdl, 16> ManipulatorDraw_ZHdlDA;
typedef DynArray_Z<ManipulatorSceneDraw_ZHdl, 16> ManipulatorSceneDraw_ZHdlDA;

#endif
