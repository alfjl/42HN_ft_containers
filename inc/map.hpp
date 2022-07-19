#pragma once

#include <memory>

#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/utility.hpp"
#include "utils/functional.hpp"

namespace ft
{

    /* --------------------------------- map --------------------------------- */

    /*
    ** (https://cplusplus.com/reference/map/map/)
    ** Maps are associative containers that store elements formed by a combination of a key value
    ** and a mapped value, following a specific order.
    ** In a map, the key values are generally used to sort and uniquely identify the elements,
    ** while the mapped values store the content associated to this key.
    ** The types of key and mapped value may differ,[...]
    ** Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion
    ** indicated by its internal comparison object (of type Compare).
    ** The mapped values in a map can be accessed directly by their corresponding key
    ** using the bracket operator ((operator[]).
    ** Maps are typically implemented as binary search trees.
    */

    template < typename Key,                                            // map::key_type
               typename T,                                              // map::mapped_type
               typename Compare = ft::less<Key>,                       // map::key_compare
               typename Alloc = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
    class map
    {

        // code....

    }

}