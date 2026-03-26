#ifndef _MOVIEMANIPULATOR_ZHDL_H_
#define _MOVIEMANIPULATOR_ZHDL_H_
#include "ManipulatorDraw_ZHdl.h"
#include "MovieManipulator_Z.h"

HANDLE_Z(MovieManipulator_Z, ManipulatorDraw_Z);

#ifdef __MWERKS__ // TODO: Should check for GC instead of metrowerks

#include "GCMovieManipulator_Z.h"
HANDLE_Z(GCMovieManipulator_Z, ManipulatorDraw_Z);

typedef GCMovieManipulator_ZHdl MovieManipHdl;

#else

typedef MovieManipulator_ZHdl MovieManipHdl;

#endif

typedef DynArray_Z<MovieManipHdl, 8> MovieManipHdlDA;

#endif
