#ifndef _CLASSMANAGER_Z_H_
#define _CLASSMANAGER_Z_H_
#include "Handle_Z.h"
#include "File_Z.h"

#define REGISTER_CLASS(a, b, c) gData.ClassMgr->RegisterClass(a, b, c)

typedef BaseObject_Z* (*NewObjectProc)();

struct BigFileRscHeader_Z {
    U32 m_Size;
    U32 m_LinkSize;
    U32 m_DataSize;
    U32 m_CompressedSize;
    Name_Z m_ClassName;
    Name_Z m_Name;
};

struct BigFileRsc_Z {
    BigFileRscHeader_Z* m_Header;
    U8* m_Data;
    BaseObject_Z* m_Rsc;
    U8 m_Flag;
};

class ClassManager_Z : public HandleManager_Z {
public:
    void LoadLinkId(void* i_ID, void** i_Data);
    void UpdateLinkFromId(BaseObject_ZHdl& i_Hdl, S32 i_ID);
    void UpdateLink(BaseObject_ZHdl& i_Hdl);
    void LoadName(Name_Z&, void**);
    void LoadLink(BaseObject_ZHdl& i_Hdl, void** i_Data);

    void RegisterClass(const Char* i_ClassName, const Char* i_ParentName, NewObjectProc i_NewObject);

    Bool IsBigFileOpened() const { return m_IsBigFileOpened; }

    BaseObject_ZHdl& NewObject(const Char* i_ClassName);
    BaseObject_ZHdl& NewObject(const Name_Z& i_ClassName);
    BaseObject_ZHdl& NewObject(const Name_Z& i_ClassName, const Name_Z& i_Name);
    Bool IsObjectInherit(const Name_Z& i_ClassName, const Name_Z& i_ParentClassName);
    Bool GetFile(const Char* i_Path, File_Z& i_File);

private:
    Char m_Unks[0x522];
    Bool m_IsBigFileOpened;
};

#endif
