# 42HN_ft_containers

The goal of the **ft_containers** project is to reimplement some of the C++ STL containers, in order to get a deeper understanding of how they work.  
Additionally, since map and set include an implementation of a red-black tree, the second main goal of this project is to get a better understanding of different trees as data structures.  
As all C++ projects at the core curriculum of School 42, the students code has to comply with the C++98 standard.

## Description

Take the structure of each standard container as reference. Comply with the C++98 standard, so any later feature of the containers MUST NOT be implemented, but every C++98 feature (even deprecated ones) is expected.  
The namespace must be 'ft'. There can't be more public functions than in the original implementation.  
You must use the std::allocator. If the container has an iterator system, you have to implement it.
Implement the following containers and necessary add-ons:

 - vector  
 - map
 - stack
 - set (BONUS)
 - iterators_traits
 - reverse_iterator
 - enable_if (even though its C++11, so implement it in a C++98 style)
 - is_integral
 - equal and/or lexicographical_compare
 - std::pair
 - std::make_pair


## Learnings

I learned how to really use the C++ references [cplusplus.com](http://www.cplusplus.com/) and [cppreference.com](https://en.cppreference.com/), how to read the STL source code and see the difference (and historic development) between different C++ generations. It also showed me the lineage from C to C++, and how these two languages are connected internally. Further, I gained a deeper understanding of the inner workings of STL containers and supporting structures, such as, how iterators work. I also got in contact with allocators for the first time, and understood, that there are more ways to deal with memory, besides my old friends new and delete. Finally, I concerned myself with trees as data structures (e.g. binary search tree, red-black tree), while checking out some of the pros and cons of different tree types.

## Testing

The main.cpp provided is only a limited test, to pass the evaluation guidelines of this project.
To make sure my code was working as sound as possible, I've tested my code with the following testers and mains (including running each main with valgrind on macOS, to check for leaks):

* [mli42 / containers_test](https://github.com/mli42/containers_test)
* [Mikastiv / ft_containers-terminator](https://github.com/Mikastiv/ft_containers-terminator) (including its benchmark tester)
* [the tester of fellow 42 Heilbronn peer Aktai0n](https://github.com/Aktai0n/ft_containers-42Heilbronn)
* [the main of fellow 42 Heilbronn peer JL1709](https://github.com/JL1709/ft_containers)
* [the main of fellow 42 Heilbronn peer JeremieSiller](https://github.com/JeremieSiller/ft_containers)

Being a school project and the first time for me to come in contact with the inner workings of the STL containers, I don't presume my implementation to be bulletproof.  
Thus, I'm very happy about every constructive feedback I can get!  

## Resources

#### STL
* [cplusplus.com](http://www.cplusplus.com/)
* [cppreference.com](https://en.cppreference.com/w/)
* [The C++ Standard Library, Second Edition](https://www.mica.edu.vn/perso/Vu-Hai/EE3490/Ref/The%20C++Standard%20Library%20-%202nd%20Edition.pdf)
#### Trees
* [Algorithms, Third Edition, Chapters 12 & 13](https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf)
* [Red-black tree visualizer](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
