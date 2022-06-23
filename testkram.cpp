#include <iostream>

// // check to see if assignation operator of std:;pair deletes potential old ptr in pair.second, or not
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


/* test FT::PAIR implementation */
// CONSTRUCTORS
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

// // pair relational operators
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


// // pair::pair example
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



// make_pair example
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

// check SFINAE
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

// is_integral example
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

// enable_if example: two ways of using enable_if
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

// lexicographical_compare example
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


