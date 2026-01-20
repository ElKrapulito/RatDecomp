#ifndef _OBJECTSGAME_Z_H_
#define _OBJECTSGAME_Z_H_
#include "ObjectGame_Z.h"

class ObjectsGame_Z : public ObjectGame_Z {
public:
    virtual ~ObjectsGame_Z();
    virtual void Init();
    virtual void Reset();
    virtual void ActionOnActivate();
    virtual void ActionOnDeactivate();
    virtual void Update(Float a1);
    virtual void AddGameObject(const ObjectMove_ZHdl& a1);
    virtual void RemoveGameObject(const ObjectMove_ZHdl& a1);
    virtual void UnregistredFromGame(const Agent_ZHdl& a1);

    static BaseObject_Z* NewObject() { return NewL_Z(125) ObjectsGame_Z; }
};

#endif // _OBJECTSGAME_Z_H_
