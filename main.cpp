#include <iostream>
#include <cassert>
#include "utils/Containers/vector.hpp"
#include <vector>
#include <sstream>

std::string b_string[64] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63"};
std::string s_string[32] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
int b_int[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
int s_int[32] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

 int main()
 {
     {
         ft::vector<int> v;

         v.assign(s_int, s_int + 32);

         std::cout << v.size() << std::endl;
         std::cout << v.capacity() << std::endl;

          v.push_back(64);
          std::cout << v.size() << std::endl;
          std::cout << v.capacity() << std::endl;
          v.assign(b_int, b_int + 64);
          std::cout << "----------------" << std::endl;
     }
     {
        ft::vector<std::string> v;
        std::string s;
        std::istringstream str("1 2 3 4 5 6 7");
        while (str >> s)
            v.push_back(s);
        std::cout << v.size() << std::endl;
        std::cout << v.capacity() << std::endl;
        v.assign(v.begin(), v.end());
        std::cout << v.size() << std::endl;
        std::cout << v.capacity() << std::endl;
        v.assign(v.begin(), v.begin() + 21);
        std::cout << v.size() << std::endl;
        std::cout << v.capacity() << std::endl;
        std::cout << "----------------" << std::endl;
     }
     {
         ft::vector<std::string> v;

         v.assign(b_string, b_string + 64);
         std::cout << v.size() << std::endl;
         std::cout << v.capacity() << std::endl;
         v.assign(65, "test");
         std::cout << v.size() << std::endl;
         std::cout << v.capacity() << std::endl;
         v.assign(s_string, s_string + 32);
         std::cout << v.size() << std::endl;
         std::cout << v.capacity() << std::endl;
         std::cout << "----------------" << std::endl;
     }
 }

// int main()
// {
//     ft::vector<std::string> v;
//     ft::vector<std::string>::iterator it = v.insert(v.begin(), b_string[54]);
//     std::cout << *it << std::endl;
//     it = v.insert(v.begin(), b_string[19]);
//     std::cout << *it << std::endl;
// }

// int main(){
//     const int size = 5;
//     ft::vector<int> vct(size);
//     ft::vector<int>::reverse_iterator it = vct.rbegin();
//     ft::vector<int>::const_reverse_iterator ite = vct.rbegin();
//
// 	for (int i = 0; i < size; ++i)
// 		it[i] = (size - i) * 5;
//
// 	it = it + 5;
// 	it = 1 + it;
// 	it = it - 4;
// 	std::cout << *(it += 2) << std::endl;
// 	std::cout << *(it -= 1) << std::endl;
//
// 	*(it -= 2) = 42;
// 	*(it += 2) = 21;
//
// 	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;
//
// 	std::cout << "(it == const_it): " << (ite == it) << std::endl;
// 	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
// 	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
//
// }

//class B {
//public:
//    char *l;
//    int i;
//
//    B() : l(nullptr), i(1) {};
//
//    B(const int &ex) {
//        this->i = ex;
//        this->l = new char('a');
//    };
//
//    virtual ~B() {
//        delete this->l;
//        this->l = nullptr;
//    };
//};
//
//class A : public B {
//public:
//    A() : B() {};
//
//    A(const B *ex) {
//        this->l = new char(*(ex->l));
//        this->i = ex->i;
//        if (ex->i == -1)
//            throw "n";
//    }
//
//    ~A() {
//        delete this->l;
//        this->l = nullptr;
//    };
//};
//
//int main() {
//    try {
//        std::unique_ptr <B> k2(new B(3));
//        ft::vector<A> vv;
//        ft::vector<B *> vv2;
//
//        vv2.push_back(&(*k2));
//
//        std::cout << "----------------" << std::endl;
//        vv.insert(vv.begin(), vv2.begin(), vv2.end());
//        std::cout << "----------------" << std::endl;
//    }
//    catch (const char *e) {
//        std::cout << e << std::endl;
//    }
//}

// int main()
// {
//     ft::vector<long> v1;
//     ft::vector<long> v2;

//     if (v1 == v2)
//     {
//         printf("Equal");
//     }
// }

// int main()
// {
//     ft::vector<char> v1;
//     std::vector<char> v2;
//     std::cout << v1.max_size() << std::endl;
//     std::cout << v2.max_size() << std::endl;
//     std::cout << PTRDIFF_MAX << std::endl;
//
// }
