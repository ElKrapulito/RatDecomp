#ifndef _SYSTEMDATAS_Z_H_
#define _SYSTEMDATAS_Z_H_
#include "Light_ZHdl.h"

class SystemDatas_Z {
public:
    inline LightData_ZHdl& GetDefaultLight() {
        return m_DefaultLightDataHdl;
    }

private:
    U8 m_Pad_0x0[0x68];
    LightData_ZHdl m_DefaultLightDataHdl;
};
#endif // _SYSTEMDATAS_Z_H_
