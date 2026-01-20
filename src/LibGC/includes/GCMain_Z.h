#ifndef _GCMAIN_Z_H_
#define _GCMAIN_Z_H_
#include "Main_Z.h"
#include "Handle_Z.h"
#include "ClassManager_Z.h"

class GCParticlesManager_Z;
class TextureManager_Z;

class GCGlobals : public Globals {
public:
    virtual ~GCGlobals() { };
    virtual U32 GetMgrSize(Name_Z* l_Name, S32* a1, S32* a2);
    virtual void Minimize();

    //U8 m_Pad_0x7E0[0x110];
    GCParticlesManager_Z* GCParticlesManager;
    TextureManager_Z* TextureMgr;
    String_Z<ARRAY_CHAR_MAX> m_AliasPath;

    GCGlobals() {
        GCParticlesManager = NULL;
        TextureMgr = NULL;
    }
};

Weak_Z BaseObject_ZHdl::operator BaseObject_Z*() const {
    return GETPTR(*this);
}

#endif
