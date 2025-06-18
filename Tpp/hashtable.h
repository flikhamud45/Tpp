#include <string>

class HashTable
{
public:
    HashTable(size_t table_size);

    void add(std::string key, void* value);

    void* get(std::string key);

    // remove the given key
    void pop(std::string key);

    // the number of elements in the table
    size_t size();

    // get an element by value
    std::string get(void* value);

    // return if the given key exist
    bool is_exist(std::string key);

    void operator+(HashTable t);

    void operator+=(HashTable t);

    bool operator==(HashTable t);

private:

};
