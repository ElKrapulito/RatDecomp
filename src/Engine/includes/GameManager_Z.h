#ifndef _GAMEMANAGER_Z_H_
#define _GAMEMANAGER_Z_H_
#include "CameraUser_ZHdl.h"
#include "CameraOccluder_ZHdl.h"
#include "CameraStream_ZHdl.h"
#include "Game_ZHdl.h"
class Viewport_Z;

class GameManager_Z {
    void DebugDisplay(Viewport_Z* i_Vp);

private:
    CameraUser_ZHdl m_CameraUserHdls[4];
    Bool m_CameraUserBools[4];
    Game_ZHdlDA m_GameHdls;
    CameraOccluder_ZHdl m_CameraOccluderHdls[4];
    CameraStream_ZHdl m_CameraStreamHdls[4];
    Bool m_IsPaused;
};

#endif
