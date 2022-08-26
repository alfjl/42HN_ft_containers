#pragma once

#include <memory>
#include <stdexcept>

#include "./utils/algorithm.hpp"
#include "./utils/functional.hpp"
#include "./utils/iterator.hpp"
#include "./utils/tree.hpp"
#include "./utils/type_traits.hpp"
#include "./utils/utility.hpp"

#ifndef nullptr
#define nullptr NULL
#endif

namespace ft
{

    /* --------------------------------- set -------------------------------- */

    /*
    ** (https://cplusplus.com/reference/set/set/?kw=set)
    ** Sets are containers that store unique elements following a specific order.
    ** In a set, the value of an element also identifies it
    ** (the value is itself the key, of type T), and each value must be unique.
    ** The value of the elements in a set cannot be modified once in the container
    ** (the elements are always const), but they can be inserted or removed from the container.
    ** Internally, the elements in a set are always sorted following a specific strict weak ordering criterion
    ** indicated by its internal comparison object (of type Compare).
    ** Sets are typically implemented as binary search trees.
    */
    template < typename T,                                                      // set::key_type/value_type
               typename Compare = less<T>,                                      // set::key_compare/value_compare
               typename Alloc = std::allocator<T> >                             // set::allocator_type
    class set
    {
    public:
        typedef T                                                               key_type;
        typedef T                                                               value_type;
        typedef Compare                                                         key_compare;
        typedef Compare                                                         value_compare;
        typedef Alloc                                                           allocator_type;
        typedef typename allocator_type::reference                              reference;
        typedef typename allocator_type::const_reference                        const_reference;
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;
        typedef typename allocator_type::size_type                              size_type;
        typedef typename allocator_type::difference_type                        difference_type;

    private:
        typedef ft::red_black_tree<value_type, value_compare, allocator_type>   base;

        base    tree;

    public:
        typedef typename base::const_iterator                                   iterator;
        typedef typename base::const_iterator                                   const_iterator;
        typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;

    public:
        // Constructors / Destructor / Assignment
        explicit set( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ); // default constructor (empty container)
        template <typename InputIterator>
            set( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type() ); // range constructor
        set( const set& src ); // copy constructor
        ~set(); // destructor

        set& operator=( const set& other ); // assignment operator

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

        // Modifiers:
        ft::pair<iterator,bool> insert( const value_type& val ); // single element
        iterator insert( iterator position, const value_type& val ); // with hint
        template <typename InputIterator>
            void insert( InputIterator first, InputIterator last ); // range
        void erase( iterator position ); // iterator
        size_type erase( const value_type& val ); // key
        void erase( iterator first, iterator last ); // range
        void swap( set& x );
        void clear();

        // Observers:
        key_compare key_comp() const;
        value_compare value_comp() const;

        // Operations:
        iterator find( const value_type& val ) const;
        size_type count( const value_type& val ) const;
        iterator lower_bound( const value_type& val ) const;
        iterator upper_bound( const value_type& val ) const;
        ft::pair<iterator,iterator> equal_range( const value_type& val ) const;

        // Allocator:
        allocator_type get_allocator() const;

        // Debugging:
        // void debug_print() const; // for debugging purposes only! // comment in for usage of debug_print()

    }; // set

    /* set member functions */
    /* public */

    template <typename T, typename Compare, typename Alloc>
    set<T,Compare,Alloc>::set( const key_compare& comp, const allocator_type& alloc ) // default constructor (empty container)
    : tree( comp, alloc ) {}

    template <typename T, typename Compare, typename Alloc>
    template <typename InputIterator>
    set<T,Compare,Alloc>::set( InputIterator first, InputIterator last, const key_compare& comp,
    const allocator_type& alloc ) // range constructor
    : tree( comp, alloc )
    {
        this->insert( first, last );
    }

    template <typename T, typename Compare, typename Alloc>
    set<T,Compare,Alloc>::set( const set& src ) // copy constructor
    : tree( src.tree ) {}

    template <typename T, typename Compare, typename Alloc>
    set<T,Compare,Alloc>::~set() {} // destructor

    template <typename T, typename Compare, typename Alloc>
    set<T,Compare,Alloc>& set<T,Compare,Alloc>::operator=( const set& other ) // assignment operator
    {
        if ( this != &other )
        {
            this->tree = other.tree;
        }
        return ( *this );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::iterator set<T,Compare,Alloc>::begin()
    {
        return ( this->tree.begin() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::const_iterator set<T,Compare,Alloc>::begin() const
    {
        return ( this->tree.begin() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::iterator set<T,Compare,Alloc>::end()
    {
        return ( this->tree.end() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::const_iterator set<T,Compare,Alloc>::end() const
    {
        return ( this->tree.end() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::reverse_iterator set<T,Compare,Alloc>::rbegin()
    {
        return ( reverse_iterator( this->end() ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::const_reverse_iterator set<T,Compare,Alloc>::rbegin() const
    {
        return ( const_reverse_iterator( this->end() ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::reverse_iterator set<T,Compare,Alloc>::rend()
    {
        return ( reverse_iterator( this->begin() ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::const_reverse_iterator set<T,Compare,Alloc>::rend() const
    {
        return ( const_reverse_iterator( this->begin() ) );
    }

    template <typename T, typename Compare, typename Alloc>
    bool set<T,Compare,Alloc>::empty() const
    {
        return ( this->tree.size() == 0 );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::size_type set<T,Compare,Alloc>::size() const
    {
        return ( this->tree.size() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::size_type set<T,Compare,Alloc>::max_size() const
    {
        return ( this->tree.max_size() );
    }

    template <typename T, typename Compare, typename Alloc>
    ft::pair<typename set<T,Compare,Alloc>::iterator,bool> set<T,Compare,Alloc>::insert( const value_type& val ) // single element
    {
        return ( this->tree.insert( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::iterator set<T,Compare,Alloc>::insert(__attribute__((unused)) iterator position, const value_type& val ) // with hint
    {
        return ( this->tree.insert( val ).first );
    }

    template <typename T, typename Compare, typename Alloc>
    template <typename InputIterator>
    void set<T,Compare,Alloc>::insert( InputIterator first, InputIterator last ) // range
    {
        this->tree.insert( first, last );
    }

    template <typename T, typename Compare, typename Alloc>
    void set<T,Compare,Alloc>::erase( iterator position ) // iterator
    {
        this->tree.erase( *( position ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::size_type set<T,Compare,Alloc>::erase( const value_type& val ) // key
    {
        return ( this->tree.erase( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    void set<T,Compare,Alloc>::erase( iterator first, iterator last ) // range
    {
        while ( first != last )
        this->tree.erase( *( first++ ) );
    }

    template <typename T, typename Compare, typename Alloc>
    void set<T,Compare,Alloc>::swap( set& x )
    {
        this->tree.swap( x.tree );
    }

    template <typename T, typename Compare, typename Alloc>
    void set<T,Compare,Alloc>::clear()
    {
        this->tree.clear();
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::key_compare set<T,Compare,Alloc>::key_comp() const
    {
        return ( key_compare() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::value_compare set<T,Compare,Alloc>::value_comp() const
    {
        return ( this->tree.value_comp() );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::iterator set<T,Compare,Alloc>::find( const value_type& val ) const
    {
        return ( this->tree.find( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::size_type set<T,Compare,Alloc>::count( const value_type& val ) const
    {
        return ( this->tree.count( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::iterator set<T,Compare,Alloc>::lower_bound( const value_type& val ) const
    {
        return ( this->tree.lower_bound( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::iterator set<T,Compare,Alloc>::upper_bound( const value_type& val ) const
    {
        return ( this->tree.upper_bound( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    ft::pair<typename set<T,Compare,Alloc>::iterator,
            typename set<T,Compare,Alloc>::iterator> 
            set<T,Compare,Alloc>::equal_range( const value_type& val ) const
    {
        return ( this->tree.equal_range( val ) );
    }

    template <typename T, typename Compare, typename Alloc>
    typename set<T,Compare,Alloc>::allocator_type set<T,Compare,Alloc>::get_allocator() const
    {
        return ( this->tree.get_allocator() );
    }

    // for debugging purposes only! // comment in for usage of debug_print()
    // template <typename T, typename Compare, typename Alloc>
    // void set<T,Compare,Alloc>::debug_print() const
    // {
    //     tree.debug_print();
    // }

    /* set non-member functions */

    template <typename T, typename Compare, typename Alloc>
    inline bool operator==( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs )
    {
        return ( lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
    }

    template <typename T, typename Compare, typename Alloc>
    inline bool operator!=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename T, typename Compare, typename Alloc>
    inline bool operator<( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs )
    {
        return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
    }

    template <typename T, typename Compare, typename Alloc>
    inline bool operator<=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs )
    {
        return ( !( rhs < lhs ) );
    }

    template <typename T, typename Compare, typename Alloc>
    inline bool operator>( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs )
    {
        return ( rhs < lhs );
    }

    template <typename T, typename Compare, typename Alloc>
    inline bool operator>=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs )
    {
        return ( !( lhs < rhs ) );
    }


    template <typename T, typename Compare, typename Alloc>
    void swap( ft::set<T,Compare,Alloc>& lhs, ft::set<T,Compare,Alloc>& rhs )
    {
        lhs.swap( rhs );
    }

} // namespace ft
