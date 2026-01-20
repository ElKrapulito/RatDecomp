#ifndef _TXT_H_
#define _TXT_H_
#include "ResourceObject_Z.h"
#include "File_Z.h"

class Txt_Z : public ResourceObject_Z {
public:
    // clang-format off
    virtual ~Txt_Z() { };
    virtual void Load(void** i_Data);
    // clang-format on

    static BaseObject_Z* NewObject() { return NewL_Z(21) Txt_Z; }

private:
    File_Z m_File;
};

#endif
