#ifndef _GAMEMANAGER_Z_H_
#define _GAMEMANAGER_Z_H_
#include "CameraUser_ZHdl.h"
#include "CameraOccluder_ZHdl.h"
#include "CameraStream_ZHdl.h"
#include "Game_ZHdl.h"
#include "Game_Z.h"

class Viewport_Z;

Extern_Z void RegisterGameMgrCommand();
Bool SetMultiGame();
Bool SetMonoGame();
Bool SetGame(Bool i_IsMono);
Bool AddGamePlayer();
Bool AddMenuPlayer();
Bool AddPlayer(Bool i_IsMenu);
Bool RemoveGamePlayer();
Bool ActivateGamePlayer();
Bool DeactivateGamePlayer();
Bool SwitchGameToMono();
Bool SwitchGameToMulti();
Bool ActivateGame();
Bool DeactivateGame();
Bool SwitchCameraUser();
Bool SetPersoCamera();
Bool ResetGame();
Bool PlayerGoto();
Bool RemoveGame();
Bool SetRtc();
Bool PlayRtc();
Bool ShutRtc();
Bool LoadRtc();
Bool AddTransText();
Bool SetLanguage();
Bool AddParameter();
Bool ReadParameters();
Bool MarkMemory();
Bool ShowUnmarkedMemory();

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
