#ifndef _ERRORLANGUAGE_Z_H_
#define _ERRORLANGUAGE_Z_H_
#include "Types_Z.h"
#include "Language_Z.h"

enum SystemHdlError {
    error_none = 0,
    error_unknown = 1,
    error_eight = 8,
    type_error_count = 13,
};

void InitTabError();
const Char* GetStringTabError(LanguageEnum_Z i_Enum, SystemHdlError i_Error);

#endif // _ERRORLANGUAGE_Z_H_
