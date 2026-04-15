#ifndef _SCRIPTMANAGER_G_H_
#define _SCRIPTMANAGER_G_H_
#include "ABC_ScriptManager.h"
#include "BaseInGameDatas_GHdl.h"
#include "UnLock_G.h"
class ActionHelper_G;

enum GameDifficulty {
    VeryEasy,
    Easy,
    Normal,
    Hard,
    Nightmare
};

class PlayerSaveStruct_G {
    S32 m_Health;
    S32 m_MaxHealth;
    S32 m_Lives;
};

class ScriptManager_G : public ABC_ScriptManager {

    virtual ~ScriptManager_G();
    virtual void Init();
    virtual void Shut();
    virtual void MarkHandles();
    virtual void ReadEnumFromFiles();
    virtual U32 MateriaInterpColFlag(const Char* a1);
    virtual U32 MateriaInterpObjFlag(const Char* a1);
    virtual U32 MateriaRemoveColFlag(const Char* a1);
    virtual void GameSet(const Game_ZHdl& i_GameHdl);
    virtual void GameAgentSet(const Game_ZHdl& i_GameHdl);
    virtual void RemoveGame(const Game_ZHdl& i_GameHdl);
    virtual void GameReseted(const Game_ZHdl& i_GameHdl);
    virtual void ActivateGame(const Game_ZHdl& i_GameHdl);
    virtual void UpdateIndependentResources(const World_ZHdl& a1);
    virtual void InterpKeyframeMsg(const RegMessage_Z& a1);
    virtual void StreamRemoving(const Game_ZHdl& i_GameHdl, const Node_ZHdl& a2);
    virtual void StreamDone(const Game_ZHdl& i_GameHdl, const Node_ZHdl& a2);
    virtual void StreamDone(const Game_ZHdl& i_GameHdl, S32 a2);
    virtual void Update(Float a1);
    virtual Bool Minimize();
    virtual void SetPlayer(S32 a1, ABC_AgentHdl a2);
    virtual void GetPlayer(S32 a1);
    virtual void ResetGame(Game_ZHdl& i_GameHdl);

    U8 m_Pad_0xc8[0xF8];
    GameDifficulty m_Difficulty;
    U8 m_Pad_0x1c4[0x6450];
    ActionHelper_G* m_ActionHelper;
    U8 m_Pad_0x6618[0x6c];
    BaseInGameDatas_GHdl m_InGameDatasHdl;
    U8 m_Pad_0x6688[0x20];
    UnLockEvents_G m_UnlockEvents;
    U8 m_Pad_0x66b0[0x44];
    PlayerSaveStruct_G m_PlayerSaveStruct;
    U8 m_Pad_0x6700[0x10];
};

#endif // _SCRIPTMANAGER_G_H_
