#include <algorithm>
#include <iostream>

using namespace std;

string xor_string(string s, int x)
{
    return [s, x]() {
        string s2;
        transform(s.begin(), s.end(), back_inserter(s2), [x](char c) { return static_cast<char>(c ^ x); });
        return s2;
    }();
}

string reverse_string(string s)
{
    return [s]() {
        string s2;
        transform(s.rbegin(), s.rend(), back_inserter(s2), [](char c) { return c; });
        return s2;
    }();
}

int main()
{
    cout << xor_string("hi", 0) << endl;
    cout << reverse_string("hello") << endl;

    return 0;
}
