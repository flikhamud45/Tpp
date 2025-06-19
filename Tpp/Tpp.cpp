#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

string xor_string(string s, int x){
    return accumulate(s.begin(), s.end(), string(), [x](string& s, char c) {
        s.push_back(static_cast<char>(c ^ x));
        return s;
    });
}

string reverse_string(string s)
{
    return accumulate(s.rbegin(), s.rend(), string(), [](string &s, char c) {
        s.push_back(c);
        return s;
    });
    
}

bool is_all_caps(vector<string> v)
{
    // i accept characters like , . or space
    return all_of(v.begin(), v.end(),
                  [](string s) {
                      return all_of(s.begin(), s.end(), 
                          [](char c) { return !(c >= 'a' && c <= 'z'); }
                      );}
    );
}


vector<int> flatten(vector<vector<int>> &mat)
{
    return accumulate(mat.begin(), mat.end(), vector<int>(), [](vector<int>& v1, vector<int>& v2) mutable {
        copy(v2.begin(), v2.end(), back_inserter(v1));
        return v1;
    });
    

}


int main()
{
    
    cout << xor_string("hi", 0) << endl;
    cout << reverse_string("hello") << endl;
    vector<string> v1 = {"OFEK LAVI", "LIRI"}, v2 = {"OFEK", "Liri"};
    cout << is_all_caps(v1) << ", " << is_all_caps(v2) << "\n";

    vector<vector<int>> mat({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    vector<int> v = flatten(mat);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
