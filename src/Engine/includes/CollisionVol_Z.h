#ifndef _COLLISIONVOL_Z_H_
#define _COLLISIONVOL_Z_H_
#include "Object_Z.h"

class CollisionVol_Z : public Object_Z {
public:
    virtual ~CollisionVol_Z();
    virtual void Load(void** a1);
    virtual void EndLoad();
    virtual Bool MarkHandles();
    virtual void Draw(DrawInfo_Z& a1, ObjectDatas_Z* a2);
    virtual S32 GetCollisions(
        Node_Z* i_Node,
        ObjectDatas_Z* i_Data,
        const Sphere_Z& i_Sph,
        const Vec3f& i_Dir,
        Float i_Len,
        ColLineResult_Z* o_Result,
        S32 i_MaxElem,
        U64 i_Flag,
        U64 i_NoFlag
    );

    static BaseObject_Z* NewObject() { return NewL_Z(112) CollisionVol_Z; }
};

#endif // _COLLISIONVOL_Z_H_
