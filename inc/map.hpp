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


        /* -------------------------- value_compare -------------------------- */

        /*
        ** (https://en.cppreference.com/w/cpp/container/map/value_compare)
        ** ft::map::value_compare is a function object that compares objects
        ** of type ft::map::value_type (key-value pairs) by comparing of the first components of the pairs.
        **
        ** (https://cplusplus.com/reference/map/map/value_comp/)
        ** The public member of this comparison class returns true
        ** if the key of the first argument is considered to go before that of the second
        ** (according to the strict weak ordering specified by the container's comparison object, key_comp),
        ** and false otherwise.
        */

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

    private:
        typedef ft::binary_search_tree<value_type, value_compare, allocator_type>   base;

        base    tree;

    public:
        typedef map_iterator<typename base::iterator>                               iterator;
        typedef map_const_iterator<typename base::const_iterator>                   const_iterator;
        typedef ft::reverse_iterator<iterator>                                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                const_reverse_iterator;

        typedef typename iterator_traits<iterator>::difference_type                 difference_type;
        typedef typename std::size_t                                                size_type;

        // Constructors / Destructor / Assignment
        explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ); // default constructor (empty container)
        template <typename InputIterator>
            map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type() ); // range constructor
        map( const map& src ); // copy constructor
        ~map(); // destructor

        map& operator=( const map& other ); // assignment operator

        // Iterators:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // Capacity:
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        // Element access:
        mapped_type& operator[]( const key_type& k );

        // Modifiers:
        pair<iterator,bool> insert( const value_type& val ); // single element
        iterator insert( iterator position, const value_type& val ); // with hint
        template <typename InputIterator>
            void insert( InputIterator first, InputIterator last ); // range
        void erase( iterator position ); // iterator
        size_type erase( const key_type& k ); // key
        void erase( iterator first, iterator last ); // range
        void swap( map& x );
        void clear();

        // Observers:
        key_compare key_comp() const;
        value_compare value_comp() const;

        // Operations:
        iterator find( const key_type& k );
        const_iterator find( const key_type& k ) const;
        size_type count( const key_type& k ) const;
        iterator lower_bound( const key_type& k );
        const_iterator lower_bound( const key_type& k ) const;
        iterator upper_bound( const key_type& k );
        const_iterator upper_bound( const key_type& k ) const;
        pair<const_iterator,const_iterator> equal_range( const key_type& k ) const;
        pair<iterator,iterator> equal_range( const key_type& k );

        // Allocator:
        allocator_type get_allocator() const;

    }; // map

    /* map member functions */
    /* public */

    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>::map( const key_compare& comp, const allocator_type& alloc ) // default constructor (empty container)
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    template <typename InputIterator>
    map<Key,T,Compare,Alloc>::map( InputIterator first, InputIterator last, const key_compare& comp,
    const allocator_type& alloc ) // range constructor
    {
        
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>::map( const map& src ) // copy constructor
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>::~map() // destructor
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>& map<Key,T,Compare,Alloc>::operator=( const map& other ) // assignment operator
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::begin()
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::begin() const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::end()
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::end() const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::reverse_iterator map<Key,T,Compare,Alloc>::rbegin()
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_reverse_iterator map<Key,T,Compare,Alloc>::rbegin() const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::reverse_iterator map<Key,T,Compare,Alloc>::rend()
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_reverse_iterator map<Key,T,Compare,Alloc>::rend() const
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    bool map<Key,T,Compare,Alloc>::empty() const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::size() const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::max_size() const
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::mapped_type& map<Key,T,Compare,Alloc>::operator[]( const key_type& k )
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    ft::pair<iterator,bool> map<Key,T,Compare,Alloc>::insert( const value_type& val ) // single element
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::insert( iterator position, const value_type& val ) // with hint
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    template <typename InputIterator>
    void map<Key,T,Compare,Alloc>::insert( InputIterator first, InputIterator last ) // range
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::erase( iterator position ) // iterator
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::erase( const key_type& k ) // key
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::erase( iterator first, iterator last ) // range
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::swap( map& x )
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::clear()
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::key_compare map<Key,T,Compare,Alloc>::key_comp() const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::value_compare map<Key,T,Compare,Alloc>::value_comp() const
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::find( const key_type& k )
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::find( const key_type& k ) const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::count( const key_type& k ) const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::lower_bound( const key_type& k )
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::lower_bound( const key_type& k ) const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::upper_bound( const key_type& k )
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::upper_bound( const key_type& k ) const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    ft::pair<const_iterator,const_iterator> map<Key,T,Compare,Alloc>::equal_range( const key_type& k ) const
    {

    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    ft::pair<iterator,iterator> map<Key,T,Compare,Alloc>::equal_range( const key_type& k )
    {

    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::allocator_type map<Key,T,Compare,Alloc>::get_allocator() const
    {

    }


    /* vector non-member functions */  STILL fix declaration and arguments!!!!!

    // template <typename Key, typename T, typename Compare, typename Alloc>
    // inline bool operator==( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    // {
    //     return ( lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
    // }

    // template <typename Key, typename T, typename Compare, typename Alloc>
    // inline bool operator!=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    // {
    //     return ( !( lhs == rhs ) );
    // }

    // template <typename Key, typename T, typename Compare, typename Alloc>
    // inline bool operator<( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    // {
    //     return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
    // }

    // template <typename Key, typename T, typename Compare, typename Alloc>
    // inline bool operator<=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    // {
    //     return ( !( rhs < lhs ) );
    // }

    // template <typename Key, typename T, typename Compare, typename Alloc>
    // inline bool operator>( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    // {
    //     return ( rhs < lhs );
    // }

    // template <typename Key, typename T, typename Compare, typename Alloc>
    // inline bool operator>=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    // {
    //     return ( !( lhs < rhs ) );
    // }


    // template <typename Key, typename T, typename Compare, typename Alloc>
    // void swap( vector<T, Alloc>& lhs, vector<T, Alloc>& rhs )
    // {
    //     lhs.swap( rhs );
    // }

} // namespace ft