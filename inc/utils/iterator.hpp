/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:21:31 by alanghan          #+#    #+#             */
/*   Updated: 2022/06/23 15:21:32 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft
{

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

} // namespace f