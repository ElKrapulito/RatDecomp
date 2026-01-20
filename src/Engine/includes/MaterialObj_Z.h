#ifndef _MATERIALOBJ_Z_H_
#define _MATERIALOBJ_Z_H_
#include "ResourceObject_Z.h"

class MaterialObj_Z : public ResourceObject_Z {
public:
    virtual ~MaterialObj_Z();
    virtual void Load(void** i_Data);
    virtual void EndLoad();
    virtual Bool MarkHandles();

    static BaseObject_Z* NewObject() { return NewL_Z(20) MaterialObj_Z; }
};

#endif // _MATERIALOBJ_Z_H_
