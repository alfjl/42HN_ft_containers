/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testkram.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:15:43 by alanghan          #+#    #+#             */
/*   Updated: 2022/07/12 18:03:04 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* ################################ FT::PAIR ################################ */


// // check to see if assignation operator of std::pair deletes potential old ptr in pair.second, or not
// int main(void)
// {
//     int *one = new int(1);
//     int *two = new int(2);
//     int *three = new int(3);
//     std::pair<char, int *>  paerle;
//     std::pair<char, int *>  paerle2;

//     paerle = std::make_pair('a', one);
//     paerle2 = std::make_pair('b', two);
//     std::cout << *(paerle.second) << std::endl;

//     paerle = paerle2;
//     // paerle.second = two;
//     std::cout << *(paerle.second) << std::endl;
//     std::cout << *one << std::endl;

//     paerle = std::make_pair('c', three);
//     std::cout << *(paerle.second) << std::endl;
// }
// // ===> RESULT: No! Just assigns new values, but doesn't delete anything.


/* -------------------------------------------------------------------------- */

// /* test FT::PAIR implementation */
// // CONSTRUCTORS
// #include <string>       // std::string
// #include <iostream>     // std::cout

// #include "inc/utils/utility.hpp"      // ft::pair, ft::make_pair

// int main () {
//   ft::pair <std::string,double> product1;                     // default constructor
//   ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
//   ft::pair <std::string,double> product3 (product2);          // copy constructor

//   product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

//   product2.first = "shoes";                  // the type of first is string
//   product2.second = 39.90;                   // the type of second is double

//   std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
//   std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
//   std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
//   return 0;
// }

// // Output: ***********************
// // The price of lightbulbs is $0.99
// // The price of shoes is $39.9
// // The price of tomatoes is $2.3

/* ---------------------------------------------------------------------------------- */
// // pair::operator= example
// #include <string>       // std::string
// #include <iostream>     // std::cout

// #include "inc/utils/utility.hpp"      // ft::pair, ft::make_pair

// int main () {
//   ft::pair <std::string,int> planet, homeplanet;

//   planet = ft::make_pair("Earth",6371);

//   homeplanet = planet;

//   std::cout << "Home planet: " << homeplanet.first << '\n';
//   std::cout << "Planet size: " << homeplanet.second << '\n';
//   return 0;
// }

// // Output: ***********************
// // Home planet: Earth
// // Planet size: 6371

/* -------------------------------------------------------------------------- */

// // // pair relational operators
// #include <iostream>     // std::cout

// #include "inc/utils/utility.hpp"      // ft::pair, ft::make_pair

// int main ()
// {
//   ft::pair<int,char> foo (10,'z');
//   ft::pair<int,char> bar (90,'a');

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }

// // Output: ***********************
// // foo and bar are not equal
// // foo is less than bar
// // foo is less than or equal to bar

/* -------------------------------------------------------------------------- */

// // make_pair example
// #include <iostream>     // std::cout

// #include "inc/utils/utility.hpp"      // ft::pair, ft::make_pair

// int main () {
//   ft::pair <int,int> foo;
//   ft::pair <int,int> bar;

//   foo = ft::make_pair (10,20);
//   bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

//   std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
//   std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

//   return 0;
// }

// // Output: ***********************
// // foo: 10, 20
// // bar: 10, 65



/* ################################## TYPE_TRAITS ################################## */


// // check SFINAE
// template <class T>
// struct is_pointer
// {
//   template <class U>
//   static char is_ptr(U *);

//   template <class X, class Y>
//   static char is_ptr(Y X::*);

//   template <class U>
//   static char is_ptr(U (*)());

//   static double is_ptr(...);

//   static T t;
//   enum { value = sizeof(is_ptr(t)) == sizeof(char) };
// };

// struct Foo {
//   int bar;
// };

// int main(void)
// {
//   typedef int * IntPtr;
//   typedef int Foo::* FooMemberPtr;
//   typedef int (*FuncPtr)();
//   typedef int one;
//   typedef char  *two;

//   char a = 'a';
//   two two_two = &a;

//   printf("%c, %c\n", a, *two_two);              // prints a, a
//   printf("%d\n",is_pointer<IntPtr>::value);        // prints 1
//   printf("%d\n",is_pointer<FooMemberPtr>::value);  // prints 1
//   printf("%d\n",is_pointer<FuncPtr>::value);       // prints 1
//   printf("%d\n",is_pointer<one>::value);       // prints 0
//   printf("%d\n",is_pointer<two>::value);       // prints 1
// }

// // Output: ***********************
// // a, a
// // 1
// // 1
// // 1
// // 0
// // 1

/* -------------------------------------------------------------------------- */

// // is_integral example
// #include <iostream>

// #include "inc/utils/type_traits.hpp"

// int main()
// {
//   std::cout << std::boolalpha;
//   std::cout << "is_integral:" << std::endl;
//   std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//   std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//   std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//   std::cout << "double: " << ft::is_integral<double>::value << std::endl;
//   return 0;
// }

// // Output: ***********************
// // is_integral:
// // char: true
// // int: true
// // float: false
// // double: false

/* -------------------------------------------------------------------------- */

// // enable_if example: two ways of using enable_if
// #include <iostream>

// #include "inc/utils/type_traits.hpp"

// // 1. the return type (bool) is only valid if T is an integral type:
// template <class T>
// typename ft::enable_if<ft::is_integral<T>::value,bool>::type
//   is_odd (T i) {return bool(i%2);}

// // 2. the second template argument is only valid if T is an integral type:
// template < class T,
//            class = typename ft::enable_if<ft::is_integral<T>::value>::type> // some C++11 magic!
// bool is_even (T i) {return !bool(i%2);}

// int main() {

//   short int i = 1;    // code does not compile if type of i is not integral

//   std::cout << std::boolalpha;
//   std::cout << "i is odd: " << is_odd(i) << std::endl;
//   std::cout << "i is even: " << is_even(i) << std::endl;

//   return 0;
// }

// // Output: ***********************
// // i is odd: true
// // i is even: false




/* ################################## ALGORITHMS ################################## */


// equal algorithm example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/algorithm.hpp"    // ft::equal

// bool mypredicate (int i, int j) {
//   return (i==j);
// }

// int main () {
//   int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
//   std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

//   // using default comparison:
//   if ( ft::equal (myvector.begin(), myvector.end(), myints) )
//     std::cout << "The contents of both sequences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

//                                                    //   myints: 20 40 60 80 100
//   myvector[3]=81;                                 // myvector: 20 40 60 81 100

//   // using predicate comparison:
//   if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
//     std::cout << "The contents of both sequences are equal.\n";
//   else
//     std::cout << "The contents of both sequences differ.\n";

//   return 0;
// }

// // Output: ***********************
// // The contents of both sequences are equal.
// // The contents of both sequence differ.


/* -------------------------------------------------------------------------- */
// // lexicographical_compare example
// #include <iostream>     // std::cout, std::boolalpha
// #include <cctype>       // std::tolower

// #include "inc/algorithm.hpp"    // ft::equal

// // a case-insensitive comparison function:
// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }

// int main () {
//   char foo[]="Apple";
//   char bar[]="apartment";

//   std::cout << std::boolalpha;

//   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

//   std::cout << "Using default comparison (operator<): ";
//   std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
//   std::cout << '\n';

//   std::cout << "Using mycomp as comparison object: ";
//   std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // Comparing foo and bar lexicographically (foo<bar):
// // Using default comparison (operator<): true
// // Using mycomp as comparison object: false




/* ################################ FT::ITERATOR_TRAITS ################################ */


// // iterator_traits example
// #include <iostream>     // std::cout
// #include <typeinfo>     // typeid

// #include "inc/utils/iterator.hpp"
// int main() {
//   typedef ft::iterator_traits<int*> traits;
//   if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
//     std::cout << "int* is a random-access iterator" << std::endl;
//   return 0;
// }

// // Output: ***********************
// // int* is a random-access iterator



/* ################################ FT::REVERSE_ITERATOR ############################### */  //STILL TESTING NEEDED!!!!!!


// // reverse_iterator example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;
//                                                          // ? 0 1 2 3 4 5 6 7 8 9 ?
//   iter_type from (myvector.begin());                     //   ^
//                                                          //         ------>
//   iter_type until (myvector.end());                      //                       ^
//                                                          //
//   ft::reverse_iterator<iter_type> rev_until (from);      // ^
//                                                          //         <------
//   ft::reverse_iterator<iter_type> rev_from (until);      //                     ^

//   std::cout << "myvector:";
//   while (rev_from != rev_until)
//     std::cout << ' ' << *rev_from++;
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector: 9 8 7 6 5 4 3 2 1 0

/* ------------------------------------------------------------------------- */

// // reverse_iterator::base example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"


// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_end (myvector.begin());
//   ft::reverse_iterator<iter_type> rev_begin (myvector.end());

//   std::cout << "myvector:";
//   for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector: 0 1 2 3 4 5 6 7 8 9

/* -------------------------------------------------------------------------- */

// // reverse_iterator::operator+ example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_it;

//   rev_it = myvector.rbegin() +3;

//   std::cout << "The fourth element from the end is: " << *rev_it << '\n';

//   return 0;
// }

// // // Output: *********************** ERROR: testkram.cpp:408:10: error: no viable overloaded '='
// // The fourth element from the end is: 6

/* -------------------------------------------------------------------------- */

// // reverse_iterator::operator+= example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

//   rev_iterator += 2;

//   std::cout << "The third element from the end is: " << *rev_iterator << '\n';

//   return 0;
// }

// // Output: *********************** ERROR: testkram.cpp:432:35: error: no viable conversion from 'std::__1::vector<int, std::__1::allocator<int> >::reverse_iterator' (aka 'reverse_iterator<__wrap_iter<int *> >') to 'ft::reverse_iterator<iter_type>' (aka 'reverse_iterator<__wrap_iter<int *> >')
// // The third element from the end is: 7

/* -------------------------------------------------------------------------- */

// // reverse_iterator::operator- example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator;

//   rev_iterator = myvector.rend() - 3;

//   std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';

//   return 0;
// }

// // Output: *********************** ERROR: testkram.cpp:460:16: error: no viable overloaded '='
// // myvector.rend()-3 points to: 2

/* -------------------------------------------------------------------------- */

// // reverse_iterator::operator-- example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_begin (myvector.end());
//   ft::reverse_iterator<iter_type> rev_end (myvector.begin());

//   ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
//   while ( rev_iterator != rev_end )
//     std::cout << *rev_iterator++ << ' ';
//   std::cout << '\n';

//   while ( rev_iterator != rev_begin )
//     std::cout << *(--rev_iterator) << ' ';
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // 9 8 7 6 5 4 3 2 1 0
// // 0 1 2 3 4 5 6 7 8 9

/* ------------------------------------------------------------------------- */

// // reverse_iterator::operator-= example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rend();

//   rev_iterator -= 4;

//   std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';

//   return 0;
// }

// // Output: *********************** ERROR: testkram.cpp:517:35: error: no viable conversion from 'std::__1::vector<int, std::__1::allocator<int> >::reverse_iterator' (aka 'reverse_iterator<__wrap_iter<int *> >') to 'ft::reverse_iterator<iter_type>' (aka 'reverse_iterator<__wrap_iter<int *> >')
// // rev_iterator now points to: 3

/* -------------------------------------------------------------------------- */

// // reverse_iterator::operator-> example
// #include <iostream>     // std::cout
// #include <map>          // std::map
// #include <string>       // std::string

// #include "inc/utils/iterator.hpp"
// #include "inc/utils/utility.hpp"      // std::make_pair

// int main () {
//   std::map<int,std::string> numbers;
//   numbers.insert (ft::make_pair(1,"one"));
//   numbers.insert (ft::make_pair(2,"two"));
//   numbers.insert (ft::make_pair(3,"three"));

//   typedef std::map<int,std::string>::iterator map_iter;

//   ft::reverse_iterator<map_iter> rev_end (numbers.begin());

//   ft::reverse_iterator<map_iter> rev_iterator (numbers.end());

//   for ( ; rev_iterator != rev_end ; ++rev_iterator )
//     std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';

//   return 0;
// }

// // Output: *********************** ERROR: testkram.cpp:541:11: error: no matching member function for call to 'insert'
// // 3 three
// // 2 two
// // 1 one

/* -------------------------------------------------------------------------- */

// // reverse_iterator::operator[] example
// #include <iostream>     // std::cout
// #include <vector>       // std::vector

// #include "inc/utils/iterator.hpp"

// int main () {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

//   std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';

//   return 0;
// }

// // Output: *********************** ERROR: testkram.cpp:576:35: error: no viable conversion from 'std::__1::vector<int, std::__1::allocator<int> >::reverse_iterator' (aka 'reverse_iterator<__wrap_iter<int *> >') to 'ft::reverse_iterator<iter_type>' (aka 'reverse_iterator<__wrap_iter<int *> >')
// // The fourth element from the end is: 6

/* -------------------------------------------------------------------------- */

// // reverse_iterator example (https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_cmp)
// #include <compare>
// #include <iostream>

// #include "inc/utils/iterator.hpp"

// int main()
// {
//     int a[] = {0, 1, 2, 3};
//     //             ↑  └───── x, y
//     //             └──────── z
 
//     ft::reverse_iterator<int*>
//         // x { std::rend(a) - std::size(a) },
//         // y { std::rend(a) - std::size(a) },
//         // z { std::rbegin(a) + 1 };
//         x = std::rend(a) - std::size(a) ,
//         y = std::rend(a) - std::size(a) ,
//         z = std::rbegin(a) + 1 ;
 
//     std::cout
//         << std::boolalpha
//         << "*x == " << *x << '\n' // 3
//         << "*y == " << *y << '\n' // 3
//         << "*z == " << *z << '\n' // 2
//         << "x == y ? " << (x == y) << '\n' // true
//         << "x != y ? " << (x != y) << '\n' // false
//         << "x <  y ? " << (x <  y) << '\n' // false
//         << "x <= y ? " << (x <= y) << '\n' // true
//         << "x == z ? " << (x == z) << '\n' // false
//         << "x != z ? " << (x != z) << '\n' // true
//         << "x <  z ? " << (x <  z) << '\n' // true!
//         << "x <= z ? " << (x <= z) << '\n' // true
//         // << "x <=> y == 0 ? " << (x <=> y == 0) << '\n' // true
//         // << "x <=> y <  0 ? " << (x <=> y <  0) << '\n' // false
//         // << "x <=> y >  0 ? " << (x <=> y >  0) << '\n' // false
//         // << "x <=> z == 0 ? " << (x <=> z == 0) << '\n' // false
//         // << "x <=> z <  0 ? " << (x <=> z <  0) << '\n' // true
//         // << "x <=> z >  0 ? " << (x <=> z >  0) << '\n' // false
//         ;
// }

// // Output: *********************** ERROR: testkram.cpp:605:18: error: no member named 'rend'/'size'/'rbegin' in namespace 'std'
// // see code above

/* ------------------------------------------------------------------------- */

// // iter/reviter4.cpp (The C++ Standard Library - 2nd Edition)
// // #include <iterator>
// #include "inc/utils/iterator.hpp"
// #include <iostream>
// #include <list>
// #include <algorithm>
// using namespace std;
// int main()
// {
// // create list with elements from 1 to 9
// // list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // error: non-aggregate type 'list<int>' cannot be initialized with an initializer list
// list<int> coll;
// coll.push_back(1);
// coll.push_back(2);
// coll.push_back(3);
// coll.push_back(4);
// coll.push_back(5);
// coll.push_back(6);
// coll.push_back(7);
// coll.push_back(8);
// coll.push_back(9);
// // find position of element with value 5
// list<int>::const_iterator pos;
// pos = find (coll.cbegin(), coll.cend(), // range
// 5); // value
// // print value of the element
// cout << "pos: " << *pos << endl;
// // convert iterator to reverse iterator
// list<int>::const_reverse_iterator rpos(pos);
// // print value of the element to which the reverse iterator refers
// cout << "rpos: " << *rpos << endl;
// // convert reverse iterator back to normal iterator
// list<int>::const_iterator rrpos;
// rrpos = rpos.base();
// // print value of the element to which the normal iterator refers
// cout << "rrpos: " << *rrpos << endl;
// }

// // Output: ***********************
// // pos: 5
// // rpos: 4
// // rrpos: 5



/* ################################ FT::STACK ############################### */  //STILL TESTING with ft::vector NEEDED!!!!!!
/* ################################## WITH STD::DEQUE ####################### */  //STILL TESTING with ft::vector NEEDED!!!!!!


// // constructing stacks
// #include <iostream>       // std::cout
// #include <vector>         // std::vector
// #include <deque>          // std::deque

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   std::deque<int> mydeque (3,100);          // deque with 3 elements
//   std::vector<int> myvector (2,200);        // vector with 2 elements

//   ft::stack<int> first;                    // empty stack
//   ft::stack<int> second (mydeque);         // stack initialized to copy of deque

//   ft::stack<int,std::vector<int> > third;  // empty stack using vector
//   ft::stack<int,std::vector<int> > fourth (myvector);

//   std::cout << "size of first: " << first.size() << '\n';
//   std::cout << "size of second: " << second.size() << '\n';
//   std::cout << "size of third: " << third.size() << '\n';
//   std::cout << "size of fourth: " << fourth.size() << '\n';

//   return 0;
// }

// // Output: ***********************
// // size of first: 0
// // size of second: 3
// // size of third: 0
// // size of fourth: 2


/* -------------------------------------------------------------------------- */

// // stack::empty
// #include <iostream>       // std::cout

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   ft::stack<int> mystack;
//   int sum (0);

//   for (int i=1;i<=10;i++) mystack.push(i);

//   while (!mystack.empty())
//   {
//      sum += mystack.top();
//      mystack.pop();
//   }

//   std::cout << "total: " << sum << '\n';

//   return 0;
// }

// // Output: ***********************
// // total: 55

/* ------------------------------------------------------------------------- */

// // stack::size
// #include <iostream>       // std::cout

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   ft::stack<int> myints;
//   std::cout << "0. size: " << myints.size() << '\n';

//   for (int i=0; i<5; i++) myints.push(i);
//   std::cout << "1. size: " << myints.size() << '\n';

//   myints.pop();
//   std::cout << "2. size: " << myints.size() << '\n';

//   return 0;
// }

// // Output: ***********************
// // 0. size: 0
// // 1. size: 5
// // 2. size: 4

/* ------------------------------------------------------------------------ */

// // stack::top
// #include <iostream>       // std::cout

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   ft::stack<int> mystack;

//   mystack.push(10);
//   mystack.push(20);

//   mystack.top() -= 5;

//   std::cout << "mystack.top() is now " << mystack.top() << '\n';

//   return 0;
// }

// // Output: ***********************
// // mystack.top() is now 15

/* -------------------------------------------------------------------------- */

// // stack::push/pop
// #include <iostream>       // std::cout

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   ft::stack<int> mystack;

//   for (int i=0; i<5; ++i) mystack.push(i);

//   std::cout << "Popping out elements...";
//   while (!mystack.empty())
//   {
//      std::cout << ' ' << mystack.top();
//      mystack.pop();
//   }
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // Popping out elements... 4 3 2 1 0

/* -------------------------------------------------------------------------- */

// // stack::push/pop
// #include <iostream>       // std::cout

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//     ft::stack<int> mystack1;
//     ft::stack<int> mystack2;

//     for (int i=0; i<5; ++i) mystack1.push(i);
//     for (int i=0; i<5; ++i) mystack2.push(1);

//   std::cout << "Popping out elements till value the same...\n";

//     int i;
//     while (mystack1.top() != mystack2.top())
//     {
//         std::cout << ' ' << mystack1.top() <<  " -- " << mystack2.top() << std::endl;
//         mystack1.pop();
//         mystack2.pop();
//     }

//   return 0;
// }


// // Output: ***********************
// // 4 -- 1
// // 3 -- 1
// // 2 -- 1



/* ################################ FT::STACK ############################### */  //STILL TESTING with ft::vector NEEDED!!!!!!
/* ################################# WITH STD::VECTOR ####################### */  //STILL TESTING with ft::vector NEEDED!!!!!!


// // constructing stacks
// #include <iostream>       // std::cout
// #include <vector>         // std::vector
// #include <deque>          // std::deque

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   std::deque<int> mydeque (3,100);          // deque with 3 elements
//   std::vector<int> myvector (2,200);        // vector with 2 elements

//   ft::stack<int> first;                    // empty stack
//   ft::stack<int> second (mydeque);         // stack initialized to copy of deque

//   ft::stack<int,std::vector<int> > third;  // empty stack using vector
//   ft::stack<int,std::vector<int> > fourth (myvector);

//   std::cout << "size of first: " << first.size() << '\n';
//   std::cout << "size of second: " << second.size() << '\n';
//   std::cout << "size of third: " << third.size() << '\n';
//   std::cout << "size of fourth: " << fourth.size() << '\n';

//   return 0;
// }

// // Output: ***********************
// // size of first: 0
// // size of second: 3
// // size of third: 0
// // size of fourth: 2


/* -------------------------------------------------------------------------- */

// // stack::empty
// #include <iostream>       // std::cout
// #include <vector>         // std::vector

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//   ft::stack<int,std::vector<int> > one;  // empty stack using vector

//   int sum (0);

//   for (int i=1;i<=10;i++) one.push(i);

//   while (!one.empty())
//   {
//      sum += one.top();
//      one.pop();
//   }

//   std::cout << "total: " << sum << '\n';

//   return 0;
// }

// // Output: ***********************
// // total: 55

/* -------------------------------------------------------------------------- */

// // stack::push/pop
// #include <iostream>       // std::cout
// #include <vector>

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//     ft::stack<int,std::vector<int> > mystack1;
//     ft::stack<int,std::vector<int> > mystack2;

//     for (int i=0; i<5; ++i) mystack1.push(i);
//     for (int i=0; i<5; ++i) mystack2.push(1);

//   std::cout << "Popping out elements till value the same...\n";

//     int i;
//     while (mystack1.top() != mystack2.top())
//     {
//         std::cout << ' ' << mystack1.top() <<  " -- " << mystack2.top() << std::endl;
//         mystack1.pop();
//         mystack2.pop();
//     }

//   return 0;
// }


// // Output: ***********************
// // 4 -- 1
// // 3 -- 1
// // 2 -- 1

/* -------------------------------------------------------------------------- */

// // stack::push/pop
// #include <iostream>       // std::cout
// #include <vector>

// #include "inc/stack.hpp" // ft::stack

// int main ()
// {
//     ft::stack<int,std::vector<int> > mystack1;
//     ft::stack<int,std::vector<int> > mystack2;

//     for (int i=0; i<5; ++i) mystack1.push(i);
//     for (int i=0; i<5; ++i) mystack2.push(1);

//   std::cout << "Popping out elements till value the same...\n";

//     int i;
//     while ( !(mystack1.empty() && mystack2.empty()) )
//     {
//         if (mystack1.top() <= mystack2.top())
//         // if (mystack1.top() < mystack2.top())
//         {
//             std::cout << ' ' << mystack1.top() <<  " -- " << mystack2.top() << std::endl;
//         }
//         mystack1.pop();
//         mystack2.pop();
//     }

//   return 0;
// }


// // Output: ***********************
// // 1 -- 1
// // 0 -- 1



/* ################################ FT::VECTOR ############################## */


// // constructing vectors
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   // constructors used in the same order as described above:
//   ft::vector<int> first;                                // empty vector of ints
//   ft::vector<int> second (4,100);                       // four ints with value 100
//   ft::vector<int> sixth (second);                       // a copy of second
//   ft::vector<int> third (second.begin(),second.end());  // iterating through second  TEST AFTERRWARDS!!!!
//   ft::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "first:" << std::endl;
//   for ( ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it )
//     std::cout << *( it ) << std::endl;
//   std::cout << "sixth:" << std::endl;
//   for ( ft::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it )
//     std::cout << *( it ) << std::endl;

//   return 0;
// }

// Output: ***********************
// The contents of fifth are: 16 2 77 29
// first:
// 100
// 100
// 100
// 100
// sixth:
// 100
// 100
// 100
// 100

/* -------------------------------------------------------------------------- */

// // vector assignment
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> foo (3,0);
//   ft::vector<int> bar (5,0);

//   bar = foo;
//   foo = ft::vector<int>();

//   std::cout << "Size of foo: " << int(foo.size()) << '\n';
//   std::cout << "Size of bar: " << int(bar.size()) << '\n';
//   return 0;
// }

// // Output: ***********************
// // Size of foo: 0
// // Size of bar: 3

/* -------------------------------------------------------------------------- */

// // vector::begin/end
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;
//   for (int i=1; i<=5; i++) myvector.push_back(i);

//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 1 2 3 4 5

/* -------------------------------------------------------------------------- */

// // vector::rbegin/rend
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector (5);  // 5 default-constructed ints

//   int i=0;

//   ft::vector<int>::reverse_iterator rit = myvector.rbegin();
//   for (; rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 5 4 3 2 1

/* -------------------------------------------------------------------------- */

// // vector::size
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myints;
//   std::cout << "0. size: " << myints.size() << '\n';

//   for (int i=0; i<10; i++) myints.push_back(i);
//   std::cout << "1. size: " << myints.size() << '\n';

//   myints.insert (myints.end(),10,100);
//   std::cout << "2. size: " << myints.size() << '\n';

//   myints.pop_back();
//   std::cout << "3. size: " << myints.size() << '\n';

//   return 0;
// }

// // Output: ***********************
// // 0. size: 0
// // 1. size: 10
// // 2. size: 20
// // 3. size: 19

/* -------------------------------------------------------------------------- */

// // comparing size, capacity and max_size
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;

//   // set some content in the vector:
//   for (int i=0; i<100; i++) myvector.push_back(i);

//   std::cout << "size: " << myvector.size() << "\n";
//   std::cout << "capacity: " << myvector.capacity() << "\n";
//   std::cout << "max_size: " << myvector.max_size() << "\n";
//   return 0;
// }

// // Output: ***********************
// // A possible output for this program could be:
// // size: 100
// // capacity: 120
// // max_size: 4611686018427387903

/* -------------------------------------------------------------------------- */

// // resizing vector
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;

//   // set some initial content:
//   for (int i=1;i<10;i++) myvector.push_back(i);

//   myvector.resize(5);
//   myvector.resize(8,100);
//   myvector.resize(12);

//   std::cout << "myvector contains:";
//   for (int i=0;i<myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0

/* -------------------------------------------------------------------------- */

// // vector::empty
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;
//   int sum (0);

//   for (int i=1;i<=10;i++) myvector.push_back(i);

//   while (!myvector.empty())
//   {
//      sum += myvector.back();
//      myvector.pop_back();
//   }

//   std::cout << "total: " << sum << '\n';

//   return 0;
// }

// // Output: ***********************
// // total: 55

/* -------------------------------------------------------------------------- */

// // vector::reserve
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int>::size_type sz;

//   ft::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   ft::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   std::cout << "capacity : " << bar.capacity() << '\n';
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }
//   return 0;
// }

// // Output: ***********************
// // Possible output:
// // making foo grow:
// // capacity changed: 1
// // capacity changed: 2
// // capacity changed: 4
// // capacity changed: 8
// // capacity changed: 16
// // capacity changed: 32
// // capacity changed: 64
// // capacity changed: 128
// // making bar grow:
// // capacity changed: 100 // in my case always double, so 200!

/* -------------------------------------------------------------------------- */

// // vector::operator[]
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector (10);   // 10 zero-initialized elements

//   ft::vector<int>::size_type sz = myvector.size();

//   // assign some values:
//   for (unsigned i=0; i<sz; i++) myvector[i]=i;

//   // reverse vector using operator[]:
//   for (unsigned i=0; i<sz/2; i++)
//   {
//     int temp;
//     temp = myvector[sz-1-i];
//     myvector[sz-1-i]=myvector[i];
//     myvector[i]=temp;
//   }

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<sz; i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }
// // Output: ***********************
// // myvector contains: 9 8 7 6 5 4 3 2 1 0

/* -------------------------------------------------------------------------- */

// // vector::at
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector (10);   // 10 zero-initialized ints

//   // assign some values:
//   for (unsigned i=0; i<myvector.size(); i++)
//     myvector.at(i)=i;

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector.at(i);
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 0 1 2 3 4 5 6 7 8 9

/* -------------------------------------------------------------------------- */

// // vector::front
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;

//   myvector.push_back(78);
//   myvector.push_back(16);

//   // now front equals 78, and back 16

//   myvector.front() -= myvector.back();

//   std::cout << "myvector.front() is now " << myvector.front() << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector.front() is now 62

/* -------------------------------------------------------------------------- */

// // vector::back
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;

//   myvector.push_back(10);

//   while (myvector.back() != 0)
//   {
//     myvector.push_back ( myvector.back() -1 );
//   }

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size() ; i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 10 9 8 7 6 5 4 3 2 1 0

/* -------------------------------------------------------------------------- */

// // vector assign
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> first;
//   ft::vector<int> second;
//   ft::vector<int> third;

//   first.assign (7,100);             // 7 ints with a value of 100

//   ft::vector<int>::iterator it;
//   it=first.begin()+1;

//   second.assign (it,first.end()-1); // the 5 central values of first

//   int myints[] = {1776,7,4};
//   third.assign (myints,myints+3);   // assigning from array.

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
//   return 0;
// }

// // Output: ***********************
// // Size of first: 7
// // Size of second: 5
// // Size of third: 3

/* -------------------------------------------------------------------------- */

// // vector::push_back
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";

//   do {
//     std::cin >> myint;
//     myvector.push_back (myint);
//   } while (myint);

//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

//   return 0;
// }

// // Output: ***********************
// // count of numbers (including the '0')

/* -------------------------------------------------------------------------- */

// // vector::pop_back
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;
//   int sum (0);
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   while (!myvector.empty())
//   {
//     sum+=myvector.back();
//     myvector.pop_back();
//   }

//   std::cout << "The elements of myvector add up to " << sum << '\n';

//   return 0;
// }

// // Output: ***********************
// // The elements of myvector add up to 600

/* -------------------------------------------------------------------------- */

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ERROR!!!!!! still CHECK @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// // inserting into a vector

// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector (3,100);
//   ft::vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   ft::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 501 502 503 300 300 400 400 200 100 100 100

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ERROR!!!!!! still CHECK @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/* -------------------------------------------------------------------------- */

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ERROR!!!!!! still CHECK @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// // erasing from vector
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin()+5);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 4 5 7 8 9 10

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ERROR!!!!!! still CHECK @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/* -------------------------------------------------------------------------- */

// // swap vectors
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // foo contains: 200 200 200 200 200 
// // bar contains: 100 100 100

/* -------------------------------------------------------------------------- */

// // clearing vectors
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   myvector.clear();
//   myvector.push_back (1101);
//   myvector.push_back (2202);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // Output: ***********************
// // myvector contains: 100 200 300
// // myvector contains: 1101 2202

/* -------------------------------------------------------------------------- */

// // vector::get_allocator
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> myvector;
//   int * p;
//   unsigned int i;

//   // allocate an array with space for 5 elements using vector's allocator:
//   p = myvector.get_allocator().allocate(5);

//   // construct values in-place on the array:
//   for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

//   std::cout << "The allocated array contains:";
//   for (i=0; i<5; i++) std::cout << ' ' << p[i];
//   std::cout << '\n';

//   // destroy and deallocate:
//   for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
//   myvector.get_allocator().deallocate(p,5);

//   return 0;
// }

// // Output: ***********************
// // The example shows an elaborate way to allocate memory for an array of ints using the same allocator used by the vector.
// // The allocated array contains: 0 1 2 3 4

/* -------------------------------------------------------------------------- */

// // vector comparisons
// #include <iostream>

// #include "inc/vector.hpp"

// int main ()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (2,200);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }

// // Output: ***********************
// // foo and bar are not equal
// // foo is less than bar
// // foo is less than or equal to bar

/* -------------------------------------------------------------------------- */
