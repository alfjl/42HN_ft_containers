#pragma once

#include <memory>
#include <stdexcept>

#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/utility.hpp"
#include "utils/functional.hpp"
#include "utils/tree.hpp"
#include "./algorithm.hpp"

#ifndef nullptr
#define nullptr NULL
#endif

namespace ft
{

    /* --------------------------- Map Iterator ----------------------------- */

    /*
    ** A bidirectional_iterator, utilizing the iterator of the underlying tree
    */

    template<typename TreeIterator>
    class map_iterator
    {
    
    private:
        TreeIterator    _tree_iterator;

    public:
        typedef bidirectional_iterator_tag                  iterator_category;
        typedef typename TreeIterator::value_type           value_type;
        typedef typename TreeIterator::difference_type      difference_type;
        typedef typename TreeIterator::reference            reference;
        typedef typename TreeIterator::pointer              pointer;

        map_iterator();
        map_iterator( TreeIterator ite );

        reference operator*() const;
        pointer operator->() const;
        map_iterator& operator++();
        map_iterator operator++(int);
        map_iterator& operator--();
        map_iterator operator--(int);

        TreeIterator base() const;

    }; // map_iterator

    /* map_iterator member functions */

    template <typename TreeIterator>
    map_iterator<TreeIterator>::map_iterator() : _tree_iterator() {}

    template<typename TreeIterator>
    map_iterator<TreeIterator>::map_iterator( TreeIterator ite ) : _tree_iterator( ite ) {}


    template <typename TreeIterator>
    typename map_iterator<TreeIterator>::reference map_iterator<TreeIterator>::operator*() const
    {
        // return ( ite.get_value????? ); // TASK: write function
        return ( *( _tree_iterator ) );
    }

    template <typename TreeIterator>
    typename map_iterator<TreeIterator>::pointer map_iterator<TreeIterator>::operator->() const
    {
        // return ( &( *( _tree_iterator ) ) );
        return ( &( *( _tree_iterator ) ) );
    }

    template <typename TreeIterator>
    map_iterator<TreeIterator>& map_iterator<TreeIterator>::operator++()
    {
        ++( _tree_iterator );
        return ( *( this ) );
    }

    template <typename TreeIterator>
    map_iterator<TreeIterator> map_iterator<TreeIterator>::operator++(int)
    {
        map_iterator    temp( *( this ) );

        ++( *( this ) );
        return ( temp );
    }

    template <typename TreeIterator>
    map_iterator<TreeIterator>& map_iterator<TreeIterator>::operator--()
    {
        --( _tree_iterator );
        return ( *( this ) );
    }

    template <typename TreeIterator>
    map_iterator<TreeIterator> map_iterator<TreeIterator>::operator--(int)
    {
        map_iterator    temp( *( this ) );

        --( *( this ) );
        return ( temp );
    }

    template <typename TreeIterator>
    TreeIterator map_iterator<TreeIterator>::base() const
    {
        return ( this->_tree_iterator );
    }

    /* map_iterator non-member functions */

    template <typename TreeIterator>
    bool operator==( const map_iterator<TreeIterator>& lhs, const map_iterator<TreeIterator>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename TreeIterator>
    bool operator!=( const map_iterator<TreeIterator>& lhs, const map_iterator<TreeIterator>& rhs )
    {
        return ( !( lhs == rhs ) );
    }


    /* ------------------------ Map Const Iterator -------------------------- */

    /*
    ** A bidirectional_iterator, utilizing the const iterator of the
    ** underlying tree
    */

    template<typename TreeIterator>
    class map_const_iterator
    {
    
    private:
        TreeIterator    _tree_iterator;

    public:
        typedef bidirectional_iterator_tag                  iterator_category;
        typedef typename TreeIterator::value_type           value_type;
        typedef typename TreeIterator::difference_type      difference_type;
        typedef typename TreeIterator::reference            reference;
        typedef typename TreeIterator::pointer              pointer;
    
    public:
        map_const_iterator();
        map_const_iterator( TreeIterator ite );
        map_const_iterator( map_iterator<typename TreeIterator::non_const_iterator> other );

        reference operator*() const;
        pointer operator->() const;
        map_const_iterator& operator++();
        map_const_iterator operator++(int);
        map_const_iterator& operator--();
        map_const_iterator operator--(int);

        TreeIterator base() const;

    }; // map_const_iterator

    /* map_const_iterator member functions */

    template <typename TreeIterator>
    map_const_iterator<TreeIterator>::map_const_iterator() : _tree_iterator() {}

    template<typename TreeIterator>
    map_const_iterator<TreeIterator>::map_const_iterator( TreeIterator ite ) : _tree_iterator( ite ) {}

    template<typename TreeIterator> // TASK: still understand how to implement non_const_iterator here. maybe 'typedef typename tree_iterator::non_const_iterator'
    map_const_iterator<TreeIterator>::map_const_iterator( map_iterator<typename TreeIterator::non_const_iterator> other ) : _tree_iterator( other.base() ) {}

    template <typename TreeIterator>
    typename map_const_iterator<TreeIterator>::reference map_const_iterator<TreeIterator>::operator*() const
    {
        // return ( ite.get_value????? ); // TASK: write function
        return ( *( _tree_iterator ) );
    }

    template <typename TreeIterator>
    typename map_const_iterator<TreeIterator>::pointer map_const_iterator<TreeIterator>::operator->() const
    {
        return ( &( *( _tree_iterator ) ) );
    }

    template <typename TreeIterator>
    map_const_iterator<TreeIterator>& map_const_iterator<TreeIterator>::operator++()
    {
        ++( _tree_iterator );
        return ( *( this ) );
    }

    template <typename TreeIterator>
    map_const_iterator<TreeIterator> map_const_iterator<TreeIterator>::operator++(int)
    {
        map_const_iterator    temp( *( this ) );

        ++( *( this ) );
        return ( temp );
    }

    template <typename TreeIterator>
    map_const_iterator<TreeIterator>& map_const_iterator<TreeIterator>::operator--()
    {
        --( _tree_iterator );
        return ( *( this ) );
    }

    template <typename TreeIterator>
    map_const_iterator<TreeIterator> map_const_iterator<TreeIterator>::operator--(int)
    {
        map_const_iterator    temp( *( this ) );

        --( *( this ) );
        return ( temp );
    }

    template <typename TreeIterator>
    TreeIterator map_const_iterator<TreeIterator>::base() const
    {
        return ( this->_tree_iterator );
    }

    /* map_const_iterator non-member functions */

    template <typename TreeIterator>
    bool operator==( const map_const_iterator<TreeIterator>& lhs, const map_const_iterator<TreeIterator>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename TreeIterator>
    bool operator!=( const map_const_iterator<TreeIterator>& lhs, const map_const_iterator<TreeIterator>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename TreeIterator, typename TreeIterator2>
    bool operator==( const map_iterator<TreeIterator2>& lhs, const map_const_iterator<TreeIterator>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename TreeIterator, typename TreeIterator2>
    bool operator!=( const map_iterator<TreeIterator2>& lhs, const map_const_iterator<TreeIterator>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename TreeIterator, typename TreeIterator2>
    bool operator==( const map_const_iterator<TreeIterator>& lhs, const map_iterator<TreeIterator2>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename TreeIterator, typename TreeIterator2>
    bool operator!=( const map_const_iterator<TreeIterator>& lhs, const map_iterator<TreeIterator2>& rhs )
    {
        return ( !( lhs == rhs ) );
    }


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

    template < typename Key,                                                        // map::key_type
               typename T,                                                          // map::mapped_type
               typename Compare = ft::less<Key>,                                    // map::key_compare
               typename Alloc = std::allocator<ft::pair<const Key, T> > >            // map::allocator_type
    class map
    {
    public:
        typedef Key                                                                 key_type;
        typedef T                                                                   mapped_type;
        typedef Compare                                                             key_compare;
        typedef Alloc                                                               allocator_type;
        typedef ft::pair<const key_type, mapped_type>                               value_type;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;
        typedef typename allocator_type::size_type                                  size_type;
        typedef typename allocator_type::difference_type                            difference_type;


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
        // typedef ft::red_black_tree<value_type, value_compare, allocator_type>   base;
        typedef ft::binary_search_tree<value_type, value_compare, allocator_type>   base; // needs to be adapted to RB Tree, after initial testing phase!

        base    tree;

    public:
        typedef map_iterator<typename base::iterator>                           iterator;
        typedef map_const_iterator<typename base::const_iterator>               const_iterator;
        typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;
        // typedef typename iterator_traits<iterator>::difference_type             difference_type;
        // typedef typename std::size_t                                            size_type;

        // Steffens version (without added map_iterator)
        // public: // iterator types
        //     typedef typename tree_type::iterator				iterator;
        //     typedef typename tree_type::const_iterator			const_iterator;
        //     typedef typename tree_type::reverse_iterator		reverse_iterator;
        //     typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

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
        mapped_type& at (const key_type& k);
        const mapped_type& at (const key_type& k) const;

        // Modifiers:
        ft::pair<iterator,bool> insert( const value_type& val ); // single element
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
        ft::pair<const_iterator,const_iterator> equal_range( const key_type& k ) const;
        ft::pair<iterator,iterator> equal_range( const key_type& k );

        // Allocator:
        allocator_type get_allocator() const;

        // Debugging:
            void debug_print() const; // only for debugging purposes

    }; // map

    /* map member functions */
    /* public */

    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>::map( const key_compare& comp, const allocator_type& alloc ) // default constructor (empty container)
    : tree( value_compare( comp ), alloc ) {}

    template <typename Key, typename T, typename Compare, typename Alloc>
    template <typename InputIterator>
    map<Key,T,Compare,Alloc>::map( InputIterator first, InputIterator last, const key_compare& comp,
    const allocator_type& alloc ) // range constructor
    : tree( value_compare( comp ), alloc )
    {
        // std::cout << "----------in range constr of map ----------" << std::endl; // TPO
        this->insert( first, last );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>::map( const map& src ) // copy constructor
    : tree( src.tree ) {
        // std::cout << "---------- copy constr of map ----------" << std::endl; // TPO
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>::~map() {} // destructor

    template <typename Key, typename T, typename Compare, typename Alloc>
    map<Key,T,Compare,Alloc>& map<Key,T,Compare,Alloc>::operator=( const map& other ) // assignment operator
    {
        // std::cout << "---------- operator= of map ----------" << std::endl; // TPO
        if ( this != &other )
        {
            this->tree = other.tree;
        }
        return ( *this );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::begin()
    {
        return ( this->tree.begin() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::begin() const
    {
        return ( this->tree.begin() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::end()
    {
        return ( this->tree.end() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::end() const
    {
        return ( this->tree.end() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::reverse_iterator map<Key,T,Compare,Alloc>::rbegin()
    {
        return ( reverse_iterator( this->end() ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_reverse_iterator map<Key,T,Compare,Alloc>::rbegin() const
    {
        return ( const_reverse_iterator( this->end() ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::reverse_iterator map<Key,T,Compare,Alloc>::rend()
    {
        return ( reverse_iterator( this->begin() ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_reverse_iterator map<Key,T,Compare,Alloc>::rend() const
    {
        return ( const_reverse_iterator( this->begin() ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    bool map<Key,T,Compare,Alloc>::empty() const
    {
        return ( this->tree.size() == 0 );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::size() const
    {
        return ( this->tree.size() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::max_size() const
    {
        return ( this->tree.max_size() );
    }

    // https://cplusplus.com/reference/map/map/operator[]/
    // Access element
    // If k matches the key of an element in the container, the function returns a reference to its mapped value.
    // If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value.
    // Notice that this always increases the container size by one, even if no mapped value is assigned to the element (the element is constructed using its default constructor).
    // A similar member function, map::at, has the same behavior when an element with the key exists, but throws an exception when it does not.
    // A call to this function is equivalent to:
    // (*((this->insert(make_pair(k,mapped_type()))).first)).second
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::mapped_type& map<Key,T,Compare,Alloc>::operator[]( const key_type& k )
    {
        iterator position = this->insert( ft::make_pair( k, mapped_type() ) ).first;
        return ( ( *( position ) ).second );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::mapped_type& map<Key,T,Compare,Alloc>::at (const key_type& k)
    {
        iterator position = this->find( k );

        if ( position.base() == this->tree.end() )
            throw std::out_of_range( "ft::map" );
        return ( ( *( position ) ).second );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    const typename map<Key,T,Compare,Alloc>::mapped_type& map<Key,T,Compare,Alloc>::at (const key_type& k) const
    {
        const_iterator position = this->find( k );

        if ( position.base() == this->tree.end() )
            throw std::out_of_range( "ft::map" );
        return ( ( *( position ) ).second );
    }


    template <typename Key, typename T, typename Compare, typename Alloc>
    ft::pair<typename map<Key,T,Compare,Alloc>::iterator,bool> map<Key,T,Compare,Alloc>::insert( const value_type& val ) // single element
    {
        return ( this->tree.insert( val ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::insert( iterator position, const value_type& val ) // with hint
    {
        // return ( this->tree.insert( position, val ) );

        typename base::iterator x = position.base();

        return ( this->tree.insert( x, val ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    template <typename InputIterator>
    void map<Key,T,Compare,Alloc>::insert( InputIterator first, InputIterator last ) // range
    {
        // std::cout << "----------in range insert of map ----------" << std::endl; // TPO
        this->tree.insert( first, last );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::erase( iterator position ) // iterator
    {
        this->tree.erase( position.base() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::erase( const key_type& k ) // key
    {
        return ( this->tree.erase( ft::make_pair( k, mapped_type() ) ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::erase( iterator first, iterator last ) // range
    {
        this->tree.erase( first.base(), last.base() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::swap( map& x )
    {
        this->tree.swap( x.tree );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::clear()
    {
        this->tree.clear();
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::key_compare map<Key,T,Compare,Alloc>::key_comp() const
    {
        return ( key_compare() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::value_compare map<Key,T,Compare,Alloc>::value_comp() const
    {
        return ( this->tree.value_comp() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::find( const key_type& k )
    {
        return ( this->tree.find( ft::make_pair( k, mapped_type() ) ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::find( const key_type& k ) const
    {
        return ( this->tree.find( ft::make_pair( k, mapped_type() ) ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::size_type map<Key,T,Compare,Alloc>::count( const key_type& k ) const
    {
        return ( this->tree.count( ft::make_pair( k, mapped_type() ) ) );
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::lower_bound( const key_type& k )
    {
        return ( this->tree.lower_bound( ft::make_pair( k, mapped_type() ) ) );
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::lower_bound( const key_type& k ) const
    {
        return ( this->tree.lower_bound( ft::make_pair( k, mapped_type() ) ) );
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::iterator map<Key,T,Compare,Alloc>::upper_bound( const key_type& k )
    {
        return ( this->tree.upper_bound( ft::make_pair( k, mapped_type() ) ) );
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::const_iterator map<Key,T,Compare,Alloc>::upper_bound( const key_type& k ) const
    {
        return ( this->tree.upper_bound( ft::make_pair( k, mapped_type() ) ) );
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    ft::pair<typename map<Key,T,Compare,Alloc>::const_iterator,
            typename map<Key,T,Compare,Alloc>::const_iterator> 
            map<Key,T,Compare,Alloc>::equal_range( const key_type& k ) const
    {
        return ( this->tree.equal_range( ft::make_pair( k, mapped_type() ) ) );
    }
    
    template <typename Key, typename T, typename Compare, typename Alloc>
    ft::pair<typename map<Key,T,Compare,Alloc>::iterator,
            typename map<Key,T,Compare,Alloc>::iterator> 
            map<Key,T,Compare,Alloc>::equal_range( const key_type& k )
    {
        return ( this->tree.equal_range( ft::make_pair( k, mapped_type() ) ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    typename map<Key,T,Compare,Alloc>::allocator_type map<Key,T,Compare,Alloc>::get_allocator() const
    {
        // return ( allocator_type( this->tree.get_allocator() ) ); // Version from STL, or:
        return ( this->tree.get_allocator() );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    void map<Key,T,Compare,Alloc>::debug_print() const
    {
        tree.debug_print();
    }

    /* map non-member functions */

    template <typename Key, typename T, typename Compare, typename Alloc>
    inline bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return ( lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    inline bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    inline bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    inline bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return ( !( rhs < lhs ) );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    inline bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return ( rhs < lhs );
    }

    template <typename Key, typename T, typename Compare, typename Alloc>
    inline bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return ( !( lhs < rhs ) );
    }


    template <typename Key, typename T, typename Compare, typename Alloc>
    void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
    {
        lhs.swap( rhs );
    }

} // namespace ft
