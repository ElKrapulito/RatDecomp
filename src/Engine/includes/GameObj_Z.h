#ifndef _GAMEOBJ_Z_H_
#define _GAMEOBJ_Z_H_
#include "ResourceObject_Z.h"

class GameObj_Z : public ResourceObject_Z {
public:
    virtual ~GameObj_Z();
    virtual void Load(void** i_Data);
    virtual void EndLoad();
    virtual Bool MarkHandles();

    static BaseObject_Z* NewObject() { return NewL_Z(26) GameObj_Z; }
};

#endif // _GAMEOBJ_Z_H_
