#include "LodDynAgent_Z.h"

BEGIN_INIT_AGENT_CLASS(LodDynAgent_Z, AnimatedAgent_Z)
END_INIT_AGENT_CLASS

LodDynAgent_Z::LodDynAgent_Z() {
    EnableFlag(FL_AGENT_LODDYN);
    DisableFlag(FL_AGENT_ANIMATED_SEQ);
}
