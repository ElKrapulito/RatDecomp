#include "ABC_Agent.h"
#include "ABC_ScriptManager.h"
#include "Program_Z.h"

ABC_Behavior* ABC_Agent::GetNewBehavior() {
    return gData.ScriptMgr->GetNewBehavior();
}

void ABC_Agent::ReleaseBehaviors() {
    gData.ScriptMgr->ReleaseBehaviors(m_BehaviorListHead);
    m_BehaviorListHead = NULL;
}

ABC_CategoryHolder* ABC_Agent::GetNewCategoryHolder() {
    return gData.ScriptMgr->GetNewCategoryHolder();
}

void ABC_Agent::ReleaseCategoryHolders(ABC_CategoryHolder* i_CategoryHolder) {
    gData.ScriptMgr->ReleaseCategoryHolders(i_CategoryHolder);
}

ABC_BehaviorHolder* ABC_Agent::GetNewBehaviorHolder() {
    return gData.ScriptMgr->GetNewBehaviorHolder();
}
