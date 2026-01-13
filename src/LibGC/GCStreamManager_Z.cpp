#include "Mutex_Z.h"
#include "Memory_Z.h"
#include "StreamManager_Z.h"
#include "dolphin/OS/OSMutex.h"

#define STREAM_THREAD_STACK_SIZE 0x1000
#define STREAM_THREAD_STACK_OFFSET 0x400
#define STREAM_THREAD_PRIORITY 16

OSThread ThreadId;
static void* ThreadStack;

class SharedResource_Z::Primitive {
public:
    OSMutex m_Mutex;
};

SharedResource_Z::SharedResource_Z()
    : m_Primitive(NewL_Z(12) Primitive) {
    OSInitMutex(&m_Primitive->m_Mutex);
}

SharedResource_Z::~SharedResource_Z() {
    Delete_Z m_Primitive;
}

void SharedResource_Z::Lock() {
    OSLockMutex(&m_Primitive->m_Mutex);
}

void SharedResource_Z::Unlock() {
    OSUnlockMutex(&m_Primitive->m_Mutex);
}

SharedResourceGuard_Z::SharedResourceGuard_Z(SharedResource_Z& i_SharedResource)
    : m_SharedResource(i_SharedResource) {
    i_SharedResource.Lock();
}

SharedResourceGuard_Z::~SharedResourceGuard_Z() {
    m_SharedResource.Unlock();
}

Bool Event_Z::Create() {
    return TRUE;
}

Bool Event_Z::Wait(S32 i_Time) {
    return TRUE;
}

Bool StreamManager_Z::Init() {
    ThreadStack = AllocL_Z(STREAM_THREAD_STACK_SIZE, 111);
    void* l_Stack = (void*)((Char*)ThreadStack + STREAM_THREAD_STACK_SIZE);

    S32 l_Result = OSCreateThread(
        &ThreadId,
        ThreadProcVoid,
        this,
        l_Stack,
        STREAM_THREAD_STACK_SIZE,
        STREAM_THREAD_PRIORITY,
        1
    );

    l_Result = l_Result != 0;

    if (!l_Result) {
        return FALSE;
    }

    OSResumeThread(&ThreadId);
    return TRUE;
}

StreamManager_Z::~StreamManager_Z() {
    OSCancelThread(&ThreadId);
    Free_Z(ThreadStack);
    ThreadStack = NULL;
}

void StreamManager_Z::Update(Float i_DeltaTime) {
    Heartbeat(i_DeltaTime);
}

void* StreamManager_Z::ThreadProcVoid(void* i_Param) {
    StreamManager_Z* l_StreamManager = (StreamManager_Z*)i_Param;
    while (!l_StreamManager->m_Finished) {
        l_StreamManager->Thread();
        OSYieldThread();
    }
    return NULL;
}
