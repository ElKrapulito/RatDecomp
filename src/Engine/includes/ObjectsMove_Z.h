#ifndef _OBJECTSMOVE_Z_H_
#define _OBJECTSMOVE_Z_H_
#include "ObjectMove_Z.h"

class ObjectMoveSphereColl_Z;

class ObjectsMove_Z : public ObjectMove_Z {
public:
    virtual void Init();
    virtual ~ObjectsMove_Z();
    virtual void Reset();
    virtual void Update(Float a1);
    virtual void Update(const Vec3f& a1, const Vec3f& a2, const Vec3f& a3, Float a4, S32 a5);
    virtual void ComputeNewPos(const Vec3f& a1, Vec3f& a2, Vec3f& a3, Float a4, S32 a5);
    virtual void ResetPosAndRot(const Vec3f& a1, const Quat& a2);
    virtual void DisableCollision(World_Z* a1, Float a2, S32 a3);
    virtual void UpdateCollision(SeadZone_Z& a1, const Vec3f& a2, Vec3f& a3, Vec3f& a4, Vec3f& a5, Float a6, S32 a7);
    virtual void RestoreCollision(SeadZone_Z& a1, S32 a2);
    virtual void SetCollideData(const Node_ZHdl& a1, const ObjectMoveCollData_Z& a2);
    virtual void UpdateShadow(SeadZone_Z& a1, Float a2, S32 a3);
    virtual void UpdateCollisionMsg(Node_Z* a1, const Vec3f& a2, U64 a3, S32 a4);
    virtual void GetName();
    virtual void GetNode(S32 a1);
    virtual void GetPos(S32 a1);
    virtual void GetScale(S32 a1);
    virtual void GetRot(S32 a1);
    virtual void SetPos(const Vec3f& a1, S32 a2);
    virtual void SetPosAndRot(const Vec3f& a1, const Quat& a2, S32 a3);
    virtual void SetPosAndScale(const Vec3f& a1, Float a2, S32 a3);
    virtual void SetPosRotAndScale(const Vec3f& a1, const Quat& a2, Float a3, S32 a4);
    virtual void SetScale(Float a1, S32 a2);
    virtual void GetLastEffectiveSpeed(S32 a1);
    virtual void GetLastEffectiveAccel(S32 a1);
    virtual void FatherUnLinked(S32 a1);
    virtual void UpdateDynamic(SeadZone_Z& a1, const Vec3f& a2, const Vec3f& a3, S32 a4);
    virtual void InitLinkCollisionNode(ColLineResult_Z& a1, const Vec3f& a2, S32 a3);
    virtual void EndCollisionNode(bool a1, S32 a2);
    virtual void GetLinkCollisionNode(Vec3f& a1, Vec3f& a2, Vec3f& a3, Vec3f& a4, S32 a5);
    virtual void GetVolumeMemory(S32 a1);
    virtual void Shut();
    virtual void IsVisible();
    virtual void SetNodeObjectNb(S32 a1);
    virtual void GetBoneNodeObject(S32 a1);
    virtual void CheckObjectMove(S32 a1, Float a2);
    virtual void EndLiveTimeObject(S32 a1);
    virtual void RemoveObjectMove(S32 a1);
    virtual void UpdateCollision(const ColLineResult_Z& a1, ObjectMoveSphereColl_Z& a2, Float a3, S32 a4);

    static BaseObject_Z* NewObject() { return NewL_Z(230) ObjectsMove_Z; }

private:
    U8 m_Pad_0x1c0[0x40];
};

#endif // _OBJECTSMOVE_Z_H_
