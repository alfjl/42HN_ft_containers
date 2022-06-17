#include <iostream>

// check to see if assignation operator of std:;pair deletes potential old ptr in pair.second, or not
int main(void)
{
    int *one = new int(1);
    int *two = new int(2);
    int *three = new int(3);
    std::pair<char, int *>  paerle;
    std::pair<char, int *>  paerle2;

    paerle = std::make_pair('a', one);
    paerle2 = std::make_pair('b', two);
    std::cout << *(paerle.second) << std::endl;

    paerle = paerle2;
    // paerle.second = two;
    std::cout << *(paerle.second) << std::endl;
    std::cout << *one << std::endl;

    paerle = std::make_pair('c', three);
    std::cout << *(paerle.second) << std::endl;
}
// ===> RESULT: No! Just assigns new values, but doesn't delete anything.