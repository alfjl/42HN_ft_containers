#pragma once

#ifndef nullptr
#define nullptr NULL
#endif

namespace ft
{

    /* ------------------------------ tree_node ------------------------------- */

    /*
    ** A general node template to be used in my implementation of 
    ** Binary Search Tree (BST) and Red Black Tree (RBT)
    ** Colour is unused in BST und just set to default 'black'
    */

    enum node_state
    {
        red = 1,
        black = 0
    };

    template <typename T>
    class tree_node
    {
    private:
        node_state   colour;
        T           data;
        tree_node    *parent;
        tree_node    *left;
        tree_node    *right;
    public:
        tree_node();
        tree_node( const tree_node &other);
        ~tree_node();

        tree_node    &operator=( const tree_node &src );
    };

    template <typename T>
    tree_node<T>::tree_node() : colour(black), data(), parent(), left(), right() {}

    template <typename T>
    tree_node<T>::tree_node( const tree_node &other) : colour(black), data(), parent(), left(), right()
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
    }; // tree_node

    /* --------------------------- Tree Iterator ----------------------------- */

    template <typename T, typename NodePtr>
    class tree_iterator
    {
    public:
        typedef typename tree_iterator_tag              iterator_category;
        typedef typename T                              value_type;
        typedef typename ptrdiff_t                      difference_type;
        typedef typename T*                             pointer;
        typedef typename T&                             reference;

    private:
        NodePtr current_node;

    public:
        tree_iterator();
        tree_iterator( const NodePtr& ptr );
        tree_iterator( const tree_iterator& other );
        ~tree_iterator();

        operator tree_iterator<const T>() const;

        tree_iterator& operator=( const tree_iterator& src );
        tree_iterator& operator=( const pointer& src_ptr );

        iterator_type base() const;
        reference operator*() const;
        pointer operator->() const;
        tree_iterator& operator++();
        tree_iterator  operator++(int);
        tree_iterator& operator--();
        tree_iterator  operator--(int);

    }; // tree_iterator

        /* bidirectional_iterator member functions */
    
    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>::tree_iterator() : _ptr() {}

    // template <typename T, typename NodePtr>
    // tree_iterator<T, NodePtr>::tree_iterator( pointer ptr ) : _ptr( ptr ) {}

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>::tree_iterator( const NodePtr& ptr ) : _ptr( ptr ) {}
    
    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>::tree_iterator( const tree_iterator& other ) : _ptr( other.base() ) {}

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>::~tree_iterator() {}

    // template <typename T, typename NodePtr>
    // tree_iterator<T, NodePtr>::operator tree_iterator<const T, const NodePtr>() const
    // {
    //     return ( this->_ptr );
    // }

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>& tree_iterator<T, NodePtr>::operator=( const tree_iterator<T, NodePtr>& src )
    {
        _ptr = src.base();
        return ( *this );
    }

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>& tree_iterator<T, NodePtr>::operator=( const pointer& src_ptr )
    {
        _ptr = src_ptr;
        return ( *this );
    }

    template <typename T, typename NodePtr>
    typename tree_iterator<T, NodePtr>::iterator_type tree_iterator<T, NodePtr>::base() const
    {
        return ( this->_ptr );
    }

    template <typename T, typename NodePtr>
    typename tree_iterator<T, NodePtr>::reference tree_iterator<T, NodePtr>::operator*() const
    {
        return ( *(this->_ptr) );
    }

    template <typename T, typename NodePtr>
    typename tree_iterator<T, NodePtr>::pointer tree_iterator<T, NodePtr>::operator->() const
    {
        return ( this->_ptr );
    }

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>& tree_iterator<T, NodePtr>::operator++()
    {
        ++( this->_ptr );
        return ( *this );
    }

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>  tree_iterator<T, NodePtr>::operator++( int )
    {
        bidirectional_iterator  temp = *this;
        ++( this->_ptr );
        return ( temp );
    }

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>& tree_iterator<T, NodePtr>::operator--()
    {
        --( this->_ptr );
        return ( *this );
    }

    template <typename T, typename NodePtr>
    tree_iterator<T, NodePtr>  tree_iterator<T, NodePtr>::operator--( int )
    {
        bidirectional_iterator  temp = *this;
        --( this->_ptr );
        return ( temp );
    }

    /* bidirectional_iterator non-member functions */

    template <typename T1, typename T2>
    bool operator==( const bidirectional_iterator<T1>& lhs, const bidirectional_iterator<T2>& rhs )
    {
        return ( lhs.base() == rhs.base() );
    }

    template <typename T1, typename T2>
    bool operator!=( const bidirectional_iterator<T1>& lhs, const bidirectional_iterator<T2>& rhs )
    {
        return ( lhs.base() != rhs.base() );
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

    template <typename T, typename Compare, typename Allocator>
    class binary_search_tree
    {

    public:
        typedef T                                               value_type;
        typedef Compare                                         value_compare;
        typedef Allocator                                       allocator_type;
        typedef typename allocator_type::size_type              size_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;

    private:
        typedef ft::tree_node<value_type>                       node_type;

    private:
        node_type      *root;
        value_compare   _compare;
        allocator_type  _allocator;
        size_type       _size;


    }; // binary_search_tree

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
    class red_black_tree : public binary_search_tree
    {

        // code...

    }; // red_black_tree
} // namespace ft