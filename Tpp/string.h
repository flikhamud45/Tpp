#include <ostream>

class String
{
public:
    // assume s in null terminated
    String(const char* s);

    String(const String &s);

    // empty string
    String();

    ~String();

    String operator+(String s);

    // assume s in null terminated
    String operator+(const char* s);


    // for printing
    friend std::ostream& operator<<(std::ostream& os, const String& str);



private:
    // there is not get and set for this intentially
    char* arr;


};
