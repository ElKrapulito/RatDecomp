#ifndef _CAMERAENGINEZONECOLL_Z_H_
#define _CAMERAENGINEZONECOLL_Z_H_
#include "Types_Z.h"
#endif // _CAMERAENGINEZONECOLL_Z_H_
#include "World_ZHdl.h"
#include "AnimationNode_Z.h"
#include "AnimationMesh_Z.h"
#include "AnimationMaterial_Z.h"
#include "AnimationMorph_Z.h"
#include "ResourceObject_Z.h"
#include "BoneNode_Z.h"


class CameraEngineZone_Z {
public:
    Vec3f position;  // must be at offset 0

    void CameraGameColl(const World_Z*, Vec3f, Vec3f pos, float);
};