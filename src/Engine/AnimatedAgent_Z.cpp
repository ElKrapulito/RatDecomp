#include "AnimatedAgent_Z.h"

BEGIN_INIT_AGENT_CLASS(AnimatedAgent_Z, AnimatedMsgAgent_Z)
END_INIT_AGENT_CLASS

AnimatedAgent_Z::AnimatedAgent_Z() {
    EnableFlag(FL_AGENT_ANIMATED | FL_AGENT_ANIMATED_SEQ | FL_AGENT_UNK_0x400 | FL_AGENT_NEED_SOUND);
    m_ClassAnimationIndex = -1;
}
