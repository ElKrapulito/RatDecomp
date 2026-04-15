#ifndef _CAMERAENGINEZONECOLL_Z_H_
#define _CAMERAENGINEZONECOLL_Z_H_
#include "Types_Z.h"
#include "World_ZHdl.h"
#include "AnimationNode_Z.h"
#include "AnimationMesh_Z.h"
#include "AnimationMaterial_Z.h"
#include "AnimationMorph_Z.h"
#include "ResourceObject_Z.h"
#include "BoneNode_Z.h"


class CameraEngineZone_Z {
public:
    Vec3f CameraGameColl(
        World_Z *i_World,
        Vec3f i_CamPos,
        Vec3f i_CamTarget,
        float i_DeltaTime
    );
};
#endif // _CAMERAENGINEZONECOLL_Z_H_
