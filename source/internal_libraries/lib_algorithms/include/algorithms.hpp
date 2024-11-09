#ifndef	_ALGORITHMS_
#define	_ALGORITHMS_

#include <cstddef>

namespace ufo
{
    template<typename T, std::size_t S>
    std::size_t linear(T(&p_Container)[S], const T& p_Target, bool& p_Found, std::size_t lower_Bound = std::size_t(0), std::size_t upper_Bound = S - 1);

    // Iterative approach
    template<typename T, std::size_t S>
    std::size_t binary(T(&p_Container)[S], const T& p_Target, bool& p_Found, std::size_t lower_Bound = std::size_t(0), std::size_t upper_Bound = S - 1);

    // Recursive appreach
    // template<typename T, std::size_t S>
    // std::size_t binary(T(&p_Container)[S], std::size_t lower_Bound = std::size_t(0), std::size_t upper_Bound = S - 1, const int& p_Target, bool& p_Found);
};


namespace ufo
{
    template<typename T, std::size_t S>
    std::size_t linear(T(&p_Container)[S], const T& p_Target, bool& p_Found, std::size_t lower_Bound, std::size_t upper_Bound)
    {
        std::size_t target_Index = std::size_t(0);
        p_Found = false;

        for(std::size_t index = lower_Bound; index < upper_Bound; ++index)
        {
            if(p_Container[index] == p_Target)
            {
                target_Index = index;
                p_Found = true;

                break;
            }
        }

        return (target_Index);
    }

    // Iterative approach
    template<typename T, std::size_t S>
    std::size_t binary(T(&p_Container)[S], const T& p_Target, bool& p_Found, std::size_t lower_Bound, std::size_t upper_Bound)
    {
        std::size_t center_Index = std::size_t(0);
        std::size_t result_Index = std::size_t(0);
        p_Found = false;

        while(lower_Bound <= upper_Bound)
        {
            center_Index = lower_Bound + (upper_Bound - lower_Bound) / 2;

            if(p_Container[center_Index] == p_Target)
            {
                result_Index = center_Index;
                p_Found = true;

                break;
            }

            if(p_Container[center_Index] < p_Target)
            {
                lower_Bound = center_Index + 1;

                continue;
            }

            if(p_Container[center_Index] > p_Target)
            {
                upper_Bound = center_Index - 1;

                continue;
            }
        }

        return (result_Index);
    };
};


// Recursive

// Returns the index of element e in array a, searching for the element between
// the left index l and the right index r.  Applies the binary search algorithm
// recursively to conduct the search.  Returns -1 if element isn't in the array.
// int binary_search(int a[], int e, int l, int r)
// {

//     // find the mid-way index between index l and index r
//     int mid = l + (r - l) / 2;

//     // if l is ever > r, it means the element is not in the array
//     if (l > r) return -1;

//     // if we've found the element at the mid-way index, return the index
//     // else if the element MUST be in the left-portion of the portion of the
//     //         array we are currently looking at, search for it in this portion
//     // else if the element MUST be in the right-portion of the portion of the
//     //         array we are currently looking at, search for it in this portion
//     if (a[mid] == e)
//     return mid;
//   else if (a[mid] > e)
//     return binary_search(a, e, l, mid - 1);
//   else
//     return binary_search(a, e, mid + 1, r);

// }

#endif	// _ALGORITHMS_
