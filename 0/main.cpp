#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> v(10);
    for (long long i = 0; i < 10; ++i)
    {
        v.Set(i, i);
    }
    std::cout << v << "\n";
    v.PushBack(25);
    std::cout << v << "\n";
    v.Insert(3, 100);
    std::cout << v << "\n";
    return 0;
}