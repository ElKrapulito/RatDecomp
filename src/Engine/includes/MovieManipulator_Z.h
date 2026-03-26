#ifndef _MOVIEMANIPULATOR_Z_H_
#define _MOVIEMANIPULATOR_Z_H_
#include "Manipulator_Z.h"
#include "Math_Z.h"
#include "Types_Z.h"
#include "bink.h"

class Movie_Z;

class MovieManipulator_Z : public ManipulatorDraw_Z {
    friend class Movie_Z;

public:
    virtual ~MovieManipulator_Z();                          /* 0x08 */
    virtual void Update(Float i_DeltaTime);                 /* 0x0C */
    virtual void Draw(const DrawInfo_Z& i_DrawInfo);        /* 0x10 */
    virtual void Open(const Char* i_FilePath, U32 i_Flags); /* 0x14 */
    virtual void Pause(bool i_Pause);                       /* 0x18 */
    virtual void Stop(bool i_Restart);                      /* 0x1C */
    virtual void Retry();                                   /* 0x20 */
    virtual void Skip(Float i_SkipTime);                    /* 0x24 */
    virtual void IsAnyButton();                             /* 0x28 */
    virtual void SetError(U32 i_ErrorCode);                 /* 0x2C */
    virtual void HandleBinkCopyToBuffer();                  /* 0x30 */

private:
    S32 m_Width;
    S32 m_Height;
    Vec2f m_FrameStart; // Start point of the movie area on the screen
    Vec2f m_FrameEnd;   // End point of the movie area on the screen
    Bool m_AttemptingSkip;
    Vec2f m_BlackBarsTopLeftPoints[2];     // Start points of each black bar (Either top/bottom or left/right depending on the screen aspect ratio)
    Vec2f m_BlackBarsBottomRightPoints[2]; // End points of each black bar (Either top/bottom or left/right depending on the screen aspect ratio)
    U32 m_PlayState;
    S32 m_Flag;
    Color m_Color;      // Base color to apply to the movie
    Color m_FinalColor; // Final color to apply to the movie after calculating fade out
    Bool m_BeingSkipped;
    Float m_SkipMaxTime; // Time it takes for the movie to be fully faded out when skipping
    Float m_SkipTimer;   // Timer used to calculate the fade out effect when skipping
    Float m_PlayTime;
    Float m_PlaySpeed;
    S32 m_Language; // Probably used for subtitles
    U32 m_ErrorCode;
    HBINK m_Bink; // Bink handle
    S32 m_BinkShouldSkip;
    S32 m_CurrentFrame;
    String_Z<ARRAY_CHAR_MAX> m_FilePath;
};

#endif // _MOVIEMANIPULATOR_Z_H_
