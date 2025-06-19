#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>
 using namespace std;

int main()
{
    // 1
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 2
    cout << count(v.begin(), v.end(), 4) << " elements are equal to 4\n";

    // 3
    cout << count_if(v.begin(), v.end(), [](int x) { return x > 4; }) << " elements are greater than 4\n";

    // 4
    v =  vector<int>(v.begin(), remove_if(v.begin(), v.end(), [](int x) { return x < 8; }));

    // 5
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    // 6
    vector<int> v2;

    // 7
    adjacent_difference(v.begin(), v.end(), back_inserter(v2));

    // 8 
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    // 9
    cout << "The sum of v2 is " << accumulate(v2.begin(), v2.end(), 0) << "\n";
    return 0;
}
