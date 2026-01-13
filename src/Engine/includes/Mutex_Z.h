#ifndef _MUTEX_Z_H_
#define _MUTEX_Z_H_
#include "Assert_Z.h"

class SharedResource_Z;

class SharedResourceGuard_Z {
public:
    SharedResourceGuard_Z(SharedResource_Z& i_SharedResource);
    ~SharedResourceGuard_Z();

private:
    SharedResource_Z& m_SharedResource;

    SharedResourceGuard_Z& operator=(const SharedResourceGuard_Z&);
    SharedResourceGuard_Z(const SharedResourceGuard_Z&);
};

class SharedResource_Z {
public:
    SharedResource_Z();
    ~SharedResource_Z();

    void Lock();
    void Unlock();

private:
    // $SABE: Underlying OS synchronization primitive
    class Primitive;
    Primitive* m_Primitive;

    SharedResource_Z& operator=(const SharedResource_Z&);
    SharedResource_Z(const SharedResource_Z&);

    friend class SharedResourceGuard_Z;
};

class Event_Z {
public:
    Event_Z() {
        if (!Create()) {
            ASSERTL_Z(FALSE, "Event::Event - unable to create event", 83);
        }
    }

    Bool Wait(S32 i_Time);

private:
    Bool Create();

    U32 m_Handle;
};

#endif // _MUTEX_Z_H_
