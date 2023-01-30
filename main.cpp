#include <iostream>
#include "utils/Containers/Vector.hpp"
int main()
{
    ft::Vector<int> v;
    int i[] = {1, 2, 3, 4, 5};
    v.assign(i, i + 5);
    ft::Vector<int>::const_iterator it = v.begin();
    std::cout << *it << std::endl;
    

    
    return 0;
}