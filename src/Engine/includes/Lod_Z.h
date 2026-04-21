#ifndef _LOD_Z_H_
#define _LOD_Z_H_
#include "DynArray_Z.h"
#include "Math_Z.h"
#include "LightData_Z.h"
#include "Node_ZHdl.h"
#include "Object_ZHdl.h"
#include "Light_ZHdl.h"

struct ShadowReceiver_Z {
    Node_ZHdl m_NodeHdl;                  // node we collided with hdl
    Object_ZHdl m_ObjectHdl;              // object we collided with hdl
    ObjectDatas_ZHdl m_ObjectDataHdl;     // object data we collided with hdl
    S32DA m_ShadowReceiverElementIndices; // indices of the elements of the object that receive shadow (ex: for surface, the patch ids)
};

typedef DynArray_Z<ShadowReceiver_Z, 2, 1, 1, 4> ShadowReceiver_ZDA;

struct ActorData_Z {
    Vec3f m_LocalShadowPos;
    Float m_ShadowRadius;
    Vec3f m_WorldShadowPos;
    Float m_LightInterpolationTime; // used to switch light
    Vec3f m_WorldShadowNormal;
    U32 m_Flag;
    Vec3f m_LocalShadowBoundsCenter;
    Float m_LocalShadowBoundsRadius;
    LightData_Z m_LightData;
    LightData_ZHdl m_CurLightDataHdl;
    ShadowReceiver_ZDA m_ShadowReceivers;
    Vec4f m_UnkVec4f_0xbc;
    Bool m_UnkBool_0xcc;
};

#endif // _LOD_Z_H_
