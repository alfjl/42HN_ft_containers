#pragma once

#include <iostream> // for debug_print() only! // comment in for usage of debug_print()
#include <memory>

#include "./iterator.hpp"
#include "./functional.hpp"
#include "./utility.hpp"

#ifndef nullptr
#define nullptr NULL
#endif

namespace ft
{

    /* ----------------------------- tree_node ------------------------------ */

    /*
    ** A general node template to be used in my implementations of 
    ** Binary Search Tree (BST) and Red Black Tree (RBT)
    ** Colour is unused in BST and set to default 'BLACK'
    */

    enum node_state
    {
        RED = 1,
        BLACK = 0
    };

    template <typename T>
    class tree_node
    {

    public:
        typedef T                               value_type;
        typedef tree_node<value_type>*          node_ptr;
        typedef const tree_node<value_type>*    const_node_ptr;
        typedef tree_node<value_type>&          node_ref;
        typedef const tree_node<value_type>&    const_node_ref;

    public:
        T                   _data;
        node_state          _colour;
        node_ptr            _parent;
        node_ptr            _left;
        node_ptr            _right;

    public:
        tree_node();
        tree_node( const value_type& value );
        tree_node( const tree_node& other);
        ~tree_node();

        tree_node& operator=( const tree_node& src );
    
    private:
        void change_colour();

    }; // tree_node

    /* tree_node member functions */
    /* public */

    template <typename T>
    tree_node<T>::tree_node() : _data(), _colour( BLACK ), _parent( nullptr ), _left( nullptr ), _right( nullptr ) {}

    template <typename T>
    tree_node<T>::tree_node( const value_type& value ) : _data( value ), _colour( BLACK ), _parent( nullptr ), _left( nullptr ), _right( nullptr ) {}

    template <typename T>
    tree_node<T>::tree_node( const tree_node& other) : _data( other._data ), _colour( other._colour ), _parent( other._parent ), _left( other._left ), _right( other._right ) {}

    template <typename T>
    tree_node<T>::~tree_node() {}

    template <typename T>
    tree_node<T>& tree_node<T>::operator=( const tree_node& src )
    {
        if ( this != &src )
        {
            this->_colour = src._colour;
            this->_data = src._data;
            this->_parent = src._parent;
            this->_left = src._left;
            this->_right = src._right;
        }
        return ( *( this ) );
    }

    /* private */

    template <typename T>
    void tree_node<T>::change_colour()
    {
        this->_colour = ( this->_colour == RED ) ? BLACK : RED;
    }


    /* ----------------------- tree utility functions ----------------------- */

    /*
    ** A collection of useful algorithms and utility functions
    ** for the implemented binary search tree or red black tree
    */

    template <typename T>
    typename tree_node<T>::node_ptr tree_min( typename tree_node<T>::node_ptr nodeptr )
    {
        while ( nodeptr != nullptr && nodeptr->_left->_left != nullptr ) // equals this->_null
            nodeptr = nodeptr->_left;
        return ( nodeptr );
    }

    template <typename T>
    typename tree_node<T>::const_node_ptr tree_min( typename tree_node<T>::const_node_ptr nodeptr )
    {
        while ( nodeptr != nullptr || nodeptr->_left->_left != nullptr ) // equals this->_null
            nodeptr = nodeptr->_left;
        return ( nodeptr );
    }

    template <typename T>
    typename tree_node<T>::node_ptr tree_max( typename tree_node<T>::node_ptr nodeptr )
    {
        while ( nodeptr->_right->_right != nullptr ) // equals this->_null
            nodeptr = nodeptr->_right;
        return ( nodeptr );
    }

    template <typename T>
    typename tree_node<T>::const_node_ptr tree_max( typename tree_node<T>::const_node_ptr nodeptr )
    {
        while ( nodeptr->_right->_right != nullptr ) // equals this->_null
            nodeptr = nodeptr->_right;
        return ( nodeptr );
    }

    template <typename T>
    bool tree_is_left_child( typename tree_node<T>::node_ptr nodeptr )
    {
        return ( nodeptr == nodeptr->_parent->_left );
    }

    template <typename T>
    bool tree_is_left_child( typename tree_node<T>::const_node_ptr nodeptr )
    {
        return ( nodeptr == nodeptr->_parent->_left );
    }


    /* --------------------------- Tree Iterator ---------------------------- */

    /*
    ** A bidirectional_iterator, with typenames NodePtr and T
    */

    template <typename NodePtr, typename T>
    class tree_iterator
    {
    public:
        typedef bidirectional_iterator_tag          iterator_category;
        typedef T                                   value_type;
        typedef ptrdiff_t                           difference_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;

    private:
        NodePtr _node_ptr;

    public:
        tree_iterator();
        tree_iterator( const NodePtr& ptr );
        tree_iterator( const tree_iterator& other );
        ~tree_iterator();

        tree_iterator& operator=( const tree_iterator& src );
        tree_iterator& operator=( const NodePtr& src_ptr );

        NodePtr base() const;
        reference operator*() const;
        pointer operator->() const;
        tree_iterator& operator++();
        tree_iterator  operator++(int);
        tree_iterator& operator--();
        tree_iterator  operator--(int);

    }; // tree_iterator

    /* tree_iterator member functions */
    
    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>::tree_iterator() : _node_ptr() {}

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>::tree_iterator( const NodePtr& ptr ) : _node_ptr( ptr ) {}
    
    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>::tree_iterator( const tree_iterator& other ) : _node_ptr( other._node_ptr ) {}

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>::~tree_iterator() {}


    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>& tree_iterator<NodePtr, T>::operator=( const tree_iterator& src )
    {
        if ( this != &src )
            this->_node_ptr = src._node_ptr;
        return ( *this );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>& tree_iterator<NodePtr, T>::operator=( const NodePtr& src_ptr )
    {
        this->_node_ptr = src_ptr;
        return ( *this );
    }

    template <typename NodePtr, typename T>
    NodePtr tree_iterator<NodePtr, T>::base() const
    {
        return ( this->_node_ptr );
    }

    template <typename NodePtr, typename T>
    typename tree_iterator<NodePtr, T>::reference tree_iterator<NodePtr, T>::operator*() const
    {
        return ( this->_node_ptr->_data );
    }

    template <typename NodePtr, typename T>
    typename tree_iterator<NodePtr, T>::pointer tree_iterator<NodePtr, T>::operator->() const
    {
        return ( &( this->_node_ptr->_data ) );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>& tree_iterator<NodePtr, T>::operator++()
    {
        if ( this->_node_ptr->_right->_right != nullptr ) // equals 'this->_node_ptr->_right == this->_null'
            this->_node_ptr = tree_min<value_type>( this->_node_ptr->_right );
        else
        {
            while ( !( tree_is_left_child<value_type>( this->_node_ptr ) )
            && ( this->_node_ptr->_parent->_parent != nullptr ) )
                this->_node_ptr = this->_node_ptr->_parent;
            this->_node_ptr = this->_node_ptr->_parent;
        }
        return ( *( this ) );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>  tree_iterator<NodePtr, T>::operator++( int )
    {
        tree_iterator   it = *( this );

        ++( *( this ) );
        return ( it );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>& tree_iterator<NodePtr, T>::operator--()
    {
        if ( this->_node_ptr->_left->_left != nullptr ) // equals 'this->_node_ptr->_left == this->_null'
            this->_node_ptr = tree_max<value_type>( this->_node_ptr->_left );
        else
        {
            while ( tree_is_left_child<value_type>( this->_node_ptr ) )
                this->_node_ptr = this->_node_ptr->_parent;
            this->_node_ptr = this->_node_ptr->_parent;
        }
        return ( *( this ) );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>  tree_iterator<NodePtr, T>::operator--( int )
    {
        tree_iterator   it = *( this );

        --( *( this ) );
        return ( it );
    }

    /* tree_iterator non-member functions */

    template <typename NodePtr, typename T>
    bool operator==( const tree_iterator<NodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename NodePtr, typename T>
    bool operator!=( const tree_iterator<NodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs )
    {
        return ( !( lhs == rhs ) );
    }


    /* ------------------------ Tree Const Iterator ------------------------- */

    /*
    ** A bidirectional_iterator, with typenames ConstNodePtr and T
    */

    template <typename ConstNodePtr, typename T>
    class tree_const_iterator
    {

    public:
        typedef bidirectional_iterator_tag      iterator_category;
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;

    public: // needs to be public for current implementation of 'map_const_iterator( map_iterator<typename TreeIterator::non_const_iterator> other )' to work
        typedef tree_iterator<typename tree_node<T>::node_ptr, value_type>  non_const_iterator;

    private:
        ConstNodePtr _node_ptr;

    public:
        tree_const_iterator();
        tree_const_iterator( const ConstNodePtr& ptr );
        tree_const_iterator( const tree_const_iterator& other );
        tree_const_iterator( const non_const_iterator& other );
        ~tree_const_iterator();

        tree_const_iterator& operator=( const tree_const_iterator& src );
        tree_const_iterator& operator=( const ConstNodePtr& src_ptr );

        ConstNodePtr base() const;
        reference operator*() const;
        pointer operator->() const;
        tree_const_iterator& operator++();
        tree_const_iterator  operator++(int);
        tree_const_iterator& operator--();
        tree_const_iterator  operator--(int);

    }; // tree_const_iterator

    /* tree_const_iterator member functions */
    
    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator() : _node_ptr() {}

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( const ConstNodePtr& ptr ) : _node_ptr( ptr ) {}    

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( const tree_const_iterator& other ) : _node_ptr( other._node_ptr ) {}

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( const non_const_iterator& other ) : _node_ptr( other.base() ) {}

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::~tree_const_iterator() {}


    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>& tree_const_iterator<ConstNodePtr, T>::operator=( const tree_const_iterator& src )
    {
        if ( this != &src )
            this->_node_ptr = src._node_ptr;
        return ( *this );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>& tree_const_iterator<ConstNodePtr, T>::operator=( const ConstNodePtr& src_ptr )
    {
        this->_node_ptr = src_ptr;
        return ( *this );
    }

    template <typename ConstNodePtr, typename T>
    ConstNodePtr tree_const_iterator<ConstNodePtr, T>::base() const
    {
        return ( this->_node_ptr );
    }

    template <typename ConstNodePtr, typename T>
    typename tree_const_iterator<ConstNodePtr, T>::reference tree_const_iterator<ConstNodePtr, T>::operator*() const
    {
        return ( this->_node_ptr->_data );
    }

    template <typename ConstNodePtr, typename T>
    typename tree_const_iterator<ConstNodePtr, T>::pointer tree_const_iterator<ConstNodePtr, T>::operator->() const
    {
        return ( &( this->_node_ptr->_data ) );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>& tree_const_iterator<ConstNodePtr, T>::operator++()
    {
        if ( this->_node_ptr->_right->_right != nullptr ) // equals 'this->_node_ptr->_right == this->_null'
            this->_node_ptr = tree_min<value_type>( this->_node_ptr->_right );
        else
        {
            while ( !( tree_is_left_child<value_type>( this->_node_ptr ) ) )
                this->_node_ptr = this->_node_ptr->_parent;
            this->_node_ptr = this->_node_ptr->_parent;
        }
        return ( *( this ) );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>  tree_const_iterator<ConstNodePtr, T>::operator++( int )
    {
        tree_const_iterator   it = *( this );

        ++( *( this ) );
        return ( it );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>& tree_const_iterator<ConstNodePtr, T>::operator--()
    {
        if ( this->_node_ptr->_left->_left != nullptr ) // equals 'this->_node_ptr->_left == this->_null'
            this->_node_ptr = tree_max<value_type>( this->_node_ptr->_left );
        else
        {
            while ( tree_is_left_child<value_type>( this->_node_ptr ) )
                this->_node_ptr = this->_node_ptr->_parent;
            this->_node_ptr = this->_node_ptr->_parent;
        }
        return ( *( this ) );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>  tree_const_iterator<ConstNodePtr, T>::operator--( int )
    {
        tree_const_iterator   it = *( this );

        --( *( this ) );
        return ( it );
    }

    /* tree_const_iterator non-member functions */

    template <typename ConstNodePtr, typename T>
    inline bool operator==( const tree_const_iterator<ConstNodePtr, T>& lhs, const tree_const_iterator<ConstNodePtr, T>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename ConstNodePtr, typename T>
    inline bool operator!=( const tree_const_iterator<ConstNodePtr, T>& lhs, const tree_const_iterator<ConstNodePtr, T>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename ConstNodePtr, typename NodePtr, typename T>
    inline bool operator==( const tree_iterator<NodePtr, T>& lhs, const tree_const_iterator<ConstNodePtr, T>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename ConstNodePtr, typename NodePtr, typename T>
    inline bool operator!=( const tree_iterator<NodePtr, T>& lhs, const tree_const_iterator<ConstNodePtr, T>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

        template <typename ConstNodePtr, typename NodePtr, typename T>
    inline bool operator==( const tree_const_iterator<ConstNodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename ConstNodePtr, typename NodePtr, typename T>
    inline bool operator!=( const tree_const_iterator<ConstNodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs )
    {
        return ( !( lhs == rhs ) );
    }


    /* --------------------------- Red Black Tree --------------------------- */

    /*
    ** (Cormen, Leiserson, Rivest & Stein: 'Introduction to Algorithms' - 3rd Edition, Chapter 13)
    ** A red-black tree is a binary search tree with one extra bit of storage per node:
    ** its color, which can be either RED or BLACK.
    ** By constraining the node colors on any simple path from the root to a leaf,
    ** red-black trees ensure that no such path is more than twice as long as any other,
    ** so that the tree is approximately balanced.
    **
    ** If a child or the parent of a node does not exist, the corresponding pointer attribute
    ** of the node contains the value NIL. We shall regard these NILs as being pointers to
    ** leaves (external nodes) of the binary search tree and the normal, key-bearing nodes
    ** as being internal nodes of the tree.
    **
    ** A red-black tree [...] satisfies the following red-black properties:
    ** 1. Every node is either red or black.
    ** 2. The root is black.
    ** 3. Every leaf ( NIL ) is black.
    ** 4. If a node is red, then both its children are black.
    ** 5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes
    */

    template <typename T, typename Compare, typename Allocator>
    class red_black_tree
    {

    private:
        typedef ft::tree_node<T>                                            node_type;
        typedef typename node_type::node_ptr                                node_type_ptr;
        typedef typename node_type::const_node_ptr                          const_node_type_ptr;
        typedef typename node_type::node_ref                                node_type_ref;
        typedef typename node_type::const_node_ref                          const_node_type_ref;

    public:
        typedef T                                                           value_type;
        typedef Compare                                                     value_compare;
        typedef Allocator                                                   allocator_type;
        typedef typename allocator_type::template rebind<node_type>::other  node_allocator_type;
        typedef typename allocator_type::size_type                          size_type;
        typedef typename allocator_type::difference_type                    difference_type;
        typedef typename allocator_type::reference                          reference;
        typedef typename allocator_type::const_reference                    const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;
        typedef ft::tree_iterator<node_type_ptr, value_type>                iterator;
        typedef ft::tree_const_iterator<const_node_type_ptr, value_type>    const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

    // private: // TODO: Change back to private
    public:
        node_type           _base; // first node in tree. _base->_left is root node
        node_type_ptr       _null; // every node_direction without attached child points onto this node (instead of nullptr)
        node_type_ptr       _begin_node; // left-most node, a.k.a node with smallest key
        value_compare       _compare; 
        allocator_type      _allocator;
        node_allocator_type _node_allocator;
        size_type           _size;

    public:
        // Constructors / Destructor / Assignment
        explicit red_black_tree( const value_compare& comp = Compare(), const allocator_type& alloc = Allocator() );
	    red_black_tree( const red_black_tree& other );
        ~red_black_tree();

    	red_black_tree& operator=( const red_black_tree& other );

        // Iterators:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // Capacity
        size_type size() const;
        size_type max_size() const;

        // Modifiers:
        ft::pair<iterator,bool> insert( const value_type& value); // single element
        iterator insert( iterator position, const value_type& value); // with hint
        template <typename InputIterator>
            void insert( InputIterator first, InputIterator last ); // range
        void erase( iterator position ); // iterator
        size_type erase( const value_type& value); // key
        void erase( iterator first, iterator last ); // range
        void swap( red_black_tree& x );
        void clear();

        // Operations:
        iterator find( const value_type& value );
        const_iterator find( const value_type& value ) const;
        size_type count( const value_type& value ) const;
        iterator lower_bound( const value_type& value );
        const_iterator lower_bound( const value_type& value ) const;
        iterator upper_bound( const value_type& value );
        const_iterator upper_bound( const value_type& value ) const;
        ft::pair<iterator,iterator> equal_range( const value_type& value );
        ft::pair<const_iterator,const_iterator> equal_range( const value_type& value ) const;
        void debug_print() const; // only for debugging purposes // comment in for usage of debug_print()

        // Allocator / Compare:
        allocator_type get_allocator() const;
        void destroy_node( node_type_ptr node );
        value_compare value_comp() const;

    private:
        void _create_null();
        void _init_root( node_type_ptr &new_node, node_type_ptr &position );
        ft::pair<iterator, bool> _insert( node_type_ptr rootptr, const value_type& value ); // helper function for all insert methods
        void _transplant( node_type_ptr old_subtree, node_type_ptr new_subtree ); // helper function for erase()
        bool _node_has_children( node_type_ptr& node);
        node_type_ptr _clone_tree( const red_black_tree& other, const node_type_ptr& other_root ); // helper function for assignment operator
        void _debug_print_recursive_inverted( const node_type_ptr& rootptr, int level, bool is_right ) const;  // comment in for usage of debug_print()
        node_type_ptr _create_node( const value_type& value );
        void _clear( node_type_ptr& rootptr);
        iterator _make_iter( node_type_ptr ptr );
        const_iterator _make_iter( const_node_type_ptr ptr ) const;
        void _left_rotate( node_type_ptr position );
        void _right_rotate( node_type_ptr position );
        void _tree_insert_fixup( node_type_ptr position );
        void _tree_erase_fixup( node_type_ptr position );

    }; // red_black_tree

    /* red_black_tree member functions */
    /* public */

   template < typename T, typename Compare, typename Allocator>
    red_black_tree<T, Compare, Allocator>::red_black_tree( const value_compare& comp, const allocator_type& alloc ) 
    : _base(), _begin_node(&this->_base), _compare( comp ), _allocator( alloc ), _node_allocator( alloc ), _size( 0 )
    {
        _create_null();
        this->_base._left = this->_null;
        this->_begin_node = &this->_base;
    }

    template < typename T, typename Compare, typename Allocator>
    red_black_tree<T, Compare, Allocator>::red_black_tree( const red_black_tree& src )
    : _base(), _begin_node(&this->_base), _compare( src._compare ), _allocator( src._allocator ), _node_allocator( src._node_allocator ), _size( src._size )
    {
        _create_null();
        this->_base._left = this->_null;
        this->_begin_node = &this->_base;
        if ( src._base._left != nullptr )
        {
            this->_base._left = this->_clone_tree( src, src._base._left );
            this->_base._left->_parent = &this->_base;
            this->_begin_node = tree_min<T>( this->_base._left );
        }
    }

    template < typename T, typename Compare, typename Allocator>
    red_black_tree<T, Compare, Allocator>::~red_black_tree()
    {
        if (this->_base._left != this->_null)
        {
            this->clear();
            this->_base._left = this->_null;
            this->_begin_node = this->_base._left;
        }
        if (this->_null != nullptr)
            destroy_node( this->_null );
    }


    template < typename T, typename Compare, typename Allocator>
    red_black_tree<T, Compare, Allocator>& red_black_tree<T, Compare, Allocator>::operator=( const red_black_tree& other )
    {
        if ( this != &other )
        {
            this->clear();
            this->_allocator = other._allocator;
            this->_node_allocator = other._node_allocator;
            this->_compare = other._compare;
            if ( other._base._left != other._null )
            {
                this->_base._left = this->_clone_tree( other, other._base._left );
                this->_begin_node = tree_min<T>( this->_base._left );
            }
            this->_size = other._size;
            this->_base._left->_parent = &this->_base;
        }
        return ( *( this ) );
    }


    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::begin()
    {
        return ( iterator( this->_begin_node ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::begin() const
    {
        return ( const_iterator( this->_begin_node ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::end()
    {
        return ( iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::end() const
    {
        return ( const_iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::reverse_iterator red_black_tree<T, Compare, Allocator>::rbegin()
    {
        return ( reverse_iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_reverse_iterator red_black_tree<T, Compare, Allocator>::rbegin() const
    {
        return ( const_reverse_iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::reverse_iterator red_black_tree<T, Compare, Allocator>::rend()
    {
        return ( reverse_iterator( this->_begin_node ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_reverse_iterator red_black_tree<T, Compare, Allocator>::rend() const
    {
        return ( const_reverse_iterator( this->_begin_node ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::size_type red_black_tree<T, Compare, Allocator>::size() const
    {
        return ( this->_size);
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::size_type red_black_tree<T, Compare, Allocator>::max_size() const
    {
        size_type alloc_max = this->_node_allocator.max_size();
        size_type numeric_max = std::numeric_limits<difference_type>::max();

        return ( ( alloc_max < numeric_max ) ? alloc_max : numeric_max );
    }

    // https://cplusplus.com/reference/map/map/insert/
    // Insert elements
    // Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
    // Because element keys in a map are unique, the insertion operation checks whether each inserted element has a key equivalent to the one of an element already in the container, and if so, the element is not inserted, returning an iterator to this existing element (if the function returns a value).
    // For a similar container allowing for duplicate elements, see multimap.
    // An alternative way to insert elements in a map is by using member function map::operator[].
    // Internally, map containers keep all their elements sorted by their key following the criterion specified by its comparison object. The elements are always inserted in its respective position following this ordering.
    // The parameters determine how many elements are inserted and to which values they are initialized:
    template < typename T, typename Compare, typename Allocator>
    ft::pair<typename red_black_tree<T, Compare, Allocator>::iterator, bool> red_black_tree<T, Compare, Allocator>::insert( const value_type& value)
    {
        return ( this->_insert( this->_base._left, value ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::insert( __attribute__( ( unused ) ) iterator position, const value_type& value)
    {
        // TASK: rewrite the hint part:
        // if the element is smaller than 'value', and the successor bigger, insert here.

        // old/wrong version
        // if ( ( this->_compare( position.base()->_data, value ) && this->_compare( value, position.base()->_data ) ) )
        //     return ( this->_insert( position.base(), value ).first );
        // return ( this->_insert( _base._left, value ).first );

        return ( this->_insert( this->_base._left, value ).first );
    }

    template < typename T, typename Compare, typename Allocator>
    template <typename InputIterator>
    void red_black_tree<T, Compare, Allocator>::insert( InputIterator first, InputIterator last )
    {
        for ( ; first != last; ++first )
            this->insert( *( first ) );
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::erase( iterator position )
    {
        // std::cout << " -------------------- e1 --------------------- " << std::endl; // TPO
        node_type_ptr node = position.base();

        // std::cout << " -------------------- e2 --------------------- " << std::endl; // TPO
        if ( node == &this->_base || node == this->_null )
        { // TPO
        // std::cout << " -------------------- e3 --------------------- " << std::endl; // TPO
            return ;
        } // TPO

        // std::cout << " -------------------- e4 --------------------- " << std::endl; // TPO
        node_type_ptr   track_node = node;
        node_state      original_track_node_colour = track_node->_colour;
        node_type_ptr   replacement = &this->_base;

        // std::cout << " -------------------- e5 --------------------- " << std::endl; // TPO
        if ( node->_left == this->_null )
        {
        // std::cout << " -------------------- e6 --------------------- " << std::endl; // TPO
            replacement = node->_right;
            this->_transplant( node, node->_right );
        // std::cout << " -------------------- e7 --------------------- " << std::endl; // TPO
        }
        else if ( node->_right == this->_null )
        {
        // std::cout << " -------------------- e8 --------------------- " << std::endl; // TPO
            replacement = node->_left;
            this->_transplant( node, node->_left );
        // std::cout << " -------------------- e9 --------------------- " << std::endl; // TPO
        }
        else
        {
        // std::cout << " -------------------- e10 --------------------- " << std::endl; // TPO
            track_node = tree_min<T>( node->_right );
            original_track_node_colour = track_node->_colour;
            replacement = track_node->_right;
        // std::cout << " -------------------- e11 --------------------- " << std::endl; // TPO
            if ( track_node->_parent == node )
            { // TPO
        // std::cout << " -------------------- e12 --------------------- " << std::endl; // TPO
                replacement->_parent = track_node;
            } // TPO
            else
            {
        // std::cout << " -------------------- e13 --------------------- " << std::endl; // TPO
                this->_transplant( track_node, track_node->_right );
                track_node->_right = node->_right;
                track_node->_right->_parent = track_node;
        // std::cout << " -------------------- e14 --------------------- " << std::endl; // TPO
            }
        // std::cout << " -------------------- e15 --------------------- " << std::endl; // TPO
            this->_transplant( node, track_node );
            track_node->_left = node->_left;
            track_node->_left->_parent = track_node;
            track_node->_colour = node->_colour;
        // std::cout << " -------------------- e16 --------------------- " << std::endl; // TPO
        }
        if ( node == this->_begin_node )
        {
        // std::cout << " -------------------- e17 --------------------- " << std::endl; // TPO
            if ( node->_right != this->_null )
            { // TPO
        // std::cout << " -------------------- e18 --------------------- " << std::endl; // TPO
                this->_begin_node = tree_min<T>( node->_right );
        // std::cout << " -------------------- e19 --------------------- " << std::endl; // TPO
            } // TPO
            else
            { // TPO
        // std::cout << " -------------------- e20 --------------------- " << std::endl; // TPO
                this->_begin_node = this->_begin_node->_parent;
            } // TPO
        // std::cout << " -------------------- e21 --------------------- " << std::endl; // TPO
        }
        if ( original_track_node_colour == BLACK )
        { // TPO
        // std::cout << " -------------------- e22 --------------------- " << std::endl; // TPO
            _tree_erase_fixup( replacement );
        } // TPO
        // std::cout << " -------------------- e23 --------------------- " << std::endl; // TPO
        this->destroy_node( node );
        // std::cout << " -------------------- e24 --------------------- " << std::endl; // TPO
        --( this->_size );
        // std::cout << " -------------------- e25 --------------------- " << std::endl; // TPO
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::size_type red_black_tree<T, Compare, Allocator>::erase( const value_type& value)
    {
        iterator find_return = this->find( value );

        if ( find_return == this->end() )
            return ( 0 );
        this->erase( find_return );
        return ( 1 );
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::erase( iterator first, iterator last )
    {
        while ( first != last )
            this->erase( first++ );
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::swap( red_black_tree& x )
    {
        if ( this != &x )
        {
            ft::swap( this->_null, x._null );
            ft::swap( this->_base._left, x._base._left );
            ft::swap( this->_begin_node, x._begin_node );
            ft::swap( this->_node_allocator, x._node_allocator );
            ft::swap( this->_allocator, x._allocator );
            ft::swap( this->_compare, x._compare );
            ft::swap( this->_size, x._size );
            if ( this->_size == 0 )
            {
                this->_begin_node = &this->_base;
                this->_base._left = this->_null;
            }
            else
            {
                this->_base._left->_parent = &this->_base;
            }
            if ( x._size == 0 )
            {
                x._begin_node = &x._base;
                x._base._left = x._null;
            }
            else
                x._base._left->_parent = &x._base;
        }
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::clear()
    {
        if ( this->_base._left != this->_null )
        {
            _clear( this->_base._left );
            this->_base._left = this->_null;
        }
        this->_begin_node = &this->_base;
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::find( const value_type& value)
    {
        node_type_ptr rootptr = this->_base._left;

        while ( rootptr != this->_null )
        {
            if ( this->_compare( value, rootptr->_data ) )
                rootptr = rootptr->_left;
            else if ( this->_compare( rootptr->_data, value ) )
                rootptr = rootptr->_right;
            else
                return ( iterator( rootptr ) );
        }
        return ( &this->_base );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::find( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_base._left;

        while ( rootptr != this->_null )
        {
            if ( this->_compare( value, rootptr->_data ) )
                rootptr = rootptr->_left;
            else if ( this->_compare( rootptr->_data, value ) )
                rootptr = rootptr->_right;
            else
                return ( const_iterator( rootptr ) );
        }
        return ( &this->_base ); //is this correct? Not const_iterator( this->_base)???
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::size_type red_black_tree<T, Compare, Allocator>::count( const value_type& value) const
    {
        return ( ( this->find( value ).base() == &this->_base ) ? 0 : 1 );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::lower_bound( const value_type& value)
    {
        node_type_ptr       rootptr = this->_base._left;
        node_type_ptr       position = const_cast<node_type_ptr>( &this->_base );

        while ( rootptr != this->_null )
        {
            if ( !( this->_compare( rootptr->_data, value ) ) )
            {
                position = rootptr;
                rootptr = rootptr->_left;
            }
            else
                rootptr = rootptr->_right;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::lower_bound( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_base._left;
        const_node_type_ptr position = const_cast<const_node_type_ptr>( &this->_base );

        while ( rootptr != this->_null )
        {
            if ( !( this->_compare( rootptr->_data, value ) ) )
            {
                position = rootptr;
                rootptr = rootptr->_left;
            }
            else
                rootptr = rootptr->_right;
        }
        return ( const_iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::upper_bound( const value_type& value)
    {
        node_type_ptr       rootptr = this->_base._left;
        node_type_ptr       position = const_cast<node_type_ptr>( &this->_base );

        while ( rootptr != this->_null )
        {
            if ( this->_compare( value, rootptr->_data ) )
            {
                position = rootptr;
                rootptr = rootptr->_left;
            }
            else
                rootptr = rootptr->_right;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::upper_bound( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_base._left;
        const_node_type_ptr position = const_cast<const_node_type_ptr>( &this->_base );

        while ( rootptr != this->_null )
        {
            if ( this->_compare( value, rootptr->_data ) )
            {
                position = rootptr;
                rootptr = rootptr->_left;
            }
            else
                rootptr = rootptr->_right;
        }
        return ( const_iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    ft::pair<typename red_black_tree<T, Compare, Allocator>::const_iterator,
        typename red_black_tree<T, Compare, Allocator>::const_iterator> 
        red_black_tree<T, Compare, Allocator>::equal_range( const value_type& k ) const
    {
        const_node_type_ptr                 rootptr = this->_base._left;
        const_node_type_ptr                 position = const_cast<const_node_type_ptr>( &this->_base );

        while ( rootptr != this->_null )
        {
            if ( this->_compare( k, rootptr->_data ) )
            {
                position = rootptr;
                rootptr = rootptr->_left;
            }
            else if ( this->_compare( rootptr->_data, k ) )
                rootptr = rootptr->_right;
            else
                return ( ft::make_pair( const_iterator( rootptr ), const_iterator( rootptr->_right != this->_null ? tree_min<value_type>( rootptr->_right) : position ) ) );
        }
        return ( ft::make_pair( const_iterator( position ), const_iterator( position ) ) );
    }

    template < typename T, typename Compare, typename Allocator>
    ft::pair<typename red_black_tree<T, Compare, Allocator>::iterator,
        typename red_black_tree<T, Compare, Allocator>::iterator> 
        red_black_tree<T, Compare, Allocator>::equal_range( const value_type& k )
    {
        node_type_ptr                       rootptr = this->_base._left;
        node_type_ptr                       position = &this->_base;

        while ( rootptr != this->_null )
        {
            if ( this->_compare( k, rootptr->_data ) )
            {
                position = rootptr;
                rootptr = rootptr->_left;
            }
            else if ( this->_compare( rootptr->_data, k ) )
                rootptr = rootptr->_right;
            else
                return ( ft::make_pair( iterator( rootptr ), iterator( rootptr->_right != this->_null ? tree_min<value_type>( rootptr->_right) : position ) ) );
        }
        return ( ft::make_pair( iterator( position ), iterator( position ) ) );
    }

    // for debugging purposes only  // comment in for usage of debug_print()
    template <typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::debug_print() const
    {
        _debug_print_recursive_inverted( this->_base._left, 0, false );
    }

    template <typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::allocator_type red_black_tree<T, Compare, Allocator>::get_allocator() const
    {
        return ( this->_allocator );
    }

    template <typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::destroy_node( node_type_ptr node )
    {
        if ( node != nullptr )
        {
            this->_allocator.destroy( &node->_data );
            this->_node_allocator.deallocate( node, 1 );
        }
    }

    template <typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::value_compare red_black_tree<T, Compare, Allocator>::value_comp() const
    {
        return ( this->_compare );
    }

    /* private */

    template <typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_create_null()
    {
        this->_null = this->_node_allocator.allocate( 1 );
        this->_node_allocator.construct( this->_null, value_type() );
    }

    template <typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_init_root( node_type_ptr &new_node, node_type_ptr &position )
    {
        this->_base._left = new_node;
        this->_base._left->_parent = &this->_base;
        this->_base._left->_left = this->_null;
        this->_base._left->_right = this->_null;
        position = this->_base._left;
        this->_begin_node = this->_base._left;
    }

    template <typename T, typename Compare, typename Allocator>
    ft::pair<typename red_black_tree<T, Compare, Allocator>::iterator, bool> red_black_tree<T, Compare, Allocator>::_insert( node_type_ptr rootptr, const value_type& value )
    {
        // std::cout << " -------------------- _1 --------------------- " << std::endl; // TPO
        node_type_ptr       position = &this->_base;
        node_type_ptr       new_node = this->_create_node( value );
        bool                insert_flag = true;

        // std::cout << " -------------------- _2 --------------------- " << std::endl; // TPO
        while ( rootptr != this->_null )
        {
        // std::cout << " -------------------- _3 --------------------- " << std::endl; // TPO
            position = rootptr;
            if ( this->_compare( new_node->_data, rootptr->_data ) )
            { // TPO
        // std::cout << " -------------------- _4 --------------------- " << std::endl; // TPO
                rootptr = rootptr->_left;
            } // TPO
            else if ( this->_compare( rootptr->_data, new_node->_data ) )
            { // TPO
        // std::cout << " -------------------- _5 --------------------- " << std::endl; // TPO
                rootptr = rootptr->_right;
            } // TPO
            else
            {
        // std::cout << " -------------------- _6 --------------------- " << std::endl; // TPO
                insert_flag = false;
                break ;
            }
        // std::cout << " -------------------- _7 --------------------- " << std::endl; // TPO
        }
        new_node->_parent = position;
        // std::cout << " -------------------- _8 --------------------- " << std::endl; // TPO
        if ( position == &this->_base ) // empty tree
        { // TPO
        // std::cout << " -------------------- _9 --------------------- " << std::endl; // TPO
            this->_init_root( new_node, position );
        } // TPO
        else if ( this->_compare( new_node->_data, position->_data ) )
        {
        // std::cout << " -------------------- _10 --------------------- " << std::endl; // TPO
            position->_left = new_node;
            new_node->_parent = position;
            position = position->_left;
        // std::cout << " -------------------- _11 --------------------- " << std::endl; // TPO
        }
        else if ( this->_compare( position->_data, new_node->_data ) )
        {
        // std::cout << " -------------------- _12 --------------------- " << std::endl; // TPO
            position->_right = new_node;
            new_node->_parent = position;
            position = position->_right;
        // std::cout << " -------------------- _13 --------------------- " << std::endl; // TPO
        }
        else
        { // TPO
        // std::cout << " -------------------- _14 --------------------- " << std::endl; // TPO
            this->destroy_node( new_node);
            return ( ft::make_pair( this->_make_iter( position ), insert_flag ) ); // DONE: 1.) add return statement
        } // TPO
        if ( insert_flag == true )
        { // TPO
        // std::cout << " -------------------- _15 --------------------- " << std::endl; // TPO
            ++( this->_size );
        } // TPO
        // std::cout << " -------------------- _16 --------------------- " << std::endl; // TPO
        this->_base._left->_parent = &this->_base;
        // std::cout << " -------------------- _17 --------------------- " << std::endl; // TPO
        if ( ( position->_parent == this->_begin_node ) && ( position == position->_parent->_left ) )
        { // TPO
        // std::cout << " -------------------- _18 --------------------- " << std::endl; // TPO
            this->_begin_node = position;
        // std::cout << " -------------------- _19 --------------------- " << std::endl; // TPO
        } // TPO
        // std::cout << " -------------------- _20 --------------------- " << std::endl; // TPO
        this->_tree_insert_fixup( position );
        // std::cout << " -------------------- _21 --------------------- " << std::endl; // TPO
        return ( ft::make_pair( this->_make_iter( position ), insert_flag ) );
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_transplant( node_type_ptr old_subtree, node_type_ptr new_subtree )
    {
        if ( old_subtree->_parent == &this->_base )
        {
            this->_base._left = new_subtree;
            this->_base._left->_parent = &this->_base;
            // this->_base._left->_parent->_left = new_subtree; // unnecessary!
        }
        else if ( old_subtree == old_subtree->_parent->_left )
            old_subtree->_parent->_left = new_subtree;
        else
            old_subtree->_parent->_right = new_subtree;
        new_subtree->_parent = old_subtree->_parent;
    }

    template < typename T, typename Compare, typename Allocator>
    bool red_black_tree<T, Compare, Allocator>::_node_has_children( node_type_ptr& node)
    {
        if ( node->_left == this->_null && node->_right == this->_null )
            return ( false );
        return ( true );
    }
    
    template < typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::node_type_ptr 
    red_black_tree<T, Compare, Allocator>::_clone_tree( const red_black_tree& other, const node_type_ptr& other_root )
    {
        if ( other_root == other._null ) // or nullptr?
            return ( this->_null ); // or nullptr?
        node_type_ptr copy_node = this->_create_node( other_root->_data );
        copy_node->_left = this->_clone_tree( other, other_root->_left );
        if ( copy_node->_left != this->_null )
            copy_node->_left->_parent = copy_node;        
        copy_node->_right = this->_clone_tree( other, other_root->_right );
        if ( copy_node->_right != this->_null )
            copy_node->_right->_parent = copy_node;
        return ( copy_node );
    }

    // for debugging purposes only  // comment in for usage of debug_print()
    template <typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_debug_print_recursive_inverted( const node_type_ptr& rootptr, int level, bool is_right ) const
    {
        //INVERTED for better human readability
        if ( rootptr == nullptr )
            return ;

        _debug_print_recursive_inverted( rootptr->_right,  level + 1, true );

        for ( int i = 0; i < level; i++ )
        std::cout << "\t";

        if ( rootptr->_parent != &this->_base )
            std::cout << ( is_right ? "┌──" : "└──" );
        else
            std::cout << "├──";
        
        if ( rootptr->_colour == RED )
            std::cout << "\033[31m";
        else
            std::cout << "\033[30m";
        if (rootptr == this->_null)
            std::cout << " null\033[37m\n";
        else
            std::cout << " " << rootptr->_data.first << " / " << rootptr->_data.second << "\033[37m\n";

        _debug_print_recursive_inverted( rootptr->_left, level + 1, false );
    }

    template <typename T, typename Compare, typename Allocator>
    typename red_black_tree<T, Compare, Allocator>::node_type_ptr red_black_tree<T, Compare, Allocator>::_create_node( const value_type& value )
    {
        node_type_ptr new_node = this->_node_allocator.allocate( 1 );
        this->_allocator.construct( &new_node->_data, value );
        new_node->_colour = RED;
        new_node->_parent = this->_null;
        new_node->_left = this->_null;
        new_node->_right = this->_null;
        return ( new_node );
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_clear( node_type_ptr& rootptr)
    {
        if ( rootptr != this->_null )
        {
            if ( rootptr->_left != this->_null )
                _clear( rootptr->_left );
            if  ( rootptr->_right != this->_null )
                _clear( rootptr->_right );
            destroy_node( rootptr );
            rootptr = this->_null;
        }
        this->_size = 0;
    }

    template <typename T, typename Compare, typename Allocator>
    inline typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::_make_iter( node_type_ptr ptr )
    {
        return ( iterator( ptr ) );
    }

    template <typename T, typename Compare, typename Allocator>
    inline typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::_make_iter( const_node_type_ptr ptr ) const
    {
        return ( const_iterator( ptr ) );
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_left_rotate( node_type_ptr position )
    {
        // std::cout << " -------------------- LR IN --------------------- " << std::endl; // TPO
        node_type_ptr   right_node = position->_right;

        position->_right = right_node->_left; // turn right_nodes’s left subtree into positions’s right subtree
        if ( right_node->_left != this->_null )
            right_node->_left->_parent = position;
        right_node->_parent = position->_parent; // link position’s parent to right_node
        if ( position->_parent == &this->_base )
            this->_base._left = right_node;
        else if ( position == position->_parent->_left )
            position->_parent->_left = right_node;
        else
            position->_parent->_right = right_node;
        right_node->_left = position; // put position on right_node’s left
        position->_parent = right_node;
        // std::cout << " -------------------- LR OUT --------------------- " << std::endl; // TPO
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_right_rotate( node_type_ptr position )
    {
        // std::cout << " -------------------- RR IN --------------------- " << std::endl; // TPO
        node_type_ptr   left_node = position->_left;

        position->_left = left_node->_right; // turn left_nodes’s right subtree into positions’s left subtree
        if ( left_node->_right != this->_null )
            left_node->_right->_parent = position;
        left_node->_parent = position->_parent; // link position’s parent to left_node
        if ( position->_parent == &this->_base )
            this->_base._left = left_node;
        else if ( position == position->_parent->_right )
            position->_parent->_right = left_node;
        else
            position->_parent->_left = left_node;
        left_node->_right = position; // put position on left_node’s right
        position->_parent = left_node;
        // std::cout << " -------------------- RR OUT --------------------- " << std::endl; // TPO
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_tree_insert_fixup( node_type_ptr position )
    {
        // if ( position == this->_null) // needed here?
        //     return ;
        // std::cout << " -------------------- F 1 --------------------- " << std::endl; // TPO
        // while ( position->_parent->_colour == RED && position != this->_base._left ) // DONE: 1.) added '&& position != this->_base._left'
        while ( position->_parent->_colour == RED ) // DONE: 1.) added '&& position != this->_base._left'
        {
        // std::cout << " -------------------- F 2 --------------------- " << std::endl; // TPO
            node_type_ptr   uncle = &this->_base; // same level as parent node

            if ( position->_parent == position->_parent->_parent->_left )
            {
        // std::cout << " -------------------- F 3 --------------------- " << std::endl; // TPO
                uncle = position->_parent->_parent->_right;
                // 3 cases:
        // std::cout << " -------------------- F 4 --------------------- " << std::endl; // TPO
                if ( uncle->_colour == RED ) // 1
                {
        // std::cout << " -------------------- F 5 --------------------- " << std::endl; // TPO
                    position->_parent->_colour = BLACK;
                    uncle->_colour = BLACK;
                    position->_parent->_parent->_colour = RED;
                    position = position->_parent->_parent;
        // std::cout << " -------------------- F 6 --------------------- " << std::endl; // TPO
                }
                else
                {
        // std::cout << " -------------------- F 7 --------------------- " << std::endl; // TPO
                    if ( position == position->_parent->_right ) // 2
                    {
        // std::cout << " -------------------- F 8 --------------------- " << std::endl; // TPO
                        position = position->_parent;
                        this->_left_rotate( position );
        // std::cout << " -------------------- F 9 --------------------- " << std::endl; // TPO
                    }
                    // 3
        // std::cout << " -------------------- F 10 --------------------- " << std::endl; // TPO
                    position->_parent->_colour = BLACK;
                    position->_parent->_parent->_colour = RED;
                    this->_right_rotate( position->_parent->_parent );
        // std::cout << " -------------------- F 11 --------------------- " << std::endl; // TPO
                }
        // std::cout << " -------------------- F 12 --------------------- " << std::endl; // TPO
            }
            else
            {
        // std::cout << " -------------------- F 13 --------------------- " << std::endl; // TPO
                uncle = position->_parent->_parent->_left;
                // 3 cases:
                if ( uncle->_colour == RED ) // 1
                {
        // std::cout << " -------------------- F 14 --------------------- " << std::endl; // TPO
                    position->_parent->_colour = BLACK;
                    uncle->_colour = BLACK;
                    position->_parent->_parent->_colour = RED;
                    position = position->_parent->_parent;
        // std::cout << " -------------------- F 15 --------------------- " << std::endl; // TPO
                }
                else
                {
        // std::cout << " -------------------- F 16 --------------------- " << std::endl; // TPO
                    if ( position == position->_parent->_left ) // 2
                    {
        // std::cout << " -------------------- F 17 --------------------- " << std::endl; // TPO
                        position = position->_parent;
                        this->_right_rotate( position );
        // std::cout << " -------------------- F 18 --------------------- " << std::endl; // TPO
                    }
                    // 3
        // std::cout << " -------------------- F 19 --------------------- " << std::endl; // TPO
                    position->_parent->_colour = BLACK;
                    position->_parent->_parent->_colour = RED;
                    this->_left_rotate( position->_parent->_parent );
        // std::cout << " -------------------- F 20 --------------------- " << std::endl; // TPO
                }
        // std::cout << " -------------------- F 21 --------------------- " << std::endl; // TPO
            }
        }
        // std::cout << " -------------------- F 22 --------------------- " << std::endl; // TPO
        this->_base._left->_colour = BLACK;
        // std::cout << " -------------------- F 23 --------------------- " << std::endl; // TPO
    }

    template < typename T, typename Compare, typename Allocator>
    void red_black_tree<T, Compare, Allocator>::_tree_erase_fixup( node_type_ptr position )
    {
        // std::cout << " -------------------- EF 1 --------------------- " << std::endl; // TPO
        if ( position == this->_null)
        {
        // std::cout << " -------------------- EF 2 --------------------- " << std::endl; // TPO
            return ;
        }
        // std::cout << " -------------------- EF 3 --------------------- " << std::endl; // TPO
        while ( position != this->_base._left && position->_colour == BLACK )
        {
        // std::cout << " -------------------- EF 4 --------------------- " << std::endl; // TPO
            node_type_ptr   sibling = &this->_base; // same level as position

        // std::cout << " -------------------- EF 5 --------------------- " << std::endl; // TPO
            if ( position == position->_parent->_left )
            {
        // std::cout << " -------------------- EF 6 --------------------- " << std::endl; // TPO
                sibling = position->_parent->_right;
        // std::cout << " -------------------- EF 7 --------------------- " << std::endl; // TPO
                if ( sibling->_colour == RED ) // 1
                {
        // std::cout << " -------------------- EF 8 --------------------- " << std::endl; // TPO
                    sibling->_colour = BLACK;
                    position->_parent->_colour = RED;
                    this->_left_rotate( position->_parent );
                    sibling = position->_parent->_right;
        // std::cout << " -------------------- EF 9 --------------------- " << std::endl; // TPO
                }
        // std::cout << " -------------------- EF 10 --------------------- " << std::endl; // TPO
                // if ( sibling == this->_null) // TPO
                //     return ; // TPO
                if ( sibling->_left->_colour == BLACK && sibling->_right->_colour == BLACK ) // 2
                {
        // std::cout << " -------------------- EF 11 --------------------- " << std::endl; // TPO
                    sibling->_colour = RED;
                    position = position->_parent;
        // std::cout << " -------------------- EF 12 --------------------- " << std::endl; // TPO
                }
                else
                {
        // std::cout << " -------------------- EF 13 --------------------- " << std::endl; // TPO
                    if ( sibling->_right->_colour == BLACK ) // 3
                    {
        // std::cout << " -------------------- EF 14 --------------------- " << std::endl; // TPO
                        sibling->_left->_colour = BLACK;
                        sibling->_colour = RED;
                        this->_right_rotate( sibling );
                        sibling = position->_parent->_right;
        // std::cout << " -------------------- EF 15 --------------------- " << std::endl; // TPO
                    }
                    // 4
        // std::cout << " -------------------- EF 16 --------------------- " << std::endl; // TPO
                    sibling->_colour = position->_parent->_colour;
                    position->_parent->_colour = BLACK;
                    sibling->_right->_colour = BLACK;
                    this->_left_rotate( position->_parent );
                    position = this->_base._left;
        // std::cout << " -------------------- EF 17 --------------------- " << std::endl; // TPO
                }
            }
            else
            {
        // std::cout << " -------------------- EF 18 --------------------- " << std::endl; // TPO
                sibling = position->_parent->_left;
        // std::cout << " -------------------- EF 19 --------------------- " << std::endl; // TPO
                if ( sibling->_colour == RED ) // 1
                {
        // std::cout << " -------------------- EF 20 --------------------- " << std::endl; // TPO
                    sibling->_colour = BLACK;
                    position->_parent->_colour = RED;
                    this->_right_rotate( position->_parent );
                    sibling = position->_parent->_left;
        // std::cout << " -------------------- EF 21 --------------------- " << std::endl; // TPO
                }
                // if ( sibling == this->_null) // TPO
                //     return ; // TPO
                if ( sibling->_right->_colour == BLACK && sibling->_left->_colour == BLACK ) // 2
                {
        // std::cout << " -------------------- EF 22 --------------------- " << std::endl; // TPO
                    sibling->_colour = RED;
                    position = position->_parent;
        // std::cout << " -------------------- EF 23 --------------------- " << std::endl; // TPO
                }
                else
                {
        // std::cout << " -------------------- EF 24 --------------------- " << std::endl; // TPO
                    if ( sibling->_left->_colour == BLACK ) // 3
                    {
        // std::cout << " -------------------- EF 25 --------------------- " << std::endl; // TPO
                        sibling->_right->_colour = BLACK;
                        sibling->_colour = RED;
                        this->_left_rotate( sibling );
                        sibling = position->_parent->_left;
        // std::cout << " -------------------- EF 26 --------------------- " << std::endl; // TPO
                    }
                    // 4
        // std::cout << " -------------------- EF 27 --------------------- " << std::endl; // TPO
                    sibling->_colour = position->_parent->_colour;
                    position->_parent->_colour = BLACK;
                    sibling->_left->_colour = BLACK;
                    this->_right_rotate( position->_parent );
                    position = this->_base._left;
        // std::cout << " -------------------- EF 28 --------------------- " << std::endl; // TPO
                }
        // std::cout << " -------------------- EF 29 --------------------- " << std::endl; // TPO
            }
        // std::cout << " -------------------- EF 30 --------------------- " << std::endl; // TPO
        }
        // std::cout << " -------------------- EF 31 --------------------- " << std::endl; // TPO
        position->_colour = BLACK;
        // std::cout << " -------------------- EF 32 --------------------- " << std::endl; // TPO
    }

    /* red_black_tree non-member functions */

    template <typename T, typename Compare, typename Allocator>
    void swap( red_black_tree<T, Compare, Allocator>& lhs, red_black_tree<T, Compare, Allocator>& rhs )
    {
        lhs.swap( rhs );
    }

} // namespace ft
