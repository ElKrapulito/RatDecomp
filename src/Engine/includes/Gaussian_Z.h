#ifndef _GAUSSIAN_Z_H_
#define _GAUSSIAN_Z_H_
#include "Types_Z.h"
#include "Math_Z.h"

struct MipmapGC {
    Float m_Floats[48]; // $VIOLET: not certain its vecs
                        // $SABE: It might be floats cause there's no constructor called for the struct in Renderer_Z::Renderer_Z()
};

S32 Compute_MipmapedGaussConvol(MipmapGC* i_Mip, int i_SizeX, int i_SizeY, Float i_UnkFloat, Float i_UnkFloat2); // $VIOLET: Maybe i_Sigma and i_Alpha? idrk

#endif
