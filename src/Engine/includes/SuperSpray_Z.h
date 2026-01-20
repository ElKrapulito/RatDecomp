#ifndef _SUPERSPRAY_Z_H_
#define _SUPERSPRAY_Z_H_
#include "Manipulator_Z.h"
#include "Math_Z.h"

class Node_ZHdl;

class SuperSpray_Z : public Manipulator_Z {
public:
    virtual ~SuperSpray_Z();
    virtual void Reset();
    virtual void Update(Float a1);
    virtual void Replay();
    virtual void SetNode(const Node_ZHdl& a1);
    virtual void GetEmitRange(S32 a1);
    virtual void GetEmitTime(S32 a1);
    virtual void SetEmitColor(const Vec3f& a1, S32 a2);
    virtual void Pause();
    virtual void Resume();

    static BaseObject_Z* NewObject() { return NewL_Z(32) SuperSpray_Z; }
};

#endif // _SUPERSPRAY_Z_H_
