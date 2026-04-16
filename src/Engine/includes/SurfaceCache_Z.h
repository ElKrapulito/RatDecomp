#ifndef _SURFACECACHE_Z_H_
#define _SURFACECACHE_Z_H_
#include "ObjectCache_Z.h"
#include "Math_Z.h"
#include "Surface_Z.h"

#define SURFACECACHED_LOD_MAX 3
#define SURFACECACHED_COLLISION_LOD_MAX 3
#define SURFACECACHED_COLLISION_CACHE_ENTRY_COUNT 50

class BaseColSurfaceCache_Z {
public:
    BaseColSurfaceCache_Z() {
        m_CollisionLod = SURFACECACHED_COLLISION_LOD_MAX;
        S32 l_Lod = m_CollisionLod;
        m_Cache.SetSize(
            SURFACECACHED_COLLISION_CACHE_ENTRY_COUNT,
            ((l_Lod + 1) * (l_Lod + 1) * 4) + (l_Lod * l_Lod * 3) + ((l_Lod + 1) * 2)
        );
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
        FIXDEBUGINLINING_Z();
    }

private:
    S32 m_CollisionLod;
    CacheEntryLRU_Z<Vec4f> m_Cache;
};

class ColSurfaceCache_Z : public BaseColSurfaceCache_Z {
public:
    U16 GetFreeEntry(Surface_Z* i_Surface, U16 i_PatchId);
};

#endif
