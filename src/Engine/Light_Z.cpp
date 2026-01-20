#include "Light_Z.h"

LightData_Z::LightData_Z() {
    m_LightFlag = FL_OBJECT_ACTIVE;
    m_Direction = VEC3F_NULL;
    m_Ambient = VEC3F_NULL;
    m_Color = VEC3F_ONE;
}
