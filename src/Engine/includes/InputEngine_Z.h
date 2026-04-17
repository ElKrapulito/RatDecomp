#ifndef _INPUTENGINE_Z_H_
#define _INPUTENGINE_Z_H_
#include "DynArray_Z.h"
#include "Main_Z.h"
#include "Math_Z.h"
#include "HoleArray_Z.h"

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

struct InputAction_Z {
    Bool m_UnkBool_0x0;
    Bool m_UnkBool_0x1;
    Bool m_UnkBool_0x2;
    Float m_Unk4Bytes_0x4;
    Bool m_UnkBool_0x8;
    Bool m_UnkBool_0x9;
    Bool m_UnkBool_0xa;
    S32 m_Unk4Bytes_0xc;
    Float m_UnkFloat_0x10;
    Float m_UnkFloat_0x14;
    Float m_BaseValue;
    Float m_MinValue;
    Float m_MaxValue;
    Float m_UnkFloat_0x24;
    S32 m_UnkS32_0x28;
    Float m_UnkFloat_0x2c;
    Bool m_Pressed;
    Bool m_UnkBool_0x31;
    Bool m_UnkBool_0x32;
    Float m_PressedTimer;
    Float m_SomeTimer_0x38;
    Float m_SomeOtherTimer_0x3c;
    S32 m_DeviceIdx;
    S32 m_ActionId;
};

struct InputActionContext_Z {
    S32 m_DeviceIdx;
    Bool m_UnkBool_0x4;
    DynArray_Z<InputAction_Z, 4> m_Actions;
    S32 m_UnkS32_0x10;
    S32 m_UnkS32_0x14;
};

struct ButtonRemap_Z {
    S32 m_ButtonId;
    S32 m_SecondaryButtonId;
    Bool m_ControlMode;
};

// $SABE: Fake name
struct InputData_Z {
    Vec2f m_WiiMotePointerRelated1;
    Vec2f m_WiiMotePointerRelated2;
    Bool m_UnkBool_0x18;
    Bool m_UnkBool_0x19;
    Bool m_UnkBool_0x1a;
    Bool m_UnkBool_0x1b;
    Bool m_UnkBool_0x1c;
    Bool m_UnkBool_0x1d;
    Bool m_UnkBool_0x1e;
    Bool m_UnkBool_0x1f;

    InputData_Z()
        : m_UnkBool_0x18(FALSE)
        , m_UnkBool_0x19(FALSE)
        , m_UnkBool_0x1a(FALSE)
        , m_UnkBool_0x1b(FALSE)
        , m_UnkBool_0x1c(FALSE)
        , m_UnkBool_0x1d(FALSE)
        , m_UnkBool_0x1e(FALSE)
        , m_UnkBool_0x1f(FALSE) {
        m_WiiMotePointerRelated1 = VEC2F_NULL;
        m_WiiMotePointerRelated2 = VEC2F_NULL;
    }
};

class InputPlatForm_Z {
public:
    DynArray_Z<InputDevice_Z, 8> m_Devices;
    InputData_Z m_InputData;
    S32 m_UnkBytes_0x20;
    Bool m_UnkBool_0x24;
    Bool m_UnkBool_0x25;
    Bool m_IsPaused;
    HoleArray_Z<InputActionContext_Z, 4> m_RegisteredInputActionContexts;
    HoleArray_Z<InputActionContext_Z, 4> m_ActiveInputActionContexts;
    DynArray_Z<ButtonRemap_Z, 32> m_ActionButtonMappings; // for each action

public:
    InputPlatForm_Z()
        : m_UnkBytes_0x20(0) {
        m_UnkBool_0x24 = FALSE;
        m_UnkBool_0x25 = TRUE;
        m_IsPaused = FALSE;
    }

    inline S32 GetDeviceCount() const {
        return m_Devices.GetSize();
    }

    inline InputDevice_Z& GetDevice(S32 i_Index) {
        return m_Devices[i_Index];
    }

    inline void EndPause() {
        m_IsPaused = FALSE;
    }

    virtual ~InputPlatForm_Z();
    virtual Bool Init();
    virtual void Minimize();

    virtual void Shut() { }

    virtual void AddDevice();
    virtual void ResetPads();
    virtual void RemoveDevice(S32 a1);
    virtual void UpdateInput(Float a1);
    virtual void IsButtonPressed(U8 a1);
    virtual void IsAnyButton(U32 a1);
    virtual void ChangeActionMapping(U32 a1, S32* a2, S32* a3);
    virtual void SetControl(S32 a1, Name_Z a2, Name_Z a3);
    virtual void SetControlMode(S32 a1, Bool a2);
    virtual void EnableJoystick(S32 a1);
    virtual void DisableJoystick(S32 a1);
    virtual void EnableVibration(S32 a1, Bool a2);
    virtual void Vibration(S32 a1, U8 a2, U8 a3);
    virtual void SetEcoMode(S32 a1, Bool a2);
    virtual void GetDeviceStatus(S32 a1, S32 a2);
    virtual void GetPCStringFromInput(Char* a1, S32 a2, S32 a3);
    virtual void GetControls(InputDevice_Z* a1, void* a2, Bool a3);
    virtual void GetControl(InputDevice_Z* a1, S32 a2, void* a3, Bool a4);
};

class InputEngine_Z {
public:
    virtual ~InputEngine_Z();
    virtual void Update(Float i_DeltaTime);
    virtual void Minimize();

protected:
    S32DA m_OldInput; // JIMMY DWARF
};

#endif
