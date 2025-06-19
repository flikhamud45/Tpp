#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class is_prime
{
public:
    bool operator()(int x)
    {
        if (x < 2)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};

class greater
{
public:
    bool operator()(std::pair<int, int> &p)
    {
        return p.first > p.second;
    }
};

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p)
{
    os << "<" << p.first << ", " << p.second << ">";
    return os;
}


class divided_by
{
public:
    divided_by(int n)
        : m_n(n)
    {
        // left empty intentially
    }

    bool operator()(int x)
    {
        return x % m_n == 0;
    }

private:
  int m_n;
};

class product
{
    // product the numbers with state
public:
    product(int init = 1) : m_p(init)
    {
        // left blank intentially
    }

    void operator()(int x)
    {
        m_p *= x;
    }

    int get()
    {
        return m_p;
    }

private:
    int m_p;
};

int main()
{
    

    // 1. print the prime numbers
    std::vector<int> v(30);
    std::generate(v.begin(), v.end(), [n = 1]() mutable { return n++; });
    std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), is_prime());
    std::cout << "\n";
    
    // 2. remove pairs which the first greater than the second
    std::vector<std::pair<int, int>> v2{30};
    std::generate(v2.begin(), v2.end(), []() {
        return std::pair<int, int>{static_cast<int>(rand()), static_cast<int>(rand())};
    });
    v2 = std::vector<std::pair<int, int>>(v2.begin(), std::remove_if(v2.begin(), v2.end(), greater()));
    std::for_each(v2.begin(), v2.end(), [](std::pair<int, int> p) { std::cout << p << " "; });
    std::cout << "\n";
    
    // 3. print all number that can be divided by 3 in v
    std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), divided_by(3));
    std::cout << "\n";

    // 4. print the product of v
    auto p = product();
    std::for_each(v.begin(), v.end(), std::ref(p));
    std::cout << p.get();
    


    return 0;
}
