#ifndef _TRIANGLECACHE_Z_H_
#define _TRIANGLECACHE_Z_H_
#include "DynArray_Z.h"
#include "BaseObject_Z.h"

struct TriInfos {
    U8 m_UnkBytes_0x0[0x120];
};

typedef DynArray_Z<TriInfos, 32, FALSE, FALSE>
    TriInfosDA;

struct OwnerTInfos {
    S32 m_UnkS32_0x0;
    S32 m_UnkS32_0x4;
    S32 m_UnkS32_0x8;
};

typedef DynArray_Z<OwnerTInfos, 32, FALSE, FALSE>
    OwnerTInfosDA;

class ColTriangleCache_Z {
    S32 m_UnkCount;
    S32 m_UnkCount2;
    TriInfosDA m_TriInfos;
    U16DA m_UnkU16DA_0x10;
    S32 m_UnkS32_0x18;
    S32 m_UnkS32_0x1c;
    OwnerTInfosDA m_TriOwnerInfos;
    S32 m_UnkS32_0x28;
    S32 m_UnkS32_0x2c;

public:
    ColTriangleCache_Z() {
        Flush();
    }

    void Flush();
};

#endif // _TRIANGLECACHE_Z_H_
