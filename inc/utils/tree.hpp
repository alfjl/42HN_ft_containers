#pragma once

#include <memory>

#include "utils/functional.hpp"

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
    template <typename NodePtr>
    bool tree_is_left_child( NodePtr node_ptr )
    {
        return ( node_ptr == node_ptr->parent->left );
    }

    // Returns a pointer to the left-most node under node_ptr.
    template <typename NodePtr>
    NodePtr tree_min( NodePtr node_ptr )
    {
        while (node_ptr->left != nullptr)
            node_ptr = node_ptr->left;
        return node_ptr;
    }

    // Returns a pointer to the right-most node under node_ptr.
    template <typename NodePtr>
    NodePtr tree_max( NodePtr node_ptr )
    {
        while (node_ptr->right != nullptr)
            node_ptr = node_ptr->right;
        return node_ptr;
    }

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
    template <typename NodePtr>
    NodePtr tree_next_iter( NodePtr node_ptr )
    {
        if ( node_ptr->right != nullptr )
            return ( tree_min( node_ptr->right ) );
        while ( !( tree_is_left_child( node_ptr ) ) )
            node_ptr = node_ptr->parent;
        return ( node_ptr->parent );
    }

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
    template <typename NodePtr>
    NodePtr tree_prev_iter( NodePtr node_ptr )
    {
        if ( node_ptr->left != nullptr )
            return ( tree_max( node_ptr->left ) );
        while ( tree_is_left_child( node_ptr ) )
            node_ptr = node_ptr->parent;
        return ( node_ptr->parent );
    }



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

    private:
        node_state        colour;
        T                 data;
        tree_node         *parent;
        tree_node         *left;
        tree_node         *right;

    public:
        tree_node();
        tree_node( const tree_node &other);
        ~tree_node();

        tree_node &operator=( const tree_node &src );
    
        void change_colour();

    }; // tree_node

    /* tree_node member functions */

    template <typename T>
    tree_node<T>::tree_node() : colour( BLACK ), data(), parent(), left(), right() {}

    template <typename T>
    tree_node<T>::tree_node( const tree_node &other) : colour( BLACK ), data(), parent(), left(), right()
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
            this->colour = src.colour;
            this->data = src.data;
            this->parent = src.parent;
            this->left = src.left;
            this->right = src.right;
        }
        return ( *this );
    }

    template <typename T>
    void change_colour()
    {
        this->colour = ( this->colour == RED ) ? BLACK : RED;
    }


    /* --------------------------- Tree Iterator ----------------------------- */

    /*
    ** A bidirectional_iterator, with typenames NodePtr and T
    */

    template <typename NodePtr, typename T>
    class tree_iterator
    {
    public:
        typedef typename bidirectional_iterator_tag     iterator_category;
        typedef typename T                              value_type;
        typedef typename ptrdiff_t                      difference_type;
        typedef typename T*                             pointer;
        typedef typename T&                             reference;

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

    // template <typename NodePtr, typename T>
    // tree_iterator<NodePtr, T>::tree_iterator( pointer ptr ) : _ptr( ptr ) {}

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
        return ( this->_node_ptr->data );
    }

    template <typename NodePtr, typename T>
    typename tree_iterator<NodePtr, T>::pointer tree_iterator<NodePtr, T>::operator->() const
    {
        return ( &( this->_node_ptr->data ) );
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
        typedef typename bidirectional_iterator_tag         iterator_category;
        typedef typename T                                  value_type;
        typedef typename ptrdiff_t                          difference_type;
        typedef const T*                                    pointer;
        typedef const T&                                    reference;

    // private:
        // typedef tree_iterator<value_type, __node_pointer>   non_const_iterator;

    private:
        ConstNodePtr _node_ptr;

    public:
        tree_const_iterator();
        tree_const_iterator( const ConstNodePtr& ptr );
        tree_const_iterator( const tree_const_iterator& other );
        // tree_const_iterator( non_const_iterator non_const_other ); // maybe try this way first:
        tree_const_iterator( tree_iterator non_const_other );
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

    // template <typename NodePtr, typename T>
    // tree_iterator<NodePtr, T>::tree_iterator( pointer ptr ) : _ptr( ptr ) {}

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( const ConstNodePtr& ptr ) : _node_ptr( ptr ) {}    

    template <typename ConstNodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( const tree_const_iterator& other ) : _node_ptr( other._node_ptr ) {}

    // template <typename ConstNodePtr, typename T>
    // tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( non_const_iterator non_const_other ) : _node_ptr( non_const_other._node_ptr ) {} //  maybe try this way first:

    template <typename ConstNodePtr, typename T>
    template <typename NodePtr, typename T>
    tree_const_iterator<ConstNodePtr, T>::tree_const_iterator( tree_iterator<NodePtr, T> non_const_other ) : _node_ptr( non_const_other._node_ptr ) {}

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
        return ( this->_node_ptr->data );
    }

    template <typename ConstNodePtr, typename T>
    typename tree_const_iterator<ConstNodePtr, T>::pointer tree_const_iterator<ConstNodePtr, T>::operator->() const
    {
        return ( &( this->_node_ptr->data ) );
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
        tree_iterator   it = *this;
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
        typedef ft::tree_node<T>                                node_type;
        typedef typename node_type::node_ptr                    node_type_ptr;
        typedef typename node_type::const_node_ptr              const_node_type_ptr;
        typedef typename node_type::node_ref                    node_type_ref;
        typedef typename node_type::const_node_ref              const_node_type_ref;

    public:
        typedef T                                               value_type;
        typedef Compare                                         value_compare;
        typedef Allocator                                       allocator_type;
        typedef typename allocator_type::size_type              size_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef ft::tree_iterator<node_type, value_type>        iterator;
        typedef ft::tree_const_iterator<node_type, value_type>  const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

    private:
        node_type       *_base; // first node in tree. base->left is: root 
        node_type       *_root; // first node of tree with value
        value_compare   _compare; 
        allocator_type  _allocator; // for associated allocator object, map.get_allocator()
        size_type       _size; // number of elements in tree ( for use in map.size() )

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
        iterator find( const value_type& value);
        const_iterator find( const value_type& value) const;
        size_type count( const value_type& value) const;
        iterator lower_bound( const value_type& value);
        const_iterator lower_bound( const value_type& value) const;
        iterator upper_bound( const value_type& value);
        const_iterator upper_bound( const value_type& value) const;
        pair<iterator,iterator> equal_range( const value_type& value);
        pair<const_iterator,const_iterator> equal_range( const value_type& value) const;

        // Allocator / Compare:
        allocator_type get_allocator() const;
        value_compare value_comp();

    }; // binary_search_tree

    /* binary_search_tree member functions */

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
        return ( iterator( this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::end() const
    {
        return ( const_iterator( this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::reverse_iterator binary_search_tree<T, Compare, Allocator>::rbegin()
    {
        return ( reverse_iterator( this->_base ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_reverse_iterator binary_search_tree<T, Compare, Allocator>::rbegin() const
    {
        return ( const_reverse_iterator( this->_base ) );
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

    template < typename T, typename Compare, typename Allocator>
    pair<typename binary_search_tree<T, Compare, Allocator>::iterator, bool> binary_search_tree<T, Compare, Allocator>::insert( const value_type& value)
    {
        // https://cplusplus.com/reference/map/map/insert/
        // Insert elements
        // Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
        // Because element keys in a map are unique, the insertion operation checks whether each inserted element has a key equivalent to the one of an element already in the container, and if so, the element is not inserted, returning an iterator to this existing element (if the function returns a value).
        // For a similar container allowing for duplicate elements, see multimap.
        // An alternative way to insert elements in a map is by using member function map::operator[].
        // Internally, map containers keep all their elements sorted by their key following the criterion specified by its comparison object. The elements are always inserted in its respective position following this ordering.
        // The parameters determine how many elements are inserted and to which values they are initialized:
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::insert( iterator position, const value_type& value)
    {

    }

    template < typename T, typename Compare, typename Allocator>
    template <typename InputIterator>
    void binary_search_tree<T, Compare, Allocator>::insert( InputIterator first, InputIterator last )
    {
        
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::erase( iterator position )
    {

    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::size_type binary_search_tree<T, Compare, Allocator>::erase( const value_type& value)
    {

    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::erase( iterator first, iterator last )
    {

    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::swap( binary_search_tree& x )
    {
        
    }

    template < typename T, typename Compare, typename Allocator>
    void binary_search_tree<T, Compare, Allocator>::clear()
    {

    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::find( const value_type& value)
    {
        node_type_ptr rootptr = this->_root;

        while ( rootptr != nullptr )
        {
            if ( this->_compare( value, rootptr->data ) )
                rootptr = rootptr->left;
            else if ( this->_compare( rootptr->data, value ) )
                rootptr = rootptr->right;
            else
                return ( iterator( rootptr ) );
        }
        return ( this->_base );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::find( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->_root;

        while ( rootptr != nullptr )
        {
            if ( this->_compare( value, rootptr->data ) )
                rootptr = rootptr->left;
            else if ( this->_compare( rootptr->data, value ) )
                rootptr = rootptr->right;
            else
                return ( const_iterator( rootptr ) );
        }
        return ( this->_base );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::size_type binary_search_tree<T, Compare, Allocator>::count( const value_type& value) const
    {
        return ( this->find( value ) == this->_base ? 0 : 1 );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::lower_bound( const value_type& value)
    {
        node_type_ptr       rootptr = this->root;
        iterator            position = this->_base;

        while ( rootptr != nullptr )
        {
            if ( this->_compare( rootptr->data, value ) )
            {
                position = rootptr;
                rootptr = rootptr->right;
            }
            else
                rootptr = rootptr->left;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::lower_bound( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->root;
        const_iterator      position = this->_base;

        while ( rootptr != nullptr )
        {
            if ( this->_compare( rootptr->data, value ) )
            {
                position = rootptr;
                rootptr = rootptr->right;
            }
            else
                rootptr = rootptr->left;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::iterator binary_search_tree<T, Compare, Allocator>::upper_bound( const value_type& value)
    {
        node_type_ptr       rootptr = this->root;
        iterator            position = this->_base;

        while ( rootptr != nullptr )
        {
            if ( this->_compare( value, rootptr->data ) )
            {
                position = rootptr;
                rootptr = rootptr->left;
            }
            else
                rootptr = rootptr->right;
        }
        return ( iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::const_iterator binary_search_tree<T, Compare, Allocator>::upper_bound( const value_type& value) const
    {
        const_node_type_ptr rootptr = this->root;
        const_iterator      position = this->_base;

        while ( rootptr != nullptr )
        {
            if ( this->_compare( value, rootptr->data ) )
            {
                position = rootptr;
                rootptr = rootptr->left;
            }
            else
                rootptr = rootptr->right;
        }
        return ( const_iterator( position ) );
    }

    template < typename T, typename Compare, typename Allocator>
    pair<typename binary_search_tree<T, Compare, Allocator>::const_iterator,
        typename binary_search_tree<T, Compare, Allocator>::const_iterator> 
        binary_search_tree<T, Compare, Allocator>::equal_range( const value_type& k ) const
    {

    }

    template < typename T, typename Compare, typename Allocator>
    pair<typename binary_search_tree<T, Compare, Allocator>::iterator,
        typename binary_search_tree<T, Compare, Allocator>::iterator> 
        binary_search_tree<T, Compare, Allocator>::equal_range( const value_type& k )
    {

    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::allocator_type binary_search_tree<T, Compare, Allocator>::get_allocator() const
    {
        return ( this->_allocator );
    }

    template < typename T, typename Compare, typename Allocator>
    typename binary_search_tree<T, Compare, Allocator>::value_compare binary_search_tree<T, Compare, Allocator>::value_comp()
    {
        return ( this->_compare );
    }

    /* binary_search_tree non-member functions */


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
    template <typename T, typename Compare, typename Allocator>
    class red_black_tree : public binary_search_tree<typename T, typename Compare, typename Allocator>
    {

        // code...

        // queries (search min, max, successor, precursor) from BST

        // updates (insert, delete/erase) <- recolour and reorder (via rotation = right_rotate(node) left_rotate(node))
        // RB_insert(x) -> tree_insert(x)
            // -> might violate rule that red node needs black parent
            // solution: move problem up the tree, until we can fix it via recolouring and/or rotation
            // steps:
            // tree_insert(x) (BST)
            // colour x = red
            //  (walk up the tree) while x != root && colour x == red
            // 6 cases (3 left, and 3 right):
            // if p[p[x]] == p[p[x]]->left
                // 3 cases:
                // 1. y = p[p[x]]->right (= uncle/aunt of x)
                // if colour[y] == RED -> we recolour   CASE 1
                  // else if x == p[x]->right  CASE 2
                  // after that do CASE 3
            // else: do it the same but right, instead of left
            // after that, always colour root to BLACK (just in case)


            // 3 CASES:
            // CASE 1:
                // recolour p[x], p[p[x]] & y and change x to p[p[x]] (and go on in the loop) -> pushes the problem up the tree
            // CASE 2:
                // left rotation on p[x] so x is now left child
            // CASE 3
                // right rotate of p[p[x]]

    }; // red_black_tree

} // namespace ft
