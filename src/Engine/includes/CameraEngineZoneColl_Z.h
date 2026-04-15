#ifndef _CAMERAENGINEZONECOLL_Z_H_
#define _CAMERAENGINEZONECOLL_Z_H_
#include "Types_Z.h"
#include "World_ZHdl.h"
#include "Math_Z.h"

class CameraEngineZone_Z {
public:
    Vec3f CameraGameColl(const World_Z* i_World, Vec3f i_CamPos, Vec3f i_CamTarget, Float i_DeltaTime);
};

#endif // _CAMERAENGINEZONECOLL_Z_H_
