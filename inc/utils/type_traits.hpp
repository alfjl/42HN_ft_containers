/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:33:29 by alanghan          #+#    #+#             */
/*   Updated: 2022/10/18 10:36:27 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

namespace   ft
{

    /* ------------------------- enable_if / SFINAE ------------------------- */
    
    template <bool Cond, typename T = void>
    struct enable_if
    {};

    template<typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };


    /* ------------------- integral_constant / is_integral ------------------ */

    template <typename T, T v>
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

    template <typename T>
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

    // template <>
    // struct is_integral<long long>           : public true_type {}; // = C++11 Extension

    template <>
    struct is_integral<unsigned char>       : public true_type {};

    template <>
    struct is_integral<unsigned short>      : public true_type {};

    template <>
    struct is_integral<unsigned int>        : public true_type {};

    template <>
    struct is_integral<unsigned long>       : public true_type {};

    // template <>
    // struct is_integral<unsigned long long>  : public true_type {}; // = C++11 Extension



    // const

    template <>
    struct is_integral<const bool>                : public true_type {};

    template <>
    struct is_integral<const char>                : public true_type {};

    template <>
    struct is_integral<const char16_t>            : public true_type {};

    template <>
    struct is_integral<const char32_t>            : public true_type {};

    template <>
    struct is_integral<const wchar_t>             : public true_type {};

    template <>
    struct is_integral<const signed char>         : public true_type {};
 
    template <>
    struct is_integral<const short>               : public true_type {};

    template <>
    struct is_integral<const int>                 : public true_type {};

    template <>
    struct is_integral<const long>                : public true_type {};

    // template <>
    // struct is_integral<const long long>           : public true_type {}; // = C++11 Extension

    template <>
    struct is_integral<const unsigned char>       : public true_type {};

    template <>
    struct is_integral<const unsigned short>      : public true_type {};

    template <>
    struct is_integral<const unsigned int>        : public true_type {};

    template <>
    struct is_integral<const unsigned long>       : public true_type {};

    // template <>
    // struct is_integral<const unsigned long long>  : public true_type {}; // = C++11 Extension


    // volatile

    template <>
    struct is_integral<volatile bool>                : public true_type {};

    template <>
    struct is_integral<volatile char>                : public true_type {};

    template <>
    struct is_integral<volatile char16_t>            : public true_type {};

    template <>
    struct is_integral<volatile char32_t>            : public true_type {};

    template <>
    struct is_integral<volatile wchar_t>             : public true_type {};

    template <>
    struct is_integral<volatile signed char>         : public true_type {};
 
    template <>
    struct is_integral<volatile short>               : public true_type {};

    template <>
    struct is_integral<volatile int>                 : public true_type {};

    template <>
    struct is_integral<volatile long>                : public true_type {};

    // template <>
    // struct is_integral<volatile long long>           : public true_type {}; // = C++11 Extension

    template <>
    struct is_integral<volatile unsigned char>       : public true_type {};

    template <>
    struct is_integral<volatile unsigned short>      : public true_type {};

    template <>
    struct is_integral<volatile unsigned int>        : public true_type {};

    template <>
    struct is_integral<volatile unsigned long>       : public true_type {};

    // template <>
    // struct is_integral<volatile unsigned long long>  : public true_type {}; // = C++11 Extension


    // const volatile

    template <>
    struct is_integral<const volatile bool>                : public true_type {};

    template <>
    struct is_integral<const volatile char>                : public true_type {};

    template <>
    struct is_integral<const volatile char16_t>            : public true_type {};

    template <>
    struct is_integral<const volatile char32_t>            : public true_type {};

    template <>
    struct is_integral<const volatile wchar_t>             : public true_type {};

    template <>
    struct is_integral<const volatile signed char>         : public true_type {};
 
    template <>
    struct is_integral<const volatile short>               : public true_type {};

    template <>
    struct is_integral<const volatile int>                 : public true_type {};

    template <>
    struct is_integral<const volatile long>                : public true_type {};

    // template <>
    // struct is_integral<const volatile long long>           : public true_type {}; // = C++11 Extension

    template <>
    struct is_integral<const volatile unsigned char>       : public true_type {};

    template <>
    struct is_integral<const volatile unsigned short>      : public true_type {};

    template <>
    struct is_integral<const volatile unsigned int>        : public true_type {};

    template <>
    struct is_integral<const volatile unsigned long>       : public true_type {};

    // template <>
    // struct is_integral<const volatile unsigned long long>  : public true_type {}; // = C++11 Extension

} // namespace  ft
