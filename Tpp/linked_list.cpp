#include "linked_list.h"

#include <new>

LinkedList::LinkedList()
{
    // we add a dummy node to the list
    m_start = static_cast<node_t*>(malloc(sizeof(node_t)));
    if (m_start == nullptr)
    {
        throw std::bad_alloc();
    }
    m_end = m_start;
    m_start->next = nullptr;
    m_start->prev = nullptr;
}

void LinkedList::push(node_t* n)
{
    m_end->next = n;
    n->prev = m_end;
    m_end = n;
    n->next = nullptr;
}


void LinkedList::pop(node_t* n)
{
    n->prev->next = n->next;
    if (n->next != nullptr)
    {
        n->next->prev = n->prev;
    }
    else
    {
        m_end = n->prev;
    }
    delete n->value;
    delete n;
    
}

void LinkedList::clear()
{
    while (m_start != m_end)
    {
        pop(m_end);
    }
}


node_t* LinkedList::getEnd() const
{
    return m_end;
}

node_t* LinkedList::getStart() const
{
    return m_start;
}


LinkedList::~LinkedList()
{
    clear();
    delete m_start;
}

