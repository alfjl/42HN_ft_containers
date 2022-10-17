#pragma once

namespace ft
{

    /* --------------------------- binary_function -------------------------- */

    /*
    ** (https://cplusplus.com/reference/functional/binary_function/)
    ** Note: This class has been deprecated in C++11.
    ** This is a base class for standard binary function objects.
    ** Generically, function objects are instances of a class with member function operator() defined.
    ** This member function allows the object to be used with the same syntax as a regular function call,
    ** and therefore its type can be used as template parameter when a generic function type is expected.
    ** binary_function is just a base class, from which specific binary function objects are derived.
    ** It has no operator() member defined (which derived classes are expected to define).
    */

    template <typename Arg1, typename Arg2, typename Result>
    struct binary_function
    {
        typedef Arg1        first_argument_type;
        typedef Arg2        second_argument_type;
        typedef Result      result_type;
    }; // binary_function


    /* -------------------------------- less -------------------------------- */

    /*
    ** (https://cplusplus.com/reference/functional/less/)
    ** Function object class for less-than inequality comparison:
    ** Binary function object class whose call returns whether its first argument
    ** compares less than the second (as returned by operator <).
    */

    template <class T>
    struct less : ft::binary_function<T,T,bool>
    {
    public:
        bool operator() ( const T& x, const T& y ) const;
    }; // less

    template <class T>
    bool less<T>::operator() ( const T& x, const T& y ) const
    {
        return ( x < y );
    }

} // namespace ft
