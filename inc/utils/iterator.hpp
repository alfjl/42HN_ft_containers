#pragma once

#include <iterator>

namespace ft
{

    template <class Category,               // Category to which the iterator belongs to (see: 'iterator tags')
              class T,                      // Type of elements pointed by the iterator
              class Distance = ptrdiff_t,   // Type to represent the difference between two iterators
              class Pointer = T*,           // Type to represent a pointer to an element pointed by the iterator.
              class Reference = T&>         // Type to represent a reference to an element pointed by the iterator
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

} // namespace f