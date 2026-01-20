#ifndef _INGAMEOBJECTSMANIPULATOR_Z_H_
#define _INGAMEOBJECTSMANIPULATOR_Z_H_
#include "Manipulator_Z.h"

class InGameObjects_ZHdl;

class InGameObjectsManipulator_Z : public Manipulator_Z {
public:
    virtual ~InGameObjectsManipulator_Z();
    virtual void Update(Float i_DeltaTime);
    virtual void SetTarget(InGameObjects_ZHdl& a1);
    virtual void GetTarget();
    virtual void LoadDataDesc(const Char* a1);

    static BaseObject_Z* NewObject() { return NewL_Z(35) InGameObjectsManipulator_Z; }
};

#endif // _INGAMEOBJECTSMANIPULATOR_Z_H_
