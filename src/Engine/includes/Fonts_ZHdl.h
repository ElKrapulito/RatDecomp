#ifndef _FONTS_ZHDL_H_
#define _FONTS_ZHDL_H_
#include "ResourceObject_ZHdl.h"
#include "Program_Z.h"

class Fonts_Z;
HANDLE_Z(Fonts_Z, ResourceObject_Z);
typedef DynArray_Z<Fonts_ZHdl, 4> Fonts_ZHdlDA;

#endif
