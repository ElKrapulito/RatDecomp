#ifndef _PRIMITIVEBUFFERS_Z_H_
#define _PRIMITIVEBUFFERS_Z_H_
#include "Types_Z.h"
#include "Assert_Z.h"

class VertexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */

    virtual Bool Release() {
        ASSERTLE_Z((Bool)(0 == 1), "", 15, "(Bool) (0==1)");
        return FALSE;
    }

    void* m_Data;
};

class IndexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */

    virtual Bool Release() {
        ASSERTLE_Z((Bool)(0 == 1), "", 23, "(Bool) (0==1)");
        return FALSE;
    }
};

class BaseVertexBuffer_Z : public VertexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */
    virtual Bool Release();                              /* 0x0C */
};

class BaseIndexBuffer_Z : public IndexBuffer_Z {
public:
    virtual void Create(S32 a1);                         /* 0x00 */
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4); /* 0x04 */
    virtual void Unlock();                               /* 0x08 */
    virtual Bool Release();                              /* 0x0C */
};

#endif
