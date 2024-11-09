#pragma once

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>
#include <array>


template<typename T>
void printArray(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Heapsort
// Make sure to create alternatives for the sorting ufo that can take in heap allocated containers.

namespace ufo
{
	namespace sort
	{
		enum order
		{
			forward_order = 0,	// The same as ascending,  or forward alphabetical
			reverse_order = 1	// The same as descending, or reverse alphabetical
		};

        // Research and see if it is possible to create a multithreaded version of these ufo to increase their performance
		// You need to write overloads for C and STL containers that are created on the heap.

		// C arrays
		///////////////////////////////////////////////////////////////////////


		// Bubble sort
		///////////////////////////////

		template<typename T, std::size_t S>
        void bubble(T(&container)[S], const ufo::sort::order& requested_order = ufo::sort::order::forward_order);

        template<typename T, std::size_t S>
        static void bubble_forward_order(T(&container)[S]);

        template<typename T, std::size_t S>
        static void bubble_reverse_order(T(&container)[S]);

		///////////////////////////////
		// Bubble sort



		// Selection sort
		///////////////////////////////

		template<typename T, std::size_t S>
        void selection(T(&container)[S], const ufo::sort::order& requested_order = ufo::sort::order::forward_order, bool is_stable = true);

		template<typename T, std::size_t S>
		static void selection_forward_order(T(&container)[S]);

		template<typename T, std::size_t S>
		static void selection_reverse_order(T(&container)[S]);

		template<typename T, std::size_t S>
		static void selection_stable_forward_order(T(&container)[S]);

		template<typename T, std::size_t S>
		static void selection_stable_reverse_order(T(&container)[S]);

		///////////////////////////////
		// Selection sort



		// Insertion sort
		///////////////////////////////

		template<typename T, std::size_t S>
        void insertion(T(&container)[S], const ufo::sort::order& requested_order = ufo::sort::order::forward_order);

		template<typename T, std::size_t S>
		static void insertion_forward_order(T(&container)[S]);

		template<typename T, std::size_t S>
		static void insertion_reverse_order(T(&container)[S]);

		///////////////////////////////
		// Insertion sort



		// Quick sort
		///////////////////////////////

		template<typename T, std::size_t S>
        void quick(T(&container)[S], const ufo::sort::order& requested_order = ufo::sort::order::forward_order, std::size_t lower_bound = std::size_t(0), std::size_t upper_bound = S - 1);

		template<typename T, std::size_t S>
		static void quick_forward_order(T(&container)[S], std::size_t lower_bound = std::size_t(0), std::size_t upper_bound = S - 1);

		template<typename T, std::size_t S>
		static void quick_reverse_order(T(&container)[S], std::size_t lower_bound = std::size_t(0), std::size_t upper_bound = S - 1);

		///////////////////////////////
		// Quick sort



		// Merge sort
		///////////////////////////////

		template<typename T, std::size_t S>
        void merge(T(&container)[S], const ufo::sort::order& requested_order = ufo::sort::order::forward_order, std::size_t lower_bound = std::size_t(0), std::size_t upper_bound = S - 1);

		template<typename T, std::size_t S>
		static void merge_forward_order(T(&container)[S], std::size_t lower_bound = std::size_t(0), std::size_t upper_bound = S - 1);

		template<typename T, std::size_t S>
		static void merge_reverse_order(T(&container)[S], std::size_t lower_bound = std::size_t(0), std::size_t upper_bound = S - 1);

		///////////////////////////////
		// Merge sort


		///////////////////////////////////////////////////////////////////////
		// C arrays





		// STL - Array
		///////////////////////////////////////////////////////////////////////


		// Bubble sort
		///////////////////////////////

		template<typename T, std::size_t S>
        void bubble(std::array<T, S>& container, const ufo::sort::order& requested_order = ufo::sort::order::forward_order);

		template<typename T, std::size_t S>
		static void bubble_forward_order(std::array<T, S>& container);

		template<typename T, std::size_t S>
		static void bubble_reverse_order(std::array<T, S>& container);

		///////////////////////////////
		// Bubble sort


		///////////////////////////////////////////////////////////////////////
		// STL - Array





		// STL - Vector
		///////////////////////////////////////////////////////////////////////


		// Bubble sort
		///////////////////////////////

		template<typename T>
        void bubble(std::vector<T>& container, const ufo::sort::order& requested_order = ufo::sort::order::forward_order);

		template<typename T>
		static void bubble_forward_order(std::vector<T>& container);

		template<typename T>
		static void bubble_reverse_order(std::vector<T>& container);

		///////////////////////////////
		// Bubble sort


		///////////////////////////////////////////////////////////////////////
		// STL - Vector





		// STL - General approach
		///////////////////////////////////////////////////////////////////////


		// Bubble sort
		///////////////////////////////

		template<typename Iterator>
        void bubble(Iterator begin, Iterator end, const ufo::sort::order& requested_order = ufo::sort::order::forward_order);

		template<typename Iterator>
        static void bubble_forward_order(Iterator begin, Iterator end);

		template<typename Iterator>
        static void bubble_reverse_order(Iterator begin, Iterator end);

		///////////////////////////////
		// Bubble sort


		///////////////////////////////////////////////////////////////////////
		// STL - General approach
	};
};




// C arrays
///////////////////////////////////////////////////////////////////////


// Bubble sort
///////////////////////////////

template<typename T, std::size_t S>
void ufo::sort::bubble(T(&container)[S], const ufo::sort::order& requested_order)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);
	
	if(is_forward_order)
	{
        ufo::sort::bubble_forward_order(container);

		return;
	}

    ufo::sort::bubble_reverse_order(container);
};

template<typename T, std::size_t S>
void ufo::sort::bubble_forward_order(T(&container)[S])
{
    for (std::size_t unsorted_element = 0; unsorted_element < S; ++unsorted_element)
    {
        for (std::size_t selected_element = 0; selected_element < S -1 -unsorted_element; ++selected_element)
        {
            T& element_1 = container[selected_element + 0];
            T& element_2 = container[selected_element + 1];

            if(element_1 > element_2)
            {
                std::swap(element_1, element_2);
            }
        }
    }
};

template<typename T, std::size_t S>
void ufo::sort::bubble_reverse_order(T(&container)[S])
{
    for (std::size_t unsorted_element = 0; unsorted_element < S; ++unsorted_element)
    {
        for (std::size_t selected_element = 0; selected_element < S -1 -unsorted_element; ++selected_element)
        {
            T& element_1 = container[selected_element + 0];
            T& element_2 = container[selected_element + 1];

            if(element_1 < element_2)
            {
                std::swap(element_1, element_2);
            }
        }
    }
};

///////////////////////////////
// Bubble sort



// Selection sort
///////////////////////////////

template<typename T, std::size_t S>
void ufo::sort::selection(T(&container)[S], const ufo::sort::order& requested_order, bool is_stable)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);
	
	if(is_stable)
	{
		if(is_forward_order)
		{
			selection_stable_forward_order(container);

			return;
		}

		selection_stable_reverse_order(container);
	}

	else
	{
		if(is_forward_order)
		{
			selection_forward_order(container);

			return;
		}

		selection_reverse_order(container);
	}
};

template<typename T, std::size_t S>
static void ufo::sort::selection_forward_order(T(&container)[S])
{
	for (std::size_t unsorted_element_index = 0; unsorted_element_index < S - 1; ++unsorted_element_index)
	{
		std::size_t smallest_element_index = unsorted_element_index;

		for (std::size_t selected_element_index = unsorted_element_index + 1; selected_element_index < S; ++selected_element_index)
		{
			// We will compare smallest and selected to find out which is smaller and swap them.
			T& element_1 = container[smallest_element_index];
			T& element_2 = container[selected_element_index];

			if(element_1 > element_2)
			{
				smallest_element_index = selected_element_index;
			}
		}

		//If smallest is different from what we set it intially, then swap them.
		if(smallest_element_index != unsorted_element_index)
		{
			std::swap(
				container[smallest_element_index], 
				container[unsorted_element_index]
			);
		}
	}
};

template<typename T, std::size_t S>
static void ufo::sort::selection_reverse_order(T(&container)[S])
{
	for (std::size_t unsorted_element_index = 0; unsorted_element_index < S - 1; ++unsorted_element_index)
	{
		std::size_t smallest_element_index = unsorted_element_index;

		for (std::size_t selected_element_index = unsorted_element_index + 1; selected_element_index < S; ++selected_element_index)
		{
			// We will compare smallest and selected to find out which is smaller and swap them.
			T& element_1 = container[smallest_element_index];
			T& element_2 = container[selected_element_index];

			if(element_1 < element_2)
			{
				smallest_element_index = selected_element_index;
			}
		}

		// If smallest is different from what we set it intially, then swap them.
		if(smallest_element_index != unsorted_element_index)
		{
			std::swap(
				container[smallest_element_index], 
				container[unsorted_element_index]
			);
		}
	}
};

template<typename T, std::size_t S>
static void ufo::sort::selection_stable_forward_order(T(&container)[S])
{
	for (std::size_t unsorted_element_index = 0; unsorted_element_index < S - 1; ++unsorted_element_index)
	{
		std::size_t smallest_element_index = unsorted_element_index;

		for (std::size_t selected_element_index = unsorted_element_index + 1; selected_element_index < S; ++selected_element_index)
		{
			// We will compare smallest and selected to find out which is smaller and swap them.
			T& element_1 = container[smallest_element_index];
			T& element_2 = container[selected_element_index];

			if(element_1 > element_2)
			{
				smallest_element_index = selected_element_index;
			}
		}

		if(smallest_element_index != unsorted_element_index)
		{
			T& smallest_element = container[smallest_element_index];

			for(std::size_t current_index = smallest_element_index; current_index > unsorted_element_index; --current_index)
			{
			    std::swap(
					container[current_index + 0], 
					container[current_index - 1]
				);
			}

			container[unsorted_element_index] = smallest_element;
		}
	}
};

template<typename T, std::size_t S>
static void ufo::sort::selection_stable_reverse_order(T(&container)[S])
{
	for (std::size_t unsorted_element_index = 0; unsorted_element_index < S - 1; ++unsorted_element_index)
	{
		std::size_t smallest_element_index = unsorted_element_index;

		for (std::size_t selected_element_index = unsorted_element_index + 1; selected_element_index < S; ++selected_element_index)
		{
			// We will compare smallest and selected to find out which is smaller and swap them.
			T& element_1 = container[smallest_element_index];
			T& element_2 = container[selected_element_index];

			if(element_1 < element_2)
			{
				smallest_element_index = selected_element_index;
			}
		}

		if(smallest_element_index != unsorted_element_index)
		{
			T& smallest_element = container[smallest_element_index];

			for(std::size_t current_index = smallest_element_index; current_index > unsorted_element_index; --current_index)
			{
			    std::swap(
					container[current_index + 0], 
					container[current_index - 1]
				);
			}

			container[unsorted_element_index] = smallest_element;
		}
	}
};

///////////////////////////////
// Selection sort



// Insertion sort
///////////////////////////////

template<typename T, std::size_t S>
void ufo::sort::insertion(T(&container)[S], const ufo::sort::order& requested_order)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);
	
	if(is_forward_order)
	{
        ufo::sort::insertion_forward_order(container);

		return;
	}

    ufo::sort::insertion_reverse_order(container);
};

template<typename T, std::size_t S>
static void ufo::sort::insertion_forward_order(T(&container)[S])
{
	for (std::size_t unsorted_element_index = 1; unsorted_element_index < S; ++unsorted_element_index)
	{
		T unsorted_element_save = container[unsorted_element_index + 0];
		std::size_t shifting_element_index = unsorted_element_index - 1;

		// Keep shifiting to the right side...
		while (shifting_element_index != std::size_t(-1) && container[shifting_element_index] > unsorted_element_save)
		{
			container[shifting_element_index + 1] = container[shifting_element_index + 0];
			
			--shifting_element_index;
		}

		container[shifting_element_index + 1] = unsorted_element_save;
	}
};

template<typename T, std::size_t S>
static void ufo::sort::insertion_reverse_order(T(&container)[S])
{
	for (std::size_t unsorted_element_index = 1; unsorted_element_index < S; ++unsorted_element_index)
	{
		T unsorted_element_save = container[unsorted_element_index + 0];
		std::size_t shifting_element_index = unsorted_element_index - 1;

		// Keep shifiting to the right side...
		while (shifting_element_index != std::size_t(-1) && container[shifting_element_index] < unsorted_element_save)
		{
			container[shifting_element_index + 1] = container[shifting_element_index + 0];
			
			--shifting_element_index;
		}

		container[shifting_element_index + 1] = unsorted_element_save;
	}
};

///////////////////////////////
// Insertion sort



// Quick sort
///////////////////////////////

template<typename T, std::size_t S>
void ufo::sort::quick(T(&container)[S], const ufo::sort::order& requested_order, std::size_t lower_bound, std::size_t upper_bound)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);
	
	if(is_forward_order)
	{
        ufo::sort::quick_forward_order(container, lower_bound, upper_bound);

		return;
	}

    ufo::sort::quick_reverse_order(container, lower_bound, upper_bound);
};

template<typename T, std::size_t S>
static void ufo::sort::quick_forward_order(T(&container)[S], std::size_t lower_bound, std::size_t upper_bound)
{
	// If the container is of size 1 or 0, then just return
	if(lower_bound >= upper_bound)
	{
		return;
	}

	// Choosing the last element as the pivot
    const T& pivot_element = container[upper_bound];

    std::size_t rhs_pointer = upper_bound;
    std::size_t lhs_pointer = lower_bound;

    while (lhs_pointer < rhs_pointer)
    {
    	while(container[lhs_pointer] <= pivot_element && lhs_pointer < rhs_pointer)
    	{
    		++lhs_pointer;
    	}

    	while(container[rhs_pointer] >= pivot_element && rhs_pointer > lhs_pointer)
    	{
    		--rhs_pointer;
    	}

    	std::swap(
    		container[lhs_pointer],
    		container[rhs_pointer]
		);
    }

    // Now just swap the position of the pivot element with one of the pointer elements.
    std::swap(
		container[lhs_pointer],
		container[upper_bound]
	);

    // As a safety check for `std::size_t`. If you use an int, this wont' be nccessary.
	if(lhs_pointer == std::size_t(0))
	{
		return;
	}

	quick_forward_order(container, lower_bound, lhs_pointer - 1);
	quick_forward_order(container, lhs_pointer + 1, upper_bound);
};

template<typename T, std::size_t S>
static void ufo::sort::quick_reverse_order(T(&container)[S], std::size_t lower_bound, std::size_t upper_bound)
{
	// If the container is of size 1 or 0, then just return
	if(lower_bound >= upper_bound)
	{
		return;
	}

	// Choosing the last element as the pivot
    const T& pivot_element = container[upper_bound];

    std::size_t rhs_pointer = upper_bound;
    std::size_t lhs_pointer = lower_bound;

    while (lhs_pointer < rhs_pointer)
    {
    	while(container[lhs_pointer] >= pivot_element && lhs_pointer < rhs_pointer)
    	{
    		++lhs_pointer;
    	}

    	while(container[rhs_pointer] <= pivot_element && rhs_pointer > lhs_pointer)
    	{
    		--rhs_pointer;
    	}

    	std::swap(
    		container[lhs_pointer],
    		container[rhs_pointer]
		);
    }

    // Now just swap the position of the pivot element with one of the pointer elements.
    std::swap(
		container[lhs_pointer],
		container[upper_bound]
	);


    // As a safety check for `std::size_t`. If you use an int, this wont' be nccessary.
	if(lhs_pointer == std::size_t(0))
	{
		return;
	}

	quick_reverse_order(container, lower_bound, lhs_pointer - 1);
	quick_reverse_order(container, lhs_pointer + 1, upper_bound);
};

///////////////////////////////
// Quick sort



// Merge sort
///////////////////////////////

template<typename T, std::size_t S>
void ufo::sort::merge(T(&container)[S], const ufo::sort::order& requested_order, std::size_t lower_bound, std::size_t upper_bound)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);
	
	if(is_forward_order)
	{
        ufo::sort::merge_forward_order(container, lower_bound, upper_bound);

		return;
	}

    ufo::sort::merge_reverse_order(container, lower_bound, upper_bound);
};

template<typename T, std::size_t S>
static void ufo::sort::merge_forward_order(T(&container)[S], std::size_t lower_bound, std::size_t upper_bound)
{
	if(lower_bound >= upper_bound)
	{
		return;
	}

	std::size_t middle_index = lower_bound + (upper_bound - lower_bound) / 2;

	merge_forward_order(container, lower_bound, middle_index + 0);
	merge_forward_order(container, middle_index + 1, upper_bound);


	// Sorting section
	///////////////////////////////////


	// Finding the length of each array that needs sorting.
	std::size_t lhs_length = (middle_index - lower_bound) + 1;
	std::size_t rhs_length = (upper_bound - middle_index) + 0;


	// Creating temporary subarrays.
	T subarray_l[lhs_length] = {T()};
	T subarray_r[rhs_length] = {T()};


	// Copy elements over to each of the subarrays.
	for(std::size_t index = 0; index < lhs_length; ++index)
	{
		subarray_l[index] = container[index + lower_bound];
	}

	for(std::size_t index = 0; index < rhs_length; ++index)
	{
		subarray_r[index] = container[index + 1 + middle_index];
	}


	// Creating 3 indexes to keep track in each array when iterating.
	std::size_t index_l = std::size_t(0);
	std::size_t index_r = std::size_t(0);
	std::size_t index_m = lower_bound;

	bool element_l_is_smaller = false;
	bool element_r_is_smaller = false;


	// Merging
	while(index_l < lhs_length && index_r < rhs_length)
	{
		element_l_is_smaller = (subarray_l[index_l] < subarray_r[index_r]);
		element_r_is_smaller = (subarray_l[index_l] > subarray_r[index_r]);

		if(element_l_is_smaller)
		{
			container[index_m] = subarray_l[index_l];
			++index_l;
			++index_m;

			continue;
		}

		if(element_r_is_smaller)
		{
			container[index_m] = subarray_r[index_r];
			++index_r;
			++index_m;

			continue;
		}
	}

	// Chances are there are still some elements remaining.
	while(index_l < lhs_length)
	{
		container[index_m] = subarray_l[index_l];
		++index_l;
		++index_m;
	}

	while(index_r < rhs_length)
	{
		container[index_m] = subarray_r[index_r];
		++index_r;
		++index_m;
	}

	///////////////////////////////////
	// Sorting section
};

template<typename T, std::size_t S>
static void ufo::sort::merge_reverse_order(T(&container)[S], std::size_t lower_bound, std::size_t upper_bound)
{
	if(lower_bound >= upper_bound)
	{
		return;
	}

	std::size_t middle_index = lower_bound + (upper_bound - lower_bound) / 2;

	merge_reverse_order(container, lower_bound, middle_index + 0);
	merge_reverse_order(container, middle_index + 1, upper_bound);


	// Sorting section
	///////////////////////////////////


	// Finding the length of each array that needs sorting.
	std::size_t lhs_length = (middle_index - lower_bound) + 1;
	std::size_t rhs_length = (upper_bound - middle_index) + 0;


	// Creating temporary subarrays.
	T subarray_l[lhs_length] = {T()};
	T subarray_r[rhs_length] = {T()};


	// Copy elements over to each of the subarrays.
	for(std::size_t index = 0; index < lhs_length; ++index)
	{
		subarray_l[index] = container[index + lower_bound];
	}

	for(std::size_t index = 0; index < rhs_length; ++index)
	{
		subarray_r[index] = container[index + 1 + middle_index];
	}


	// Creating 3 indexes to keep track in each array when iterating.
	std::size_t index_l = std::size_t(0);
	std::size_t index_r = std::size_t(0);
	std::size_t index_m = lower_bound;

	bool element_l_is_smaller = false;
	bool element_r_is_smaller = false;
    bool element_l_is_bigger = false;
    bool element_r_is_bigger = false;


	// Merging
	while(index_l < lhs_length && index_r < rhs_length)
	{
		element_l_is_bigger = (subarray_l[index_l] > subarray_r[index_r]);
		element_r_is_bigger = (subarray_l[index_l] < subarray_r[index_r]);

		if(element_l_is_bigger)
		{
			container[index_m] = subarray_l[index_l];
			++index_l;
			++index_m;

			continue;
		}

		if(element_r_is_bigger)
		{
			container[index_m] = subarray_r[index_r];
			++index_r;
			++index_m;

			continue;
		}
	}

	// Chances are there are still some elements remaining.
	while(index_l < lhs_length)
	{
		container[index_m] = subarray_l[index_l];
		++index_l;
		++index_m;
	}

	while(index_r < rhs_length)
	{
		container[index_m] = subarray_r[index_r];
		++index_r;
		++index_m;
	}

	///////////////////////////////////
	// Sorting section
};

///////////////////////////////
// Merge sort


///////////////////////////////////////////////////////////////////////
// C arrays















// STL - Array
///////////////////////////////////////////////////////////////////////


// Bubble sort
///////////////////////////////

template<typename T, std::size_t S>
void ufo::sort::bubble(std::array<T, S>& container, const ufo::sort::order& requested_order)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);

	if(is_forward_order)
	{
        ufo::sort::bubble_forward_order(container);

		return;
	}

    ufo::sort::bubble_reverse_order(container);
};

template<typename T, std::size_t S>
static void ufo::sort::bubble_forward_order(std::array<T, S>& container)
{
	for (std::size_t unsorted_element = 0; unsorted_element < container.size(); ++unsorted_element)		// "container.size()" could be replaced with "S". Just to make a point.
	{
		for (std::size_t selected_element = 0; selected_element < container.size() -1 -unsorted_element; ++selected_element)
		{
			T& element_1 = container[selected_element + 0];
			T& element_2 = container[selected_element + 1];

			if(element_1 > element_2)
			{
				std::swap(element_1, element_2);
			}
		}
	}
};

template<typename T, std::size_t S>
static void ufo::sort::bubble_reverse_order(std::array<T, S>& container)
{
	for (std::size_t unsorted_element = 0; unsorted_element < container.size(); ++unsorted_element)
	{
		for (std::size_t selected_element = 0; selected_element < container.size() -1 -unsorted_element; ++selected_element)
		{
			T& element_1 = container[selected_element + 0];
			T& element_2 = container[selected_element + 1];

			if(element_1 > element_2)
			{
				std::swap(element_1, element_2);
			}
		}
	}
};

///////////////////////////////
// Bubble sort


///////////////////////////////////////////////////////////////////////
// STL - Array














// STL - Vector
///////////////////////////////////////////////////////////////////////


// Bubble sort
///////////////////////////////

template<typename T>
void ufo::sort::bubble(std::vector<T>& container, const ufo::sort::order& requested_order)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);

	if(is_forward_order)
	{
        ufo::sort::bubble_forward_order(container);

		return;
	}

    ufo::sort::bubble_reverse_order(container);
};

template<typename T>
static void ufo::sort::bubble_forward_order(std::vector<T>& container)
{
	for (typename std::vector<T>::iterator unsorted_element = container.begin(); unsorted_element != container.end(); ++unsorted_element)
	{
		for (typename std::vector<T>::iterator selected_element = container.begin(); selected_element != container.end() - 1; ++selected_element)
		{
			T& element_1 = *(selected_element + 0);
			T& element_2 = *(selected_element + 1);

			if(element_1 > element_2)
			{
				std::iter_swap(

					(selected_element + 0),
					(selected_element + 1)
				);
			}
		}
	}
};

template<typename T>
static void ufo::sort::bubble_reverse_order(std::vector<T>& container)
{
	for (typename std::vector<T>::iterator unsorted_element = container.begin(); unsorted_element != container.end(); ++unsorted_element)
	{
		for (typename std::vector<T>::iterator selected_element = container.begin(); selected_element != container.end() - 1; ++selected_element)
		{
			T& element_1 = *(selected_element + 0);
			T& element_2 = *(selected_element + 1);

			if(element_1 < element_2)
			{
				std::iter_swap(
					
					(selected_element + 0),
					(selected_element + 1)
				);
			}
		}
	}
};

///////////////////////////////
// Bubble sort


///////////////////////////////////////////////////////////////////////
// STL - Vector














// STL - General approach
///////////////////////////////////////////////////////////////////////


// Bubble sort
///////////////////////////////

template<typename Iterator>
void ufo::sort::bubble(Iterator begin, Iterator end, const ufo::sort::order& requested_order)
{
    bool is_forward_order = (requested_order == ufo::sort::order::forward_order);

	if(is_forward_order)
	{
        ufo::sort::bubble_forward_order(begin, end);

		return;
	}

    ufo::sort::bubble_reverse_order(begin, end);
};

template<typename Iterator>
static void ufo::sort::bubble_forward_order(Iterator begin, Iterator end)
{
	for (Iterator unsorted_element = begin; unsorted_element != end; ++unsorted_element)
	{
		for (Iterator selected_element = begin; selected_element != end - 1; ++selected_element)
		{
			bool is_bigger = *(selected_element + 0) > *(selected_element + 1);

			if(is_bigger)
			{
				std::iter_swap(

					(selected_element + 0),
					(selected_element + 1)
				);
			}
		}
	}
};

template<typename Iterator>
static void ufo::sort::bubble_reverse_order(Iterator begin, Iterator end)
{
	for (Iterator unsorted_element = begin; unsorted_element != end; ++unsorted_element)
	{
		for (Iterator selected_element = begin; selected_element != end - 1; ++selected_element)
		{
			bool is_smaller = *(selected_element + 0) < *(selected_element + 1);

			if(is_smaller)
			{
				std::iter_swap(

					(selected_element + 0),
					(selected_element + 1)
				);
			}
		}
	}
};

///////////////////////////////
// Bubble sort





template<typename T, std::size_t S>
void reverse(T(&container)[S])
{
	// A container of size (0) or (1) is already reversed.
	if(S == std::size_t(0) || S == std::size_t(1))
	{
		return;
	}


	for(std::size_t index = 0, middle = S / 2; index < middle; ++index)
	{
		std::swap(
			container[index],
			container[S - 1 - index]
		);
	}
};




///////////////////////////////////////////////////////////////////////
// STL - General approach
