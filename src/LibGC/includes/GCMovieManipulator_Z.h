#ifndef _GCMOVIEMANIPULATOR_Z_H_
#define _GCMOVIEMANIPULATOR_Z_H_
#include "MovieManipulator_Z.h"
#include "binktextures.h"

class GCMovieManipulator_Z : public MovieManipulator_Z {
    friend class Movie_Z;

public:
    virtual ~GCMovieManipulator_Z();                 /* 0x08 */
    virtual void Draw(const DrawInfo_Z& i_DrawInfo); /* 0x0C */
    virtual void Open(const Char* a1, U32 a2);       /* 0x10 */
    virtual void Stop(bool a1);                      /* 0x14 */
    virtual void SetError(U32 a1);                   /* 0x18 */
    virtual void HandleBinkCopyToBuffer();           /* 0x1C */

private:
    BINKTEXTURESET m_TextureSet;
    Bool m_RestoreVsync;
};

#endif // _GCMOVIEMANIPULATOR_Z_H_
