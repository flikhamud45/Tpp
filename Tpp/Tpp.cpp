#include "memory.h"

#include <iostream>

int main()
{
    int* num = static_cast<int*>(new_alloc(sizeof(int)));
    int* num_arr = static_cast<int*>(new_alloc(sizeof(int)*10));
    num_arr[8] = 3;
    num_arr[3] = 10;
    *num = 7;

    std::cout << *num + num_arr[8] + num_arr[3] << "\n";
    print_memory();
    delete_alloc(num);
    print_memory();
    delete_alloc(num_arr);
    print_memory();
    char* char_arr = static_cast<char*>(new_alloc(sizeof(char) * 14));
    print_memory();
    delete_alloc(char_arr);
    print_memory();


    return 0;
}
