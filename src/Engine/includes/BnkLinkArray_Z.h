#ifndef _BNKLINKARRAY_Z_H_
#define _BNKLINKARRAY_Z_H_
#include "Types_Z.h"
#include "Memory_Z.h"
#include "Math_Z.h"

template <class T, S32 Granularity = 256, S32 Alignment = 4>
struct BnkLinkArrayEle_Z {
    typedef BnkLinkArrayEle_Z<T, Granularity, Alignment> Bank_Z;

    Bank_Z* m_NextBank;
    T m_Ele[Granularity];
    T* m_HeadEle;
    T* m_FirstEle;
    T* m_LastEle;
    S32 m_NbFree;

    BnkLinkArrayEle_Z() {
        m_NextBank = NULL;
        m_NbFree = Granularity;

        m_HeadEle = m_Ele;
        m_FirstEle = m_HeadEle;

        T* l_Cur = m_HeadEle;
        T* l_Next = l_Cur + 1;
        S32 i = Granularity - 1;
        while (i--) {
            l_Cur->m_Next = l_Next;
            ++l_Cur;
            ++l_Next;
        }

        l_Cur->m_Next = NULL;
        m_LastEle = l_Cur;
    }
};

template <class T, S32 Granularity = 256, S32 Alignment = 4>
class BnkLinkArray_Z {
public:
    typedef BnkLinkArrayEle_Z<T, Granularity, Alignment> Bank_Z;

    BnkLinkArray_Z() {
        m_HeadBank = NULL;
        m_NbMaxUsed = 0;
        m_NbUsed = 0;
        m_NbElement = 0;
    }

    ~BnkLinkArray_Z() {
        Bank_Z* l_Bank = m_HeadBank;
        while (l_Bank) {
            m_HeadBank = l_Bank->m_NextBank;
            Delete_Z l_Bank;
            l_Bank = m_HeadBank;
        }
    }

    inline T* Get() {
        Bank_Z** l_Link = &m_HeadBank;
        Bank_Z* l_Bank;

        while ((l_Bank = *l_Link)) {
            if (l_Bank->m_NbFree) {
                return Ret(l_Bank);
            }
            l_Link = &l_Bank->m_NextBank;
        }

        *l_Link = NewL_Z(85) Bank_Z;
        m_NbElement += Granularity;

        return Ret(*l_Link);
    }

    inline T* Ret(Bank_Z* i_Bank) {
        T* l_HeadEle = i_Bank->m_HeadEle;
        i_Bank->m_HeadEle = l_HeadEle->m_Next;
        l_HeadEle->m_Next = NULL;

        m_NbUsed++;
        i_Bank->m_NbFree--;
        m_NbMaxUsed = Max(m_NbUsed, m_NbMaxUsed);

        return l_HeadEle;
    }

    inline void Minimize() {
        Bank_Z** l_Link = &m_HeadBank;
        while (Bank_Z* l_Bank = *l_Link) {
            if (l_Bank->m_NbFree == Granularity) {
                *l_Link = l_Bank->m_NextBank;
                Delete_Z l_Bank;
                m_NbElement -= Granularity;
            }
            else {
                l_Link = &l_Bank->m_NextBank;
            }
        }
    }

    inline void ReleaseAll(T* i_Ele) {
        if (i_Ele) {
            T* l_Next;
            do {
                l_Next = i_Ele->m_Next;
                Release(i_Ele);
                i_Ele = l_Next;
            } while (l_Next);
        }
    }

    inline void Release(T* i_Ele) {
        Bank_Z* l_Bank = Find(i_Ele);
        i_Ele->~T();

        i_Ele->m_Next = l_Bank->m_HeadEle;
        l_Bank->m_HeadEle = i_Ele;

        l_Bank->m_NbFree++;
        m_NbUsed--;
    }

    inline Bank_Z* Find(T* i_Ele) {
        Bank_Z* l_Bank = m_HeadBank;
        do {
            if (i_Ele >= l_Bank->m_FirstEle && i_Ele <= l_Bank->m_LastEle) {
                return l_Bank;
            }
            l_Bank = l_Bank->m_NextBank;
        } while (l_Bank);

        ASSERTL_Z(FALSE, "BnkLinkArrayEle_Z Ele not Found", 153);
        return l_Bank;
    }

private:
    Bank_Z* m_HeadBank;
    S32 m_NbMaxUsed;
    S32 m_NbUsed;
    S32 m_NbElement;
};

#endif
