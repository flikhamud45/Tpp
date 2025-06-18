#include "memory.h"
#include "linked_list.h"
#include <cstdlib>
#include <iostream>
#include <new>

typedef struct _mem_info_t
{
    // struct so it will be easier to add info in the future
    size_t size;
} mem_info_t;



LinkedList metadata;

void* new_alloc(size_t size)
{
    void* p = malloc(size + sizeof(node_t));
    if (p == nullptr)
    {
        throw std::bad_alloc();
    }
    node_t* n = static_cast<node_t*>(p);
    mem_info_t* info = static_cast<mem_info_t*>(malloc(sizeof(mem_info_t)));
    if (info == nullptr)
    {
        free(p);
        throw std::bad_alloc();
    }
    info->size = size;
    n->value = info;
    metadata.push(n);
    return static_cast<void*>(n + 1);
}


void delete_alloc(void* ptr)
{
    if (ptr == nullptr)
    {
        throw std::bad_alloc();
    }
    node_t* n = static_cast<node_t*>(ptr) - 1;
    metadata.pop(n);
    
}

void print_memory()
{
    std::cout << "memory statistics: ";
    node_t* curr = metadata.getStart();
    curr = curr->next;
    while (curr != nullptr)
    {
        mem_info_t* info = static_cast<mem_info_t*>(curr->value);
        std::cout << "address " << curr+1 << " - " << info->size << " bytes, ";
        curr = curr->next;
    }
    std::cout << "\n";
}

