#include "MaterialAnim_Z.h"
#include "Material_Z.h"

MaterialAnim_Z::MaterialAnim_Z() {
    m_CurTime = 0.0f;
    m_MaxTime = 0.0f;
    m_PlayFlag = FL_MAT_NONE;
}

Bool MaterialAnim_Z::MarkHandles() {
    if (!ResourceObject_Z::MarkHandles()) {
        return FALSE;
    }
    m_BmapHdlKfr.MarkHandles();
    if (m_MaterialHdl.IsValid()) {
        m_MaterialHdl->MarkHandles();
    }
    return TRUE;
}
