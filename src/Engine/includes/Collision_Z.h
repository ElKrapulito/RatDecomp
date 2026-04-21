#ifndef _COLLISION_Z_H_
#define _COLLISION_Z_H_
#include "SystemObject_Z.h"
class Node_Z;
class Material_Z;
class Object_Z;
class ObjectDatas_Z;

struct ColLineResult_Z {
    Vec4f m_Intersection;
    Vec4f m_Normal;
    Float m_CollisionDistance;
    Vec2f m_EleUV;
    S32 m_EleIdx;
    U64 m_Flag;
    Material_Z* m_Material;
    Node_Z* m_NodePtr;
    Object_Z* m_Object;
    ObjectDatas_Z* m_ObjectDatas;
    S32 m_UnkS32_0x48;
    Bool m_IsIntersect;
};

struct ClingLineResult_Z {
};

struct ColSphereResult_Z {
    Vec3f m_Intersection;
    Float m_CollisionDistance;
    Vec3f m_Normal;
    Node_Z* m_NodePtr;
    U64 m_Flag;
    Vec3f m_UnkVec3f_0x28;
    Vec3f m_UnkVec3f_0x34;

    ColSphereResult_Z() { Reset(); }

    void Reset() { m_NodePtr = NULL; }
};

#endif
