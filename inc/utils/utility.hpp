/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:33:21 by alanghan          #+#    #+#             */
/*   Updated: 2022/07/19 11:07:51 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace   ft
{

    /* -------------------------------- pair -------------------------------- */
    
    /*
    ** (https://cplusplus.com/reference/utility/pair/)
    ** Pair of values
    ** This class couples together a pair of values, which may be of different types (T1 and T2).
    ** The individual values can be accessed through its public members first and second.
    ** Pairs are a particular case of tuple.
    */
    
    template <typename T1, typename T2>
    struct pair
    {
    public:
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  first;
        second_type second;

        pair(); // default constructor
        template<typename U, typename V>
            pair ( const pair<U, V>& pr ); // copy constructor
        pair ( const first_type& a, const second_type& b ); // initialization constructor

        pair& operator=( const pair& pr );
    }; // pair

    template <typename T1, typename T2>
    pair<T1, T2>::pair() : first(), second() {}

    template <typename T1, typename T2>
    template<typename U, typename V>
    pair<T1, T2>::pair ( const pair<U, V>& pr ) : first( pr.first ), second( pr.second ) {}

    template <typename T1, typename T2>
    pair<T1, T2>::pair ( const first_type& a, const second_type& b ) : first( a ), second( b ) {}

    template <typename T1, typename T2>
    pair<T1, T2>    &pair<T1, T2>::operator= ( const pair& pr )
    {
        if ( this != &pr )
        {
            this->first = pr.first;
            this->second = pr.second;
        }
        return ( *this );
    } // assignation constructor

    template <typename T1, typename T2>
    bool operator== ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
    {
        return ( lhs.first == rhs.first && lhs.second == rhs.second );
    }
    
    template <typename T1, typename T2>
    bool operator!= ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
    {
        return ( !( lhs == rhs ) );
    }

    template <typename T1, typename T2>
    bool operator<  ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
    {
        return ( lhs.first < rhs.first || ( !( rhs.first < lhs.first ) && lhs.second < rhs.second ) ); 
    }

    template <typename T1, typename T2>
    bool operator<= ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs  )
    {
        return ( !( rhs < lhs ) );
    }

    template <typename T1, typename T2>
    bool operator>  ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
    {
        return ( rhs < lhs );
    }

    template <typename T1, typename T2>
    bool operator>= ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
    {
        return ( !( lhs < rhs ) );
    }

    template <typename T1, typename T2>
    ft::pair<T1,T2> make_pair( T1 x, T2 y )
    {
        return ( ft::pair<T1, T2>( x, y ) );
    }


    /* -------------------------------- swap -------------------------------- */
    
    /*
    ** (https://cplusplus.com/reference/algorithm/swap/)
    ** Exchanges the values of a and b.
    */

    template <typename T>
    void swap ( T& a, T& b )
    {
        T temp( a );

        a = b;
        b = temp;
    }

} // namespace ft
