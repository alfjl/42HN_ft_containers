#ifndef PAIR_HPP
#define PAIR_HPP

namespace   ft
{

    template <class T1, class T2>
    struct pair
    {
    public:
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  first;
        second_type second;

        pair(); // default constructor
        template<class U, class V>
            pair ( const pair<U,V>& pr ); // copy constructor
        pair ( const first_type& a, const second_type& b ); // initialization constructor

        pair& operator=( const pair& pr );
    }; // pair

    template <class T1, class T2>
    pair<T1, T2>::pair() : first(), second() {}

    template <class T1, class T2>
    template<class U, class V>
    pair<T1, T2>::pair ( const pair<U,V>& pr ) : first( pr.first ), second( pr.second ) {}

    template <class T1, class T2>
    pair<T1, T2>::pair ( const first_type& a, const second_type& b ) : first( a ), second( b ) {}

    template <class T1, class T2>
    pair<T1, T2>    &pair<T1, T2>::operator= ( const pair& pr )
    {
        if ( this != &ptr )
        {
            this->first = pr.first;
            this->second = pr.second;
        }
        return ( *this );
    } // assignation constructor

    template <class T1, class T2>
        bool operator== ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
        {
            return ( lhs.first == rhs.first && lhs.second == rhs.second );
        }
    
    template <class T1, class T2>
        bool operator!= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
        {
            return ( !( lhs == rhs ) );
        }

    template <class T1, class T2>
        bool operator<  ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
        {
             return ( lhs.first < rhs.first || ( !( rhs.first < lhs.first ) && lhs.second < rhs.second ) ); 
        }

    template <class T1, class T2>
        bool operator<= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs  )
        {
            return ( !( rhs < lhs ) );
        }

    template <class T1, class T2>
        bool operator>  ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
        {
            return ( rhs < lhs );
        }

    template <class T1, class T2>
        bool operator>= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
        {
            return ( !( lhs < rhs ) );
        }

    template <class T1, class T2>
        ft::pair<T1,T2> make_pair( T1 x, T2 y )
        {
            return ( ft::pair<T1, T2>( x, y ) );
        }
} // namespace ft

#endif // PAIR_HPP