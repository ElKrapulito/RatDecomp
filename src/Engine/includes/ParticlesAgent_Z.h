#ifndef _PARTICLESAGENT_Z_H_
#define _PARTICLESAGENT_Z_H_
#include "Agent_Z.h"
#include "PlayParticles_ZHdl.h"
#include "Skel_ZHdl.h"
// clang-format off

BEGIN_AGENT_CLASS(ParticlesAgent_Z, Agent_Z, 12)
public:
    ParticlesAgent_Z();
    virtual void Init();
    virtual ~ParticlesAgent_Z() { }
    virtual Bool MarkHandles();
    virtual void Suspend();
    virtual void Restore();
    virtual void Reset();
    virtual void UseNode(Node_ZHdl& a1);
    virtual void RegisterWithGame(Game_ZHdl& a1);
    virtual void UnRegisterFromGame(Game_ZHdl& a1);
    virtual void DoFollow();

    void Pause();
    void Resume();
    void Replay();

private:
    PlayParticles_ZHdl m_PlayParticlesHdl;
    Node_ZHdl m_FollowNodeHdl;
    Skel_ZHdl m_FollowSkelHdl;
    S32 m_FollowBoneId;
END_AGENT_CLASS

// clang-format on
#endif // _PARTICLESAGENT_Z_H_
