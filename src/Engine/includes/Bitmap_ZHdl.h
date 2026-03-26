#ifndef _BITMAP_ZHDL_H_
#define _BITMAP_ZHDL_H_
#include "Bitmap_Z.h"
#include "ResourceObject_ZHdl.h"

class Bitmap_Z;
HANDLE_Z(Bitmap_Z, ResourceObject_Z);

typedef DynArray_Z<Bitmap_ZHdl, 32> Bitmap_ZHdlDA;

#endif
