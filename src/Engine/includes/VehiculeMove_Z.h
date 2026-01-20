#ifndef _VEHICULEMOVE_Z_H_
#define _VEHICULEMOVE_Z_H_
#include "LodMove_Z.h"

class VehiculeMove_Z : public LodMove_Z {
public:
    virtual ~VehiculeMove_Z();
    virtual void Init();
    virtual void Reset();
    virtual void Update(const Vec3f& a1, const Vec3f& a2, const Vec3f& a3, Float a4, S32 a5);

    static BaseObject_Z* NewObject() { return NewL_Z(17) VehiculeMove_Z; }
};

#endif // _VEHICULEMOVE_Z_H_
