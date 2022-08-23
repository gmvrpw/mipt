#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> v(10, 12);
    std::cout << v << "\n";
    v.PushBack(25);
    std::cout << v << "\n";
    return 0;
}