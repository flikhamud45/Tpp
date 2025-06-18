#include <ostream>

class String
{
public:
    // assume s in null terminated
    String(const char* s);

    String(const String &s);

    String(String&& s) noexcept;

    // empty string
    String();

    ~String();

    String operator+(String &s);

    // assume s in null terminated
    String operator+(const char*& s);

    String& operator=(const String& other);

    bool operator==(const String& other);

    // for printing
    friend std::ostream& operator<<(std::ostream& os, const String& str);



private:
    // there is not get and set for this intentially
    char* arr;


};
