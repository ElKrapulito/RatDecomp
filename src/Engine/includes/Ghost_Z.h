#ifndef _GHOST_Z_H_
#define _GHOST_Z_H_
#include "Manipulator_Z.h"

class Node_ZHdl;
class File_Z;

class Ghost_Z : public Manipulator_Z {
public:
    virtual ~Ghost_Z();
    virtual Bool MarkHandles();
    virtual void Reset();
    virtual void Update(Float i_DeltaTime);
    virtual void ResetGhost();
    virtual void UpdateBestGhost();
    virtual void GetPlayerState(Float a1);
    virtual void Save(Float a1);
    virtual void Play(Float a1);
    virtual void StartSave(const Node_ZHdl& a1);
    virtual void SaveToFile(File_Z& a1);
    virtual void LoadFromFile(File_Z& a1);

    static BaseObject_Z* NewObject() { return NewL_Z(99) Ghost_Z; }
};

#endif // _GHOST_Z_H_
