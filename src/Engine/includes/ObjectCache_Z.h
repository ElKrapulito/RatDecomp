#ifndef _OBJECTCACHE_Z_H_
#define _OBJECTCACHE_Z_H_

#include "DynArray_Z.h"
#include "BaseObject_Z.h"

struct CacheStateLRU_Z {
    BaseObject_Z* m_OwnerPtr;
    U16 m_OwnerId;
};

template <class T, class V>
class LRU_Z {
public:
    struct List_Ele : public T {
        V m_PrevEntry;
        V m_NextEntry;
    };

    void Init(S32 i_Unk);

private:
    DynArray_Z<List_Ele, 32, 0, 1, 4> m_LRUList;
};

template <class T>
class CacheEntryLRU_Z {
public:
    inline void SetSize(S32 i_LRUCount, S32 i_EntryCount) {
        m_CacheEntryCount = i_EntryCount;
        m_LRU.Init(i_LRUCount);
        if (m_CacheData) {
            if (TRUE) {
                Delete_Z[] m_CacheData;
            }
        }
        m_CacheData = NewL_Z(34) T[(i_LRUCount * m_CacheEntryCount) + 1];
        return;
    }

private:
    LRU_Z<CacheStateLRU_Z, U16> m_LRU;
    S32 m_CacheEntryCount;
    T* m_CacheData;
};

#endif
