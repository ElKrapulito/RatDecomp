#ifndef _RENDERPRIMITIVEBUFFERS_Z_H_
#define _RENDERPRIMITIVEBUFFERS_Z_H_
#include "Types_Z.h"

class IndexBuffer_Z {
public:
    virtual void Create(S32 a1);
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4);
    virtual void Unlock();
    virtual void Release();
};

class BaseIndexBuffer_Z : public IndexBuffer_Z {
public:
    virtual void Create(S32 a1);
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4);
    virtual void Unlock();
    virtual void Release();
};

class VertexBuffer_Z {
public:
    virtual void Create(S32 a1);
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4);
    virtual void Unlock();
    virtual void Release();
    void* m_Data;
};

class BaseVertexBuffer_Z : public VertexBuffer_Z {
public:
    virtual void Create(S32 a1);
    virtual void Lock(U32 a1, U32 a2, void* a3, U32 a4);
    virtual void Unlock();
    virtual void Release();
};
#endif
