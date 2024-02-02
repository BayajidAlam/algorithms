#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int first, second;
    void make_pair(int a, int b)
    {
        first = a;
        second = b;
    }
};

int main()
{   
    // using custom class 
    Pair p;
    p.make_pair(10, 20);
    cout << p.first << " " << p.second << endl;

    // using stl
    pair<int, int> pr;
    pr = make_pair(30, 40);
    cout << pr.first << " " << pr.second << endl;
    return 0;
}