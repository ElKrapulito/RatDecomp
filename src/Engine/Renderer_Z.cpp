#include "Renderer_Z.h"
#include "Node_ZHdl.h"
#include "SystemObject_Z.h"
#include "Types_Z.h"
#include "Math_Z.h"
#include "Node_Z.h"
#include "Camera_Z.h"
#include "Console_Z.h"
#include "Program_Z.h"
#pragma dont_inline on

Renderer_Z::Renderer_Z() {
    REGISTERCOMMAND("SetSplitType", SetSplitType);
    REGISTERCOMMAND("SetWorldToSplit", SetWorldToSplit);
    REGISTERCOMMAND("SetLodRender", SetLodRender);
    REGISTERCOMMANDC("SetLIghtingType", SetLIghtingType, " [Pixel=0 Vertex=1]");
    REGISTERCOMMANDC("SetLodTexture", SetLOdTexture, "[Max=0,Min=max(level-1)]");
    REGISTERCOMMANDC("SetMaxAnisotropy", SetMAxAnisotropy, "[Min=1,Max=caps]");
    REGISTERCOMMANDC("SetTExtureFiltering", SetTExtureFiltering, "[Bilinear=0,Trilinear=1,Anisotropic=2]");
    REGISTERCOMMANDC("FitOnObject", FitOnObject, " [ObjectName] [VpId=0]");
    REGISTERCOMMANDC("DisplayImage", DisplayImage, " [DB ImageName]");
    REGISTERCOMMANDC("MakeAVI", MakeAvi, "FrameBuffer - Fps");
    REGISTERCOMMAND("CloseAVI", CloseAvi);
    REGISTERCOMMAND("StartRenderBench", StartRenderBench);
    m_ActiveViewport = 0;
    m_EffectFlag = FL_EFFECT_BLOOM | FL_EFFECT_VSYNC;
    m_DefaultScreenRatio = RATIO_SCREEN_STANDARD;
    EnableEffectFlag(FL_EFFECT_CLEAR_SCREEN);
    m_UnkRtcFXColor.Set(0.5f, 0.5f, 0.5f, 1.0f);
    m_UnkVec3f_001_0x76c = Vec3f(0.0f, 0.0f, 1.0f);
    m_UnkVec3f_100_0x778 = Vec3f(1.0f, 0.0f, 0.0f);
    SetLodPatchMax(8);
    SetLodPatchMin(1);
    SetLodPatchDist(-1.0f);
    SetLodDist(10.0f);
    SetLodFadeDist(10.0f);
    SetLodShadowFadeDist(10.0f);
    SetParticlesFadeDist(20.0f);
    SetDOF_Depth(34.0f);
    SetLightingType(0);
    SetTextureFiltering(0);
    SetTextureQuality(0);
    SetMaxAnisotropy(1);
    SetMultisampleType(0);
    m_LightFactorX = 1.0f;
    m_LightFactorY = 1.0f;
    m_LightFactorZ = 1.0f;
    m_UnkBoolFalse_0x73C = FALSE;
    m_SpecialVisionColor1.Set(0.0f, 0.03137255f, 0.15686275f);
    m_SpecialVisionColor2.Set(0.0f, 0.0f, 0.0f);
    m_SpecialVisionColor3.Set(1.0f, 1.0f, 0.0f);
    m_SpecialVisionColor4.Set(1.0f, 1.0f, 0.0f);
    m_UnkParam_0 = 0;
    m_VSize = 0.0f;
    m_HSize = 0.0f;
    m_VCenter = 0.0f;
    m_HCenter = 0.0f;
    m_SizeY = 100.0f;
    m_SizeX = 100.0f;
    m_UnkBoolFalse_0x704 = FALSE;
    m_CurFps = 30.0f;
    m_CpuTargetMsOrFps = 30.0f;
    m_GpuTargetMsOrFps = 30.0f;
    m_UnkFloat_0_0x8c4 = 0.0f;
    m_UnkFloat_0_0x8bc = 0.0f;
    m_DisplayCacheStateUpdateTimer = 0.0f;
    m_GblDmaTotalNb = 0;
    m_GblDmaMaxInUseNb = 0;
    m_GblDmaInUseNb = 0;
    m_GifDmaTotalNb = 0;
    m_GifDmaMaxInUseNb = 0;
    m_GifDmaInUseNb = 0;
    m_DisplayFpsUpdateTimer = 0.0f;
    m_CpuFps = 60.0f;
    m_GpuFps = 60.0f;
    m_Fps = 60.0f;
    m_ClearColor.Set(0.0, 0.0f, 0.0f, 1.0f);
    m_PerlinArray3D.Generate(0.5f, 1.0f, 16);
}

Renderer_Z::~Renderer_Z() {
}

Bool Renderer_Z::Init(S32 i_SizeX, S32 i_SizeY) {
    SetSize(i_SizeX, i_SizeY);
    SwitchScreen(screen_standard);
    m_MipmapedGaussConvol = Compute_MipmapedGaussConvol(&m_MipmapGC, i_SizeX, i_SizeY, 14.0f, 1.0f);
    return TRUE;
}

void Renderer_Z::Shut() {
    for (S32 i = 0; i < m_VertexBufferPtrDA.GetSize(); i++) {
        m_VertexBufferPtrDA[i]->Release();
        Delete_Z m_VertexBufferPtrDA[i];
    }
    for (S32 i = 0; i < m_IndexBufferPtrDA.GetSize(); i++) {
        m_IndexBufferPtrDA[i]->Release();
        Delete_Z m_IndexBufferPtrDA[i];
    }
    m_VertexBufferPtrDA.Flush();
    m_IndexBufferPtrDA.Flush();
}

void Renderer_Z::SetSize(S32 i_SizeX, S32 i_SizeY) {
    m_SizeX = i_SizeX;
    m_SizeY = i_SizeY;
    m_Viewports[6].SetPosAndSize(0, 0, i_SizeX, i_SizeY);
    m_Viewports[6].SetRenderer(this);
}

void Renderer_Z::InitViewport(U32 i_NbViewports) {
    S32 l_SizeX;
    S32 l_SizeY;
    switch (i_NbViewports) {
        case 1:
            m_NbViewports = 1;
            m_Viewports[0].SetPosAndSize(0, 0, m_SizeX, m_SizeY);
            break;
        case 2:
            m_NbViewports = 2;
            if (GetScreenRatio() == RATIO_SCREEN_WIDESCREEN) {
                l_SizeX = m_SizeX >> 1;
                m_Viewports[0].SetPosAndSize(0, 0, l_SizeX - 1, m_SizeY);
                m_Viewports[1].SetPosAndSize(l_SizeX + 1, 0, l_SizeX - 1, m_SizeY);
            }
            else {
                S32 l_SizeY = m_SizeY >> 1;
                m_Viewports[0].SetPosAndSize(0, 0, m_SizeX, l_SizeY - 1);
                m_Viewports[1].SetPosAndSize(0, l_SizeY + 1, m_SizeX, l_SizeY - 1);
            }
            break;
        case 3: {
            m_NbViewports = 3;
            S32 l_SizeX = m_SizeX >> 1;
            S32 l_SizeY = m_SizeY >> 1;
            m_Viewports[0].SetPosAndSize(0, 0, l_SizeX - 1, l_SizeY - 1);
            m_Viewports[1].SetPosAndSize(l_SizeX + 1, 0, l_SizeX - 1, l_SizeY - 1);
            m_Viewports[2].SetPosAndSize(0, l_SizeY + 1, l_SizeX - 1, l_SizeY - 1);
        } break;
        case 4: {
            m_NbViewports = 4;
            S32 l_SizeX = m_SizeX >> 1;
            S32 l_SizeY = m_SizeY >> 1;
            m_Viewports[0].SetPosAndSize(0, 0, l_SizeX - 1, l_SizeY - 1);
            m_Viewports[1].SetPosAndSize(l_SizeX + 1, 0, l_SizeX - 1, l_SizeY - 1);
            m_Viewports[2].SetPosAndSize(0, l_SizeY + 1, l_SizeX - 1, l_SizeY - 1);
            m_Viewports[3].SetPosAndSize(l_SizeX + 1, l_SizeY + 1, l_SizeX - 1, l_SizeY - 1);
            break;
        }
    }
    for (S32 i = 0; i < m_NbViewports; i++) {
        m_Viewports[i].SetRenderer(this);
    }
}

void Renderer_Z::SetActiveViewport(S32 i_ViewportId) {
    SetCurrentFogColor(VEC3F_NULL);
    FlushActiveViewport();
    m_ActiveViewport = i_ViewportId;
    Viewport_Z& l_Viewport = GetViewport(i_ViewportId);
    m_HSize = l_Viewport.GetHSize();
    m_VSize = l_Viewport.GetVSize();
    m_HCenter = l_Viewport.GetHCenter();
    m_VCenter = l_Viewport.GetVCenter();
    Node_Z* l_CameraNode = GetViewport(i_ViewportId).GetCamera();
    if (l_CameraNode) {
        Camera_Z* l_Camera = (Camera_Z*)(l_CameraNode->GetObject(FALSE));
        l_Camera->UpdateInverseWorldMatrix(l_CameraNode);
    }
}

void Renderer_Z::FlushActiveViewport() { }

void Renderer_Z::Draw(S32 i_ViewportId, Float i_DeltaTime) {
    SetActiveViewport(i_ViewportId);
    DrawInfo_Z l_DrawInfo;
}

// TODO: Implement commands below

Bool SetSplitType() {
    return TRUE;
}

Bool SetWorldToSplit() {
    return TRUE;
}

Bool SetLodRender() {
    return TRUE;
}

Bool SetLIghtingType() {
    return TRUE;
}

Bool SetLOdTexture() {
    return TRUE;
}

Bool SetMAxAnisotropy() {
    return TRUE;
}

Bool SetTExtureFiltering() {
    return TRUE;
}

Bool FitOnObject() {
    return TRUE;
}

Bool DisplayImage() {
    return TRUE;
}

Bool MakeAvi() {
    return TRUE;
}

Bool CloseAvi() {
    return TRUE;
}

Bool StartRenderBench() {
    return TRUE;
}

#pragma dont_inline reset
