#ifndef _STATICARRAY_Z_H_
#define _STATICARRAY_Z_H_

#include <BitArray_Z.h>

template <class T, int ReservedSize, Bool DeleteObject = TRUE, Bool InitObject = TRUE>
class StaticArray_Z {
private:
    Char m_ArrayChar[ReservedSize * sizeof(T)];
    int m_Size;

public:
    StaticArray_Z() {
        m_Size = 0;
    }

    StaticArray_Z(T nValue[], S32 nSize) {
        m_Size = 0;
        for (int i = 0; i < nSize; i++)
            Add(nValue[i]);
    }

    StaticArray_Z(const StaticArray_Z<T, ReservedSize>& Src) {
        m_Size = 0;
        for (int i = 0; i < Src.GetSize(); i++)
            Add(Src[i]);
    }

    ~StaticArray_Z() {
        // $SABE: Supposedly they hadn't added the check for DeleteObject here yet
        for (int i = 0; i < m_Size; i++)
            Get(i).~T();
    }

    T& Get(int Id) {
        return *(T*)(m_ArrayChar + Id * sizeof(T));
    }

    const T& Get(int Id) const {
        return *(T*)(m_ArrayChar + Id * sizeof(T));
    }

    T& operator[](int Id) {
        return Get(Id);
    }

    const T& operator[](int Id) const {
        return Get(Id);
    }

    int GetSize() const {
        return m_Size;
    }

    int Add() {
        DYNARRAY_Z_EXP(m_Size < ReservedSize);

        if (m_Size >= ReservedSize) {
            if (DeleteObject)
                Get(ReservedSize - 1).~T();
            if (InitObject)
                new (&Get(ReservedSize - 1)) T();
            return ReservedSize - 1;
        }

        if (InitObject)
            new (&Get(m_Size++)) T();
        else
            m_Size++;
        return m_Size - 1;
    }

    int Add(const T& Ele) {
        if (m_Size >= ReservedSize) {
            DYNARRAY_Z_EXP(m_Size < ReservedSize);
            if (InitObject)
                new (&Get(ReservedSize - 1)) T(Ele);
            return ReservedSize - 1;
        }

        if (InitObject)
            new (&Get(m_Size++)) T(Ele);
        else {
            Get(m_Size) = Ele;
            m_Size++;
        }
        return m_Size - 1;
    }

    Bool IsFull() {
        return ReservedSize == m_Size ? TRUE : FALSE;
    }
} Aligned_Z(16);

#endif
