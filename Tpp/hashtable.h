#pragma once
#include <string>
#include "linked_list.h"

typedef enum _hash_error
{
    KEY_NOT_FOUND
} hash_error;


class HashTable
{
public:
    HashTable(size_t table_size);

    HashTable(const HashTable &h);

    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void add(const char*  key, void* value);

    void* get(const char*  key) const;

    // remove the given key
    void pop(const char*  key);

    // the number of elements in the table
    size_t getSize() const;

    // get an element by value
    const char* get_key(void* value) const;

    // return if the given *key exist
    bool is_exist(const char*  key) const;

    HashTable operator+(const HashTable &other) const;

    void operator+=(const HashTable& other);

    bool operator==(const HashTable& other) const;

private:
    // each value will be pointer to the key and value node so we can search for value and go through the keys in O(number of values) and not O(size of arr). we can still get and add in O(1).
  node_t** m_arr;

    // linked list of pairs of key and value
  LinkedList m_keys_values;

    // size of the table
  size_t m_table_size;

    // number of elements
  size_t m_size;

    // index in the hashtable
  size_t getIndex(const char* key) const;

};
