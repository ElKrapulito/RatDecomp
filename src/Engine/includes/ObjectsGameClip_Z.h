#ifndef _OBJECTSGAMECLIP_Z_H_
#define _OBJECTSGAMECLIP_Z_H_
#include "ObjectGame_Z.h"
#include "ObjectsGame_ZHdl.h"
#include "ObjectsGameClip_ZHdl.h"
#include "Game_ZHdl.h"

class ObjectsGameClip_Z : public ObjectGame_Z {
public:
    virtual ~ObjectsGameClip_Z();
    virtual void Init();
    virtual void Update(Float i_DeltaTime);

    void SetObjectsGameHdl(ObjectsGame_ZHdl& i_ObjectsGameHdl) {
        m_ObjectsGameHdl = i_ObjectsGameHdl;
    }

private:
    Game_ZHdl m_GameHdl;
    Bool m_UnkBool_0x2c;
    ObjectsGame_ZHdl m_ObjectsGameHdl;
};

#endif // _OBJECTSGAMECLIP_Z_H_
