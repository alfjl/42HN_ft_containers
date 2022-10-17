/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:04:09 by alanghan          #+#    #+#             */
/*   Updated: 2022/10/17 17:52:14 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include <ctime>
#include <string>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"

#if STD

    #include <stack>
    #include <vector>
    #include <map>
    #include <set>

    #define FT "STD";

    namespace ft = std;

#else

    #include "./inc/stack.hpp"
    #include "./inc/vector.hpp"
    #include "./inc/map.hpp"
    #include "./inc/set.hpp"

    #define FT "FT";

#endif

int main()
{
    std::cout << CYAN << "\n          ***************************" << std::endl;
    std::cout         <<   "          ***************************" << std::endl;
    std::cout         <<   "          **     " << BLUE << "FT_CONTAINERS" << CYAN << "     **" << std::endl;
    std::cout         <<   "          ***************************" << std::endl;
    std::cout         <<   "          ***************************" << RESET << std::endl;

    std::cout << "\nA simple tester for the most important functionalities of the STL containers and\nclasses we had to recode for our 42 Heilbronn project 'ft_containers'.\n";
    std::cout << "All functions can be run under the namespaces std and ft, to draw a comparison." << std::endl;
    std::cout << "Many of the standard tests are taken from cplusplus.com and adpated." << std::endl;

    std::cout << "\n -------------- IN ";
    std::cout << FT;
    std::cout << " --------------\n" << std::endl;

    /* ############################### PAIR ################################# */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *          PAIR           *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    /* ---------------------------------------------------------------------- */

    // CONSTRUCTORS
    std::cout << "\n - Constructors: " << std::endl;

    ft::pair <std::string,double> product1;                     // default constructor
    ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    ft::pair <std::string,double> product3 (product2);          // copy constructor

    product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    product2.first = "shoes";                  // the type of first is string
    product2.second = 39.90;                   // the type of second is double

    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

    // Output: ***********************
    // The price of lightbulbs is $0.99
    // The price of shoes is $39.9
    // The price of tomatoes is $2.3

    /* ---------------------------------------------------------------------- */
    
    // pair::operator= example
    std::cout << "\n - pair::operator= example: " << std::endl;

    ft::pair <std::string,int> planet, homeplanet;

    planet = ft::make_pair("Earth",6371);

    homeplanet = planet;

    std::cout << "Home planet: " << homeplanet.first << '\n';
    std::cout << "Planet size: " << homeplanet.second << '\n';

    // Output: ***********************
    // Home planet: Earth
    // Planet size: 6371

    /* ---------------------------------------------------------------------- */

    // pair relational operators
    std::cout << "\n - pair relational operators: " << std::endl;
    
    ft::pair<int,char> foo (10,'z');
    ft::pair<int,char> bar (90,'a');

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

    // Output: ***********************
    // foo and bar are not equal
    // foo is less than bar
    // foo is less than or equal to bar

    /* ---------------------------------------------------------------------- */

    // make_pair example
    std::cout << "\n - make_pair example: " << std::endl;

    ft::pair <int,int> boo;
    ft::pair <int,int> far;

    boo = ft::make_pair (10,20);
    far = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

    std::cout << "boo: " << boo.first << ", " << boo.second << '\n';
    std::cout << "bar: " << far.first << ", " << far.second << '\n';

    // Output: ***********************
    // boo: 10, 20
    // far: 10, 65

    std::cout << GREEN << "\n --------------------------------------------- " << std::endl;

    /* ############################### STACK ################################ */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *          STACK          *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    std::cout << GREEN << "\n --------------------------------------------- " << std::endl;

    /* ############################### VECTOR ############################### */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *         VECTOR          *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    std::cout << GREEN << "\n --------------------------------------------- " << std::endl;

    /* ################################ MAP ################################# */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *           MAP           *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    /* ---------------------------------------------------------------------- */

    // insert & erase huge map
    std::cout << "\n - insert & erase huge map: " << std::endl;

    ft::map<int, std::string> map;
    // srand(time(0)); // can not be used to compare output of ft & std, since the seed would be different every time you compile
    srand(5);
    for (size_t i = 0; i < 1000000; ++i)
    		map.insert(ft::make_pair<int, std::string>(std::rand() % 1000000, "performance: " + std::to_string(i)));
    std::cout << "Map map.size() = " << map.size() << std::endl;
    ft::map<int, std::string> map2(map);	
    std::cout << "Map map2.size() = " << map2.size() << std::endl;
    ft::map<int, std::string> map3(map2.begin(), map2.end());
    std::cout << "Map map3.size() = " << map3.size() << std::endl;
    map.erase(map.begin(), map.end());	
    std::cout << "Map map.size() = " << map.size() << std::endl;

    std::cout << GREEN << "\n --------------------------------------------- " << std::endl;

    /* ################################ SET ################################# */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *           SET           *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    std::cout << GREEN << "\n --------------------------------------------- " << std::endl;

    std::cout << "\n !!!!!!!!!!!!!!!!! FINISHED !!!!!!!!!!!!!!!!!! " << std::endl;

    return (0);
}
