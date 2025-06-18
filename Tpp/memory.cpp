#include "memory.h"
#include <cstdlib>
#include <iostream>
#include <new>

typedef struct _mem_info_t
{
    // struct so it will be easier to add info in the future
    size_t size;
} mem_info_t;


typedef struct _node_t
{
    struct _node_t* next;
    struct _node_t* prev;
    mem_info_t info;
} node_t;

typedef struct _linked_list_t
{
    node_t* start;
    node_t* end;
} linked_list_t;

linked_list_t metadata{nullptr, nullptr};


void init_metadata()
{
    // we add a dummy node to the list
    metadata.start = static_cast<node_t*>(malloc(sizeof(node_t)));
    if (metadata.start == nullptr)
    {
        throw std::bad_alloc();
    }
    metadata.end = metadata.start;
    metadata.start->next = nullptr;
    metadata.start->prev = nullptr;
}

void push_metadata(node_t* n)
{
    if (metadata.start == nullptr)
    {
        init_metadata();
    }
    metadata.end->next = n;
    n->prev = metadata.end;
    metadata.end = n;
    n->next = nullptr;
}

void pop_metadata(node_t* n)
{
    n->prev->next = n->next;
    if (n->next != nullptr)
    {
        n->next->prev = n->prev;
    }
    else
    {
        metadata.end = n->prev;
    }
}

void* new_alloc(size_t size)
{
    void* p = malloc(size + sizeof(node_t));
    if (p == nullptr)
    {
        throw std::bad_alloc();
    }
    node_t* n = static_cast<node_t*>(p);
    n->info.size = size;
    push_metadata(n);

    return static_cast<void*>(n + 1);
}


void delete_alloc(void* ptr)
{
    node_t* n = static_cast<node_t*>(ptr) - 1;
    pop_metadata(n);
    free(n);
}

void print_memory()
{
    std::cout << "memory statistics: ";
    node_t* curr = metadata.start;
    size_t i = 0;
    curr = curr->next;
    while (curr != nullptr)
    {
        std::cout << "mem" << i << " - " << curr->info.size << " bytes, ";
        curr = curr->next;
        i++;
    }
    std::cout << "\n";
}

