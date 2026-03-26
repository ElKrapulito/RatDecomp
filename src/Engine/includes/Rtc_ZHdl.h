#ifndef _RTC_ZHDL_H_
#define _RTC_ZHDL_H_

#include "ResourceObject_ZHdl.h"

class Rtc_Z;
class ResourceObject_Z;
HANDLE_Z(Rtc_Z, ResourceObject_Z);
typedef DynArray_Z<Rtc_ZHdl, 4> Rtc_ZHdlDA;

#endif
