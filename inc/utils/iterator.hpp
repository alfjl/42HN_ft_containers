/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:21:31 by alanghan          #+#    #+#             */
/*   Updated: 2022/07/12 16:43:22 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator> // still needed after changing the iterator_tags?

#include "type_traits.hpp"

namespace ft
{

    /* ---------------------------- iterator_tags --------------------------- */

    /* make own iterator_tag structs and use them later in the iterator typedef and iterator_traits instead of std::..._iterator_tag?

    // struct input_iterator_tag  {};
    // struct output_iterator_tag {};
    // struct forward_iterator_tag       : public input_iterator_tag         {};
    // struct bidirectional_iterator_tag : public forward_iterator_tag       {};
    // struct random_access_iterator_tag : public bidirectional_iterator_tag {};*/

    typedef std::output_iterator_tag		output_iterator_tag;
    typedef std::input_iterator_tag			input_iterator_tag;
    typedef std::forward_iterator_tag		forward_iterator_tag;
    typedef std::bidirectional_iterator_tag	bidirectional_iterator_tag;
    typedef std::random_access_iterator_tag	random_access_iterator_tag;

    /* ------------------------------ iterator ------------------------------ */

    /*
    ** (https://cplusplus.com/reference/iterator/iterator/)
    ** This is a base class template that can be used to derive iterator classes from it.
    ** It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
    ** This base class only provides some member types, which in fact are not required to be present in any iterator type
    ** (iterator types have no specific member requirements), but they might be useful,
    ** since they define the members needed for the default iterator_traits class template
    ** to generate the appropriate instantiation automatically
    ** (and such instantiation is required to be valid for all iterator types).
    */
    

    template <typename Category,               // Category to which the iterator belongs to (see: 'iterator tags')
              typename T,                      // Type of elements pointed by the iterator
              typename Distance = ptrdiff_t,   // Type to represent the difference between two iterators
              typename Pointer = T*,           // Type to represent a pointer to an element pointed by the iterator.
              typename Reference = T&>         // Type to represent a reference to an element pointed by the iterator
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    /* -------------------------- iterator_traits --------------------------- */

    template<typename Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    template<typename T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t                               difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef random_access_iterator_tag              iterator_category; // need change to ft::random_a....???? If yes, write structs for all iterator_tags first
    };

    template<typename T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                               difference_type;
        typedef T                                       value_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
        typedef random_access_iterator_tag              iterator_category; // need change to ft::random_a....???? If yes, write structs for all iterator_tags first
    };

    /* -------------------- auxiliary iterator functions -------------------- */

    /*
    ** (The C++ Standard Library - 2nd Edition / 9.3.3 & 9.5)
    */

    template <typename InputIterator>
    inline typename iterator_traits<InputIterator>::difference_type
    _distance( InputIterator first, InputIterator last, input_iterator_tag )
    {
        typename iterator_traits<InputIterator>::difference_type r( 0 );
        for ( ; first != last; ++first )
            ++r;
        return ( r );
    }

    template <typename RandomAccessIterator>
    inline typename iterator_traits<RandomAccessIterator>::difference_type
    _distance( RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag )
    {
        return ( last - first );
    }

    // also valid for forward and bidirectional iterator, since they inherit from input iterator
    template <typename InputIterator>
    inline typename iterator_traits<InputIterator>::difference_type
    distance( InputIterator first, InputIterator last )
    {
        return ( _distance( first, last, typename iterator_traits<InputIterator>::iterator_category() ) );
    }

    /* -------------------------- reverse_iterator -------------------------- */
    
    /*
    ** (https://cplusplus.com/reference/iterator/reverse_iterator/)
    ** This class reverses the direction in which a bidirectional or
    ** random-access iterator iterates through a range.
    */
    
    template <typename Iterator>
    class reverse_iterator
        : public iterator<typename iterator_traits<Iterator>::iterator_category,
                          typename iterator_traits<Iterator>::value_type,
                          typename iterator_traits<Iterator>::difference_type,
                          typename iterator_traits<Iterator>::pointer,
                          typename iterator_traits<Iterator>::reference>
    {
    public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::reference           reference;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
    
    protected:
        iterator_type current; // oder:
        // iterator_type current; ?????
    
    public:
        reverse_iterator(); // default constructor
        explicit reverse_iterator( iterator_type it ); // initialization constructor
        template<typename Iter>
            reverse_iterator( const reverse_iterator<Iter>& rev_it ); // copy constructor
        ~reverse_iterator(); // destructor // needed here? not in source code! Should be default destructor, if not specified here!

        template <typename Iter>
            reverse_iterator& operator=( const reverse_iterator<Iter>& src );
        Iterator base() const; // oder:
        // iterator_type base() const; ????? if yes, rewrite function definition below!
        reference operator*() const;
        pointer operator->() const;
        reverse_iterator& operator++();
        reverse_iterator  operator++(int);
        reverse_iterator& operator--();
        reverse_iterator  operator--(int);
        reverse_iterator operator+(difference_type n) const;
        reverse_iterator& operator+=(difference_type n);
        reverse_iterator operator-(difference_type n) const;
        reverse_iterator& operator-=(difference_type n);
        reference operator[] (difference_type n) const;
        
        
    }; // reverse_iterator
    
    /* reverse_iterator member functions */
    
    template <typename Iterator>
    reverse_iterator<Iterator>::reverse_iterator() : current() {}

    template <typename Iterator>
    reverse_iterator<Iterator>::reverse_iterator( iterator_type it ) : current( it ) {}
    
    template <typename Iterator>
    template<typename Iter>
    reverse_iterator<Iterator>::reverse_iterator( const reverse_iterator<Iter>& rev_it ) : current( rev_it.base() ) {}

    template <typename Iterator>
    reverse_iterator<Iterator>::~reverse_iterator() {}

    template <typename Iterator>
    template <typename Iter>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator=( const reverse_iterator<Iter>& src )
    {
        current = src.base();
        return ( *this );
    }

    template <typename Iterator>
    Iterator reverse_iterator<Iterator>::base() const
    {
        return ( this->current );
    }

    template <typename Iterator>
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const
    {
        Iterator    tmp = this->current;
        return ( *(--tmp) );
    }

    template <typename Iterator>
    typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const
    {
        return ( &( this->operator*() ) );
    }

    template <typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++()
    {
        --( this->current );
        return ( *this );
    }

    template <typename Iterator>
    reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator++( int )
    {
        reverse_iterator temp = *this;
        --( this->current );
        return ( temp );
    }

    template <typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--()
    {
        ++( this->current );
        return ( *this );
    }

    template <typename Iterator>
    reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator--( int )
    {
        reverse_iterator temp = *this;
        ++( this->current );
        return ( temp );
    }

    template <typename Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+( difference_type n ) const
    {
        return reverse_iterator( this->current - n );
    }

    template <typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=( difference_type n )
    {
        this->current -= n;
        return ( *this );
    }

    template <typename Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-( difference_type n ) const
    {
        return reverse_iterator( this->current + n );
    }

    template <typename Iterator>
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=( difference_type n )
    {
        this->current += n;
        return ( *this );
    }

    template <typename Iterator>
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const
    {
        return *( *this + n );
    }
    
    
    /* reverse_iterator non-member functions */

    template <typename Iterator1, typename Iterator2>
        bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() == rhs.base() );
        }

    template <typename Iterator1, typename Iterator2>
        bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() != rhs.base() );
        }

    template <typename Iterator1, typename Iterator2>
        bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() > rhs.base() );
        }

    template <typename Iterator1, typename Iterator2>
        bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() >= rhs.base() );
        }

    template <typename Iterator1, typename Iterator2>
        bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() < rhs.base() );
        }

    template <typename Iterator1, typename Iterator2>
        bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( rhs.base() <= lhs.base() );
        }

    template <typename Iterator>
        reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n,
                                                const reverse_iterator<Iterator>& rev_it ) // addition operator
        {
            return ( reverse_iterator<Iterator>( rev_it.base() - n ) );
        }

    template <typename Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,
                                                                        const reverse_iterator<Iterator>& rhs ) // subtraction operator
        {
            return ( rhs.base() - lhs.base() );
        }


    /* ----------------------- random_access_iterator ----------------------- */
    
    /*
    ** follow the general recipe for a user-defined iterator from (The C++ Standard Library - 2nd Edition / 9.6)
    ** and the info about random_access_iterators from (https://cplusplus.com/reference/iterator/RandomAccessIterator/)
    ** Random-access iterators are iterators that can be used to access elements at an arbitrary offset position
    ** relative to the element they point to, offering the same functionality as pointers.
    */
    
    template <typename T>
    class random_access_iterator
    {
    public:
        // Provide the necessary five type definitions for the general iterator_traits structure
        typedef T*                                                          iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type         value_type;
        typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
        typedef typename iterator_traits<iterator_type>::pointer            pointer;
        typedef typename iterator_traits<iterator_type>::reference          reference;

    private:
        iterator_type   _ptr;

    public:
        random_access_iterator();
        // random_access_iterator( pointer ptr = nullptr );
        random_access_iterator( const iterator_type& ptr );
        random_access_iterator( const random_access_iterator& other );
        ~random_access_iterator();
        
        random_access_iterator& operator=( const random_access_iterator& src );
        random_access_iterator& operator=( const pointer& src_ptr );

        iterator_type base() const;
        reference operator*() const;
        pointer operator->() const;
        random_access_iterator& operator++();
        random_access_iterator  operator++(int);
        random_access_iterator& operator--();
        random_access_iterator  operator--(int);
        random_access_iterator operator+(difference_type n) const;
        random_access_iterator& operator+=(difference_type n);
        random_access_iterator operator-(difference_type n) const;
        random_access_iterator& operator-=(difference_type n);
        reference operator[] (difference_type n) const;
        
    }; // random_access_iterator

    /* random_access_iterator member functions */
    
    template <typename T>
    random_access_iterator<T>::random_access_iterator() : _ptr() {}

    // template <typename T>
    // random_access_iterator<T>::random_access_iterator( pointer ptr ) : _ptr( ptr ) {}

    template <typename T>
    random_access_iterator<T>::random_access_iterator( const iterator_type& ptr ) : _ptr( ptr ) {}
    
    template <typename T>
    random_access_iterator<T>::random_access_iterator( const random_access_iterator<T>& other ) : _ptr( other.base() ) {}

    template <typename T>
    random_access_iterator<T>::~random_access_iterator() {}

    template <typename T>
    random_access_iterator<T>& random_access_iterator<T>::operator=( const random_access_iterator<T>& src )
    {
        _ptr = src.base();
        return ( *this );
    }

    template <typename T>
    random_access_iterator<T>& random_access_iterator<T>::operator=( const pointer& src_ptr )
    {
        _ptr = src_ptr;
        return ( *this );
    }

    template <typename T>
    typename random_access_iterator<T>::iterator_type random_access_iterator<T>::base() const
    {
        return ( this->_ptr );
    }

    template <typename T>
    typename random_access_iterator<T>::reference random_access_iterator<T>::operator*() const
    {
        return ( *(this->_ptr) );
    }

    template <typename T>
    typename random_access_iterator<T>::pointer random_access_iterator<T>::operator->() const
    {
        return ( this->_ptr );
    }

    template <typename T>
    random_access_iterator<T>& random_access_iterator<T>::operator++()
    {
        ++( this->_ptr );
        return ( *this );
    }

    template <typename T>
    random_access_iterator<T>  random_access_iterator<T>::operator++( int )
    {
        random_access_iterator  temp = *this;
        ++( this->_ptr );
        return ( temp );
    }

    template <typename T>
    random_access_iterator<T>& random_access_iterator<T>::operator--()
    {
        --( this->_ptr );
        return ( *this );
    }

    template <typename T>
    random_access_iterator<T>  random_access_iterator<T>::operator--( int )
    {
        random_access_iterator  temp = *this;
        --( this->_ptr );
        return ( temp );
    }

    template <typename T>
    random_access_iterator<T> random_access_iterator<T>::operator+( difference_type n ) const
    {
        return random_access_iterator( this->_ptr + n );
    }

    template <typename T>
    random_access_iterator<T>& random_access_iterator<T>::operator+=( difference_type n )
    {
        this->_ptr += n;
        return ( *this );
    }

    template <typename T>
    random_access_iterator<T> random_access_iterator<T>::operator-( difference_type n ) const
    {
        return random_access_iterator( this->_ptr - n );
    }

    template <typename T>
    random_access_iterator<T>& random_access_iterator<T>::operator-=( difference_type n )
    {
        this->_ptr -= n;
        return ( *this );
    }

    template <typename T>
    typename random_access_iterator<T>::reference random_access_iterator<T>::operator[]( difference_type n ) const
    {
        return *( *this->_ptr + n );
    }
    
    
    /* random_access_iterator non-member functions */

    template <typename T1, typename T2>
        bool operator==( const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs )
        {
            return ( lhs.base() == rhs.base() );
        }

    template <typename T1, typename T2>
        bool operator!=( const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs )
        {
            return ( lhs.base() != rhs.base() );
        }

    template <typename T1, typename T2>
        bool operator<( const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs )
        {
            return ( lhs.base() < rhs.base() );
        }

    template <typename T1, typename T2>
        bool operator<=( const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs )
        {
            return ( lhs.base() <= rhs.base() );
        }

    template <typename T1, typename T2>
        bool operator>( const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs )
        {
            return ( lhs.base() > rhs.base() );
        }

    template <typename T1, typename T2>
        bool operator>=( const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs )
        {
            return ( lhs.base() >= rhs.base() );
        }

    template <typename T>
        random_access_iterator<T> operator+( typename random_access_iterator<T>::difference_type n,
                                                const random_access_iterator<T>& rev_it ) // addition operator
        {
            return ( random_access_iterator<T>( rev_it.base() + n ) );
        }

    template <typename T>
        typename random_access_iterator<T>::difference_type operator-( const random_access_iterator<T>& lhs,
                                                                        const random_access_iterator<T>& rhs ) // subtraction operator
        {
            return ( lhs.base() - rhs.base() );
        }

} // namespace ft
