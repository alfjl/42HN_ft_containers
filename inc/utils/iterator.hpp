/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:21:31 by alanghan          #+#    #+#             */
/*   Updated: 2022/06/30 12:13:22 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft
{

    /* make own iterator_tag structs and use them later in the iterator typedef and iterator_traits instead of std::..._iterator_tag?

    // struct input_iterator_tag  {};
    // struct output_iterator_tag {};
    // struct forward_iterator_tag       : public input_iterator_tag         {};
    // struct bidirectional_iterator_tag : public forward_iterator_tag       {};
    // struct random_access_iterator_tag : public bidirectional_iterator_tag {};*/

    typedef std::output_iterator_tag		output_iterator_tag;
    typedef std::input_iterator_tag			input_iterator_tag ;
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
        Iterator current;
    
    public:
        reverse_iterator(); // default constructor
        explicit reverse_iterator( iterator_type it ); // initialization constructor
        template<typename Iter>
            reverse_iterator( const reverse_iterator<Iter>& rev_it ); // copy constructor

        template <typename Iter>
            reverse_iterator& operator=( const reverse_iterator<Iter>& src );
        Iterator base() const;
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

    template< typename Iterator1, typename Iterator2 >
        bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() == rhs.base() );
        }

    template< typename Iterator1, typename Iterator2 >
        bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() != rhs.base() );
        }

    template< typename Iterator1, typename Iterator2 >
        bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() > rhs.base() );
        }

    template< typename Iterator1, typename Iterator2 >
        bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() >= rhs.base() );
        }

    template< typename Iterator1, typename Iterator2 >
        bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
        {
            return ( lhs.base() < rhs.base() );
        }

    template< typename Iterator1, typename Iterator2 >
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

} // namespace ft