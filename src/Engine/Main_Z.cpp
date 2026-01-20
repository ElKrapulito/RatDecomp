#include "Program_Z.h"
#include "Fonts_Z.h"
#include "ClassManager_Z.h"
#include "World_Z.h"
#include "GenWorld_Z.h"
#include "SubWorld_Z.h"
#include "Object_Z.h"
#include "Points_Z.h"
#include "Node_Z.h"
#include "Bitmap_Z.h"
#include "Spline_Z.h"
#include "SplineZone_Z.h"
#include "Occluder_Z.h"
#include "CameraZone_Z.h"
#include "Light_Z.h"
#include "LightData_Z.h"
#include "HFog_Z.h"
#include "Omni_Z.h"
#include "Emiter_Z.h"
#include "Tree_Z.h"
#include "CollisionVol_Z.h"
#include "Camera_Z.h"
#include "Game_Z.h"
#include "GameObj_Z.h"
#include "MaterialAnim_Z.h"
#include "MaterialObj_Z.h"
#include "AnimFrame_Z.h"
#include "Rtc_Z.h"
#include "Graph_Z.h"
#include "UserDefine_Z.h"
#include "Txt_Z.h"
#include "Animation_Z.h"
#include "PlayAnim_Z.h"
#include "DynamicAnim2_Z.h"
#include "SequenceAnim_Z.h"
#include "SequenceMixAnim_Z.h"
#include "CameraOccluder_Z.h"
#include "CameraStream_Z.h"
#include "CameraEngineZone_Z.h"
#include "ObjectMove_Z.h"
#include "ObjectThrow_Z.h"
#include "LodMove_Z.h"
#include "VehiculeMove_Z.h"
#include "ObjectsGame_Z.h"
#include "ObjectsGameClip_Z.h"
#include "Menu3D_Z.h"
#include "Menu2D_Z.h"
#include "RtcPlayer_Z.h"
#include "Ghost_Z.h"
#include "SelfRunning_Z.h"
#include "InGameDatas_Z.h"
#include "SuperSpray_Z.h"
#include "InGameObjectsManipulator_Z.h"
#include "StreamFile_Z.h"
#include "ConsoleInterp_Z.h"
#include "ObjectsMove_Z.h"
#include "ObjectsBounce_Z.h"
#include "ObjectsBreak_Z.h"

Char WhereAmI[128];
Bool InMainLoop;

void _CoreMainLoop() {
    static Float dTime;
    static Bool init;
}

void RegisterClasses() {
    REGISTER_CLASS("ResourceObject_Z", "BaseObject_Z", NULL);
    REGISTER_CLASS("World_Z", "ResourceObject_Z", World_Z::NewObject);
    REGISTER_CLASS("GenWorld_Z", "Object_Z", GenWorld_Z::NewObject);
    REGISTER_CLASS("SubWorld_Z", "ResourceObject_Z", SubWorld_Z::NewObject);
    REGISTER_CLASS("Object_Z", "ResourceObject_Z", NULL);
    REGISTER_CLASS("ObjectData_Z", "ResourceObject_Z", NULL);
    REGISTER_CLASS("Points_Z", "Object_Z", Points_Z::NewObject);
    REGISTER_CLASS("Node_Z", "Object_Z", Node_Z::NewObject);
    REGISTER_CLASS("Bitmap_Z", "Object_Z", Bitmap_Z::NewObject);
    REGISTER_CLASS("Spline_Z", "Object_Z", Spline_Z::NewObject);
    REGISTER_CLASS("SplineZone_Z", "Object_Z", SplineZone_Z::NewObject);
    REGISTER_CLASS("Occluder_Z", "SplineZone_Z", Occluder_Z::NewObject);
    REGISTER_CLASS("CameraZone_Z", "SplineZone_Z", CameraZone_Z::NewObject);
    REGISTER_CLASS("Light_Z", "Object_Z", Light_Z::NewObject);
    REGISTER_CLASS("LightData_Z", "ObjectData_Z", LightData_Z::NewObject);
    REGISTER_CLASS("HFog_Z", "Object_Z", HFog_Z::NewObject);
    REGISTER_CLASS("HFogData_Z", "ObjectData_Z", HFogData_Z::NewObject);
    REGISTER_CLASS("Omni_Z", "Object_Z", Omni_Z::NewObject);
    REGISTER_CLASS("Emiter_Z", "Object_Z", Emiter_Z::NewObject);
    REGISTER_CLASS("Tree_Z", "Object_Z", Tree_Z::NewObject);
    REGISTER_CLASS("CollisionVol_Z", "Object_Z", CollisionVol_Z::NewObject);
    REGISTER_CLASS("Camera_Z", "Object_Z", Camera_Z::NewObject);
    REGISTER_CLASS("Game_Z", "Object_Z", Game_Z::NewObject);
    REGISTER_CLASS("GameObj_Z", "Object_Z", GameObj_Z::NewObject);
    REGISTER_CLASS("MaterialAnim_Z", "Material_Z", MaterialAnim_Z::NewObject);
    REGISTER_CLASS("MaterialObj_Z", "ResourceObject_Z", MaterialObj_Z::NewObject);
    REGISTER_CLASS("Fonts_Z", "ResourceObject_Z", Fonts_Z::NewObject);
    REGISTER_CLASS("AnimFrame_Z", "ResourceObject_Z", AnimFrame_Z::NewObject);
    REGISTER_CLASS("Rtc_Z", "ResourceObject_Z", Rtc_Z::NewObject);
    REGISTER_CLASS("Graph_Z", "ResourceObject_Z", Graph_Z::NewObject);
    REGISTER_CLASS("UserDefine_Z", "ResourceObject_Z", UserDefine_Z::NewObject);
    REGISTER_CLASS("PointsData_Z", "ObjectData_Z", NULL);
    REGISTER_CLASS("Txt_Z", "ResourceObject_Z", Txt_Z::NewObject);
    REGISTER_CLASS("Animation_Z", "ResourceObject_Z", Animation_Z::NewObject);
    REGISTER_CLASS_TYPE("Animation_Z", FL_CLASS_STREAM_XRAM, FL_CLASS_NONE);
    RegisterLowLevelClasses();
    REGISTER_CLASS("Manipulator_Z", "BaseObject_Z", NULL);
    REGISTER_CLASS("ManipulatorDraw_Z", "Manipulator_Z", NULL);
    REGISTER_CLASS("PlayAnim_Z", "Manipulator_Z", PlayAnim_Z::NewObject);
    REGISTER_CLASS("DynamicAnim_Z", "Manipulator_Z", NULL);
    REGISTER_CLASS("DynamicAnim2_Z", "DynamicAnim_Z", DynamicAnim2_Z::NewObject);
    REGISTER_CLASS("SequenceAnim_Z", "BaseObject_Z", SequenceAnim_Z::NewObject);
    REGISTER_CLASS("SequenceMixAnim_Z", "SequenceAnim_Z", SequenceMixAnim_Z::NewObject);
    REGISTER_CLASS("CameraOccluder_Z", "Manipulator_Z", CameraOccluder_Z::NewObject);
    REGISTER_CLASS("CameraStream_Z", "Manipulator_Z", CameraStream_Z::NewObject);
    REGISTER_CLASS("CameraEngine_Z", "Manipulator_Z", NULL);
    REGISTER_CLASS("CameraEngineZone_Z", "CameraEngine_Z", CameraEngineZone_Z::NewObject);
    REGISTER_CLASS("ObjectMove_Z", "Manipulator_Z", ObjectMove_Z::NewObject);
    REGISTER_CLASS("ObjectThrow_Z", "ObjectMove_Z", ObjectThrow_Z::NewObject);
    REGISTER_CLASS("LodMove_Z", "ObjectThrow_Z", LodMove_Z::NewObject);
    REGISTER_CLASS("VehiculeMove_Z", "LodMove_Z", VehiculeMove_Z::NewObject);
    REGISTER_CLASS("ObjectsGame_Z", "ObjectGame_Z", ObjectsGame_Z::NewObject);
    REGISTER_CLASS("ObjectsGameClip_Z", "ObjectGame_Z", ObjectsGameClip_Z::NewObject);
    REGISTER_CLASS("Menu_Z", "ManipulatorDraw_Z", Menu3D_Z::NewObject);
    REGISTER_CLASS("Menu3D_Z", "Menu_Z", Menu3D_Z::NewObject);
    REGISTER_CLASS("Menu2D_Z", "Menu_Z", Menu2D_Z::NewObject);
    REGISTER_CLASS("RtcPlayer_Z", "Manipulator_Z", RtcPlayer_Z::NewObject);
    REGISTER_CLASS("Ghost_Z", "Manipulator_Z", Ghost_Z::NewObject);
    REGISTER_CLASS("SelfRunning_Z", "Manipulator_Z", SelfRunning_Z::NewObject);
    REGISTER_CLASS("InGameDatas_Z", "ManipulatorDraw_Z", InGameDatas_Z::NewObject);
    REGISTER_CLASS("PlayParticles_Z", "Manipulator_Z", NULL);
    REGISTER_CLASS("SuperSpray_Z", "PlayParticles_Z", SuperSpray_Z::NewObject);
    REGISTER_CLASS("InGameObjectsManipulator_Z", "Manipulator_Z", InGameObjectsManipulator_Z::NewObject);
    REGISTER_CLASS("StreamFile_Z", "Manipulator_Z", StreamFile_Z::NewObject);
    REGISTER_CLASS("ConsoleInterp_Z", "Manipulator_Z", ConsoleInterp_Z::NewObject);
    REGISTER_CLASS("ObjectsMove_Z", "ObjectMove_Z", ObjectsMove_Z::NewObject);
    REGISTER_CLASS("ObjectsBounce_Z", "ObjectsMove_Z", ObjectsBounce_Z::NewObject);
    REGISTER_CLASS("ObjectsBreak_Z", "ObjectsBounce_Z", ObjectsBreak_Z::NewObject);
    RegisterGameClasses();
}
