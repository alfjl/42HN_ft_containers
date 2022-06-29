/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:23:05 by alanghan          #+#    #+#             */
/*   Updated: 2022/06/29 17:17:26 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    template < typename T, typename Alloc = allocator<T> >
    class vector
    {

        typedef T												value_type;
        typedef Alloc											allocator_type;
        typedef typename allocator_type::reference				reference;
        typedef typename allocator_type::const_reference		const_reference;
        typedef typename allocator_type::pointer				pointer;
        typedef typename allocator_type::const_pointer			const_pointer;
        // typedef iterator_traits<iterator>::difference_type	difference_type; // or:
        typedef std::ptrdiff_t									difference_type; // std::ptrdiff_t
        typedef std::size_t										size_type;
        typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
        typedef ft::reverse_iterator<iterator>					reverse_iterator;
	    typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
        
        

    }; // vector

} // namespace ft
