#include <iostream>

/* ###################################### PAIR ###################################### */


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


/* ---------------------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------------------- */
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

/* ###################################### TYPE_TRAITS ###################################### */

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

/* ---------------------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------------------- */
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

/* ###################################### ALGORITHMS ###################################### */

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


/* ---------------------------------------------------------------------------------- */
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

/* ###################################### ITERATOR_TRAITS ###################################### */

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


/* ###################################### REVERSE_ITERATOR ##################################### */  //STILL TESTING NEEDED!!!!!!

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */

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

/* ---------------------------------------------------------------------------------- */


/* ###################################### REVERSE_ITERATOR ##################################### */  //STILL TESTING NEEDED!!!!!!




