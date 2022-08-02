/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:21:45 by alanghan          #+#    #+#             */
/*   Updated: 2022/08/02 11:12:27 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace   ft
{

    /* -------------------------------- equal -------------------------------- */

    /*
    ** (https://cplusplus.com/reference/algorithm/equal/?kw=equal)
    ** Compares the elements in the range [first1,last1) with those in the range beginning at first2,
    ** and returns true if all of the elements in both ranges match.
    */

    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) // equality
    {
        while ( first1 != last1 )
        {
            if ( !( *first1 == *first2 ) )
                return ( false );
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) // predicate
    {
        while ( first1 != last1 )
        {
            if ( !pred( *first1, *first2 ) )
                return ( false );
            ++first1;
            ++first2;
        }
        return true;
    }


    /* ------------------------ lexicographical_compare ---------------------- */

    /*
    ** (https://cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare)
    ** Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
    ** It involves comparing sequentially the elements that have the same position in both ranges against each other
    ** until one element is not equivalent to the other.
    */

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2) // default
    {
        while ( first1 != last1 )
        {
            if ( first2 == last2 || *first2 < *first1 )
                return ( false );
            else if ( *first1 < *first2 )
                return ( true );
            ++first1;
            ++first2;
        }
        return ( first2 != last2 );
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2, Compare comp) // custom
    {
        while ( first1 != last1 )
        {
            if ( first2 == last2 || comp( *first1, *first2 ) )
                return ( true );
            else if ( comp( *first2, *first1 ) )
                return ( false );
            ++first1;
            ++first2;
        }
        return ( false );
    }


    /* --------------------------------- copy -------------------------------- */

    /*
    ** (https://cplusplus.com/reference/algorithm/copy/)
    ** Copies the elements in the range [first,last) into the range beginning at result.
    ** The function returns an iterator to the end of the destination range
    ** (which points to the element following the last element copied).
    ** The ranges shall not overlap in such a way that result points to an element in the range [first,last).
    ** For such cases, see [std::]copy_backward.
    */

    template<class InputIterator, class OutputIterator>
    OutputIterator copy( InputIterator first, InputIterator last, OutputIterator result )
    {
        while ( first != last )
        {
            *result = *first;
            ++result; ++first;
        }
        return result;
    }

} // namespace  ft
