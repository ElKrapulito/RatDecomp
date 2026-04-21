#ifndef _OBJECTMOVECOLLDATA_H_
#define _OBJECTMOVECOLLDATA_H_

#include "Math_Z.h"

struct ObjectMoveCollData_Z {
    ObjectMoveCollData_Z() {
        m_Flag = 0;
    }

    Vec3f m_Intersection;
    U64 m_Flag;
    Vec3f m_Speed;
};

#endif //_OBJECTMOVECOLLDATA_H
