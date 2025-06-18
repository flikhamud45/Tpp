#include "hashtable.h"

#include <list>

HashTable::HashTable(size_t table_size)
{
    m_arr = new node_t*[table_size];
    m_size = 0;
    m_table_size = table_size;
    memset(m_arr, 0, table_size*sizeof(node_t*));
}

HashTable::HashTable(const HashTable& h) : HashTable(h.m_table_size)
{
    *this += h;
}

HashTable& HashTable::operator=(const HashTable& other)
{
    m_keys_values.clear();

    delete[] m_arr;
    m_arr = new node_t*[other.m_table_size];
    memset(m_arr, 0, sizeof(node_t*) * m_table_size);
    m_size = 0;
    m_table_size = other.m_table_size;
    *this += other;

    return *this;
}


HashTable::~HashTable()
{
    delete[] m_arr;
    // the linkedlist destructor gonna be called and delete everything :)

}


void HashTable::add(const char*  key, void* value)
{
    std::pair<const char* , void*> *p = new std::pair<const char* , void*>(key, value);
    node_t* n = m_keys_values.push(p);
    m_arr[getIndex(key)] = n;
    m_size++;
}

// return the index in the arr from the key
size_t HashTable::getIndex(const char*  key) const
{
    return std::hash<std::string>{}(key) % m_table_size;
}

void HashTable::pop(const char*  key)
{
    size_t index = getIndex(key);
    node_t *n = m_arr[index];
    if (n == nullptr)
    {
        throw hash_error::KEY_NOT_FOUND;
    }
    m_keys_values.pop(n);
    m_arr[index] = nullptr;
    m_size--;
    
}

void* HashTable::get(const char*  key) const
{
    size_t index = getIndex(key);
    node_t* n = m_arr[index];
    if (n == nullptr)
    {
        throw hash_error::KEY_NOT_FOUND;
    }
    std::pair<const char* , void*>* p = static_cast<std::pair<const char* , void*>*>(n->value);
    return p->second;
    
}

const char* HashTable::get_key(void* value) const
{
    node_t* curr = m_keys_values.getStart();
    curr = curr->next;
    while (curr != nullptr)
    {
        std::pair<const char* , void*>* p = static_cast<std::pair<const char* , void*>*>(curr->value);
        if (p->second == value)
        {
            return p->first;
        }
        curr = curr->next;
    }
    throw hash_error::KEY_NOT_FOUND;
}

bool HashTable::is_exist(const char*  key) const
{
    size_t index = getIndex(key);
    node_t* n = m_arr[index];
    return n != nullptr;
}

size_t HashTable::getSize() const
{
    return m_size;
}

HashTable HashTable::operator+(const HashTable &other) const
{
    HashTable h{std::max(m_table_size, other.m_table_size)};
    h += *this;
    h += other;
    return h;
}

void HashTable::operator+=(const HashTable &other)
{
    node_t *curr = other.m_keys_values.getStart();
    curr = curr->next;
    while (curr != nullptr)
    {
        std::pair<const char* , void*>* p = static_cast<std::pair<const char* , void*>*>(curr->value);
        add(p->first, p->second);
        curr = curr->next;
    }
}

bool HashTable::operator==(const HashTable &other) const
{
    if (m_size != other.m_size)
    {
        return false;
    }

    node_t* curr = m_keys_values.getStart();
    curr = curr->next;
    while (curr != nullptr)
    {
        std::pair<const char* , void*>* p = static_cast<std::pair<const char* , void*>*>(curr->value);
        if (other.get(p->first) != p->second)
        {
            return false;
        }
        curr = curr->next;
    }

    return true;
}






