#include "NetManager_Z.h"
#include "Memory_Z.h"

NetObjectDescriptors* NetManager_Z::Descriptors = NULL;

NetManager_Z::NetManager_Z() {
    m_State = 0;
    if (!Descriptors) {
        Descriptors = NewL_Z(21) NetObjectDescriptors;
    }
}

NetManager_Z::~NetManager_Z() {
    if (Descriptors) {
        Delete_Z Descriptors;
        Descriptors = NULL;
    }
}
