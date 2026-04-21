#ifndef _OBJECTSBOUNCE_Z_H_
#define _OBJECTSBOUNCE_Z_H_
#include "ObjectsMove_Z.h"

class ObjectsBounce_Z : public ObjectsMove_Z {
public:
    virtual void Init();

    virtual ~ObjectsBounce_Z() { }

    virtual void EndLiveTimeObject(S32 a1);
    virtual void UpdateCollision(const ColLineResult_Z& a1, ObjectMoveSphereColl_Z& a2, Float a3, S32 a4);

    static BaseObject_Z* NewObject() { return NewL_Z(16) ObjectsBounce_Z; }
};

#endif // _OBJECTSBOUNCE_Z_H_
