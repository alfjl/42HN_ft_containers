#pragma once

#include "utils/iterator.hpp"

namespace ft
{

    /* -------------------------------- stack -------------------------------- */

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


        explicit vector::vector( const allocator_type& alloc = allocator_type() ) // default constructor (empty container)
        {

        }

        explicit vector::vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) // fill constructor
        {

        }

        template <class InputIterator>
            vector::vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) // range constructor
            {

            }

        vector::vector( const vector& x ) // copy constructor
        {

        }

        vector::~vector()
        {

        }


        vector& vector::operator=( const vector& x ); // assignment operator

        iterator vector::begin();
        const_iterator vector::begin() const;

        iterator vector::end();
        const_iterator vector::end() const;

        reverse_iterator vector::rbegin();
        const_reverse_iterator vector::rbegin() const;

        reverse_iterator vector::rend();
        const_reverse_iterator vector::rend() const;

        size_type vector::size() const;

        size_type vector::max_size() const;

        void vector::resize( size_type n, value_type val = value_type() );

        size_type vector::capacity() const;

        bool vector::empty() const;

        void vector::reserve( size_type n );

        reference vector::operator[]( size_type n );
        const_reference vector::operator[]( size_type n ) const;

        reference vector::at( size_type n );
        const_reference vector::at( size_type n ) const;

        reference vector::front();
        const_reference vector::front() const;

        reference vector::back();
        const_reference vector::back() const;

        template <class InputIterator>
            void vector::assign( InputIterator first, InputIterator last ); // range version	
        void vector::assign( size_type n, const value_type& val ); // fill version

        void vector::push_back( const value_type& val );

        void vector::pop_back();

        iterator vector::insert( iterator position, const value_type& val ); // single element
        void vector::insert( iterator position, size_type n, const value_type& val ); // fill version
        template <class InputIterator>
            void vector::insert( iterator position, InputIterator first, InputIterator last ); // range version

        iterator vector::erase( iterator position );
        iterator vector::erase( iterator first, iterator last );

        void vector::swap( vector& x );

        void vector::clear();

        allocator_type vector::get_allocator() const;

} // namespace ft
