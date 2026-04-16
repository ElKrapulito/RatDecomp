#include "NetManager_Virtual_Z.h"
#include "Timer_Z.h"

void NetManager_Virtual_Z::FixNetTime() {
    Float l_AbsoluteTime = GetAbsoluteTime();
    m_Time1 = l_AbsoluteTime;
    m_Time2 = l_AbsoluteTime;
}
