#ifndef _LODMOVE_Z_H_
#define _LODMOVE_Z_H_
#include "ObjectThrow_Z.h"

class LodMove_Z : public ObjectThrow_Z {
public:
    virtual ~LodMove_Z();
    virtual void Init();
    virtual void Reset();
    virtual void Update(Float a1);
    virtual void Update(const Vec3f& a1, const Vec3f& a2, const Vec3f& a3, Float a4, S32 a5);
    virtual void DisableCollision(World_Z* a1, Float a2, S32 a3);
    virtual void UpdateCollision(SeadZone_Z& a1, const Vec3f& a2, Vec3f& a3, Vec3f& a4, Vec3f& a5, Float a6, S32 a7);
    virtual void RestoreCollision(SeadZone_Z& a1, S32 a2);
    virtual void UpdateCollisionCollectable(SeadZone_Z& a1, const Vec3f& a2);
    virtual void UpdateShadow(SeadZone_Z& a1, Float a2, S32 a3);
    virtual void UpdateCollisionLineFlag(const ColLineResult_Z& a1, const Vec3f& a2, S32 a3);
    virtual void GetPos(S32 a1);
    virtual void SetPos(const Vec3f& a1, S32 a2);
    virtual void SetPosAndRot(const Vec3f& a1, const Quat& a2, S32 a3);
    virtual void EndCollisionNode(bool a1, S32 a2);
    virtual void UpdateCollisionCarrying(SeadZone_Z& a1, const Vec3f& a2, const Vec3f& a3);
    virtual void GetCameraId();
    virtual void SetCameraAgent(Agent_ZHdl& a1);
    virtual void SetCameraDirFromZone(Vec3f& a1);
    virtual void SetCameraPos(Vec3f& a1);
    virtual void GetCameraDirFromZone();
    virtual void GetCameraPos();
    virtual void GetCameraNodeDisable();
    virtual void SetCameraNodeDisable(Node_ZHdl& a1);
    virtual void UpdateCollisionCling(SeadZone_Z& a1, const Vec3f& a2, Vec3f& a3, Vec3f& a4, Vec3f& a5, Float a6);
    virtual void ClingEdgeBack();
    virtual void ClingEdgeAddY();
    virtual void ClingEdgeRayAdd();
    virtual void ClingEdgeLenMin();
    virtual void ClingEdgeLandDist();

    static BaseObject_Z* NewObject() { return NewL_Z(138) LodMove_Z; }
};

#endif // _LODMOVE_Z_H_
