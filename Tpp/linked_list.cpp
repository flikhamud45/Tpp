#include "linked_list.h"

#include <new>

LinkedList::LinkedList()
{
    // we add a dummy node to the list
    m_start = new node_t;
    m_end = m_start;
    m_start->next = nullptr;
    m_start->prev = nullptr;
}


node_t* LinkedList::push(void* val)
{
    node_t* n = new node_t;
    n->value = val;
    m_end->next = n;
    n->prev = m_end;
    m_end = n;
    n->next = nullptr;
    return n;
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

