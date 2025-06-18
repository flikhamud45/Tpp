#include <iostream>
#include "hashtable.h"

int main()
{
    HashTable h1{1000};
    int n1 = 1, n2 = 2;
    h1.add("1", &n1);
    h1.add("2", &n2);
    std::cout << *static_cast<int*>(h1.get("1")) << *static_cast<int*>(h1.get("2")) << "\n";
    h1.pop("2");
    std::cout << h1.is_exist("2") << "\n";
    std::cout << *static_cast<int*>(h1.get("1")) << "\n";
    HashTable h2{1000};
    h2.add("2", &n2);
    HashTable h3 = h1 + h2;
    std::cout << *static_cast<int*>(h3.get("1")) << * static_cast<int*>(h3.get("2")) << "\n";
    h2 += h1;
    std::cout << *static_cast<int*>(h3.get("1")) << *static_cast<int*>(h3.get("2")) << "\n";
    std::cout << (h1 == h3) << "\n";
    h3.pop("2");
    std::cout << (h1 == h3) << "\n";
    return 0;
}
