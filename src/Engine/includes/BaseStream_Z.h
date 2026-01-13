#ifndef _BASESTREAM_Z_H_
#define _BASESTREAM_Z_H_

#include "Types_Z.h"

union StreamID {
    int GblID;

    struct {
        int m_StreamId : 16,
            m_ReadId : 16;
    } Ref;
};

class BaseStream_Z {
private:
    StreamID m_ID;

public:
    virtual void StreamOpened(S32 a1, S32 a2);
    virtual void StreamReaded(S32 a1, S32 a2);
    virtual void Opened(S32 a1, S32 a2, S32 a3);
    virtual void Readed(S32 a1, S32 a2, S32 a3);

    const StreamID& GetID() const {
        return m_ID;
    }

    void SetStreamId(S16 i_StreamId) {
        m_ID.Ref.m_StreamId = i_StreamId;
    }

    void SetReadId(S16 i_ReadId) {
        m_ID.Ref.m_ReadId = i_ReadId;
    }

    BaseStream_Z& operator=(const BaseStream_Z& i_Other);
};

#endif
