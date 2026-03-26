#ifndef _INPUTENGINE_Z_H_
#define _INPUTENGINE_Z_H_
#include "DynArray_Z.h"
#include "Main_Z.h"

struct InputDevice_Z {
    U8 m_Pad_0x0[0x316];
    Bool m_AnyDPadPressed;
    U8 m_Pad_0x317[0x3];
    Bool m_DPadUpPressed;
    Bool m_DPadDownPressed;
    Bool m_DPadLeftPressed;
    Bool m_DPadRightPressed;
    U8 m_Pad_0x31e[0x36];

    inline Bool IsAnyDPadPressed() const {
        return m_AnyDPadPressed;
    }
};

class InputPlatForm_Z {
public:
    DynArray_Z<InputDevice_Z, 8> m_Devices;

    // TODO: Add the rest of the members and funcs
public:
    inline S32 GetDeviceCount() const {
        return m_Devices.GetSize();
    }

    inline InputDevice_Z& GetDevice(S32 i_Index) {
        return m_Devices[i_Index];
    }
};

#endif
