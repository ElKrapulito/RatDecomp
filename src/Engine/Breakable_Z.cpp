#include "Breakable_Z.h"

BEGIN_INIT_AGENT_CLASS(Breakable_Z, Throwable_Z)
END_INIT_AGENT_CLASS

Breakable_Z::Breakable_Z() {
    EnableFlag(FL_AGENT_BREAKABLE);
}
