#ifndef _BASEAGENT_G_H_
#define _BASEAGENT_G_H_
#include "LodAgent_Z.h"
// clang-format off

BEGIN_AGENT_CLASS(BaseAgent_G, LodAgent_Z, 13)
public:
    BaseAgent_G();

    virtual ~BaseAgent_G() {}
    virtual void Init();
    virtual void IsCreature();
    virtual void Sleep();
    virtual void WakeUp();

    DECL_BHV(CheckReset);
END_AGENT_CLASS

// clang-format on
#endif // _BASEAGENT_G_H_
