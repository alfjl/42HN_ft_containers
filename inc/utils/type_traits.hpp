/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:33:29 by alanghan          #+#    #+#             */
/*   Updated: 2022/06/20 15:41:46 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

    // enable_if / SFINAE
    
    template <bool Cond, class T = void>
    struct enable_if
    {};

    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };


    // is_integral / integral_constant

    template <class T, T v>
    struct integral_constant
    {
        typedef T                       value_type;
        typedef integral_constant<T, v> type;

        static const value_type         value = v;

        operator value_type() const
        {
            return v;
        }
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    template <class T>
    struct is_integral                      : public false_type {};

    template <>
    struct is_integral<bool>                : public true_type {};

    template <>
    struct is_integral<char>                : public true_type {};

    template <>
    struct is_integral<char16_t>            : public true_type {};

    template <>
    struct is_integral<char32_t>            : public true_type {};

    template <>
    struct is_integral<wchar_t>             : public true_type {};

    template <>
    struct is_integral<signed char>         : public true_type {};
 
    template <>
    struct is_integral<short>               : public true_type {};

    template <>
    struct is_integral<int>                 : public true_type {};

    template <>
    struct is_integral<long>                : public true_type {};

    template <>
    struct is_integral<long long>           : public true_type {};

    template <>
    struct is_integral<unsigned char>       : public true_type {};

    template <>
    struct is_integral<unsigned short>      : public true_type {};

    template <>
    struct is_integral<unsigned int>        : public true_type {};

    template <>
    struct is_integral<unsigned long>       : public true_type {};

    template <>
    struct is_integral<unsigned long long>  : public true_type {};

} // namespace ft