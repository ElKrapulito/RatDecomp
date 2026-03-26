#ifndef _MOVIE_Z_H_
#define _MOVIE_Z_H_
#include "DynArray_Z.h"
#include "Viewport_Z.h"
#include "MovieManipulator_ZHdl.h"
#include "Color_Z.h"

Bool Cmd_PlayMovie();

enum MovieError {
    MOVIE_ERROR_NONE = 0,
    MOVIE_ERROR_UNKNOWN = 1
};

class Movie_Z {
    Bool m_UnkBool_0x0;
    U32 m_UnkU32_0x4;
    U32 m_UnkU32_0x8;
    U32 m_UnkU32_0xC;
    U32 m_UnkU32_0x10;
    U32 m_UnkU32_0x14;
    MovieManipHdlDA m_MovieManipHdls;
    Float m_PlaySpeed;
    Color m_Color;

public:
    virtual ~Movie_Z();                                          /* 0x08 */
    virtual Bool Init();                                         /* 0x0C */
    virtual void Shut();                                         /* 0x10 */
    virtual void Play(const Char* i_FilePath, U32 i_Flags);      /* 0x14 */
    virtual void Pause(Bool i_Pause);                            /* 0x18 */
    virtual void Skip(Float i_SkipTime);                         /* 0x1C */
    virtual void GetExtension();                                 /* 0x20 */
    virtual void PlayMovie(const Char* i_FilePath, U32 i_Flags); /* 0x24 */
    virtual void StopMovie();                                    /* 0x28 */
    virtual void SwitchFullScreen();                             /* 0x2C */
    virtual void DisplayChanged();                               /* 0x30 */
    virtual void PaintVideo();                                   /* 0x34 */
    virtual void MarkHandles();                                  /* 0x38 */
    virtual void Update(Float i_DeltaTime);                      /* 0x3C */
    virtual void Draw(DrawInfo_Z& i_DrawInfo);                   /* 0x40 */
    virtual void RemoveManip(const MovieManipHdl& i_ManipHdl);   /* 0x44 */

    Bool IsPlaying();
    U32 GetLastError();
};

void* BinkAllocate(U32 i_Bytes);
void BinkFree(void* i_Ptr);

#endif
