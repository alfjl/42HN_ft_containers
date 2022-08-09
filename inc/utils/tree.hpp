#pragma once

#include <iostream> // only for debug_print()
#include <memory>

#include "./iterator.hpp"
#include "./functional.hpp"
#include "./utility.hpp"

#ifndef nullptr
#define nullptr NULL
#endif

namespace ft
{

    /* --------------------------- tree algorithms ---------------------------- */

    /*
    ** A collection of useful algorithms for the implemented binary search tree
    ** and red black tree
    */

    // Returns true if node_ptr is a left child of its parent, else false
    // template <typename NodePtr>
    // bool tree_is_left_child( NodePtr node_ptr )
    // {
    //     return ( node_ptr == node_ptr->_parent->_left );
    // }

    // // Returns a pointer to the left-most node under node_ptr.
    // template <typename NodePtr>
    // NodePtr tree_min( NodePtr node_ptr )
    // {
    //     while (node_ptr->_left != nullptr)
    //         node_ptr = node_ptr->_left;
    //     return node_ptr;
    // }

    // // Returns a pointer to the right-most node under node_ptr.
    // template <typename NodePtr>
    // NodePtr tree_max( NodePtr node_ptr )
    // {
    //     while (node_ptr->_right != nullptr)
    //         node_ptr = node_ptr->_right;
    //     return node_ptr;
    // }

// // Returns:  pointer to the next in-order node after __x.
// // Precondition:  __x != nullptr.
// template <class _NodePtr>
// _NodePtr
// __tree_next(_NodePtr __x) _NOEXCEPT
// {
//     if (__x->__right_ != nullptr)
//         return __tree_min(__x->__right_);
//     while (!__tree_is_left_child(__x))
//         __x = __x->__parent_unsafe();
//     return __x->__parent_unsafe();
// }

    // template <class _EndNodePtr, class _NodePtr>
    // inline _LIBCPP_INLINE_VISIBILITY
    // _EndNodePtr
    // __tree_next_iter(_NodePtr __x) _NOEXCEPT
    // {
    //     if (__x->__right_ != nullptr)
    //         return static_cast<_EndNodePtr>(__tree_min(__x->__right_));
    //     while (!__tree_is_left_child(__x))
    //         __x = __x->__parent_unsafe();
    //     return static_cast<_EndNodePtr>(__x->__parent_);
    // }
    // template <typename NodePtr>
    // NodePtr tree_next_iter( NodePtr node_ptr )
    // {
    //     if ( node_ptr->_right != nullptr )
    //         return ( tree_min( node_ptr->_right ) );
    //     while ( !( tree_is_left_child( node_ptr ) ) )
    //         node_ptr = node_ptr->_parent;
    //     return ( node_ptr->_parent );
    // }

    // // Returns:  pointer to the previous in-order node before __x.
    // // Precondition:  __x != nullptr.
    // // Note: __x may be the end node.
    // template <class _NodePtr, class _EndNodePtr>
    // inline _LIBCPP_INLINE_VISIBILITY
    // _NodePtr
    // __tree_prev_iter(_EndNodePtr __x) _NOEXCEPT
    // {
    //     if (__x->__left_ != nullptr)
    //         return __tree_max(__x->__left_);
    //     _NodePtr __xx = static_cast<_NodePtr>(__x);
    //     while (__tree_is_left_child(__xx))
    //         __xx = __xx->__parent_unsafe();
    //     return __xx->__parent_unsafe();
    // }
    // template <typename NodePtr>
    // NodePtr tree_prev_iter( NodePtr node_ptr )
    // {
    //     if ( node_ptr->_left != nullptr )
    //         return ( tree_max( node_ptr->_left ) );
    //     while ( tree_is_left_child( node_ptr ) )
    //         node_ptr = node_ptr->_parent;
    //     return ( node_ptr->_parent );
    // }



    /* ------------------------------ tree_node ------------------------------- */

    /*
    ** A general node template to be used in my implementation of 
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
        tree_node( const value_type &value );
        // tree_node( const value_type &value, node_state &colour = BLACK, node_ptr parent = nullptr, node_ptr left = nullptr, node_ptr right = nullptr );
        tree_node( const tree_node &other);
        ~tree_node();

        tree_node &operator=( const tree_node &src );
    
    private:
        void change_colour();

    }; // tree_node

    /* tree_node member functions */
    /* public */

    template <typename T>
    tree_node<T>::tree_node() : _data(), _colour( BLACK ), _parent( nullptr ), _left( nullptr ), _right( nullptr ) {}

    template <typename T>
    tree_node<T>::tree_node( const value_type &value ) : _data( value ), _colour( BLACK ), _parent( nullptr ), _left( nullptr ), _right( nullptr ) {}

    // template <typename T>
    // tree_node<T>::tree_node( const value_type &value, node_state &colour, node_ptr parent, node_ptr left, node_ptr right )
    // : _data( value ), _colour( colour ), _parent( parent ), _left( left ), _right( right ) {}

    template <typename T>
    tree_node<T>::tree_node( const tree_node &other) : _data(), _colour( BLACK ), _parent(), _left(), _right()
    {
        *this = other;
    }

    template <typename T>
    tree_node<T>::~tree_node() {}

    template <typename T>
    tree_node<T>& tree_node<T>::operator=( const tree_node &src )
    {
        if ( this != &src )
        {
            this->_colour = src._colour;
            this->_data = src._data;
            this->_parent = src._parent;
            this->_left = src._left;
            this->_right = src._right;
        }
        return ( *this );
    }

    /* private */

    template <typename T>
    void tree_node<T>::change_colour()
    {
        this->_colour = ( this->_colour == RED ) ? BLACK : RED;
    }


    /* ------------------------ tree utility functions ------------------------ */

    /*
    ** Utility functions, that are used for tree and tree iterators
    */

    template <typename T>
    typename tree_node<T>::node_ptr tree_min( typename tree_node<T>::node_ptr nodeptr )
    {
        // while (nodeptr->_left != this->_null) // doesn't work because of no knoweldeg of this->_null
        //     nodeptr = nodeptr->_left;
        // return ( nodeptr );

        while ( nodeptr->_left->_left != nullptr ) // equals this->_null
            nodeptr = nodeptr->_left;
        return ( nodeptr );
    }

    template <typename T>
    typename tree_node<T>::const_node_ptr tree_min( typename tree_node<T>::const_node_ptr nodeptr )
    {
        while ( nodeptr->_left->_left != nullptr ) // equals this->_null
            nodeptr = nodeptr->_left;
        return ( nodeptr );
    }

    template <typename T>
    typename tree_node<T>::node_ptr tree_max( typename tree_node<T>::node_ptr nodeptr )
    {
        // while (nodeptr->_right != this->_null) // doesn't work because of no knoweldeg of this->_null
        //     nodeptr = nodeptr->_right;
        // return ( nodeptr );

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
    typename tree_node<T>::node_ptr tree_next_iter( typename tree_node<T>::node_ptr nodeptr )
    {
        // if ( nodeptr->_right != this->_null ) // doesn't work because of no knoweldeg of this->_null
        //     return ( tree_min( nodeptr->_right ) );
        // while ( !( tree_is_left_child( nodeptr ) ) )
        //     nodeptr = nodeptr->_parent;
        // return ( nodeptr->_parent );

        if ( nodeptr->_right->_right != nullptr ) // equals this->_null
            return ( tree_min( nodeptr->_right ) );
        while ( !( tree_is_left_child( nodeptr ) ) )
            nodeptr = nodeptr->_parent;
        return ( nodeptr->_parent );
    }

    template <typename T>
    typename tree_node<T>::const_node_ptr tree_next_iter( typename tree_node<T>::const_node_ptr nodeptr )
    {
        if ( nodeptr->_right->_right != nullptr ) // equals this->_null
            return ( tree_min( nodeptr->_right ) );
        while ( !( tree_is_left_child( nodeptr ) ) )
            nodeptr = nodeptr->_parent;
        return ( nodeptr->_parent );
    }

    template <typename T>
    typename tree_node<T>::node_ptr tree_prev_iter( typename tree_node<T>::node_ptr nodeptr )
    {
        // if ( nodeptr->_left != this->_null ) // doesn't work because of no knoweldeg of this->_null
        //     return ( tree_max( nodeptr->_left ) );
        // while ( tree_is_left_child( nodeptr ) )
        //     nodeptr = nodeptr->_parent;
        // return ( nodeptr->_parent );

        if ( nodeptr->_left->_left != nullptr ) // equals this->_null
            return ( tree_max( nodeptr->_left ) );
        while ( tree_is_left_child( nodeptr ) )
            nodeptr = nodeptr->_parent;
        return ( nodeptr->_parent );
    }

    template <typename T>
    typename tree_node<T>::const_node_ptr tree_prev_iter( typename tree_node<T>::const_node_ptr nodeptr )
    {
        if ( nodeptr->_left->_left != nullptr ) // equals this->_null
            return ( tree_max( nodeptr->_left ) );
        while ( tree_is_left_child( nodeptr ) )
            nodeptr = nodeptr->_parent;
        return ( nodeptr->_parent );
    }

    template <typename T>
    typename tree_node<T>::node_ptr tree_is_left_child( typename tree_node<T>::node_ptr nodeptr )
    {
        return ( nodeptr == nodeptr->_parent->_left );
    }

    template <typename T>
    typename tree_node<T>::const_node_ptr tree_is_left_child( typename tree_node<T>::const_node_ptr nodeptr )
    {
        return ( nodeptr == nodeptr->_parent->_left );
    }


    /* --------------------------- Tree Iterator ----------------------------- */

    /*
    ** A bidirectional_iterator, with typenames NodePtr and T
    */

    template <typename NodePtr, typename T>
    class tree_iterator
    {
    public:
        typedef bidirectional_iterator_tag      iterator_category;
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;

    private:
        NodePtr _node_ptr;

    public:
        tree_iterator();
        tree_iterator( const NodePtr& ptr );
        tree_iterator( const tree_iterator& other );
        ~tree_iterator();

        // operator tree_iterator<const T>() const;

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

    // template <typename NodePtr, typename T>
    // tree_iterator<NodePtr, T>::operator tree_iterator<const T, const NodePtr>() const
    // {
    //     return ( this->_ptr );
    // }

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
        this->_node_ptr = tree_next_iter<value_type>( this->_node_ptr );
        return ( *this );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>  tree_iterator<NodePtr, T>::operator++( int )
    {
        tree_iterator   it = *( this );
        ++( this->_node_ptr );  // or ++( *( this ) )?
        return ( it );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>& tree_iterator<NodePtr, T>::operator--()
    {
        this->_node_ptr = tree_prev_iter<value_type>( this->_node_ptr );
        return ( *this );
    }

    template <typename NodePtr, typename T>
    tree_iterator<NodePtr, T>  tree_iterator<NodePtr, T>::operator--( int )
    {
        tree_iterator   it = *( this );
        --( this->_node_ptr ); // or --( *( this ) )?
        return ( it );
    }

    /* tree_iterator non-member functions */

    template <typename NodePtr, typename T>
    bool operator==( const tree_iterator<NodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs )
    {
        return ( lhs._node_ptr == rhs._node_ptr );
    }

    template <typename NodePtr, typename T>
    bool operator!=( const tree_iterator<NodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs )
    {
        return ( !( lhs == rhs ) );
    }


    /* ------------------------ Tree Const Iterator -------------------------- */

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

    private:
        typedef tree_iterator<typename tree_node<T>::node_ptr, T>   non_const_iterator;

    private:
        ConstNodePtr _node_ptr;

    public:
        tree_const_iterator();
        tree_const_iterator( const ConstNodePtr& ptr );
        tree_const_iterator( const tree_const_iterator& other );
        tree_const_iterator( const non_const_iterator& other );
        ~tree_const_iterator();

        // operator tree_const_iterator<const T>() const;

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
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( const non_const_iterator& other ) : _node_ptr( other._node_ptr ) {}

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::~tree_const_iterator() {}

    // template <typename NodePtr, typename T>
    // tree_iterator<NodePtr, T>::operator tree_iterator<const T, const NodePtr>() const
    // {
    //     return ( this->_ptr );
    // }

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
        this->_node_ptr = tree_next_iter<value_type>( this->_node_ptr );
        return ( *this );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>  tree_const_iterator<ConstNodePtr, T>::operator++( int )
    {
        tree_iterator<ConstNodePtr, T>   it = *this;
        ++( this->_node_ptr ); // or ++( *( this ) )?
        return ( it );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>& tree_const_iterator<ConstNodePtr, T>::operator--()
    {
        this->_node_ptr = tree_prev_iter<value_type>( this->_node_ptr );
        return ( *this );
    }

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>  tree_const_iterator<ConstNodePtr, T>::operator--( int )
    {
        tree_const_iterator   it = *this;
        --( this->_node_ptr ); // or --( *( this ) )?
        return ( it );
    }

    /* tree_const_iterator non-member functions */

    template <typename ConstNodePtr, typename T>
    bool operator==( const tree_const_iterator<ConstNodePtr, T>& lhs, const tree_const_iterator<ConstNodePtr, T>& rhs )
    {
        return ( lhs._node_ptr == rhs._node_ptr );
    }

    template <typename ConstNodePtr, typename T>
    bool operator!=( const tree_const_iterator<ConstNodePtr, T>& lhs, const tree_const_iterator<ConstNodePtr, T>& rhs )
    {
        return ( !( lhs == rhs ) );
    }


    /* ------------------------- Binary Search Tree -------------------------- */

    /*
    ** (Cormen, Leiserson, Rivest & Stein: 'Introduction to Algorithms' - 3rd Edition, Chapter 12)
    ** We can represent such a tree by a linked data structure in which
    ** each node is an object. In addition to a key and satellite data,
    ** each node contains attributes left, right, and p [...]
    ** If a child or the parent is missing, the appropriate attribute contains the value NIL.
    ** The root node is the only node in the tree whose parent is NIL.
    */

    template < typename T, typename Compare = ft::less<T>, typename Allocator = std::allocator<T> >
    class binary_search_tree
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
        typedef ft::tree_const_iterator<node_type_ptr, value_type>          const_iterator;
        // typedef ft::reverse_iterator<iterator>                           reverse_iterator;
        // typedef ft::reverse_iterator<const_iterator>                     const_reverse_iterator;

    private:
        node_type           _base; // first node in tree. _base->_left is: root 
        node_type_ptr       _root; // first node of tree with value. left child of _base
        node_type_ptr       _null; // every node_direction without attached child points onto this node, instead of nullptr
        value_compare       _compare; 
        allocator_type      _allocator; // for associated allocator object, map.get_allocator()
        node_allocator_type _node_allocator; // for associated allocator object, map.get_allocator()
        size_type           _size; // number of elements in tree ( for use in map.size() )

    public:
        // Constructors / Destructor / Assignment
        explicit binary_search_tree( const value_compare &comp, const allocator_type &alloc );
	    binary_search_tree( const binary_search_tree& other );
        ~binary_search_tree();

    	binary_search_tree& operator=( const binary_search_tree& other );

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
        pair<iterator,bool> insert( const value_type& value); // single element
        iterator insert( iterator position, const value_type& value); // with hint
        template <typename InputIterator>
            void insert( InputIterator first, InputIterator last ); // range
        void erase( iterator position ); // iterator
        size_type erase( const value_type& value); // key
        void erase( iterator first, iterator last ); // range
        void swap( binary_search_tree& x );
        void clear();

        // Operations:
        iterator find( const value_type& value );
        const_iterator find( const value_type& value ) const;
        size_type count( const value_type& value ) const;
        iterator lower_bound( const value_type& value );
        const_iterator lower_bound( const value_type& value ) const;
        iterator upper_bound( const value_type& value );
        const_iterator upper_bound( const value_type& value ) const;
        pair<iterator,iterator> equal_range( const value_type& value );
        pair<const_iterator,const_iterator> equal_range( const value_type& value ) const;
        void debug_print(); // only for debugging purposes

        // Allocator / Compare:
        allocator_type get_allocator() const;
        void destroy_node( node_type_ptr node );
        value_compare value_comp();

    private:
        pair<iterator, bool> _insert( node_type_ptr rootptr, const value_type& value ); // helper function for all insert methods
        void _transplant( node_type_ptr old_subtree, node_type_ptr new_subtree ); // helper function for erase()
        bool _node_has_children( node_type_ptr &node);
        node_type_ptr _clone_tree( const binary_search_tree& other, node_type_ptr &other_root );
        void debug_print_recursive_inverted( node_type_ptr root, int level, bool is_right );
        node_type_ptr _vcreate_node( const value_type& value );
        void _clear( node_type_ptr &rootptr);

    }; // binary_search_tree

    /* binary_search_tree member functions */
    /* public */

    // template < typename T, typename Compare, typename Allocator>
    // binary_search_tree<T, Compare, Allocator>::binary_search_tree( const value_compare &comp, const allocator_type *alloc ) 
    // : _base( nullptr ), _root( nullptr ), _null( 0, BLACK ), _compare( comp ), _allocator( alloc ), _node_allocator( alloc ), _size( 0 ) {}

    // template < typename T, typename Compare, typename Allocator>
    // binary_search_tree<T, Compare, Allocator>::binary_search_tree( const binary_search_tree& src )
    // : _base( nullptr ), _root( nullptr ), _null( 0, BLACK ), _compare(), _allocator(), _allocator() _size( 0 )
    // {
    //     *this = src;
    // }

    template < typename T, typename Compare, typename Allocator>
    binary_search_tree<T, Compare, Allocator>::binary_search_tree( const value_compare &comp, const allocator_type &alloc ) 
    : _base( 0 ), _root( nullptr ), _null( nullptr ), _compare( comp ), _allocator( alloc ), _node_allocator( alloc ), _size( 0 )
    {
        this->_null = this->_node_allocator.allocate( 1 );
        this->_allocator.construct( &this->_null->_data, 100 );
        this->_null->_colour = BLACK; // RED for Binary Search Tree
        this->_null->_parent = nullptr;
        this->_null->_left = nullptr;
        this->_null->_right = nullptr;
        this->_base._left = this->_null;
    }

    template < typename T, typename Compare, typename Allocator>
    binary_search_tree<T, Compare, Allocator>::binary_search_tree( const binary_search_tree& src )
    : _base( 0, BLACK ), _root( nullptr ), _null( nullptr ), _compare(), _allocator(), _node_allocator(), _size( 0 )
    {
        this->_null = this->_node_allocator.allocate( 1 );
        this->_allocator.construct( &this->_null->_data, 100 );
        this->_null->_colour = BLACK; // RED for Binary Search Tree
        this->_null->_parent = nullptr;
        this->_null->_left = nullptr;
        this->_null->_right = nullptr;
        this->_base._left = this->_null;
        *this = src;
    }

    template < typename T, typename Compare, typename Allocator>
    binary_search_tree<T, Compare, Allocator>::~binary_search_tree()
    {
        if (this->_root != nullptr) // or: '...!= this->_null'?
        {
            this->clear();
            this->_base._left = this->_null;
        }
        if (this->_null != nullptr)
            destroy_node( this->_null );
    }


    template < typename T, typename Compare, typename Allocator>
    binary_search_tree<T, Compare, Allocator>& binary_search_tree<T, Compare, Allocator>::operator=( const binary_search_tree& other )
    {
        if ( this != &other )
        {
            this->clear();
            this->_allocator = other._allocator;
            this->_node_allocator = other._node_allocator;
            this->_compare = other._compare;
            this->_size = other._size;
            if ( other._root() != other._null ) // or nullptr?
                this->_root = this->_clone_tree( other, other._root );
        }
        // this->_null and this->_base don't need to be copied
        return ( *( this ) );
    }


    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::begin()
    {
        return ( iterator( this->_root ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::begin() const
    {
        return ( const_iterator( this->_root ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::end()
    {
        return ( iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::end() const
    {
        return ( const_iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::reverse_iterator binary_search_tree<T, Compare, Allocator>::rbegin()
    {
        return ( reverse_iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_reverse_iterator binary_search_tree<T, Compare, Allocator>::rbegin() const
    {
        return ( const_reverse_iterator( &this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::reverse_iterator binary_search_tree<T, Compare, Allocator>::rend()
    {
        return ( reverse_iterator( this->_root ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_reverse_iterator binary_search_tree<T, Compare, Allocator>::rend() const
    {
        return ( const_reverse_iterator( this->_root ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::size_type binary_search_tree<T, Compare, Allocator>::size() const
    {
        return ( this->_size);
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::size_type binary_search_tree<T, Compare, Allocator>::max_size() const
    {
        return ( this->_allocator.max_size() );
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
    pair<typename binary_search_tree<T, Compare, Allocator>::iterator, bool> binary_search_tree<T, Compare, Allocator>::insert( const value_type& value)
    {
        return ( this->_insert( this->_root, value ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::insert( iterator position, const value_type& value)
    {
        if ( !( this->_compare( position->_data, value ) && this->_compare( value, position->_data ) ) )
            return ( this->_insert( position, value ).first );
        return ( this->_insert( this->_root, value ).first );
    }

    template < typename T, typename Compare, typename Allocator>
    template <typename InputIterator>
    void binary_search_tree<T, Compare, Allocator>::insert( InputIterator first, InputIterator last )
    {
        for ( ; first != last; ++first )
            this->insert( *( first ) );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::erase( iterator position )
    {
    node_type_ptr node = position.base();

        if ( node == &this->_base || node == this->_null ) // do I need that? Do I need this->_base in general?
            return ;
        if ( node->_left == this->_null )
            this->_transplant( node, node->_right );
        else if ( node->_right == this->_null )
            this->_transplant( node, node->_left );
        else
        {
            node_type_ptr replacement = tree_min<T>( node->_right );
            if ( replacement->_parent != node )
            {
                this->_transplant( replacement, replacement->_right );
                replacement->_right = node->_right;
                replacement->_right->_parent = replacement;
            }
            this->_transplant( node, replacement );
            replacement->_left = node->_left;
            replacement->_left->_parent = replacement;
        }
        this->destroy_node( node ); // should catch the this->_null in the first if statement
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::size_type binary_search_tree<T, Compare, Allocator>::erase( const value_type& value)
    {
        iterator find_return = this->find( value );

        if ( find_return == this->end() )
            return ( 0 );
        this->erase( find_return );
        return ( 1 );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::erase( iterator first, iterator last )
    {
        while ( first != last )
            first = this->erase( first );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::swap( binary_search_tree& x )
    {
        if ( this != &x )
        {
            ft::swap( this->_base, x._base );
            ft::swap( this->_null, x._null );
            ft::swap( this->_root, x._root );
            if ( this->_root != nullptr )
            {
                this->_root->_parent = &this->_base;
                this->_base._left = this->_root;
            }
            if ( x._root != nullptr )
            {
                x._root->_parent = &x._base;
                x._base._left = x._root;
            }
            ft::swap( this->_compare, x._compare );
            ft::swap( this->_allocator, x._allocator );
            ft::swap( this->_size, x._size );
        }
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::clear()
    {
        if ( this->_root != this->_null )
        {
            _clear( this->_root );
            this->_root = this->_null;
            this->_base._left = this->_null;
        }
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::find( const value_type& value)
    {
        node_type_ptr rootptr = this->_root;

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
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::find( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_root;

        while ( rootptr != this->_null )
        {
            if ( this->_compare( value, rootptr->_data ) )
                rootptr = rootptr->_left;
            else if ( this->_compare( rootptr->_data, value ) )
                rootptr = rootptr->_right;
            else
                return ( const_iterator( rootptr ) );
        }
        return ( &this->_base );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::size_type binary_search_tree<T, Compare, Allocator>::count( const value_type& value) const
    {
        return ( this->find( value ) == &this->_base ? 0 : 1 );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::lower_bound( const value_type& value)
    {
        node_type_ptr       rootptr = this->_root;
        iterator            position = &this->_base;

        while ( rootptr != this->_null )
        {
            if ( this->_compare( rootptr->_data, value ) )
            {
                position = rootptr;
                rootptr = rootptr->_right;
            }
            else
                rootptr = rootptr->_left;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::lower_bound( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_root;
        const_iterator      position = &this->_base;

        while ( rootptr != this->_null )
        {
            if ( this->_compare( rootptr->_data, value ) )
            {
                position = rootptr;
                rootptr = rootptr->_right;
            }
            else
                rootptr = rootptr->_left;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::upper_bound( const value_type& value)
    {
        node_type_ptr       rootptr = this->_root;
        iterator            position = &this->_base;

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
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::upper_bound( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_root;
        const_iterator      position = &this->_base;

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
    pair<typename binary_search_tree<T, Compare, Allocator>::const_iterator,
        typename binary_search_tree<T, Compare, Allocator>::const_iterator> 
        binary_search_tree<T, Compare, Allocator>::equal_range( const value_type& k ) const
    {
        const_iterator                              first = &this->_base;
        const_iterator                              second = &this->_base;
        ft::pair<const_iterator, const_iterator>    return_pair = ft::make_pair( first, second );

        return_pair.first = lower_bound( k );
        return_pair.second = upper_bound( k );

        return ( *( return_pair ) );


        // test against:

        // typedef pair<const_iterator, const_iterator>    return_pair;
        // const_node_type_ptr                       rootptr = this->root;
        // const_iterator                            position = this->_base;

        // while ( this->_root != this->_null )
        // {
        //     if ( this->_compare( k, this->_root->_data ) )
        //     {
        //         position = this->_root;
        //         this->_root = this->_root->_left;
        //     }
        //     else if ( this->_compare( this->_root->_data, k ) )
        //         this->_root = this->_root->_right;
        //     else
        //         return ( return_pair( const_iterator( this->_root ), const_iterator( this->_root->_right != this->_null ? tree_min<value_type>( this->_root->_right : position ) ) ) );
        // }
        // return ( return_pair( const_iterator( position ), const_iterator( position ) ) );
    }

    template < typename T, typename Compare, typename Allocator>
    pair<typename binary_search_tree<T, Compare, Allocator>::iterator,
        typename binary_search_tree<T, Compare, Allocator>::iterator> 
        binary_search_tree<T, Compare, Allocator>::equal_range( const value_type& k )
    {
        iterator                        first = &this->_base;
        iterator                        second = &this->_base;
        ft::pair<iterator, iterator>    return_pair = ft::make_pair( first, second );

        return_pair.first = lower_bound( k );
        return_pair.second = upper_bound( k );

        return ( *( return_pair ) );


        // test against:

        // typedef pair<iterator, iterator>    return_pair;
        // node_type_ptr                       rootptr = this->root;
        // iterator                            position = this->_base;

        // while ( this->_root != this->_null )
        // {
        //     if ( this->_compare( k, this->_root->_data ) )
        //     {
        //         position = this->_root;
        //         this->_root = this->_root->_left;
        //     }
        //     else if ( this->_compare( this->_root->_data, k ) )
        //         this->_root = this->_root->_right;
        //     else
        //         return ( return_pair( iterator( this->_root ), iterator( this->_root->_right != this->_null ? tree_min<value_type>( this->_root->_right : position ) ) ) );
        // }
        // return ( return_pair( iterator( position ), iterator( position ) ) );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::debug_print()
    {
        debug_print_recursive_inverted( this->_root, 0, false );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::allocator_type binary_search_tree<T, Compare, Allocator>::get_allocator() const
    {
        return ( this->_allocator );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::destroy_node( node_type_ptr node )
    {
        if ( node != nullptr ) // or this->_null? No, because this is caught in the clear() function before!
        {
            this->_allocator.destroy( &node->_data );
            this->_node_allocator.deallocate( node, 1 );
            --( this->_size );
        }
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::value_compare binary_search_tree<T, Compare, Allocator>::value_comp()
    {
        return ( this->_compare );
    }

    /* private */

    template < typename T, typename Compare, typename Allocator>
    pair<typename binary_search_tree<T, Compare, Allocator>::iterator, bool> binary_search_tree<T, Compare, Allocator>::_insert( node_type_ptr rootptr, const value_type& value )
    {
        node_type_ptr       position = &this->_base;
        node_type_ptr       new_node = _vcreate_node( value );
        bool                insert_flag = true;

        while ( rootptr != this->_null )
        {
            position = rootptr;
            if ( this->_compare( new_node->_data, rootptr->_data ) )
                rootptr = rootptr->_left;
            else if ( this->_compare( rootptr->_data, new_node->_data ) )
                rootptr = rootptr->_right;
            else
            {
                insert_flag = false;
                break ;
            }
        }
        new_node->_parent = position;
        if ( position == &this->_base ) // empty tree   // TASK: write own "instanciate_root()"-function!
        {
            this->_root = new_node;
            this->_root->_parent = &this->_base;
            this->_root->_left = this->_null;
            this->_root->_right = this->_null;
            this->_base._left = this->_root;
        }
        else if ( this->_compare( new_node->_data, position->_data ) )
            position->_left = new_node;
        else if ( this->_compare( position->_data, new_node->_data ) )
            position->_right = new_node;
        else
            destroy_node( new_node);
        if ( insert_flag == true )
            ++( this->_size );
        return ( ft::make_pair( this->_make_iter( position ), insert_flag ) );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::_transplant( node_type_ptr old_subtree, node_type_ptr new_subtree )
    {
        if ( old_subtree->_parent == &this->_base )
            this->_root = new_subtree;
        else if ( old_subtree == old_subtree->_parent->_left )
            old_subtree->_parent->_left = new_subtree;
        else
            old_subtree->_parent->_right = new_subtree;
        if ( new_subtree != this->_null )
            new_subtree->_parent = old_subtree->_parent;
    }

    template < typename T, typename Compare, typename Allocator>
    bool binary_search_tree<T, Compare, Allocator>::_node_has_children( node_type_ptr &node)
    {
        if ( node->_left == this->_null && node->_right == this->_null )
            return ( false );
        return ( true );
    }
    
    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::node_type_ptr 
    binary_search_tree<T, Compare, Allocator>::_clone_tree( const binary_search_tree& other, node_type_ptr &other_root )
    {
        if ( other_root == other->_null ) // or nullptr?
            return ( this->_null ); // or nullptr?
        node_type_ptr copy_node = this->_node_allocator.allocate( 1 );
        this->allocator.construct( copy_node->_data, other_root->_data );
        copy_node->_left = this->_clone_tree( other_root->_left );
        copy_node->_right = this->_clone_tree( other_root->_right );
        return ( copy_node );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::debug_print_recursive_inverted( node_type_ptr root, int level, bool is_right )
    {
        //INVERTED for better human readability
        if (root == this->_null)
            return ;

        debug_print_recursive_inverted( root->_right,  level + 1, true );

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
            std::cout << " " << rootptr->_data << "\033[37m\n";

        debug_print_recursive_inverted( root->_left, level + 1, false );
    }

    template <typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::node_type_ptr binary_search_tree<T, Compare, Allocator>::_vcreate_node( const value_type& value )
    {
        node_type_ptr new_node = this->_node_allocator.allocate( 1 );
        this->_allocator.construct( &new_node->_data, value );
        new_node->_colour = BLACK; // RED for Binary Search Tree
        new_node->_parent = this->_null;
        new_node->_left = this->_null;
        new_node->_right = this->_null;
        return ( new_node );
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::_clear( node_type_ptr &rootptr)
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
    }

    /* binary_search_tree non-member functions */

    template < typename T, typename Compare, typename Allocator>
    void swap( const ft::binary_search_tree<T, Compare, Allocator>& lhs, const ft::binary_search_tree<T, Compare, Allocator>& rhs )
    {
        lhs.swap( rhs );
    }


    /* --------------------------- Red Black Tree ---------------------------- */

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
    ** 5. For each node, all simple paths from the node to descendant leaves contain the
same number of black nodes
    */
    // template <typename T, typename Compare, typename Allocator>
    // class red_black_tree : public binary_search_tree<typename T, typename Compare, typename Allocator>
    // {

    //     // code...

    //     // queries (search min, max, successor, precursor) from BST

    //     // updates (insert, delete/erase) <- recolour and reorder (via rotation = right_rotate(node) left_rotate(node))
    //     // RB_insert(x) -> tree_insert(x)
    //         // -> might violate rule that red node needs black parent
    //         // solution: move problem up the tree, until we can fix it via recolouring and/or rotation
    //         // steps:
    //         // tree_insert(x) (BST)
    //         // colour x = red
    //         //  (walk up the tree) while x != root && colour x == red
    //         // 6 cases (3 left, and 3 right):
    //         // if p[p[x]] == p[p[x]]->_left
    //             // 3 cases:
    //             // 1. y = p[p[x]]->_right (= uncle/aunt of x)
    //             // if colour[y] == RED -> we recolour   CASE 1
    //               // else if x == p[x]->_right  CASE 2
    //               // after that do CASE 3
    //         // else: do it the same but right, instead of left
    //         // after that, always colour root to BLACK (just in case)


    //         // 3 CASES:
    //         // CASE 1:
    //             // recolour p[x], p[p[x]] & y and change x to p[p[x]] (and go on in the loop) -> pushes the problem up the tree
    //         // CASE 2:
    //             // left rotation on p[x] so x is now left child
    //         // CASE 3
    //             // right rotate of p[p[x]]

    // }; // red_black_tree

} // namespace ft
