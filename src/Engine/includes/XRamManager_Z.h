#ifndef _XRAMMANAGER_Z_H_
#define _XRAMMANAGER_Z_H_

#include "Types_Z.h"

class XRamManager_Z {
public:
    XRamManager_Z() { }

    ~XRamManager_Z();

    virtual Bool Init();
    virtual void Shut();
    virtual void Update(Float i_DeltaTime);
    virtual void Flush();
    virtual void Minimize();
    virtual void GetMemAllocated();
    virtual void AllocBlock(S32 a1, S32 a2, S32 a3);
    virtual void GetBlockPtr(S16 a1);
    virtual void GetBlockSize(S16 a1);
    virtual void FreeBlock(S16 a1);
    virtual void LockBlockAt(S16 a1, S32 a2);
    virtual void Get(S16 a1, S32 a2);
    virtual void EndGet(U8* a1);
    virtual void Read(U8* a1, S32 a2, U32 a3, Bool a4);
    virtual void Write(U8* a1, S32 a2, U32 a3, Bool a4);
};

#endif
