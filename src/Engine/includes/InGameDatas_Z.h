#ifndef _INGAMEDATAS_Z_H_
#define _INGAMEDATAS_Z_H_
#include "Manipulator_Z.h"

class InGameDatas_Z : public ManipulatorDraw_Z {
public:
    virtual ~InGameDatas_Z();
    virtual void Update(Float i_DeltaTime);
    virtual void Draw(const Viewport_Z* a1);
    virtual void RecalcPositions();
    virtual void LoadDataDesc(const Char* a1);

    static BaseObject_Z* NewObject() { return NewL_Z(119) InGameDatas_Z; }
};
#endif // _INGAMEDATAS_Z_H_
