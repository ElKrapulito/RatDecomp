#ifndef _LANGUAGE_Z_H_
#define _LANGUAGE_Z_H_
#include "Types_Z.h"
#include "Name_Z.h"
#include "DynArray_Z.h"

enum LanguageEnum_Z {
    LANG_NONE = -1,
    LANG_JAPANESE_Z = 0,
    LANG_ENGLISH_Z = 1,
    LANG_FRENCH_Z = 2,
    LANG_SPANISH_Z = 3,
    LANG_GERMAN_Z = 4,
    LANG_ITALIAN_Z = 5,
    LANG_DUTCH_Z = 6,
    LANG_COUNT = 7
};

U8 GetCharIdFromText(Char* i_Text);
Bool TT(int i_Id);
Bool FreeLanguage();
// TODO: Make enum def.
int SetLanguage(int i_TextLang, int i_SoundLang, int i_MovieLang);
LanguageEnum_Z GetLanguage();

struct Language_Z {
    /* $VIOLET: These might be defined in the cpp and not in this struct.*/
    static DynArray_Z<Char, 256> LangTextTxt;
    static int LangForMpeg; //$VIOLET: TODO: Make enum def.
    static Char CurChar;
};
#endif
