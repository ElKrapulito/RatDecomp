#ifndef _MATERIALMANAGER_Z_H_
#define _MATERIALMANAGER_Z_H_
#include "MaterialAnim_Z.h"
#include "MaterialAnim_ZHdl.h"
#include "StaticArray_Z.h"
#include "DynArray_Z.h"

#define MAX_MATERIAL_ANIMS 1024
#define MAX_MATERIAL_USERS 16

class MaterialManager_Z {
private:
    StaticArray_Z<MaterialAnim_ZHdl, MAX_MATERIAL_ANIMS> m_MaterialAnims;
    StaticArray_Z<MaterialAnim_ZHdl, MAX_MATERIAL_ANIMS> m_MaterialAnimsReallyAnimated;
    DynArray_Z<MaterialUserDesc_Z, MAX_MATERIAL_USERS> m_MaterialUsers;
    Bool m_IsPaused;

public:
    MaterialManager_Z();
    ~MaterialManager_Z();

    void AddMaterialAnim(const MaterialAnim_ZHdl& i_MaterialAnimHdl);
    void Update(Float i_DeltaTime);

    inline void EndPause() {
        m_IsPaused = FALSE;
    }
};

#endif // _MATERIALMANAGER_Z_H_
