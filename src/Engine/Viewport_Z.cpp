#include "Viewport_Z.h"
#include "World_Z.h"

Viewport_Z::Viewport_Z() {
    Init();
}

Viewport_Z::~Viewport_Z() { }

void Viewport_Z::Init() {
    m_Renderer = NULL;
    m_VCenter = -1.0f;
    m_HCenter = -1.0f;
    m_VSize = -1.0f;
    m_HSize = -1.0f;
    m_VRatio = -1.0f;
    m_HRatio = -1.0f;
    m_Ratio = -1.0f;
    m_DFov = -1.0f;
    m_CameraMatrixId = -1;
}

void Viewport_Z::SetPosAndSize(S32 i_StartX, S32 i_StartY, S32 i_SizeX, S32 i_SizeY) {
    m_StartX = i_StartX;
    m_StartY = i_StartY;
    m_SizeX = i_SizeX;
    m_SizeY = i_SizeY;
    m_HCenter = m_StartX + m_SizeX * 0.5f;
    m_VCenter = m_StartY + m_SizeY * 0.5f;
}

void Viewport_Z::GetPosAndSize(S32& o_StartX, S32& o_StartY, S32& o_SizeX, S32& o_SizeY) const {
    o_StartX = m_StartX;
    o_StartY = m_StartY;
    o_SizeX = m_SizeX;
    o_SizeY = m_SizeY;
}

void Viewport_Z::SetWorld(const World_ZHdl& i_WorldHdl) {
    m_WorldHdl = i_WorldHdl;
    m_OccluderHdl = Occluder_ZHdl();
    if (m_WorldHdl.IsValid() && m_WorldHdl->GetNbOccluder() != 0) {
        m_OccluderHdl = m_WorldHdl->GetOccluder(0);
    }
}
