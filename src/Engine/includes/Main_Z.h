#ifndef _MAIN_Z_H_
#define _MAIN_Z_H_
#include "Name_Z.h"
#include "String_Z.h"

Extern_Z Char* strcpy(Char* __dest, Char* __src);
Extern_Z "C" void memset(void* __s, S32 __c, U32 __n);

// Extern Platform Functions

Extern_Z void RegisterLowLevelClasses();
Extern_Z void LowLevelInitProgram();

// Extern Game Functions

Extern_Z void RegisterGameClasses();
Extern_Z void GameProgramInit();

// Engine Main Functions

void RegisterClasses();
void ProgramMain();
void ProgramInit();
void _CoreMainLoop();

#define FL_GAME_NONE (U32)(0 << 0)

class ManipulatorManager_Z;
class AnimationManager_Z;
class SoundManager_Z;
class ABC_ScriptManager;
class XRamManager_Z;
class Mat4x4Buffer_Z;
class Console_Z;
class Renderer_Z;
class GameManager_Z;
class EffectManager_Z;
class SystemDatas_Z;
class StreamManager_Z;
class ClassManager_Z;
class WorldManager_Z;
class MaterialManager_Z;
class BaseColSurfaceCache_Z;
class ColTriangleCache_Z;
class ObjectBankManager_Z;
class InputPlatForm_Z;
class Movie_Z;
class InputEngine_Z;
class SaveGame_Z;
class ParticlesManager_Z;
class SurfaceCache_Z;
class VolatileMgr_Z;
class NetManager_Z;

class Globals {
public:
    virtual ~Globals() { };
    virtual U32 GetMgrSize(Name_Z* l_Name, S32* a1, S32* a2);
    virtual void Minimize();
    virtual void GetDate();
    void InitTime();

    void* UnkMgr_0x4;
    Console_Z* Cons;
    Renderer_Z* MainRdr;
    ClassManager_Z* ClassMgr;
    WorldManager_Z* WorldMgr;
    MaterialManager_Z* MaterialMgr;
    ABC_ScriptManager* ScriptMgr;
    BaseColSurfaceCache_Z* ColSurfaceCache;
    void* UnkMgr_0x24;
    ColTriangleCache_Z* ColTriangleCache;
    Mat4x4Buffer_Z* MatrixBuffer;
    ManipulatorManager_Z* ManipMgr;
    GameManager_Z* GameMgr;
    void* UnkMgr_0x38;
    AnimationManager_Z* AnimMgr;
    EffectManager_Z* EffectMgr;
    SystemDatas_Z* SystemDatas;
    ObjectBankManager_Z* ObjectBankMgr;
    InputPlatForm_Z* InputMgr;
    SoundManager_Z* SoundMgr;
    Movie_Z* MovieMgr;
    InputEngine_Z* ScriptInputMgr;
    SaveGame_Z* SavingMgr;
    ParticlesManager_Z* ParticlesMgr;
    void* UnkMgr_0x64;
    SurfaceCache_Z* SurfaceCacheMgr;
    void* UnkMgr_0x6c;
    StreamManager_Z* StreamMgr;
    VolatileMgr_Z* VolatileMgr;
    void* UnkMgr_0x78;
    NetManager_Z* NetMgr;
    void* UnkMgr_0x80;
    XRamManager_Z* XRamMgr;
    S32 m_UnkS32_0x88;
    Bool m_Running;
    Bool m_BlockFrame;
    Bool m_IsPlatformAgnostic; // $SABE: Never set to TRUE, I suppose it was used in BF Write mode
    Bool m_UpdatingResource;
    Float FrameBlockCountDownTime;
    Float m_FrameBlockTime;
    Float m_TimeFactor;
    Bool m_UnPauseRequested;
    String_Z<ARRAY_CHAR_MAX> m_DBPath;
    String_Z<ARRAY_CHAR_MAX> m_DFPath;
    String_Z<ARRAY_CHAR_MAX> m_UnkString_0x29d;
    String_Z<ARRAY_CHAR_MAX> m_UnkString_0x39d;
    String_Z<ARRAY_CHAR_MAX> m_AppPath;
    String_Z<ARRAY_CHAR_MAX> m_UnkString_0x59d;
    String_Z<ARRAY_CHAR_MAX> m_LocalSavePath; // In Roaming on windows
    U32 m_EngineFlag;
    U32 m_MaterialFlag; // Which channels of materials are enabled
    U32 m_GameFlag;
    U32 m_Unk_0x7ac;
    U32 m_UnkError_0x7b0;
    U32 m_UnkError_0x7b4;
    U32 m_FrameCount;
    Float m_Timer;
    U32 m_Unk_0x7c0;
    Bool m_IsTimerCalibrated;
    Float m_TargetSecondsPerFrame;
    Float m_AbsoluteTime;
    U16 m_Unk_0x7d0;
    U16 m_Unk_0x7d2;
    U16 m_Unk_0x7d4;
    U16 m_Unk_0x7d6;
    U16 m_Unk_0x7d8;
    U16 m_Unk_0x7da;
    U32 m_Unk_0x7dc;

    // TODO: Properly define members for all this so we don't gotta move stuff around
    inline Globals() {
        // m_Pad_0x14[137] = 0;
        // m_Pad_0x14[393] = 0;
        // m_Pad_0x14[649] = 0;
        // m_Pad_0x14[905] = 0;
        // m_Pad_0x14[1161] = 0;
        // m_Pad_0x14[1417] = 0;
        // m_Pad_0x14[1673] = 0;
        // *(S16*)(&m_Pad_0x14[1980]) = -1;
        // *(S16*)(&m_Pad_0x14[1982]) = 0;
        // *(S16*)(&m_Pad_0x14[1984]) = 1;
        // *(S16*)(&m_Pad_0x14[1990]) = 8;
        // *(S16*)(&m_Pad_0x14[1986]) = 60;
        // *(S16*)(&m_Pad_0x14[1988]) = 480;
        // memset(&m_Pad_0x0, 0, 132);
        // m_Pad_0x14[1968] = 1;
        // *(Float*)(&m_Pad_0x14[1976]) = 0.0f;
        // *(Float*)(&m_Pad_0x14[1972]) = 0.0f;
        // strcpy((Char*)&m_Pad_0x14[1161], ".\\");
        // strcpy((Char*)&m_Pad_0x14[1673], "Ace");
        // *(S32*)(&m_Pad_0x14[1956]) = 0;
        // *(S32*)(&m_Pad_0x14[1944]) = 0;
        // *(S32*)(&m_Pad_0x14[1952]) = 0;
        // *(S32*)(&m_Pad_0x14[1948]) = 0;
        // m_Pad_0x14[120] = 0;
        // m_Pad_0x14[121] = 0;
        // m_Pad_0x14[136] = 0;
        // m_Pad_0x14[123] = 0;
        // m_Pad_0x14[122] = 0;
        // *(S32*)(&m_Pad_0x14[84]) = 0;
        // *(S32*)(&m_Pad_0x14[80]) = 0;
        // *(S32*)(&m_Pad_0x14[108]) = 0;
        // *(Float*)(&m_Pad_0x14[1960]) = 0.0;
        // m_Pad_0x14[1932] = 0;
        // *(S32*)(&m_Pad_0x14[1940]) = 0;
        // *(Float*)(&m_Pad_0x14[132]) = 1.0f;
        // *(S32*)(&m_Pad_0x14[1964]) = 0;
    }
};

#endif
