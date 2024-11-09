#ifndef UFO_ARRAY_H
#define UFO_ARRAY_H

#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>


namespace ufo
{
    template<typename T, std::size_t S = std::size_t(0)>
    class Array
    {
    private:
        T m_Array[S];
        std::size_t m_Size;

    public:
        // Constructors
        Array(); // Default
        Array(std::initializer_list<T> init); // Constructor for initializer list

        // Copy Semantics
        Array(const Array<T, S>& p_Other);
        const Array<T, S>& operator=(const Array<T, S>& p_Other);

        // Move Semantics
        // TODO (SAVIZ): Implementation must be added...

        // Destructor
        ~Array();

        // Operators
    public:
        T& operator[](std::size_t p_Index);
        const T& operator[](std::size_t p_Index) const;

        bool operator==(const Array<T, S>& p_Other) const;
        bool operator!=(const Array<T, S>& p_Other) const;
        bool operator> (const Array<T, S>& p_Other) const;
        bool operator< (const Array<T, S>& p_Other) const;
        bool operator>=(const Array<T, S>& p_Other) const;
        bool operator<=(const Array<T, S>& p_Other) const;

        // Methods
    public:
        constexpr std::size_t size();
        constexpr bool is_Empty();

        const T& peek_Back() const noexcept;
        const T& peek_Front() const noexcept;
        T& at(std::size_t p_Index);
        const T& at(std::size_t p_Index) const;

        // data() methods are useful with memset().
        T* data();
        const T* data() const;

        void fill(const T& p_Filler);
        std::string to_String();
    };
}


// Implementations
///////////////////////////////////////////////////////////////////////////////


template<typename T, std::size_t S>
ufo::Array<T, S>::Array() : m_Size(S)
{
    // No operations required...
}

template<typename T, std::size_t S>
ufo::Array<T, S>::Array(std::initializer_list<T> init) : m_Size(init.size())
{
    if (init.size() > S)
    {
        throw std::out_of_range("Initializer list size exceeds array size");
    }

    std::size_t index = 0;

    for (const T& value : init)
    {
        m_Array[index++] = value;
    }
};


template<typename T, std::size_t S>
ufo::Array<T, S>::Array(const Array<T, S>& p_Other) : m_Size(p_Other.size())
{
    for(std::size_t index = 0; index < m_Size; ++index)
    {
        this->m_Array[index] = p_Other[index];
    }
};


template<typename T, std::size_t S>
const ufo::Array<T, S>& ufo::Array<T, S>::operator=(const Array<T, S>& p_Other)
{
    this->m_Size = p_Other.size();

    for(std::size_t index = 0; index < m_Size; ++index)
    {
        this->m_Array[index] = p_Other[index];
    }

    return (*this);
};


template<typename T, std::size_t S>
ufo::Array<T, S>::~Array()
    {
        // Any free operations must be done here if need be...
    };


template<typename T, std::size_t S>
const T& ufo::Array<T, S>::peek_Back() const noexcept
{
    return (
        this->m_Array[m_Size - 1]
        );
};


template<typename T, std::size_t S>
const T& ufo::Array<T, S>::peek_Front() const noexcept
{
    return (
        this->m_Array[0]
        );
};


template<typename T, std::size_t S>
T& ufo::Array<T, S>::at(std::size_t p_Index)
{
    if(p_Index < 0 || p_Index >= m_Size)
    {
        throw std::out_of_range("Attempting to access index out of bounds!");
    }

    return (
        this->m_Array[p_Index]
        );
};


template<typename T, std::size_t S>
const T& ufo::Array<T, S>::at(std::size_t p_Index) const
{
    if(p_Index < 0 || p_Index >= m_Size)
    {
        throw std::out_of_range("Attempting to access index out of bounds!");
    }

    return (
        this->m_Array[p_Index]
        );
};


template<typename T, std::size_t S>
T& ufo::Array<T, S>::operator[](std::size_t p_Index)
{
    // This version does not have bounds check since the"at()" method has one.

    return (
        this->m_Array[p_Index]
        );
};


template<typename T, std::size_t S>
const T& ufo::Array<T, S>::operator[](std::size_t p_Index) const
{
    // This version does not have bounds check since "at()" method has one.

    return (
        this->m_Array[p_Index]
        );
};


template<typename T, std::size_t S>
T* ufo::Array<T, S>::data()
{
    // Very useful when using with something like "memset".
    return(
        this->m_Array
        );
};


template<typename T, std::size_t S>
const T* ufo::Array<T, S>::data() const
{
    // Very useful when using with something like "memset".
    return(
        this->m_Array
        );
};


template<typename T, std::size_t S>
bool ufo::Array<T, S>::operator==(const Array<T, S>& p_Other) const
{
    // Comparing size of arrays first.
    if(m_Size != p_Other.size())
    {
        return (false);
    }

    // Comparing individual elements next.
    for(std::size_t index = 0; index < m_Size; ++index)
    {
        if(m_Array[index] != p_Other[index])
        {
            return (false);
        }
    }

    return (true);
};


template<typename T, std::size_t S>
bool ufo::Array<T, S>::operator!=(const Array<T, S>& p_Other) const
{
    // Comparing size of arrays first.
    if(m_Size != p_Other.size())
    {
        return (true);
    }

    // Comparing individual elements next.
    for(std::size_t index = 0; index < m_Size; ++index)
    {
        if(m_Array[index] != p_Other[index])
        {
            return (true);
        }
    }

    return (false);
};


template<typename T, std::size_t S>
bool ufo::Array<T, S>::operator> (const Array<T, S>& p_Other) const
{
    // Comparing size of arrays first.
    if (this->m_Size > p_Other.size())
    {
        return (true);
    }

    if (this->m_Size < p_Other.size())
    {
        return (false);
    }

    // Comparing individual elements next.
    for (std::size_t index = 0; index < m_Size; ++index)
    {
        if (m_Array[index] <= p_Other[index])
        {
            return (false);
        }
    }

    return (true);
};


template<typename T, std::size_t S>
bool ufo::Array<T, S>::operator< (const Array<T, S>& p_Other) const
{
    // Comparing size of arrays first.
    if (this->m_Size < p_Other.size())
    {
        return (true);
    }

    if (this->m_Size > p_Other.size())
    {
        return (false);
    }

    // Comparing individual elements next.
    for (std::size_t index = 0; index < m_Size; ++index)
    {
        if (m_Array[index] >= p_Other[index])
        {
            return (false);
        }
    }

    return (true);
};


template<typename T, std::size_t S>
bool ufo::Array<T, S>::operator>=(const Array<T, S>& p_Other) const
{
    return !(*this < p_Other);
};


template<typename T, std::size_t S>
bool ufo::Array<T, S>::operator<=(const Array<T, S>& p_Other) const
{
    return !(*this > p_Other);
}


template<typename T, std::size_t S>
void ufo::Array<T, S>::fill(const T& p_data)
{
    for(std::size_t index = 0; index < m_Size; ++index)
    {
        this->m_Array[index] = T(p_data);
    }
};


template<typename T, std::size_t S>
constexpr std::size_t ufo::Array<T, S>::size()
{
    return (this->m_Size);
};


template<typename T, std::size_t S>
constexpr bool ufo::Array<T, S>::is_Empty()
{
    // An Array is never empty.
    // All memory gets preallocated instantly at creation.
    // Unless if the array is literally of size (0). Even if the array has garbage values in its posisiotn, they are still values!!
    return (this->m_Size == std::size_t(0));
};


template<typename T, std::size_t S>
std::string ufo::Array<T, S>::to_String()
{
    std::ostringstream result;

    result << "[";

    for(std::size_t index = 0; index < m_Size - 1; ++index)
    {
        result << this->m_Array[index] << ", ";
    }

    result << this->m_Array[m_Size - 1] << "]";

    return (result.str());
};


// IOstream overloads
///////////////////////////////////////////////////////////////////////////////


template<typename T, std::size_t S>
std::istream& operator>>(std::istream& p_Istream, ufo::Array<T, S>& p_Array)
{
    for (std::size_t index = 0; index < S; ++index)
    {
        p_Istream >> p_Array[index];
    }

    return (p_Istream);
};


template<typename T, std::size_t S>
std::ostream& operator<<(std::ostream& p_Ostream, const ufo::Array<T, S>& p_Array)
{
    p_Ostream << "[";

    for (std::size_t index = 0; index < S - 1; ++index)
    {
        p_Ostream << p_Array[index] << ", ";
    }

    p_Ostream << p_Array[S - 1] << "]";

    return (p_Ostream);
};



#endif // UFO_ARRAY_H
