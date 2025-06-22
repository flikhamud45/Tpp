#pragma once
#include <string>

#include <list>
#include <vector>

typedef enum _hash_error
{
    KEY_NOT_FOUND
} hash_error;



class HashTable
{
public:
    HashTable(size_t table_size, size_t max_list_size = 10, size_t m_table_size_factor = 2);

    HashTable(const HashTable &h);

    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void add(const std::string& key, void* value);

    void* get(const std::string& key) const;

    // remove the given key
    void pop(const std::string& key);

    // the number of elements in the table
    size_t getSize() const;

    // get an element by value
    const std::string getKey(void* value) const;

    // return if the given *key exist
    bool isIn(const char*  key) const;

    HashTable operator+(const HashTable &other) const;

    void operator+=(const HashTable& other);

    bool operator==(const HashTable& other) const;

    size_t getTableSize();

private:
    // each value will be pointer to the key and value node so we can search for value and go through the keys in O(number of values) and not O(size of arr). we can still get and add in O(1).
  std::vector<std::list<std::list<std::pair<std::string, void*>>::iterator*>> m_arr;

    // linked list of pairs of key and value
  std::list<std::pair<std::string, void*>> m_keys_values;

    // size of the table
  size_t m_table_size;

    // number of elements
  size_t m_size;

    // the max number of collisions allowed
  size_t m_max_list_size;

    // the factor to multiply the table_size when having too many collisions.
  size_t m_table_size_factor;

    // index in the hashtable
  size_t getIndex(const std::string& key) const;


};
