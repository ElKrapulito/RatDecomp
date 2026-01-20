#ifndef _GRAPH_Z_H_
#define _GRAPH_Z_H_
#include "Object_Z.h"

class Graph_Z : public Object_Z {
public:
    virtual ~Graph_Z();
    virtual void Load(void** i_Data);
    virtual void Draw(DrawInfo_Z& i_DrawInfo, ObjectDatas_Z* i_Data);

    static BaseObject_Z* NewObject() { return NewL_Z(31) Graph_Z; }
};

#endif // _GRAPH_Z_H_
