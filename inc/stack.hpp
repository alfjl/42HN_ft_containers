/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:19:06 by alanghan          #+#    #+#             */
/*   Updated: 2022/07/19 17:00:13 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./vector.hpp"

namespace ft
{

    /* -------------------------------- stack -------------------------------- */
    
    /*
    ** (https://cplusplus.com/reference/stack/stack/)
    ** Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
    ** where elements are inserted and extracted only from one end of the container.
    ** Stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class
    ** as its underlying container, providing a specific set of member functions to access its elements.
    ** Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.
    ** 
    ** The underlying container may be any of the standard container class templates or some other specifically designed container class.
    ** The container shall support the following operations:
    **     empty
    **     size
    **     back
    **     push_back
    **     pop_back
    ** 
    ** The standard container classes vector, deque and list fulfill these requirements. By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.
    */

    template <typename T, typename Container = ft::vector<T> >
    class stack
    {

    public:
        typedef Container                                   container_type;
        typedef typename container_type::value_type         value_type;
        typedef typename container_type::size_type          size_type;

    protected:
        container_type  c;
    
    public:
        // Constructor / Destructor / Assignment
        explicit stack ( const container_type& ctnr = container_type() );
        ~stack();

        stack& operator=( const stack& other );

        // Capacity:
        bool empty() const;
        size_type size() const;

        // Element access:
        value_type& top();
        const value_type& top() const;

        // Modifiers:
        void push ( const value_type& val );
        void pop();

        // Friends for non-member overloads used in all relational operators
        template<typename T1, typename Container1>
            friend bool operator==( const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs );
        template<typename T1, typename Container1>
            friend bool operator<( const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs );

    }; // stack

    /* stack member functions */

    template <typename T, typename Container>
    stack<T, Container>::stack( const container_type& ctnr ) : c( ctnr ) {}

    template <typename T, typename Container>
    stack<T, Container>::~stack() {}

    template <typename T, typename Container>
    stack<T, Container>& stack<T, Container>::operator=( const stack& other )
    {
        c = other.c;
        return ( *this );
    }

    template <typename T, typename Container>
    bool stack<T, Container>::empty() const
    {
        return ( this->c.empty() );
    }

    template <typename T, typename Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return ( this->c.size() );
    }

    template <typename T, typename Container>
    typename stack<T, Container>::value_type& stack<T, Container>::top()
    {
        return ( this->c.back() );
    }

    template <typename T, typename Container>
    const typename stack<T, Container>::value_type& stack<T, Container>::top() const
    {
        return ( this->c.back() );
    }

    template <typename T, typename Container>
    void stack<T, Container>::push ( const value_type& val )
    {
        this->c.push_back( val );
    }

    template <typename T, typename Container>
    void stack<T, Container>::pop()
    {
        this->c.pop_back();
    }

    /* stack non-member functions */

    template <class T, class Container>
        bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
        {
            return ( lhs.c == rhs.c );
        }

    template <class T, class Container>
        bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return ( !( lhs == rhs ) );
        }

    template <class T, class Container>
        bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (  lhs.c < rhs.c );
        }

    template <class T, class Container>
        bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return ( !(  rhs < lhs ) );
        }

    template <class T, class Container>
        bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return ( rhs < lhs );
        }

    template <class T, class Container>
        bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return ( !( lhs < rhs ) );
        }

} // namespace ft