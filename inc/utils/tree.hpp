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


    /* ------------------------- Binary Search Tree -------------------------- */

    /*
    ** (Cormen, Leiserson, Rivest & Stein: 'Introduction to Algorithms' - 3rd Edition, Chapter 12)
    ** We can represent such a tree by a linked data structure in which
    ** each node is an object. In addition to a key and satellite data,
    ** each node contains attributes left, right, and p [...]
    ** If a child or the parent is missing, the appropriate attribute contains the value NIL.
    ** The root node is the only node in the tree whose parent is NIL.
    */

    template <class T, class Compare, class Allocator>
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
        typedef ft::tree_node<value_type>                        node_type;

    private:
        node_type      *root;
        value_compare   _compare;
        allocator_type  _allocator;
        size_type       _size;


    }; // binary_search_tree

    template <class T, class Compare, class Allocator>
    class red_black_tree : public binary_search_tree
    {

        // code...

    }; // red_black_tree
} // namespace ft