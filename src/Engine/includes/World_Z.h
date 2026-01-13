#ifndef _WORLD_Z_H_
#define _WORLD_Z_H_
#include "ResourceObject_Z.h"
#include "Node_ZHdl.h"
#include "OccludedSeadHandle_Z.h"

class World_Z : public ResourceObject_Z {
public:
    virtual ~World_Z();
    virtual void Load(void** i_Data);
    virtual void EndLoad();
    virtual void AfterEndLoad();
    virtual void LoadDone();
    virtual Bool MarkHandles();

    Node_ZHdl GetNodeByName(const Name_Z& i_Name) const;
	void Update(Float i_DeltaTime);

	inline OccludedSeadHandle_Z& GetSeadDisplay() {
		return m_SeadDisplay;
	}

	inline SeadHandle_Z& GetSeadCollide() {
		return m_SeadCollide;
	}

	inline Node_ZHdl& GetRoot() {
		return m_RootNodeHdl;
	}

private:
	U32 m_Flag;
	S32 m_NbVp;
	S32 m_FirstPlayerVpId;
	BaseObject_ZHdl m_WarpHdl; // TODO: It's a Warp_ZHdl
	BaseObject_ZHdl m_UnkHdl_0x24; // TODO: Unknown type but check correct inheritance
	BaseObject_ZHdl m_GenWorldHdl; // TODO: It's a GenWorld_ZHdl
	BaseObject_ZHdl m_GameObjHdl; // TODO: It's a GameObj_ZHdl
	Node_ZHdl m_RootNodeHdl;
	BaseObject_ZHdl m_MainHFogDataHdl; // TODO: It's a HFogData_ZHdl
	OccludedSeadHandle_Z m_SeadDisplay;
	SeadHandle_Z m_SeadCollide;
	// TODO: More members
};

#endif // _WORLD_Z_H_
