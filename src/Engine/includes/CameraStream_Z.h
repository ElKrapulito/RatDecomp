#ifndef _CAMERASTREAM_Z_H_
#define _CAMERASTREAM_Z_H_
#include "Manipulator_Z.h"

class CameraStream_Z : public Manipulator_Z {
public:
    virtual void Init();
    virtual ~CameraStream_Z();
    virtual void Update(Float i_DeltaTime);

    static BaseObject_Z* NewObject() {
        return NewL_Z(22) CameraStream_Z;
    }
};

#endif // _CAMERASTREAM_Z_H_
