/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:58:32 by alanghan          #+#    #+#             */
/*   Updated: 2022/08/24 11:46:45 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <stdexcept>

#include "utils/type_traits.hpp"
#include "utils/iterator.hpp"
#include "utils/utility.hpp"
#include "./algorithm.hpp"

#ifndef nullptr
#define nullptr NULL
#endif

namespace ft
{

    /* -------------------------------- vector ------------------------------ */

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
        typedef std::ptrdiff_t									difference_type;
        typedef std::size_t										size_type;

    private:
        allocator_type  _allocator;
        pointer         _begin;
        pointer         _end;
        size_type       _capacity;

    public:
        // Constructors / Destructor / Assignment
        explicit vector( const allocator_type& alloc = allocator_type() ); // default constructor (empty container)
        explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ); // fill constructor
        template <class InputIterator>
            vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0 ); // range constructor
        vector( const vector& src ); // copy constructor
        ~vector();

        vector& operator=( const vector& other ); // assignment operator

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
        size_type size() const;
        size_type max_size() const;
        void resize( size_type n, value_type val = value_type() );
        size_type capacity() const;
        bool empty() const;
        void reserve( size_type n );

        // Element access:
        reference operator[]( size_type n );
        const_reference operator[]( size_type n ) const;
        reference at( size_type n );
        const_reference at( size_type n ) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        // Modifiers:
        template <class InputIterator>
            void assign( InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0 ); // range version	
        void assign( size_type n, const value_type& val ); // fill version
        void push_back( const value_type& val );
        void pop_back();
        iterator insert( iterator position, const value_type& val ); // single element
        void insert( iterator position, size_type n, const value_type& val ); // fill version
        template <class InputIterator>
            void insert( iterator position, InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0 ); // range version
        iterator erase( iterator position );
        iterator erase( iterator first, iterator last );
        void swap( vector& x );
        void clear();

        // Allocator:
        allocator_type get_allocator() const;

    private:
        // Conversions:
        iterator _make_iter( pointer ptr );
        const_iterator _make_iter( const_pointer ptr ) const;
        pointer _vmake_pointer(iterator itr);
        const_pointer _vmake_pointer(const_iterator itr) const;

        // Memory Management / Construction / Destruction
        size_type _vcalculate_size( size_type n) const; // checks n for validity and returns new size
        pointer _vallocate(size_type n); // allocate space for n objects
        void _vdeallocate( size_type n ); // clears all objects from vector and deallocates space
        void _vconstruct_elements( const size_type& n, const value_type& val ); // constructs elements of type val
        void _vconstruct_copies( const vector& other ); // constructs copies of elements of 'other'
        void _vdestruct_at_end( pointer _new_end );
        void _vresize_empty_vector( size_type n );

        // Assign Helper Functions
        template <class InputIterator>
            void _assign_range( InputIterator first, InputIterator last,
                                typename ft::input_iterator_tag ); // range version: input_iterator
        template <class InputIterator>
            void _assign_range( InputIterator first, InputIterator last,
                                typename ft::forward_iterator_tag ); // range version: forward_iterator
        template <class InputIterator>
            void _insert_range( iterator position, InputIterator first, InputIterator last,
                                typename ft::input_iterator_tag ); // range version: input_iterator
        template <class InputIterator>
            void _insert_range( iterator position, InputIterator first, InputIterator last,
                                typename ft::forward_iterator_tag ); // range version: forward_iterator
                        
    }; // vector


    /* vector member functions */
    /* public */

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector( const allocator_type& alloc ) : _allocator(alloc), _begin(nullptr), _end(nullptr), _capacity(0) {}

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector( size_type n, const value_type& val, const allocator_type& alloc )  : _allocator(alloc), _begin(nullptr), _end(nullptr), _capacity(0) // fill constructor
    {
        if ( n != 0 )
        {
            this->_begin = this->_vallocate( n );
            this->_end = this->_begin + n;
            this->_vconstruct_elements( n, val );
        }
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    vector<T, Alloc>::vector( InputIterator first, InputIterator last, const allocator_type& alloc,
                                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type *) : _allocator(alloc), _begin(nullptr), _end(nullptr), _capacity(0) // range constructor
    {
        assign( first, last );
    }

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector( const vector& src )  : _allocator(src._allocator), _begin(nullptr), _end(nullptr), _capacity(0) // copy constructor
    {
        *this = src;
    }

    template <typename T, typename Alloc>
    vector<T, Alloc>::~vector()
    {
        if ( this->_begin != nullptr )
            this->_vdeallocate( this->_capacity );
    }


    template <typename T, typename Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator=( const vector<T, Alloc>& other ) // assignment operator
    {
        if ( this != &other )
        {
            this->_vdeallocate( this->_capacity );
            this->_allocator = other._allocator;
            size_type n = other.capacity();
            this->_begin = this->_vallocate( n );
            this->_end = this->_begin + other.size();
            this->_vconstruct_copies( other );
        }
        return ( *this );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return ( iterator( this->_begin ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return ( const_iterator( this->_begin ) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return ( iterator( this->_end ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return ( const_iterator( this->_end ) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return ( reverse_iterator( this->end() ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return ( const_reverse_iterator( this->end() ) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return ( reverse_iterator( this->begin() ) );

    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return ( const_reverse_iterator( this->begin() ) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return ( static_cast<size_type>(this->_end - this->_begin) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
            size_type alloc_max = this->_allocator.max_size();
            size_type numeric_max = std::numeric_limits<size_type>::max() / 2;
            return ( ( alloc_max < numeric_max ) ? alloc_max : numeric_max );
    }


    template <typename T, typename Alloc>
    void vector<T, Alloc>::resize( size_type n, value_type val )
    {
        size_type   temp_size = this->size();

        if ( n == temp_size )
            return ;
        if ( n < temp_size )
            this->_vdestruct_at_end(this->_begin + n);
        else
        {
            this->reserve( n );
            for ( ; temp_size < n; ++temp_size )
                this->push_back( val );
        }
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return ( this->_capacity );
    }


    template <typename T, typename Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return ( this->_begin == this->_end );
    }


    template <typename T, typename Alloc>
    void vector<T, Alloc>::reserve( size_type n )
    {
        if ( n > this->capacity() )
        {
            size_type   temp_capacity = this->capacity();
            size_type   temp_size = this->size();
            pointer     temp_begin = this->_vallocate( n );

            for ( size_type i = 0; i < temp_size; ++i )
                this->_allocator.construct( temp_begin + i, this->_begin[i] );
            this->_vdeallocate( temp_capacity );
            this->_begin = temp_begin;
            this->_end = this->_begin + temp_size;
        }
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[]( size_type n )
    {
        return ( *( this->_begin + n ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[]( size_type n ) const
    {
        return ( *( this->_begin + n ) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at( size_type n )
    {
        if ( n < this->size() )
            return ( *( this->_begin + n ) );
        else
            throw std::out_of_range( "ft::vector" );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at( size_type n ) const
    {
        if ( n < this->size() )
            return ( *( this->_begin + n ) );
        else
            throw std::out_of_range( "ft::vector" );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return ( *( this->_begin ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return ( *( this->_begin ) );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return ( *( this->_end - 1 ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {
        return ( *( this->_end - 1 ) );
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::assign( InputIterator first, InputIterator last,
                                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * ) // range version
    {
        this->_assign_range( first, last, ft::iterator_category( first ) );
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::assign( size_type n, const value_type& val ) // fill version
    {

        this->clear();
        if ( n > this->_capacity )
            _vresize_empty_vector( n );
        for ( size_type i = 0; i < n; ++i )
        {
            this->_allocator.construct( this->_end, val );
            ++this->_end;
        }
    }


    template <typename T, typename Alloc>
    void vector<T, Alloc>::push_back( const value_type& val )
    {
        this->reserve( this->size() + 1 );
        this->_allocator.construct( this->_end, val );
        ++this->_end;
    }


    template <typename T, typename Alloc>
    void vector<T, Alloc>::pop_back()
    {
        if ( !( this->empty() ) )
        {
            --this->_end;
            this->_allocator.destroy( this->_end );
        }
    }

    // (https://en.cppreference.com/w/cpp/container/vector/insert)
    // If the new size() is greater than capacity(),
    // all iterators and references are invalidated.
    // Otherwise, only the iterators and references before the insertion point
    // remain valid. The past-the-end iterator is also invalidated.
    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( iterator position, const value_type& val ) // single element
    {
        iterator    begin = this->begin();
        iterator    end = this->end();
        size_type   n = static_cast<size_type>( ft::distance( begin, position ) );

        if ( position == end )
        {
            push_back( val );
            return ( --( this->end() ) );
        }
        else
            this->insert( position, 1, val );
        return ( this->_make_iter( this->_begin + n ) );
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::insert( iterator position, size_type n, const value_type& val ) // fill version
    {
        pointer pos = _vmake_pointer( position );

        if ( pos == this->_end )
        {
            for ( size_type i = 0; i < n; i++ )
                push_back( val );
        }
        else
        {
            size_type       old_size = this->size();
            size_type       distance = static_cast<size_type>( ft::distance( this->_begin, pos ) );

            this->resize( old_size + n );

            iterator    temp_first = this->begin() + distance;
            iterator    temp_last = this->begin() + old_size;
            iterator    new_position = this->begin() + old_size + n;

            while ( temp_last != temp_first )
		        *( --new_position ) = *( --temp_last );
            for ( iterator it = temp_first; it != temp_first + n; ++it )
            {
                *it = val;
            }
        }
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::insert( iterator position, InputIterator first, InputIterator last,
                                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * ) // range version
    {
        this->_insert_range( position, first, last, ft::iterator_category( first ) );
    }

    // (https://cplusplus.com/reference/vector/vector/erase/)
    // An invalid position or range causes undefined behavior.
    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator position )
    {
        pointer     p = this->_vmake_pointer( position );

        if ( p == ( this->_end - 1 ) )
            this->pop_back();
        else
        {
            for ( pointer it = p; it != this->_end; ++it)
            {
                this->_allocator.destroy( it );
                if ( ( it + 1 ) != this->_end )
                    this->_allocator.construct( it, *( it + 1 ) );
            }
            --( this->_end );
        }
        return ( position );
    }

    // (https://cplusplus.com/reference/vector/vector/erase/)
    // Iterators, pointers and references pointing to position (or first) and beyond are invalidated
    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator first, iterator last )
    {
        pointer temp_first = this->_vmake_pointer( first );
        pointer temp_last = this->_vmake_pointer( last );

        if ( first != last )
            _vdestruct_at_end( ft::copy( temp_last, this->_end, temp_first ) );
        return ( first );
    }


    template <typename T, typename Alloc>
    void vector<T, Alloc>::swap( vector<T, Alloc>& x )
    {
        ft::swap(this->_allocator, x._allocator);
        ft::swap(this->_begin, x._begin);
        ft::swap(this->_end, x._end);
        ft::swap(this->_capacity, x._capacity);
    }


    template <typename T, typename Alloc>
    void vector<T, Alloc>::clear()
    {
        this->_vdestruct_at_end( this->_begin );
    }


    template <typename T, typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return ( this->_allocator );
    }

    /* private */

    template <typename T, typename Alloc>
    inline typename vector<T, Alloc>::iterator vector<T, Alloc>::_make_iter(pointer ptr)
    {
        return ( iterator( ptr ) );
    }

    template <typename T, typename Alloc>
    inline typename vector<T, Alloc>::const_iterator vector<T, Alloc>::_make_iter(const_pointer ptr) const
    {
        return ( const_iterator( ptr ) );
    }

    template <typename T, typename Alloc>
    inline typename vector<T, Alloc>::pointer vector<T, Alloc>::_vmake_pointer(iterator itr)
    {
        return ( this->_begin + ( itr - this->begin() ) );
    }

    template <typename T, typename Alloc>
    inline typename vector<T, Alloc>::const_pointer vector<T, Alloc>::_vmake_pointer(const_iterator itr) const
    {
        return ( this->_begin + ( itr - this->begin() ) );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::_vcalculate_size( size_type n) const
    {
        const size_type temp_max_size = this->max_size();
        const size_type temp_capacity = this->capacity();
    
        if ( n > temp_max_size )
            throw std::length_error( "ft::vector" );
        if ( n < temp_capacity )
            return ( temp_capacity );
        if ( n >= temp_capacity && n >= temp_max_size / 2 )
            return ( temp_max_size );
        return ( n * 2 );
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::pointer vector<T, Alloc>::_vallocate(size_type n)
    {
        n = this->_vcalculate_size( n );
        this->_capacity = n;
        return ( this->_allocator.allocate( n ) );
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::_vdeallocate( size_type n )
    {
        if ( this->_begin != nullptr )
        {
            this->clear();
            this->_allocator.deallocate( this->_begin, n );
            this->_end = this->_begin = nullptr;
        }
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::_vconstruct_elements( const size_type& n, const value_type& val )
    {
        for ( size_type i = 0; i < n; ++i )
            this->_allocator.construct( this->_begin + i, val );
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::_vconstruct_copies( const vector& other )
    {
        size_type temp_n = other.size();

        for ( size_type i = 0; i < temp_n; ++i )
            this->_allocator.construct( this->_begin + i, other[i] );
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::_vdestruct_at_end( pointer _new_end )
    {
        pointer _soon_to_be_end = this->_end;

        if ( this->_capacity > 0 )
        {
            while ( _soon_to_be_end != _new_end )
                this->_allocator.destroy( --( _soon_to_be_end ) );
            this->_end = _new_end;
        }
    }

    template <typename T, typename Alloc>
    void vector<T, Alloc>::_vresize_empty_vector( size_type n )
    {
        pointer     temp_begin = this->_vallocate( n );

        if ( this->_begin != nullptr )
            this->_allocator.deallocate(this->_begin, this->capacity());
        this->_end = this->_begin = temp_begin;
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::_assign_range( InputIterator first, InputIterator last,
                                    typename ft::input_iterator_tag ) // range version: input_iterator
    {
        this->clear();
        for ( ; first != last; first++)
            this->push_back( *( first ) );
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::_assign_range( InputIterator first, InputIterator last,
                                    typename ft::forward_iterator_tag ) // range version: forward_iterator
    {
        size_type   n = static_cast<size_type>( ft::distance( first, last ) );
        
        this->clear();
        if ( n > this->_capacity )
            _vresize_empty_vector( n );
        for ( ; first != last; ++first)
        {
            this->_allocator.construct( this->_end, *( first ) );
            ++this->_end;
        }
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::_insert_range( iterator position, InputIterator first, InputIterator last,
                        typename ft::input_iterator_tag ) // range version: input_iterator
    {
        if ( first == last )
            return ;
        if ( position == this->end() )
        {
            for ( ; first != last; ++first )
                this->push_back( *( first ) );
        }
        else if ( first != last )
        {
            vector tmp(first, last);
            insert(position, tmp.begin(), tmp.end());
        }
    }

    template <typename T, typename Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::_insert_range( iterator position, InputIterator first, InputIterator last,
                        typename ft::forward_iterator_tag ) // range version: forward_iterator
    {
        pointer         pos = this->_vmake_pointer( position );
        size_type       n = static_cast<size_type>( ft::distance( first, last ) );
        size_type       distance = static_cast<size_type>( ft::distance( this->_begin, pos ) );
        size_type       old_size = this->size();

        if ( first == last )
            return ;
        if ( position == this->end() )
        {
            for ( ; first != last; ++first )
                this->push_back( *( first ) );
        }
        else
        {
            this->resize( old_size + n );
            iterator    temp_first = this->begin() + distance;
            iterator    temp_last = this->begin() + old_size;
            iterator    new_position = this->begin() + old_size + n;

            while ( temp_last != temp_first )
		        *( --new_position ) = *( --temp_last );

            pos = this->_begin + distance;
            for ( ; first != last; ++first )
            {
                *( pos ) = *( first );
                ++pos;
            }
        }
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
