#include "NetManager_Z.h"

NetObjectDescriptors::NetObjectDescriptors() {
    for (U32 i = 0; i < 64; i++) {
        m_Descriptors[i].m_Unk_0x04 = 0;
        m_Descriptors[i].m_Unk_0x08 = 0;
        m_Descriptors[i].m_Ptr = NULL;
    }
}

NetObjectDescriptors::~NetObjectDescriptors() {
    for (U32 i = 0; i < 64; i++) {
        KillDescriptor(i);
    }
}

void NetObjectDescriptors::KillDescriptor(U32 i_Idx) {
    if (m_Descriptors[i_Idx].m_Ptr) {
        operator delete(m_Descriptors[i_Idx].m_Ptr);
    }

    m_Descriptors[i_Idx].m_Unk_0x00 = 0;
    m_Descriptors[i_Idx].m_Unk_0x04 = 0;
    m_Descriptors[i_Idx].m_Unk_0x08 = 0;
    m_Descriptors[i_Idx].m_Ptr = NULL;
}
