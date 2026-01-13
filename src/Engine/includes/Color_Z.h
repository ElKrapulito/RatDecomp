#ifndef _COLOR_Z_H_
#define _COLOR_Z_H_
#include "Types_Z.h"

class Color {

public:
    Color() { }

    Color(Float i_Red, Float i_Green, Float i_Blue, Float i_Alpha);

    Color& operator=(Color const& i_Color) {
        r = i_Color.r;
        g = i_Color.g;
        b = i_Color.b;
        a = i_Color.a;
        return *this;
    }

    void Set(Float i_Red = 1.0f, Float i_Green = 1.0f, Float i_Blue = 1.0f, Float i_Alpha = 1.0f) {
        r = i_Red;
        g = i_Green;
        b = i_Blue;
        a = i_Alpha;
    }

    Float r;
    Float g;
    Float b;
    Float a;
};

#endif
