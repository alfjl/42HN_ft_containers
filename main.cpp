/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:04:09 by alanghan          #+#    #+#             */
/*   Updated: 2022/10/17 17:05:14 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include <ctime>

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
    namespace ft = std;

#else

    #include "../inc/stack.hpp"
    #include "../inc/vector.hpp"
    #include "../inc/map.hpp"
    #include "../inc/set.hpp"

#endif

int main()
{
    std::cout << CYAN << "\n***************************" << std::endl;
    std::cout << CYAN << "\n***************************" << std::endl;
    std::cout         <<   "**     " << BLUE << "FT_CONTAINERS" << CYAN << "     **" << std::endl;
    std::cout         <<   "***************************" << RESET << std::endl;
    std::cout         <<   "***************************" << RESET << std::endl;

    std::cout << "A simple tester for the most important functionalities of the STL containers and\n classes we had to recode for our 42 Heilbronn project 'ft_containers'.\n";
    std::cout << "All functions can be run under the namespaces std and ft, to draw a comparison." << std::endl;

    /* ############################### PAIR ################################# */

    std::cout << GREEN << "\n***************************" << std::endl;
    std::cout          <<   "*          PAIR           *" << std::endl;
    std::cout          <<   "***************************" << RESET << std::endl;

    std::cout << " --------------------------------------------- " << std::endl;

    /* ############################### STACK ################################ */

    std::cout << GREEN << "\n***************************" << std::endl;
    std::cout          <<   "*          STACK          *" << std::endl;
    std::cout          <<   "***************************" << RESET << std::endl;

    std::cout << " --------------------------------------------- " << std::endl;

    /* ############################### VECTOR ############################### */

    std::cout << GREEN << "\n***************************" << std::endl;
    std::cout          <<   "*         VECTOR          *" << std::endl;
    std::cout          <<   "***************************" << RESET << std::endl;

    std::cout << " --------------------------------------------- " << std::endl;

    /* ################################ MAP ################################# */

    std::cout << GREEN << "\n***************************" << std::endl;
    std::cout          <<   "*           MAP           *" << std::endl;
    std::cout          <<   "***************************" << RESET << std::endl;

    ft::map<int, std::string> map;
    // srand(time(0)); // can not be used to compare output of ft & std, since the seed would be different every time you compile
    srand(5);
    for (size_t i = 0; i < 10; ++i)
    		map.insert(ft::make_pair<int, std::string>(std::rand() % 100, "performance: " + std::to_string(i)));
    std::cout << "Map map.size() = " << map.size() << std::endl;
    ft::map<int, std::string> map2(map);	
    std::cout << "Map map2.size() = " << map2.size() << std::endl;
    ft::map<int, std::string> map3(map2.begin(), map2.end());
    std::cout << "Map map3.size() = " << map3.size() << std::endl;
    map.erase(map.begin(), map.end());	
    std::cout << "Map map.size() = " << map.size() << std::endl;

    std::cout << " --------------------------------------------- " << std::endl;

    /* ################################ SET ################################# */

    std::cout << GREEN << "\n***************************" << std::endl;
    std::cout          <<   "*           SET           *" << std::endl;
    std::cout          <<   "***************************" << RESET << std::endl;

    std::cout << " --------------------------------------------- " << std::endl;

    std::cout << " !!!!!!!!!!!!!!!!! FINISHED !!!!!!!!!!!!!!!!!! " << std::endl;

    return (0);
}
