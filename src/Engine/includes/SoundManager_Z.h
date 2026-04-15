#ifndef _SOUNDMANAGER_Z_H_
#define _SOUNDMANAGER_Z_H_
#include "ClassNameResManager_Z.h"
#include "Math_Z.h"
#include "Node_ZHdl.h"
#include "ABC_AgentHdl.h"
#include "Sound_ZHdl.h"

class BoneNode_Z;

class SoundManager_Z : public ClassNameResManager_Z {
public:
    SoundManager_Z();

    virtual void Shut();
    virtual Bool Minimize();
    virtual ~SoundManager_Z();
    virtual void Init();
    virtual void CloseFrame();
    virtual void Update(Float a1);
    virtual void Draw(DrawInfo_Z& i_DrawInfo);
    virtual void UpdateTrack(Float a1, S32 a2, Float& a3, Float& a4, Vec3f& a5);
    virtual void CheckTrack(S32 a1);
    virtual void Reset();
    virtual void Clean();
    virtual void SetMuteState(U32 a1);
    virtual void SetSfxVol(Float a1);
    virtual void GetSfxVol();
    virtual void SetDlgVol(Float a1);
    virtual void GetDlgVol();
    virtual void SetMusicVol(Float a1);
    virtual void GetMusicVol();
    virtual void SetRandomFreqScale(Float a1, Float a2);
    virtual void SetPitchRatio(Float a1, const Sound_ZHdl& a2, const Node_ZHdl& a3, BoneNode_Z* a4, S32 a5);
    virtual void SetVolumeFactor(Float i_Volume, const Sound_ZHdl& i_SoundHdl, const Node_ZHdl& i_NodeHdl, BoneNode_Z* i_BoneNode = NULL, S32 i_UnkS32 = -1);
    virtual void OpenStreamBF(const Char* a1);
    virtual void CloseStreamBF();
    virtual void LoadStreamSound(const Char* a1);
    virtual void PlayStreamSound(const Char* a1, U32 a2, const Node_ZHdl& a3, BoneNode_Z* a4, ABC_AgentHdl a5, int a6);
    virtual void StopStreamSound(const Char* a1);
    virtual void GetStreamSoundDuration(const Char* a1);
    virtual void IsStreamPlaying(const Char* a1);
    virtual void IsAnyStreamPlaying();
    virtual void LoadMusic(const Char* a1);
    virtual void PlayMusic(const Char* a1, U32 a2, Float a3, Float a4);
    virtual void SkipMusic(const Name_Z& a1, const Name_Z& a2, U32 a3, bool a4);
    virtual void SkipMusicQueueSize();
    virtual void GetMusicTime();
    virtual void StopMusic(Float a1);
    virtual void IsMusicPlaying();
    virtual void GetLipSyncFromStream(const Node_ZHdl& a1);
    virtual void PlaySound(Sound_ZHdl& i_SoundHdl, U32 i_Flag, const Node_ZHdl& i_NodeHdl, BoneNode_Z* i_BoneNode = NULL);
    virtual void StopSound(Sound_ZHdl& i_SoundHdl, const Node_ZHdl& i_NodeHdl, Float i_UnkFloat);
    virtual void CreateSound(Sound_ZHdl& a1);
    virtual void FreeSound(void* a1);
    virtual void Compute3DVirtualization(S32 a1, Float& a2, Float& a3, Float& a4, Vec3f& a5);
    virtual void StopSound(S32 a1);
    virtual void GetTrackTime(S32 a1);
    virtual void GetDlgDTime(S32 a1);
    virtual void GetUsedTrackString();
};

#endif // _SOUNDMANAGER_Z_H_
