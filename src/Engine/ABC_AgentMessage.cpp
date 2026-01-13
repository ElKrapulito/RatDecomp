#include "ABC_Agent.h"
#include "ABC_ScriptManager.h"
#include "Program_Z.h"

ABC_Message* ABC_Agent::GetNewMessage() {
    return gData.ScriptMgr->GetNewMessage();
}

void ABC_Agent::ReleaseMessageList() {
    gData.ScriptMgr->ReleaseMessages(m_MessageListHead);
    m_MessageListHead = NULL;
    m_MessageListTail = NULL;
}

void ABC_Agent::SwapMessageList() {
    m_MessageListHead = m_BufferMessageListHead;
    m_MessageListTail = m_BufferMessageListTail;
    m_BufferMessageListHead = NULL;
    m_BufferMessageListTail = NULL;
}

void ABC_Agent::RemoveMessageFromList(ABC_Message* i_PrevMsg, ABC_Message* i_Msg) {
    if (i_PrevMsg) {
        i_PrevMsg->m_Next = i_Msg->m_Next;
    }
    else {
        m_MessageListHead = i_Msg->m_Next;
    }
    if (i_Msg->m_Next == NULL) {
        m_MessageListTail = i_PrevMsg;
    }
    gData.ScriptMgr->ReleaseMessage(i_Msg);
}

void ABC_Agent::RemoveMessageFromBufferList(ABC_Message* i_PrevMsg, ABC_Message* i_Msg) {
    if (i_PrevMsg) {
        i_PrevMsg->m_Next = i_Msg->m_Next;
    }
    else {
        m_BufferMessageListHead = i_Msg->m_Next;
    }
    if (i_Msg->m_Next == NULL) {
        m_BufferMessageListTail = i_PrevMsg;
    }
    gData.ScriptMgr->ReleaseMessage(i_Msg);
}

Bool ABC_Agent::FlushMessage(abc_message i_Msg) {
    ABC_Message* l_Msg = m_MessageListHead;
    ABC_Message* l_Prev = NULL;
    while (l_Msg) {
        if (i_Msg == l_Msg->m_Id) {
            RemoveMessageFromList(l_Prev, l_Msg);
            return TRUE;
        }
        l_Prev = l_Msg;
        l_Msg = l_Msg->m_Next;
    }
    l_Msg = m_BufferMessageListHead;
    l_Prev = NULL;
    while (l_Msg) {
        if (i_Msg == l_Msg->m_Id) {
            RemoveMessageFromBufferList(l_Prev, l_Msg);
            return TRUE;
        }
        l_Prev = l_Msg;
        l_Msg = l_Msg->m_Next;
    }
    return FALSE;
}

Bool ABC_Agent::FlushEveryMessage(abc_message i_Msg, ABC_Agent* i_Sender) {
    ABC_Message* l_Msg = m_MessageListHead;
    ABC_Message* l_Prev = NULL;
    Bool l_Flushed = FALSE;
    while (l_Msg) {
        if (i_Msg == l_Msg->m_Id) {
            if (i_Sender && i_Sender != l_Msg->m_Sender) {
                l_Prev = l_Msg;
                l_Msg = l_Msg->m_Next;
                continue;
            }
            l_Flushed = TRUE;
            RemoveMessageFromList(l_Prev, l_Msg);
            if (!l_Prev) {
                l_Msg = m_MessageListHead;
            }
            else {
                l_Msg = l_Prev->m_Next;
            }
        }
        else {
            l_Prev = l_Msg;
            l_Msg = l_Msg->m_Next;
        }
    }
    l_Msg = m_BufferMessageListHead;
    l_Prev = NULL;
    while (l_Msg) {
        if (i_Msg == l_Msg->m_Id) {
            if (i_Sender && i_Sender != l_Msg->m_Sender) {
                l_Prev = l_Msg;
                l_Msg = l_Msg->m_Next;
                continue;
            }
            l_Flushed = TRUE;
            RemoveMessageFromBufferList(l_Prev, l_Msg);
            if (!l_Prev) {
                l_Msg = m_BufferMessageListHead;
            }
            else {
                l_Msg = l_Prev->m_Next;
            }
        }
        else {
            l_Prev = l_Msg;
            l_Msg = l_Msg->m_Next;
        }
    }
    return l_Flushed;
}

Bool ABC_Agent::FlushAllMessages(Bool i_FlushTimedMessages) {
    ABC_Message* l_Msg = m_MessageListHead;
    ABC_Message* l_NextMsg;
    Bool result = (NULL != m_MessageListHead) || (NULL != m_BufferMessageListHead);
    while (l_Msg) {
        l_NextMsg = l_Msg->m_Next;
        gData.ScriptMgr->ReleaseMessage(l_Msg);
        l_Msg = l_NextMsg;
    }
    m_MessageListHead = NULL;
    m_MessageListTail = NULL;
    l_Msg = m_BufferMessageListHead;
    while (l_Msg) {
        l_NextMsg = l_Msg->m_Next;
        gData.ScriptMgr->ReleaseMessage(l_Msg);
        l_Msg = l_NextMsg;
    }
    m_BufferMessageListHead = NULL;
    m_BufferMessageListTail = NULL;
    if (i_FlushTimedMessages && gData.ScriptMgr) {
        gData.ScriptMgr->FlushTimedMessagesTo(this);
    }
    return result;
}
