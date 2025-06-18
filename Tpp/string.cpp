#include <cstring>
#include "string.h"



String::String() : String("")
{
	// left empty intentialy
}

String::String(const char* s)
{
    size_t len = strlen(s);
    arr = new char[len+1];
    strcpy_s(arr, len + 1, s);
}

String::String(const String& s)
{
    size_t len = strlen(s.arr);
    arr = new char[len + 1];
    strcpy_s(arr, len+1, s.arr);
}

String::String(String&& other) noexcept
{
    arr = other.arr;     
    other.arr = nullptr; 
}

String::~String()
{
    delete[] arr;
}

String String::operator+(const char* s)
{
    return *this + String(s);
}

String String::operator+(String s)
{
    char* new_arr = new char[strlen(arr) + strlen(s.arr) + 1];
    strcpy_s(new_arr, strlen(arr)+1, arr);
    strcat_s(new_arr, strlen(arr) + strlen(s.arr) + 1, s.arr);
    String ans = String(new_arr);
    delete[] new_arr;
    return ans;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.arr;
    return os;
}

String& String::operator=(const String& other)
{
    delete[] arr;
    size_t len = strlen(other.arr);
    arr = new char[len + 1];
    strcpy_s(arr, len + 1, other.arr);
    return *this;
}

bool String::operator==(const String& other)
{
    return strcmp(arr, other.arr) == 0;
}

