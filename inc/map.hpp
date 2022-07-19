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

    template < typename Key,                                                // map::key_type
               typename T,                                                  // map::mapped_type
               typename Compare = ft::less<Key>,                            // map::key_compare
               typename Alloc = std::allocator<ft::pair<const Key,T> > >    // map::allocator_type
    class map
    {
    public:
        typedef Key                                                                 key_type;
        typedef T                                                                   mapped_type;
        typedef ft::pair<const key_type, mapped_type>                               value_type;
        typedef Compare                                                             key_compare;
        // ????                                                                     value_compare;
        typedef Alloc                                                               allocator_type;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;

        class value_compare : public ft::binary_function<value_type, value_type, bool>
        {
            friend class map;
        
        protected:
            key_compare comp;

            value_compare( key_compare c ) : comp( c ) {}
        
        public:
            bool operator()( const value_type& x, const value_type& y ) const
            {
                return comp( x.first, y.first );
            }
        }; // value_compare

        typedef map_iterator<typename base::iterator>                               iterator;
        typedef map_const_iterator<typename base::const_iterator>                   const_iterator;
        typedef ft::reverse_iterator<iterator>                                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                const_reverse_iterator;

        typedef typename iterator_traits<iterator>::difference_type                 difference_type;
        typedef typename std::size_t                                                size_type;

    private:
        typedef ft::binary_search_tree<value_type, value_compare, allocator_type>   base;


        base    tree;

    }

}