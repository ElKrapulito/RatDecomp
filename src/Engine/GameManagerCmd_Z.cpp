#include "GameManager_Z.h"
#include "Language_Z.h"
#include "Console_Z.h"
#include "Parameters_Z.h"
#include "DebugTools_Z.h"
#include "Memory_Z.h"
#include "Program_Z.h"
#include "Console_Z.h"
#include "Language_Z.h"

void RegisterGameMgrCommand() {
    RegisterGameCommand();
    REGISTERCOMMANDC("SetGame", SetMultiGame, " WorldName NbPlayers [AgentCameraClassName=CameraGame]");
    REGISTERCOMMANDC("ActivateGame", ActivateGame, " WorldName");
    REGISTERCOMMANDC("DeactivateGame", DeactivateGame, " WorldName");
    REGISTERCOMMANDC("RemoveGame", RemoveGame, " WorldName ");
    REGISTERCOMMANDC("SetMonoGame", SetMonoGame, " WorldName NbPlayers [AgentCameraClassName=CameraGame]");
    REGISTERCOMMANDC("SwitchGameToMono", SwitchGameToMono, " WorldName");
    REGISTERCOMMANDC("SwitchGameToMUlti", SwitchGameToMulti, " WorldName NbVp");
    REGISTERCOMMANDC("AddGamePlayer", AddGamePlayer, " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS) PlayerName [TeamId=0]");
    REGISTERCOMMANDC("AddMenuPlayer", AddMenuPlayer, " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS) PlayerName [TeamId=0]");
    REGISTERCOMMANDC("ReMoveGamePlayer", RemoveGamePlayer, " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)");
    REGISTERCOMMANDC("REsetGame", ResetGame, " VpId(1-MAX_VIEWPORT)");
    REGISTERCOMMANDC("DeactivateGamePlayer", DeactivateGamePlayer, " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)");
    REGISTERCOMMANDC("ACtivateGamePlayer", ActivateGamePlayer, " WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)");
    REGISTERCOMMANDC("PlayerGotoCoord", PlayerGoto, "  X Y Z Viewport");
    REGISTERCOMMANDC("SwitchCameraUser", SwitchCameraUser, " ViewPortId");
    REGISTERCOMMANDC("SetPersoCamera", SetPersoCamera, " ViewPortId");
    REGISTERCOMMANDC("SetRTC", SetRtc, " WorldName RtcNb");
    REGISTERCOMMANDC("LoadRTC", LoadRtc, " WorldName RtcId RtcName [AgentRtcClassName=RtcGame]");
    REGISTERCOMMANDC("PlayRTC", PlayRtc, " WorldName RtcId [ViewPortId]");
    REGISTERCOMMANDC("SHutRTC", ShutRtc, " WorldName RtcId");
    REGISTERCOMMAND("TransText", AddTransText);
    REGISTERCOMMAND("SetLanguage", SetLanguage);
    REGISTERCOMMAND("FreeLanguage", FreeLanguage);
    REGISTERCOMMAND("PutParameter", AddParameter);
    REGISTERCOMMAND("ReadParameters", ReadParameters);
    REGISTERCOMMAND("MarkMEMory", MarkMemory);
    REGISTERCOMMAND("ShowUnmarkedMEMory", ShowUnmarkedMemory);
}

Bool SetMultiGame() {
    return SetGame(FALSE);
}

Bool SetMonoGame() {
    return SetGame(TRUE);
}

Bool SetGame(Bool i_IsMono) {
    return TRUE;
}

Bool AddGamePlayer() {
    return AddPlayer(FALSE);
}

Bool AddMenuPlayer() {
    return TRUE;
}

Bool AddPlayer(Bool i_IsMenu) {
    return TRUE;
}

Bool RemoveGamePlayer() {
    return TRUE;
}

Bool ActivateGamePlayer() {
    return TRUE;
}

Bool DeactivateGamePlayer() {
    return TRUE;
}

Bool SwitchGameToMono() {
    return TRUE;
}

Bool SwitchGameToMulti() {
    return TRUE;
}

Bool ActivateGame() {
    return TRUE;
}

Bool DeactivateGame() {
    return TRUE;
}

Bool SwitchCameraUser() {
    return TRUE;
}

Bool SetPersoCamera() {
    return TRUE;
}

Bool ResetGame() {
    return TRUE;
}

Bool PlayerGoto() {
    return TRUE;
}

Bool RemoveGame() {
    return TRUE;
}

Bool SetRtc() {
    return TRUE;
}

Bool PlayRtc() {
    return TRUE;
}

Bool ShutRtc() {
    return TRUE;
}

Bool LoadRtc() {
    return TRUE;
}

void GameManager_Z::DebugDisplay(Viewport_Z* i_Vp) {
    if (!(gData.m_EngineFlag & FL_POS_PERSO)) {
        return;
    }
    // TODO: Implement PosPerso debug display
}

Bool AddTransText() {
    return TRUE;
}

Bool SetLanguage() {
    if (gData.Cons->GetNbParam() < 2) {
        return TRUE;
    }
    SetLanguage((int)gData.Cons->GetParamFloat(1), -1, 0);
    return TRUE;
}

Bool AddParameter() {
    if (gData.Cons->GetNbParam() == 3) {
        Char* l_Param = gData.Cons->GetStrParam(2);
        if ('A' <= *l_Param) {
            Name_Z l_Name;
            if (l_Param) {
                l_Name = Name_Z::GetID(l_Param);
            }
            else {
                l_Name = Name_Z();
            }
            U32 l_Id = l_Name.GetID();
            AddParameters(gData.Cons->GetParamFloat(1), *((Float*)&l_Id));
        }
        else {
            AddParameters(gData.Cons->GetParamFloat(1), gData.Cons->GetParamFloat(2));
        }
    }
    return TRUE;
}

Bool ReadParameters() {
    if (gData.Cons->GetNbParam() < 2) {
        return TRUE;
    }
    ReadParameters(gData.Cons->GetParamFloat(1));
    return TRUE;
}

Bool MarkMemory() {
    s_MarkMem(1);
    return TRUE;
}

Bool ShowUnmarkedMemory() {
    s_ShowUnMarkedMem();
    return TRUE;
}
