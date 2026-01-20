#ifndef _SYSTEMDATAS_Z_H_
#define _SYSTEMDATAS_Z_H_
#include "Light_ZHdl.h"
#include "Material_ZHdl.h"
class SystemDatas_Z {
public:
    inline LightData_ZHdl& GetDefaultLight() {
        return m_DefaultLightDataHdl;
    }

    inline Material_ZHdl& GetDefaultMaterial() {
        return m_DefaultMaterialHdl;
    }

private:
    U8 m_Pad_0x0[0x38];
    Material_ZHdl m_DefaultMaterialHdl;
    U8 m_Pad_0x40[0x2c];
    LightData_ZHdl m_DefaultLightDataHdl;
};
#endif // _SYSTEMDATAS_Z_H_
