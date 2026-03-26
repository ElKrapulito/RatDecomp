#ifndef _GRAPH_ZHDL_H_
#define _GRAPH_ZHDL_H_

#include "Object_ZHdl.h"

class Graph_Z;

HANDLE_Z(Graph_Z, Object_Z);
typedef DynArray_Z<Graph_ZHdl, 8> Graph_ZHdlDA;

#endif
