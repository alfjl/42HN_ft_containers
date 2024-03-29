/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanghan <alanghan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:04:09 by alanghan          #+#    #+#             */
/*   Updated: 2022/10/18 16:53:39 by alanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include <ctime>
#include <string>
#include <cstdlib>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"

// for vectore stress test
#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
    int idx;
    char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

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


template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main()
{
    std::cout << CYAN << "\n          ***************************" << std::endl;
    std::cout         <<   "          ***************************" << std::endl;
    std::cout         <<   "          **     " << BLUE << "FT_CONTAINERS" << CYAN << "     **" << std::endl;
    std::cout         <<   "          ***************************" << std::endl;
    std::cout         <<   "          ***************************" << RESET << std::endl;

    std::cout << "\nA simple tester for the most important functionalities of the STL containers and\nclasses we had to recode for our 42 Heilbronn project 'ft_containers'.\n";
    std::cout << "All functions can be run under the namespaces std and ft, to draw a comparison." << std::endl;
    std::cout << "Many of the standard tests for pair, stack and vector are taken from http://cplusplus.com and adpated." << std::endl;
    std::cout << "Thank you also NL27 (https://github.com/NL27) for your inspiration regarding some of the map tests." << std::endl;

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

    std::cout << GREEN << "\n --------------------------------------------- " << RESET << std::endl;




    /* ############################### STACK ################################ */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *          STACK          *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    /* ---------------------------------------------------------------------- */

    // constructing stacks
    std::cout << "\n - constructing stacks: " << std::endl;

    std::deque<int> mydeque (3,100);          // deque with 3 elements
    ft::vector<int> myvector (2,200);        // vector with 2 elements

    ft::stack<int> first;                    // empty stack
    ft::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

    ft::stack<int,ft::vector<int> > third;  // empty stack using vector

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';

    // Output: ***********************
    // size of first: 0
    // size of second: 3
    // size of third: 0

    /* ---------------------------------------------------------------------- */

    // stack::empty
    std::cout << "\n - stack::empty: " << std::endl;

    ft::stack<int> mystack;
    int sum (0);

    for (int i = 1; i <= 10; i++) mystack.push(i);

    while ( !mystack.empty() )
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';

    // Output: ***********************
    // total: 55

    /* ---------------------------------------------------------------------- */

    // stack::size
    std::cout << "\n - stack::size: " << std::endl;

    ft::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';

    // Output: ***********************
    // 0. size: 0
    // 1. size: 5
    // 2. size: 4

    /* ---------------------------------------------------------------------- */

    // stack::top
    std::cout << "\n - stack::top: " << std::endl;

    ft::stack<int> mystack2;

    mystack2.push(10);
    mystack2.push(20);

    mystack2.top() -= 5;

    std::cout << "mystack2.top() is now " << mystack2.top() << '\n';

    // Output: ***********************
    // mystack2.top() is now 15

    /* ---------------------------------------------------------------------- */

    // stack::push/pop 1
    std::cout << "\n - stack::push/pop 1: " << std::endl;

    ft::stack<int> mystack3;

    for (int i=0; i<5; ++i) mystack3.push(i);

    std::cout << "Popping out elements...";
    while (!mystack3.empty())
    {
        std::cout << ' ' << mystack3.top();
        mystack3.pop();
    }
    std::cout << '\n';

    // Output: ***********************
    // Popping out elements... 4 3 2 1 0

    /* ---------------------------------------------------------------------- */

    // stack::push/pop 2
    std::cout << "\n - stack::push/pop 2: " << std::endl;

    ft::stack<int> mystack4;
    ft::stack<int> mystack5;

    for (int i=0; i<5; ++i) mystack4.push(i);
    for (int i=0; i<5; ++i) mystack5.push(1);

    std::cout << "Popping out elements till value the same...\n";

    while (mystack4.top() != mystack5.top())
    {
        std::cout << ' ' << mystack4.top() <<  " -- " << mystack5.top() << std::endl;
        mystack4.pop();
        mystack5.pop();
    }

    // Output: ***********************
    // 4 -- 1
    // 3 -- 1
    // 2 -- 1

    /* ---------------------------------------------------------------------- */

    // intra test MutantStack
    std::cout << "\n - intra test MutantStack: " << std::endl;

    MutantStack<char> iterable_stack;
    for (char letter = 'a'; letter <= 'z'; letter++)
        iterable_stack.push(letter);
    for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
    {
        std::cout << *it;
    }

    // Output: ***********************
    // abcdefghijklmnopqrstuvwxyz

    std::cout << GREEN << "\n --------------------------------------------- " << RESET << std::endl;




    /* ############################### VECTOR ############################### */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *         VECTOR          *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;


    /* ---------------------------------------------------------------------- */

    // constructing vectors
    std::cout << "\n - constructing vectors: " << std::endl;

    // constructors used in the same order as described above:
    ft::vector<int> mfirst;                                // empty vector of ints
    ft::vector<int> msecond (4,100);                       // four ints with value 100
    ft::vector<int> msixth (msecond);                       // a copy of second
    ft::vector<int> mthird (msecond.begin(),msecond.end());  // iterating through second  TEST AFTERRWARDS!!!!
    ft::vector<int> mfourth (mthird);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int mmyints[] = {16,2,77,29};
    ft::vector<int> mfifth (mmyints, mmyints + sizeof(mmyints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = mfifth.begin(); it != mfifth.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "mfirst:" << std::endl;
    for ( ft::vector<int>::iterator it = msecond.begin(); it != msecond.end(); ++it )
    std::cout << *( it ) << std::endl;
    std::cout << "msixth:" << std::endl;
    for ( ft::vector<int>::iterator it = msixth.begin(); it != msixth.end(); ++it )
    std::cout << *( it ) << std::endl;

    // Output: ***********************
    // The contents of mfifth are: 16 2 77 29
    // mfirst:
    // 100
    // 100
    // 100
    // 100
    // msixth:
    // 100
    // 100
    // 100
    // 100

    /* ---------------------------------------------------------------------- */

    // vector assignment
    std::cout << "\n - vector assignment: " << std::endl;

    ft::vector<int> too (3,0);
    ft::vector<int> tar (5,0);

    tar = too;
    too = ft::vector<int>();

    std::cout << "Size of too: " << int(too.size()) << '\n';
    std::cout << "Size of tar: " << int(tar.size()) << '\n';

    // Output: ***********************
    // Size of too: 0
    // Size of tar: 3

    /* ---------------------------------------------------------------------- */

    // vector::begin/end
    std::cout << "\n - vector::begin/end: " << std::endl;

    ft::vector<int> tmyvector;
    for (int i=1; i<=5; i++) tmyvector.push_back(i);

    std::cout << "tmyvector contains:";
    for (ft::vector<int>::iterator it = tmyvector.begin() ; it != tmyvector.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';

    // Output: ***********************
    // tmyvector contains: 1 2 3 4 5

    /* ---------------------------------------------------------------------- */

    // vector::rbegin/rend
    std::cout << "\n - vector::rbegin/rend: " << std::endl;

    ft::vector<int> smyvector (5);  // 5 default-constructed ints

    int i=0;

    ft::vector<int>::reverse_iterator rit = smyvector.rbegin();
    for (; rit!= smyvector.rend(); ++rit)
    *rit = ++i;

    std::cout << "smyvector contains:";
    for (ft::vector<int>::iterator it = smyvector.begin(); it != smyvector.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';

    // Output: ***********************
    // smyvector contains: 5 4 3 2 1

    /* ---------------------------------------------------------------------- */

    // vector::size
    std::cout << "\n - vector::size: " << std::endl;

    ft::vector<int> pmyints;
    std::cout << "0. size: " << pmyints.size() << '\n';

    for (int i=0; i<10; i++) pmyints.push_back(i);
    std::cout << "1. size: " << pmyints.size() << '\n';

    pmyints.insert (pmyints.end(),10,100);
    std::cout << "2. size: " << pmyints.size() << '\n';

    pmyints.pop_back();
    std::cout << "3. size: " << pmyints.size() << '\n';

    // Output: ***********************
    // 0. size: 0
    // 1. size: 10
    // 2. size: 20
    // 3. size: 19

    /* ---------------------------------------------------------------------- */

    // comparing size, capacity and max_size
    std::cout << "\n - comparing size, capacity and max_size: " << std::endl;

    ft::vector<int> emyvector;

    // set some content in the vector:
    for (int i=0; i<100; i++) emyvector.push_back(i);

    std::cout << "size: " << emyvector.size() << "\n";
    std::cout << "capacity: " << emyvector.capacity() << "\n";
    std::cout << "max_size: " << emyvector.max_size() << "\n";

    // Output: ***********************
    // A possible output for this program could be:
    // size: 100
    // capacity: 128
    // max_size: 4611686018427387903

    /* ---------------------------------------------------------------------- */

    // resizing vector
    std::cout << "\n - resizing vector: " << std::endl;

    ft::vector<int> gmyvector;

    // set some initial content:
    for (int i=1;i<10;i++) gmyvector.push_back(i);

    gmyvector.resize(5);
    gmyvector.resize(8,100);
    gmyvector.resize(12);

    std::cout << "gmyvector contains:";
    for (unsigned long i=0;i<gmyvector.size();i++)
    std::cout << ' ' << gmyvector[i];
    std::cout << '\n';

    // Output: ***********************
    // gmyvector contains: 1 2 3 4 5 100 100 100 0 0 0 0

    /* ---------------------------------------------------------------------- */

    // vector::empty
    std::cout << "\n - vector::empty: " << std::endl;

    ft::vector<int> imyvector;
    int ssum (0);

    for (int i=1;i<=10;i++) imyvector.push_back(i);

    while (!imyvector.empty())
    {
        ssum += imyvector.back();
        imyvector.pop_back();
    }

    std::cout << "total: " << ssum << '\n';

    // Output: ***********************
    // total: 55

    /* ---------------------------------------------------------------------- */

    // vector::reserve
    std::cout << "\n - vector::reserve: " << std::endl;

    ft::vector<int>::size_type sz;

    ft::vector<int> loo;
    sz = loo.capacity();
    std::cout << "making loo grow:\n";
    for (int i=0; i<100; ++i) {
        loo.push_back(i);
        if (sz!=loo.capacity()) {
            sz = loo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    ft::vector<int> lar;
    sz = lar.capacity();
    lar.reserve(100);   // this is the only difference with foo above
    std::cout << "making lar grow:\n";
    std::cout << "capacity : " << lar.capacity() << '\n';
    for (int i=0; i<100; ++i) {
        lar.push_back(i);
        if (sz!=lar.capacity()) {
            sz = lar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    // Output: ***********************
    // Possible output:
    // making loo grow:
    // capacity changed: 1
    // capacity changed: 2
    // capacity changed: 4
    // capacity changed: 8
    // capacity changed: 16
    // capacity changed: 32
    // capacity changed: 64
    // capacity changed: 128
    // making lar grow:
    // capacity : 100
    // capacity changed: 100

    /* ---------------------------------------------------------------------- */

    // vector::operator[]
    std::cout << "\n - vector::operator[]: " << std::endl;

    ft::vector<int> amyvector (10);   // 10 zero-initialized elements

    ft::vector<int>::size_type szz = amyvector.size();

    // assign some values:
    for (unsigned i=0; i<szz; i++) amyvector[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<szz/2; i++)
    {
        int temp;
        temp = amyvector[szz-1-i];
        amyvector[szz-1-i]=amyvector[i];
        amyvector[i]=temp;
    }

    std::cout << "amyvector contains:";
    for (unsigned i=0; i<szz; i++)
    std::cout << ' ' << amyvector[i];
    std::cout << '\n';

    // Output: ***********************
    // amyvector contains: 9 8 7 6 5 4 3 2 1 0

    /* ---------------------------------------------------------------------- */

    // vector::at
    std::cout << "\n - vector::at: " << std::endl;

    ft::vector<int> cmyvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<cmyvector.size(); i++)
    cmyvector.at(i)=i;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<cmyvector.size(); i++)
    std::cout << ' ' << cmyvector.at(i);
    std::cout << '\n';

    // Output: ***********************
    // cmyvector contains: 0 1 2 3 4 5 6 7 8 9

    /* ---------------------------------------------------------------------- */

    // vector::front
    std::cout << "\n - vector::front: " << std::endl;

    ft::vector<int> kmyvector;

    kmyvector.push_back(78);
    kmyvector.push_back(16);

    // now front equals 78, and back 16

    kmyvector.front() -= kmyvector.back();

    std::cout << "kmyvector.front() is now " << kmyvector.front() << '\n';

    // Output: ***********************
    // kmyvector.front() is now 62

    /* ---------------------------------------------------------------------- */

    // vector::back
    std::cout << "\n - vector::back: " << std::endl;

    ft::vector<int> hmyvector;

    hmyvector.push_back(10);

    while (hmyvector.back() != 0)
    {
        hmyvector.push_back ( hmyvector.back() -1 );
    }

    std::cout << "emyvector contains:";
    for (unsigned i=0; i<hmyvector.size() ; i++)
    std::cout << ' ' << hmyvector[i];
    std::cout << '\n';

    // Output: ***********************
    // hmyvector contains: 10 9 8 7 6 5 4 3 2 1 0

    /* ---------------------------------------------------------------------- */

    // vector assign
    std::cout << "\n - vector assign: " << std::endl;

    ft::vector<int> lfirst;
    ft::vector<int> lsecond;
    ft::vector<int> lthird;

    lfirst.assign (7,100);             // 7 ints with a value of 100

    ft::vector<int>::iterator it;
    it=lfirst.begin()+1;

    lsecond.assign (it,lfirst.end()-1); // the 5 central values of first

    int lmyints[] = {1776,7,4};
    lthird.assign (lmyints,lmyints+3);   // assigning from array.

    std::cout << "Size of lfirst: " << int (lfirst.size()) << '\n';
    std::cout << "Size of lsecond: " << int (lsecond.size()) << '\n';
    std::cout << "Size of lthird: " << int (lthird.size()) << '\n';

    // Output: ***********************
    // Size of lfirst: 7
    // Size of lsecond: 5
    // Size of lthird: 3

    /* ---------------------------------------------------------------------- */

    // vector::pop_back
    std::cout << "\n - vector::pop_back: " << std::endl;

    ft::vector<int> jmyvector;
    int jsum (0);
    jmyvector.push_back (100);
    jmyvector.push_back (200);
    jmyvector.push_back (300);

    while (!jmyvector.empty())
    {
        jsum+=jmyvector.back();
        jmyvector.pop_back();
    }

    std::cout << "The elements of jmyvector add up to " << jsum << '\n';

    // Output: ***********************
    // The elements of jmyvector add up to 600

    /* ---------------------------------------------------------------------- */

    // inserting into a vector
    std::cout << "\n - inserting into a vector: " << std::endl;

    ft::vector<int> mmyvector (3,100);
    ft::vector<int>::iterator mit;

    mit = mmyvector.begin();
    mit = mmyvector.insert ( mit , 200 );

    mmyvector.insert (mit,2,300);

    // "it" no longer valid, get a new one:
    mit = mmyvector.begin();

    ft::vector<int> manothervector (2,400);
    mmyvector.insert (mit+2,manothervector.begin(),manothervector.end());

    int mmyarray [] = { 501,502,503 };
    mmyvector.insert (mmyvector.begin(), mmyarray, mmyarray+3);

    std::cout << "mmyvector contains:";
    for (mit=mmyvector.begin(); mit<mmyvector.end(); mit++)
    std::cout << ' ' << *mit;
    std::cout << '\n';

    // Output: ***********************
    // mmyvector contains: 501 502 503 300 300 400 400 200 100 100 100

    /* ---------------------------------------------------------------------- */

    // erasing from vector
    std::cout << "\n - erasing from vector: " << std::endl;

    ft::vector<int> nmyvector;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) nmyvector.push_back(i);

    // erase the 6th element
    nmyvector.erase (nmyvector.begin()+5);

    // erase the first 3 elements:
    nmyvector.erase (nmyvector.begin(),nmyvector.begin()+3);

    std::cout << "nmyvector contains:";
    for (unsigned i=0; i<nmyvector.size(); ++i)
        std::cout << ' ' << nmyvector[i];
    std::cout << '\n';

    // Output: ***********************
    // nmyvector contains: 4 5 7 8 9 10

    /* ---------------------------------------------------------------------- */

    // swap vectors
    std::cout << "\n - swap vectors: " << std::endl;

    ft::vector<int> noo (3,100);   // three ints with a value of 100
    ft::vector<int> nar (5,200);   // five ints with a value of 200

    ft::vector<int>::iterator v_it = noo.begin();
    std::cout << "BEFORE: v_it points on: " << *v_it << std::endl;
    int *v_ptr = &nar[1];
    std::cout << "BEFORE: v_ptr points on: " << *v_ptr << std::endl;
    int &v_ref = nar[4];
    std::cout << "BEFORE: v_ref points on: " << v_ref << std::endl;

    noo.swap(nar);

    std::cout << "noo contains:";
    for (unsigned i=0; i<noo.size(); i++)
        std::cout << ' ' << noo[i];
    std::cout << '\n';

    std::cout << "nar contains:";
    for (unsigned i=0; i<nar.size(); i++)
        std::cout << ' ' << nar[i];
    std::cout << '\n';
    std::cout << "AFTER: v_it points on: " << *v_it << std::endl;
    std::cout << "AFTER: v_ptr points on: " << *v_ptr << std::endl;
    std::cout << "AFTER: v_ref points on: " << v_ref << std::endl;
    // Output: ***********************
    // BEFORE: v_it points on: 100
    // BEFORE: v_ptr points on: 200
    // BEFORE: v_ref points on: 200
    // noo contains: 200 200 200 200 200
    // nar contains: 100 100 100
    // AFTER: v_it points on: 100
    // AFTER: v_ptr points on: 200
    // AFTER: v_ref points on: 200

    /* ---------------------------------------------------------------------- */

    // clearing vectors
    std::cout << "\n - clearing vectors: " << std::endl;

    ft::vector<int> bmyvector;
    bmyvector.push_back (100);
    bmyvector.push_back (200);
    bmyvector.push_back (300);

    std::cout << "bmyvector contains:";
    for (unsigned i=0; i<bmyvector.size(); i++)
    std::cout << ' ' << bmyvector[i];
    std::cout << '\n';

    bmyvector.clear();
    bmyvector.push_back (1101);
    bmyvector.push_back (2202);

    std::cout << "bmyvector contains:";
    for (unsigned i=0; i<bmyvector.size(); i++)
    std::cout << ' ' << bmyvector[i];
    std::cout << '\n';

    // Output: ***********************
    // bmyvector contains: 100 200 300
    // bmyvector contains: 1101 2202

    /* ---------------------------------------------------------------------- */

    // vector::get_allocator
    std::cout << "\n - vector::get_allocator: " << std::endl;

    ft::vector<int> omyvector;
    int * p;
    unsigned int u;

    // allocate an array with space for 5 elements using vector's allocator:
    p = omyvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (u=0; u<5; u++) omyvector.get_allocator().construct(&p[u],u);

    std::cout << "The allocated array contains:";
    for (u=0; u<5; u++) std::cout << ' ' << p[u];
    std::cout << '\n';

    // destroy and deallocate:
    for (u=0; u<5; u++) omyvector.get_allocator().destroy(&p[u]);
    omyvector.get_allocator().deallocate(p,5);

    // Output: ***********************
    // The example shows an elaborate way to allocate memory for an array of ints using the same allocator used by the vector.
    // The allocated array contains: 0 1 2 3 4

    /* ---------------------------------------------------------------------- */

    // vector comparisons
    std::cout << "\n - vector comparisons: " << std::endl;

    ft::vector<int> yoo (3,100);   // three ints with a value of 100
    ft::vector<int> yar (2,200);   // two ints with a value of 200

    if (yoo==yar) std::cout << "yoo and yar are equal\n";
    if (yoo!=yar) std::cout << "yoo and yar are not equal\n";
    if (yoo< yar) std::cout << "yoo is less than yar\n";
    if (yoo> yar) std::cout << "yoo is greater than yar\n";
    if (yoo<=yar) std::cout << "yoo is less than or equal to yar\n";
    if (yoo>=yar) std::cout << "yoo is greater than or equal to yar\n";

    // Output: ***********************
    // yoo and yar are not equal
    // yoo is less than yar
    // yoo is less than or equal to yar

    /* ---------------------------------------------------------------------- */

    // vector comparisons with const_iterator & iterator
    std::cout << "\n - vector comparisons with const_iterator & iterator: " << std::endl;

    ft::vector<int> hoo;   // empty vector
    
    hoo.push_back(0);
    hoo.push_back(1);
    hoo.push_back(2);
    hoo.push_back(3);
    hoo.push_back(4);

    ft::vector<int>::iterator itt = ( hoo.begin() + 1 );
    ft::vector<int>::const_iterator c_itt = ( hoo.begin() + 3 );
    
    std::cout << "*itt: " << *itt << std::endl;
    std::cout << "*c_itt: " << *c_itt << std::endl;
    std::cout << "*itt > *c_itt = " << ( *itt > *c_itt ) << std::endl;
    std::cout << "itt > c_itt = " << ( itt > c_itt ) << std::endl;

    // Output: ***********************
    // *itt: 1
    // *c_itt: 3
    // *itt > *c_itt = 0
    // itt > c_itt = 0

    /* ---------------------------------------------------------------------- */

    // vector stress test from intra main
    std::cout << "\n - vector stress test from intra main: " << std::endl;

    const int seed = std::atoi("4189344022");
    srand(seed);

    ft::vector<std::string> vector_str;
    ft::vector<int> vector_int;
    ft::vector<Buffer> vector_buffer;
    ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
    ft::map<int, int> map_int;

    for (int i = 0; i < COUNT; i++)
    {
        vector_buffer.push_back(Buffer());
    }

    for (int i = 0; i < COUNT; i++)
    {
        const int idx = rand() % COUNT;
        vector_buffer[idx].idx = 5;
    }
    ft::vector<Buffer>().swap(vector_buffer);

    try
    {
        for (int i = 0; i < COUNT; i++)
        {
            const int idx = rand() % COUNT;
            vector_buffer.at(idx);
            std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
        }
    }
    catch(const std::exception& e)
    {
        //NORMAL ! :P
    }

    for (int i = 0; i < COUNT; ++i)
    {
        map_int.insert(ft::make_pair(rand(), rand()));
    }

    int intra_sum = 0;
    for (int i = 0; i < 10000; i++)
    {
        int access = rand();
        intra_sum += map_int[access];
    }
	std::cout << "should be constant with the same seed: " << intra_sum << std::endl;

    // Output: ***********************
    // should be constant with the same seed: 0

    std::cout << GREEN << "\n --------------------------------------------- " << RESET << std::endl;




    /* ################################ MAP ################################# */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *           MAP           *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    /* ---------------------------------------------------------------------- */

    // map regular insert
    std::cout << "\n - map regular insert: " << std::endl;

    ft::map<char, int> test_map;

    test_map.insert(ft::pair<char, int>('a', 500));
    std::cout << "test_map.size(): " << test_map.size() << std::endl;
    std::cout << "test_map.max_size(): " << test_map.max_size() << std::endl;

    test_map.insert(ft::pair<char, int>('b', 600));
    std::cout << "test_map.size(): " << test_map.size() << std::endl;

    ft::map<char, int> test_map2;
    test_map2.insert(ft::pair<char, int>('c', 1));
    std::cout << "test_map2.size(): " << test_map2.size() << std::endl;

    test_map2.insert(ft::pair<char, int>('d', 2));
    std::cout << "test_map2.size(): " << test_map2.size() << std::endl;

    // Output: ***********************
    // test_map.size(): 1
    // test_map.max_size(): 461168601842738790
    // test_map.size(): 2
    // test_map2.size(): 1
    // test_map2.size(): 2

    /* ---------------------------------------------------------------------- */
   
    // map insert/erase iterator safety
    std::cout << "\n - map insert/erase iterator safety: " << std::endl;
    ft::map<int, int> test_map222;

    for (int i = 0; i < 9; ++i) {
        test_map222.insert(ft::make_pair(i + 1, i + 1));
    }

    ft::map<int, int>::iterator it_six = test_map222.begin();
    for (int i = 0; i < 5; ++i)
        ++it_six;

    std::cout << "After construction" << std::endl;
    for (ft::map<int, int>::iterator it = test_map222.begin(); it != test_map222.end(); ++it)
        std::cout << &it->first << " " << it->first << std::endl;

    std::cout << "it_six BEFORE everything: "<< &it_six->first << " " << it_six->first << "\n" << std::endl;


    test_map222.insert(ft::make_pair(11, 11));

    std::cout << "After insert 11" << std::endl;
    for (ft::map<int, int>::iterator it = test_map222.begin(); it != test_map222.end(); ++it)
        std::cout << &it->first << " " << it->first << std::endl;

    std::cout << "it_six AFTER insert 11 everything: "<< &it_six->first << " " << it_six->first << "\n" << std::endl;

    
    test_map222.erase(5);

    std::cout << "After erase 5" << std::endl;
    for (ft::map<int, int>::iterator it = test_map222.begin(); it != test_map222.end(); ++it)
        std::cout << &it->first << " " << it->first << std::endl;

    std::cout << "it_six AFTER erase 5 everything: "<< &it_six->first << " " << it_six->first << "\n" << std::endl;
    
    // Output: ***********************
    // all addresses should remain the same, throughout the insertion and erasing
    // it_six should point to the same node until the end (address and value))
    
    /* ---------------------------------------------------------------------- */

    // map swap
    std::cout << "\n - map swap: " << std::endl;

	test_map2.swap(test_map);
	std::cout << "test_map.size(): " << test_map.size() << std::endl;
	std::cout << "test_map2.size(): " << test_map2.size() << std::endl;

    // Output: ***********************
    // test_map.size(): 2
    // test_map2.size(): 2

    /* ---------------------------------------------------------------------- */

    // map iterators (+ begin() and end())
    std::cout << "\n - map iterators (+ begin() and end()): " << std::endl;

    ft::map<char,int>::iterator map_it;

    for (map_it = test_map.begin(); map_it != test_map.end(); ++map_it)
        std::cout << map_it->first << " => " << map_it->second << std::endl;


    ft::map<char,int>::iterator map_it2;

    for (map_it2 = test_map2.begin(); map_it2 != test_map2.end(); ++map_it2)
        std::cout << map_it2->first << " => " << map_it2->second << std::endl;

    // Output: ***********************
    // c => 1
    // d => 2
    // a => 500
    // b => 600

    /* ---------------------------------------------------------------------- */

    // map::equal_range
    std::cout << "\n - map::equal_range: " << std::endl;

    ft::map<char,int> mymap;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';

    // Output: ***********************
    // lower bound points to: b => 20
    // upper bound points to: c => 30

    /* ---------------------------------------------------------------------- */
    
    // map::find
    std::cout << "\n - map::find: " << std::endl;

    ft::map<char,int> mmymap;
    ft::map<char,int>::iterator bit;

    mmymap['a']=50;
    mmymap['b']=100;
    mmymap['c']=150;
    mmymap['d']=200;

    bit = mmymap.find('b');
    if (bit != mmymap.end())
        mmymap.erase (bit);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mmymap.find('a')->second << '\n';
    std::cout << "c => " << mmymap.find('c')->second << '\n';
    std::cout << "d => " << mmymap.find('d')->second << '\n';

    // Output: ***********************
    // elements in mymap:
    // a => 50
    // c => 150
    // d => 200

    /* ---------------------------------------------------------------------- */

    // assignment operator with maps
    std::cout << "\n - assignment operator with maps: " << std::endl;

    ft::map<char,int> kfirst;
    ft::map<char,int> ksecond;

    kfirst['x'] = 8;
    kfirst['y'] = 16;
    kfirst['z'] = 32;

    ksecond = kfirst;              // second now contains 3 ints
    kfirst = ft::map<char,int>();  // and first is now empty

    std::cout << "Size of kfirst: " << kfirst.size() << '\n';
    std::cout << "Size of ksecond: " << ksecond.size() << '\n';

    // Output: ***********************
    // Size of kfirst: 0
    // Size of ksecond: 3

    /* ---------------------------------------------------------------------- */
    
    // insert & erase big map
    std::cout << "\n - insert & erase big map: " << std::endl;

    ft::map<int, std::string> map;
    // srand(time(0)); // can not be used to compare output of ft & std, since the seed would be different every time you compile
    srand(5);
    for (size_t i = 0; i < 1000000; ++i)
        map.insert(ft::make_pair<int, std::string>(std::rand() % 1000000, "performance: " + std::to_string(i)));
    std::cout << "test_map map.size() = " << map.size() << std::endl;
    ft::map<int, std::string> map2(map);	
    std::cout << "test_map map2.size() = " << map2.size() << std::endl;
    ft::map<int, std::string> map3(map2.begin(), map2.end());
    std::cout << "test_map map3.size() = " << map3.size() << std::endl;
    map.erase(map.begin(), map.end());	
    std::cout << "test_map map.size() = " << map.size() << std::endl;

    std::cout << GREEN << "\n --------------------------------------------- " << RESET << std::endl;

    // Output: ***********************
    // test_map map.size() = 632433
    // test_map map2.size() = 632433
    // test_map map3.size() = 632433
    // test_map map.size() = 0


    /* ################################ SET ################################# */

    std::cout << GREEN << "\n          ***************************" << std::endl;
    std::cout          <<   "          *           SET           *" << std::endl;
    std::cout          <<   "          ***************************" << RESET << std::endl;

    /* ---------------------------------------------------------------------- */

    // set regular insert
    std::cout << "\n - set regular insert: " << std::endl;

	ft::set<int> test_set;

	test_set.insert(500);
	std::cout << "test_set.size(): " << test_set.size() << std::endl;
	std::cout << "test_set.max_size(): " << test_set.max_size() << std::endl;

	test_set.insert(600);
	std::cout << "test_set.size(): " << test_set.size() << std::endl;

	ft::set<int> test_set2;
	test_set2.insert(1);
	std::cout << "test_set2.size(): " << test_set2.size() << std::endl;

	test_set2.insert(2);
	std::cout << "test_set2.size(): " << test_set2.size() << std::endl;

    // Output: ***********************
    // test_set.size(): 1
    // test_set.max_size(): 576460752303423487
    // test_set.size(): 2
    // test_set2.size(): 1
    // test_set2.size(): 2

    /* ---------------------------------------------------------------------- */
   
    // set insert/erase iterator safety
    std::cout << "\n - set insert/erase iterator safety: " << std::endl;
    ft::set<int> test_set222;

    for (int i = 0; i < 9; ++i) {
        test_set222.insert(i + 1);
    }

    ft::set<int>::iterator it_five = test_set222.begin();
    for (int i = 0; i < 4; ++i)
        ++it_five;

    std::cout << "After construction" << std::endl;
    for (ft::set<int>::iterator it = test_set222.begin(); it != test_set222.end(); ++it)
        std::cout << &(*it) << " " << *it << std::endl;

    std::cout << "it_five BEFORE everything: " << &(*it_five) << " " << *it_five << "\n" << std::endl;


    test_set222.insert(11);

    std::cout << "After insert 11" << std::endl;
    for (ft::set<int>::iterator it = test_set222.begin(); it != test_set222.end(); ++it)
        std::cout << &(*it) << " " << *it << std::endl;

    std::cout << "it_five AFTER insert 11 everything: " << &(*it_five) << " " << *it_five << "\n" << std::endl;

    
    test_set222.erase(4);

    std::cout << "After erase 4" << std::endl;
    for (ft::set<int>::iterator it = test_set222.begin(); it != test_set222.end(); ++it)
        std::cout << &(*it) << " " << *it << std::endl;

    std::cout << "it_five AFTER erase 4 everything: " << &(*it_five) << " " << *it_five << "\n" << std::endl;
    
    // Output: ***********************
    // all addresses should remain the same, throughout the insertion and erasing
    // it_five should point to the same node until the end (address and value))
    
    /* ---------------------------------------------------------------------- */

    // set swap
    std::cout << "\n - set swap: " << std::endl;

	test_set2.swap(test_set);
	std::cout << "test_set.size(): " << test_set.size() << std::endl;
	std::cout << "test_set2.size(): " << test_set2.size() << std::endl;

    // Output: ***********************
    // test_set.size(): 2
    // test_set2.size(): 2

    /* ---------------------------------------------------------------------- */

    // set iterators (+ begin() and end())
    std::cout << "\n - set iterators (+ begin() and end()): " << std::endl;

    ft::set<int>::iterator set_it;

    for (set_it = test_set.begin(); set_it != test_set.end(); ++set_it)
        std::cout << *set_it << std::endl;


    ft::set<int>::iterator set_it2;

    for (set_it2 = test_set2.begin(); set_it2 != test_set2.end(); ++set_it2)
        std::cout << *set_it2 << std::endl;

    // Output: ***********************
    // 1
    // 2
    // 500
    // 600

    /* ---------------------------------------------------------------------- */

    // set::equal_range
    std::cout << "\n - set::equal_range: " << std::endl;

    ft::set<int> myset;

    myset.insert(10);
    myset.insert(20);
    myset.insert(30);

    ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret_set;
    ret_set = myset.equal_range(20);

    std::cout << "lower bound points to: ";
    std::cout << *ret_set.first << '\n';

    std::cout << "upper bound points to: ";
    std::cout << *ret_set.second << '\n';

    // Output: ***********************
    // lower bound points to: 20
    // upper bound points to: 30

    /* ---------------------------------------------------------------------- */
    
    // set::find
    std::cout << "\n - set::find: " << std::endl;

    ft::set<int> mmyset;
    ft::set<int>::iterator sit;

    mmyset.insert(50);
    mmyset.insert(100);
    mmyset.insert(150);
    mmyset.insert(200);

    sit = mmyset.find(100);
    if (sit != mmyset.end())
        mmyset.erase (sit);

    // print content:
    std::cout << "elements in myset:" << '\n';
    std::cout << "50 => " << *mmyset.find(50) << '\n';
    std::cout << "150 => " << *mmyset.find(150) << '\n';
    std::cout << "200 => " << *mmyset.find(200) << '\n';

    // Output: ***********************
    // elements in myset:
    // 50 => 50
    // 150 => 150
    // 200 => 200

    /* ---------------------------------------------------------------------- */

    // assignment operator with sets
    std::cout << "\n - assignment operator with sets: " << std::endl;

    ft::set<char> sfirst;
    ft::set<char> ssecond;

    sfirst.insert('x');
    sfirst.insert('y');
    sfirst.insert('z');

    ssecond = sfirst;              // second now contains 3 ints
    sfirst = ft::set<char>();  // and first is now empty

    std::cout << "Size of sfirst: " << sfirst.size() << '\n';
    std::cout << "Size of ssecond: " << ssecond.size() << '\n';

    // Output: ***********************
    // Size of sfirst: 0
    // Size of ssecond: 3

    /* ---------------------------------------------------------------------- */
    
    // insert & erase big set
    std::cout << "\n - insert & erase big set: " << std::endl;

    ft::set<int> set;
    // srand(time(0)); // can not be used to compare output of ft & std, since the seed would be different every time you compile
    srand(5);
    for (size_t i = 0; i < 1000000; ++i)
        set.insert(std::rand() % 1000000);
    std::cout << "test_set set.size() = " << set.size() << std::endl;
    ft::set<int> set2(set);	
    std::cout << "test_set set2.size() = " << set2.size() << std::endl;
    ft::set<int> set3(set2.begin(), set2.end());
    std::cout << "test_set set3.size() = " << set3.size() << std::endl;
    set.erase(set.begin(), set.end());	
    std::cout << "test_set set.size() = " << set.size() << std::endl;

    // Output: ***********************
    // test_set set.size() = 632433
    // test_set set2.size() = 632433
    // test_set set3.size() = 632433
    // test_set set.size() = 0

    std::cout << GREEN << "\n --------------------------------------------- " << RESET << std::endl;




    std::cout << "\n !!!!!!!!!!!!!!!!! FINISHED !!!!!!!!!!!!!!!!!! " << std::endl;

    return (0);
}
