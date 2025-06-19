#include "hashtable.h"

#include <list>
#include <vector>

HashTable::HashTable(size_t table_size)
{
    m_arr = std::vector<std::list<std::pair<std::string, void*>>::iterator*>(table_size, nullptr);
    m_size = 0;
    m_table_size = table_size;
    
}

HashTable::HashTable(const HashTable& h) : HashTable(h.m_table_size)
{
    *this += h;
}

HashTable& HashTable::operator=(const HashTable& other)
{
    m_keys_values.clear();

    m_arr = std::vector<std::list<std::pair<std::string, void*>>::iterator*>(other.m_table_size, nullptr);
    m_size = 0;
    m_table_size = other.m_table_size;
    *this += other;

    return *this;
}


HashTable::~HashTable()
{
    // the linkedlist destructor gonna be called and delete everything :)

}


void HashTable::add(const std::string& key, void* value)
{
    auto it = m_keys_values.insert(m_keys_values.begin(), std::pair<std::string, void*>(key, value));
    auto pit = new std::list<std::pair<std::string, void*>>::iterator(it);
    m_arr[getIndex(key)] = pit;
    m_size++;
}

// return the index in the arr from the key
size_t HashTable::getIndex(const std::string&  key) const
{
    return std::hash<std::string>{}(key) % m_table_size;
}

void HashTable::pop(const std::string& key)
{
    size_t index = getIndex(key);
    auto pos = m_arr[index];
    if (pos == nullptr)
    {
        throw hash_error::KEY_NOT_FOUND;
    }
    m_keys_values.erase(*pos);
    m_arr[index] = nullptr;
    m_size--;
    
}

void* HashTable::get(const std::string&  key) const
{
    size_t index = getIndex(key);
    auto pos = m_arr[index];
    if (pos == nullptr)
    {
        throw hash_error::KEY_NOT_FOUND;
    }
    std::pair<std::string, void*> p = **pos;
    return p.second;
    
}

const std::string HashTable::getKey(void* value) const
{
    for (std::pair<std::string, void*> p : m_keys_values)
    {
        if (p.second == value)
        {
            return p.first;
        }
    }
    throw hash_error::KEY_NOT_FOUND;
}

bool HashTable::isIn(const char*  key) const
{
    size_t index = getIndex(key);
    auto pos = m_arr[index];
    return pos != nullptr;
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
    for (auto p: other.m_keys_values)
    {
        add(p.first, p.second);
    }
}

bool HashTable::operator==(const HashTable &other) const
{
    if (m_size != other.m_size)
    {
        return false;
    }

    for (auto p: m_keys_values) 
    {
        if (other.get(p.first) != p.second)
        {
            return false;
        }
    }
    return true;
}






