#ifndef _NETMANAGER_VIRTUAL_Z_H_
#define _NETMANAGER_VIRTUAL_Z_H_
#include "NetManager_Z.h"

class NetManager_Virtual_Z : public NetManager_Z {
public:
    NetManager_Virtual_Z() {
        FixNetTime();
    }

    virtual U32 Init() {
        return 10;
    }

    virtual void Kill() { }

    virtual void FixNetTime();

    virtual U32 EnterSession(Char* a1) { return 10; }

    virtual U32 QuitSession() { return 10; }

    virtual U32 IsMasterSession() { return 1; }

    virtual U32 GetMyUserHandle() { return 0; }

    virtual U32 WaitSynchronisation(U16 a1, Float a2) { return 0; }

    virtual void AbortSynchronisation() { }

    virtual U32 New_NetObjet(U32 a1, U8* a2) { return 0; }

    virtual U32 NewLink_NetObjet(U32 a1, U8* a2, U32 a3) { return 0; }

    virtual void AbortLink_NetObjet(U32 a1) { }

    virtual void SetDataSegment_NetObjet(U32 a1, U8* a2) { }

    virtual void Release_NetObjet(U32 a1) { }

    virtual void Update_NetObjet(U32 a1) { }

    virtual void Update_NetObjet(U32 a1, U32 a2) { }

    virtual U32 Migrate_NetObjet(U32 a1, U32 a2) { return 3; }

    virtual U32 IsMaster_NetObjet(U32 a1) { return 1; }

    virtual U32 CanMigrate_NetObjet(U32 a1) { return 0; }

    virtual U32 Exist_NetObjet(U32 a1) { return 0; }

    virtual U32 GetUserHandle_NetObjet(U32 a1) { return 0; }

    virtual void InitScanForNewSlave_NetObjet() { }

    virtual void ScanForNewSlave_NetObjet(U32& a1, U32& a2) {
        a1 = 0;
    }
};

#endif // _NETMANAGER_VIRTUAL_Z_H_
