#ifndef _BINKTEXTURES_H_
#define _BINKTEXTURES_H_
#include "bink.h"
#include "dolphin/gx.h"

typedef struct BINKFRAMETEXTURES {
    GXTexObj Ytexture;
    GXTexObj cRtexture;
    GXTexObj cBtexture;
    GXTexObj Atexture;
} BINKFRAMETEXTURES;

typedef struct BINKTEXTURESET {
    BINKFRAMETEXTURES textures[2];
    BINKFRAMEBUFFERS bink_buffers;
    void* base_ptr;
    U32 framesize;
    U32 YAdeswizzle_width;
    U32 YAdeswizzle_height;
    U32 cRcBdeswizzle_width;
    U32 cRcBdeswizzle_height;
    GXTexObj YAdeswizzle;
    GXTexObj cRcBdeswizzle;
    S32 drawing[2];
} BINKTEXTURESET;

#endif
