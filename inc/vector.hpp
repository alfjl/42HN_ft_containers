#pragma once

#include <memory>

#include "utils/iterator.hpp"
#include "algorithm.hpp"

namespace ft
{

    /* -------------------------------- vector ------------------------------- */

    /*
    ** (https://cplusplus.com/reference/vector/vector/)
    ** Vectors are sequence containers representing arrays that can change in size [dynamically].
    ** [V]ectors use contiguous storage locations for their elements, which means
    ** that their elements can also be accessed using offsets on regular pointers to its elements[.]
    ** Internally, vectors use a dynamically allocated array to store their elements.
    ** [V]vector containers may allocate some extra storage to accommodate for possible growth,
    ** and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements
    ** [V]ectors are very efficient accessing its elements [...] and relatively efficient adding or removing elements from its end.
    ** For operations that involve inserting or removing elements at positions other than the end, they perform worse than [other dynamic sequence containers (deques, lists and forward_lists)] 
    */

    template < typename T, typename Alloc = std::allocator<T> >
    class vector
    {
    
    public:
        typedef T												value_type;
        typedef Alloc											allocator_type;
        typedef typename allocator_type::reference				reference;
        typedef typename allocator_type::const_reference		const_reference;
        typedef typename allocator_type::pointer				pointer;
        typedef typename allocator_type::const_pointer			const_pointer;
        typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
        typedef ft::reverse_iterator<iterator>					reverse_iterator;
	    typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
        // typedef iterator_traits<iterator>::difference_type	difference_type; // or:
        typedef std::ptrdiff_t									difference_type;
        typedef std::size_t										size_type;
        
    private:
        allocator_type  _allocator;
        pointer         _begin;
        pointer         _end;
        size_type       _capacity;

    public:
        explicit vector( const allocator_type& alloc = allocator_type() ); // default constructor (empty container)
        explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ); // fill constructor
        template <class InputIterator>
            vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ); // range constructor
        vector( const vector& x ); // copy constructor
        ~vector();

        vector& operator= ( const vector& x ); // assignment operator

        iterator begin();
        const_iterator begin() const;

        iterator end();
        const_iterator end() const;

        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;

        reverse_iterator rend();
        const_reverse_iterator rend() const;

        size_type size() const;

        size_type max_size() const;

        void resize( size_type n, value_type val = value_type() );

        size_type capacity() const;

        bool empty() const;

        void reserve( size_type n );

        reference operator[]( size_type n );
        const_reference operator[]( size_type n ) const;

        reference at( size_type n );
        const_reference at( size_type n ) const;

        reference front();
        const_reference front() const;

        reference back();
        const_reference back() const;

        template <class InputIterator>
            void assign( InputIterator first, InputIterator last ); // range version	
        void assign( size_type n, const value_type& val ); // fill version

        void push_back( const value_type& val );

        void pop_back();

        iterator insert( iterator position, const value_type& val ); // single element
        void insert( iterator position, size_type n, const value_type& val ); // fill version
        template <class InputIterator>
            void insert( iterator position, InputIterator first, InputIterator last ); // range version

        iterator erase( iterator position );
        iterator erase( iterator first, iterator last );

        void swap( vector& x );

        void clear();

        allocator_type get_allocator() const;
    
    }; // vector


    /* vector member functions */

    template < typename T, typename Alloc>
    vector<T, Alloc>::vector( const allocator_type& alloc ) : _allocator(alloc), _begin(nullptr), _end(nullptr), _capacity(0) {}

    template < typename T, typename Alloc>
    vector<T, Alloc>::vector( size_type n, const value_type& val, const allocator_type& alloc ) // fill constructor
    {

    }

        allocator_type  _allocator;
        pointer         _begin;
        pointer         _end;
        size_type       _capacity;

    template < typename T, typename Alloc>
    template <class InputIterator>
    vector<T, Alloc>::vector( InputIterator first, InputIterator last, const allocator_type& alloc ) // range constructor
    {

    }

    template < typename T, typename Alloc>
    vector<T, Alloc>::vector( const vector& x ) // copy constructor
    {

    }

    template < typename T, typename Alloc>
    vector<T, Alloc>::~vector()
    {

    }


    template < typename T, typename Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator=( const vector<T, Alloc>& x ) // assignment operator
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {

    }


    template < typename T, typename Alloc>
    void vector<T, Alloc>::resize( size_type n, value_type val )
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {

    }


    template < typename T, typename Alloc>
    bool vector<T, Alloc>::empty() const
    {

    }


    template < typename T, typename Alloc>
    void vector<T, Alloc>::reserve( size_type n )
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[]( size_type n )
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[]( size_type n ) const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at( size_type n )
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at( size_type n ) const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {

    }


    template < typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::assign( InputIterator first, InputIterator last ) // range version
    {

    }

    template < typename T, typename Alloc>
    void vector<T, Alloc>::assign( size_type n, const value_type& val ) // fill version
    {

    }


    template < typename T, typename Alloc>
    void vector<T, Alloc>::push_back( const value_type& val )
    {

    }


    template < typename T, typename Alloc>
    void vector<T, Alloc>::pop_back()
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector::insert( iterator position, const value_type& val ) // single element
    {

    }

    template < typename T, typename Alloc>
    void vector<T, Alloc>::insert( iterator position, size_type n, const value_type& val ) // fill version
    {

    }

    template < typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::insert( iterator position, InputIterator first, InputIterator last ) // range version
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator position )
    {

    }

    template < typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator first, iterator last )
    {

    }


    template < typename T, typename Alloc>
    void vector<T, Alloc>::swap( vector<T, Alloc>& x )
    {

    }


    template < typename T, typename Alloc>
    void vector<T, Alloc>::clear()
    {

    }


    template < typename T, typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {

    }


    /* vector non-member functions */

    template <typename T, typename Alloc>
    inline bool operator==( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    {
        return ( lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
    }

    template <typename T, typename Alloc>
    inline bool operator!=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename T, typename Alloc>
    inline bool operator<( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    {
        return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
    }

    template <typename T, typename Alloc>
    inline bool operator<=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    {
        return ( !( rhs < lhs ) );
    }

    template <typename T, typename Alloc>
    inline bool operator>( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    {
        return ( rhs < lhs );
    }

    template <typename T, typename Alloc>
    inline bool operator>=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
    {
        return ( !( lhs < rhs ) );
    }


    template< typename T, typename Alloc >
    void swap( vector<T, Alloc>& lhs, vector<T, Alloc>& rhs )
    {
        lhs.swap( rhs );
    }

} // namespace ft
