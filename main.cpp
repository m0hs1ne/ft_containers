#include <iostream>
#include "utils/Containers/Vector.hpp"
#include <vector>

class Test
{
public:
    Test() { }
    ~Test() {}
};

int main()
{
    ft::Vector<int> v;
    std::vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        v2.push_back(i);
    }
    
    std::cout << v.size() << std::endl;
    std::cout << v2.size() << std::endl;

    v.resize(5);
    v2.resize(5);

    std::cout << v.size() << std::endl;
    std::cout << v2.size() << std::endl;

    std::cout << v.capacity() << std::endl;
    std::cout << v2.capacity() << std::endl;

    std::cout << v[9] << std::endl;
    // std::cout << v2[5] << std::endl;


    return 0;
}
