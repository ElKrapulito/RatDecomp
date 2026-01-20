#ifndef _SELFRUNNING_Z_H_
#define _SELFRUNNING_Z_H_
#include "Manipulator_Z.h"

class SelfRunning_Z : public Manipulator_Z {
public:
    virtual ~SelfRunning_Z();
    virtual void Reset();
    virtual void Update(Float i_DeltaTime);

    static BaseObject_Z* NewObject() { return NewL_Z(60) SelfRunning_Z; }
};

#endif // _SELFRUNNING_Z_H_
